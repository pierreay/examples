#!/usr/bin/env python3

"""Snippet taken from:
 - https://stackoverflow.com/questions/12217537/can-i-force-debugging-python-on-assertionerror
But we use ipdb instead of pdb."""

import sys

def info(type, value, tb):
    if hasattr(sys, 'ps1') or not sys.stderr.isatty() or type != AssertionError:
        # We are in interactive mode or we don't have a tty-like
        # device, so we call the default hook.
        sys.__excepthook__(type, value, tb)
    else:
        import traceback, ipdb
        # We are not in interactive mode, print the exception.
        traceback.print_exception(type, value, tb)
        print
        # Then start the debugger in post-mortem mode.
        ipdb.pm()

sys.excepthook = info

if __name__ == "__main__":
    print("Let's thrown an AssertionError for demonstration:")
    assert(1 == 2)
