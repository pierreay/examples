#!/bin/bash

help() {
    cat << EOF
Usage: netcat_shell.sh [client | server]

Demonstrate a shell using netcat. Can be executed in server mode or in client
mode.

EOF
}

if [[ $# == 0 ]]; then
    help
    exit 0
fi

if [[ $1 == "server" ]]; then
    rm -f /tmp/f; mkfifo /tmp/f
    cat /tmp/f | /bin/sh -i 2>&1 | nc -l 127.0.0.1 1234 > /tmp/f
elif [[ $1 == "client" ]]; then
    nc 127.0.0.1 1234
fi
