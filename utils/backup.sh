#!/bin/bash -eu
####################################################
# Configurations
## your workspace dir.
BACKUP_DIR_NAME="/tmp/your-backup-dirname"
## target ns-3
f="/path/to/ns-3"
## target backup dir(rsync style e.g. 'host:path/to/dir', '/path/to/dir' )
b="/path/to/backups"
# backup archive
d="PREFIX_$(date +%Y%m%d-%H%M)_ndnSIM.tar.xz"

####################################################

function _sendMail() {
    local subject="BACKUP_SCRIPT_ERROR:"
    mail -s "${subject}" 'user@mail.example.com'
}
trap "echo 'Error occurred.'; _sendNail; exit 1" ERR

# working space
mkdir -p "$BACKUP_DIR_NAME"; cd "$BACKUP_DIR_NAME"

# backup
## NOTE: exclude build data *.o *.so
rsync -arz --exclude '**/*.so' --exclude '**/*.o' "$f" .

# remove built files.
cd ns-3
## At first, configure
./waf configure --enable-examples >/dev/null 2>&1
## build data clean
./waf clean >/dev/null  2>&1
cd ../

# compress
tar acf "$d" ns-3 > /dev/null 2>&1
# send
rsync -cz "$d" "$b"
