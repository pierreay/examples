# * About

# In some project, we may need to start a long process directly after boot. One
# of the challenge is to be able to monitor the long process from a remote
# machine and load the project environment. All of this can be achieved using
# tmux and direnv.

# This script is meant to be executed by crontab after a reboot, spawning the
# long process in a tmux session attachable by a (remote) user.

# * Usage

# Run:
# $ crontab -e
# Put inside:
# @reboot cd /path/to/project && ./src/cron_tmux.sh > /tmp/crontab.log 2>&1

# * Script

# Sleep to:
# 1. Prevent boot loop in case of programmer's error.
# 2. Wait for the full initialization of the system.
sleep 60

# Start tmux server.
# NOTE: Specifying shell is important, otherwise, it will use "sh" as default
# shell for new windows and panes.
SHELL=/bin/zsh tmux start-server

# Source the project environment and start the long process inside a tmux
# session.
# NOTE: -d is important to not trying to attach to current terminal, as cron
# doesn't provide terminal.
tmux new-session -d -s collect "cd /path/to/project/src && direnv exec . ./long_process.sh"
