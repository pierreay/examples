#!/bin/bash

function check() {
    ret=$? 
    if [[ $ret == 124 ]]; then
        echo "Command timeout!"
    elif [[ $ret == 0 ]]; then
        echo "Command returned 0!"
    fi
}

timeout 1 sleep 2
check
timeout 3 sleep 2
check
