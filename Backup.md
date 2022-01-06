# Backup

## Backup Script

```bash
#!/bin/bash -eu

function _sendMail() {
    local body="Error occurred."
    local subject="BACKUP_SCRIPT_ERROR:"
    mail -s "${subject}" 'user@mail.example.com'
}

trap "echo 'Error occurred.'; _sendNail; exit 1" ERR

####################################################3

temp="/tmp/your-backup-dirname"
mkdir -p "temp"
cd "$temp"

f="/path/to/ns-3"
b="/path/to/backups"

d="PREFIX_$(date +%Y%m%d-%H%M)_ndnSIM.7z"

# NOTE: exclude build data *.o *.so
rsync -arz --exclude '**/*.so' --exclude '**/*.o' "$f" . 

cd ns-3
./waf configure --enable-examples >/dev/null &2>1 # At first, configure
./waf clean >/dev/null  &2>1 # build data clean

cd "$temp"
# compress using 7z
7z a "$d" ns-3 1> /dev/null &2>1

rsync -z "$d" "$b"
rsync -z "$d" your-ssh-remote-backup-host:backups/
```
