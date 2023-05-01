#!/bin/bash

help() {
    cat << EOF
Usage: help.sh ARG
EOF
}

if [[ $# == 0 ]]; then
    help
    exit 0
fi

echo $1
