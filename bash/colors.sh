#!/bin/bash

# Colors definition.
black='\e[30;1m'
red='\e[31;1m'
green='\e[32;1m'
yellow='\e[33;1m'
blue='\e[34;1m'
magenta='\e[35;1m'
cyan='\e[36;1m'
white='\e[37;1m'

# Reset text attributes to normal without clearing screen.
function creset() {
    tput sgr0
}

# Color-echo.
# Argument $1 = message
# Argument $2 = color
function cecho() {
    local default_msg="No message passed."
    message=${1:-$default_msg}  # Defaults to default message.
    color=${2:-$green}          # Defaults to black, if not specified.
    echo -n -e "$color"
    echo "$message"
    creset
    # return
}

cecho
cecho "Example colored message!" $red
echo "Example uncolored message!"
