#!/bin/bash -eu
rpath="$(realpath "$1")"
echo '#!/bin/bash -eu'
echo 'NS_LOG=""'
find "$1" -name "*.cpp" | grep -v '\.t\.cpp$' | xargs grep -Ir NFD_LOG_INIT | sed "s;^${rpath}/;;g" | sed 's/^\([^:]*\):\ *NFD_LOG_INIT("\(.*\)")/#NS_LOG="nfd.\2:$NS_LOG"\t# \1/g' | expand -t 30
echo 'export NS_LOG'
