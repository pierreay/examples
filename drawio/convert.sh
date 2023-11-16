#!/bin/bash

DRAWIO_BIN=/usr/bin/drawio

# Convert *.drawio file(s) into *.drawio.$2 files.
# $1 is a directory or a filename.
# $2 is an extension supported by drawio [pdf | png].
function drawio_to_ext() {
    echo "[+] Convert .drawio files to $2 from $1..."
    find "$1" -name "*.drawio" -exec rm -f {}.pdf \; -exec $DRAWIO_BIN --crop -x -o {}."$2" {} \;
}

function help() {
    cat << EOF
Usage: $0 DIR|FILE EXT

Convert drawio scheme(s) to the choosen format using the *.drawio.EXT name.

If DIR, convert all *.drawio files located under DIR.
If FILE, convert the FILE.

Supported formats for EXT:
- pdf
- png
EOF
}

if [[ $# != 2 ]]; then
    help
    exit 0
fi

if [[ ! -a "$1" ]]; then
    echo "[*] $1 is neither a valid directory or a valid file!"
    exit 1
fi

if [[ "$2" != "pdf" && "$2" != "png" ]]; then
    echo "[*] $2 is not a valid format/extension!"
    exit 1
fi

drawio_to_ext "$1" "$2"
