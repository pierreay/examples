#!/bin/bash

# Test:
# ./arguments_getopt.sh -vf /etc/hosts foo bar

# POSIX's variable of the index of next element in the argv array.
# Reset in case getopts has been used previously in the shell.
OPTIND=1

# Program's variables.
output_file=""
verbose=0

# Program's help.
function help() {
    cat << EOF
Usage: arguments_getopt.sh [-v] [-f OUTPUT_FILE] [ARGS...]
EOF
    exit 0
}

# If nothing is provided, show help and exit.
if [[ $# -lt 1 ]]; then
    help
fi

while getopts "h?vf:" opt; do
  case "$opt" in
    h|\?)
      help
      ;;
    v)  verbose=1
      ;;
    f)  output_file=$OPTARG
      ;;
  esac
done

shift $((OPTIND-1))

[ "${1:-}" = "--" ] && shift

echo "verbose=$verbose, output_file='$output_file', Leftovers: $@"
