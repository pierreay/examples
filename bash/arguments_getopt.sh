#!/bin/bash

# Test:
# ./arguments_getopt.sh -vf /etc/hosts foo bar

# POSIX's variable of the index of next element in the argv array.
# Reset in case getopts has been used previously in the shell.
OPTIND=1

# Program's options (switches).
verbose=0
# Program's option-arguments (variables).
output_file=""
# Program's arguments.
args=""

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

# Iterate over all supplied options and option-arguments.
# "f:" means that -f is an option-argument.
# "?" means that -? is an alias for -h.
while getopts "h?vf:" opt; do
  case "$opt" in
    h|\?)
      help
      ;;
    v) verbose=1
      ;;
    f) output_file=$OPTARG
      ;;
  esac
done

# Get rid of all arguments processed by getopts.
shift $((OPTIND-1))
# Skip the "--" keyword indicating that the following is a custom input.
[ "${1:-}" = "--" ] && shift
# Get the ARGS.
args="$@"

# Use the options and option-arguments in some way.
echo "verbose=$verbose, output_file='$output_file', Leftovers: $args"
