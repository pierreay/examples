#!/bin/bash

# * About

# The architecture of this file allows to separate code that is meant to be
# sourced and code that is meant to be executed in a subshell. This allows, in
# one script, to provide a library that will be available in the current shell
# (if sourced) while providing automation (if executed).

# Idea: Separation between definition and script like Python does with `if __name__ == "__main__":`.
# Source: https://unix.stackexchange.com/questions/424492/how-to-define-a-shell-script-to-be-sourced-not-run

# * Sourcing

function myfunc() {
    echo "[+] This is my defined function!"
}

# * Executing

if [ "${BASH_SOURCE[0]}" -ef "$0" ]
then
    myfunc
    exit 11
fi

return 22
