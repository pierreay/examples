#!/bin/bash

function check_error() {
    if [[ $? != 0 ]]; then
        echo "[!] Error occurred!"
    else
        echo "[+] No errors"
    fi
}

touch /unexistent_path
check_error
touch /tmp/test
check_error
