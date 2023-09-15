#!/bin/bash

# Alternatives:
# command -v $1 &> /dev/null
# which $1 &> /dev/null
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
