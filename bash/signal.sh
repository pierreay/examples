#!/bin/bash

function please_wait() {
    echo "Please, wait!"
}

trap please_wait INT

for ((n=10; n; n--))
do
    sleep 1
done
