#!/bin/bash

# * "read" Y/N

while true; do
    read -p "Do you wish to install this program? [y/n] " yn
    case $yn in
        [Yy]* ) echo "Installation"; break;;
        [Nn]* ) echo "Does not install"; break;;
        * ) echo "Please, answer yes or no.";;
    esac
done

# * "select" Menu

PS3='Please, enter your choice and press [ENTER]: '
opts=("Option 1" "Option 2" "Option 3" "Quit")
select opt in "${opts[@]}"
do
    # You can use $REPLY value instead of $opt value for "case" statement.
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

# * "select" Y/N

echo "Do you wish to install this program?"
select yn in "Yes" "No"; do
    case $yn in
        Yes ) echo "Installation"; break;;
        No ) echo "Does not install"; break;;
    esac
done
