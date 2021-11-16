# Logging

## `NS_LOG`の確認

```bash
_waf_run(){
  echo '#!/bin/bash -eu'
  echo 'NS_LOG=""'
  grep -r NFD_LOG_INIT ns-3/src/ndnSIM | sed 's;^\([^:]*\):NFD_LOG_INIT("\(.*\)");#NS_LOG="nfd.\2:$NS_LOG" # \1;g' | grep -v example |grep "#NS_LOG"
  echo 'export NS_LOG'
}
_waf_run > waf-run.sh
```
