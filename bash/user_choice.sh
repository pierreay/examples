#!/bin/bash

# * "read" Y/N

# Only works for Bash, not ZSH.
while true; do
    read -p "Do you wish to install this program? [y/n] " yn
    case $yn in
        [Yy]* ) echo "Installation"; break;;
        [Nn]* ) echo "Does not install"; break;;
        * ) echo "Please, answer yes or no.";;
    esac
done

# * "select" Menu

PS3='Please, enter your choice and press [ENTER] (Press [ENTER] to get help): '
# Set maximum column number where is it allow to start an option display. Set
# it to 1 to force 1 option per line.
COLUMN=80
opts=("Option 1" "Option 2" "Option 3" "Quit")
select opt in "${opts[@]}"
do
    # NOTE: You can use $REPLY value instead of $opt value for "case" statement.
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

# $1 is the question message.
# Return 1 if YES, 0 if NO.
# NOTE: Works for Bash and ZSH.
function yes-no() {
    echo "$1"
    select yn in "Yes" "No"; do
        case $yn in
            Yes ) return 1; break;;
            No )  return 0; break;;
        esac
    done
}

yes-no "Do you wish to install this program?"
if [[ $? == 1 ]]; then
    echo "Installation..."
else
    echo "Does not install!"
fi
