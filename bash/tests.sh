#!/bin/bash

# Alternatives:
# POSIX-compatible:
# command -v $1 &> /dev/null
# Work but not recommended:
# which $1 &> /dev/null
# See https://stackoverflow.com/questions/592620/how-can-i-check-if-a-program-exists-from-a-bash-script
function command_exist() {
    # if statement
    if type $1 &> /dev/null; then
        echo "$1 exist!"
    else
        echo "$1 doesn't exist!"
    fi
    # one-liner
    type $1 &> /dev/null && echo "$1 exist!" || echo "$1 doesn't exist!"
}

command_exist bash
command_exist wrong
