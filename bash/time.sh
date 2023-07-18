#!/bin/bash

echo "= time ="
time sleep 1

echo
echo "= SECONDS ="
# SECONDS is a Bash builtin variable that tracks the number of seconds that have passed since the shell was started.
SECONDS=0
sleep 1
duration=$SECONDS
echo "$(($duration / 60)) minutes ; $(($duration % 60)) seconds"

