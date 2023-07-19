#!/bin/bash

PS3='Please, enter your choice and press [ENTER]: '
opts=("Option 1" "Option 2" "Option 3" "Quit")
select opt in "${opts[@]}"
do
    case $opt in
        ${opts[0]})
            echo "Choice: $REPLY = $opt"
            ;;
        ${opts[1]})
            echo "Choice: $REPLY = $opt"
            ;;
        ${opts[2]})
            echo "Choice: $REPLY = $opt"
            ;;
        ${opts[3]})
            break
            ;;
        *) echo "Invalid option: $REPLY";;
    esac
done
