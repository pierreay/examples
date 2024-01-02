#!/usr/bin/env python3

"""My module."""

# NOTE: Allows to call scripts directly from project root.
if __name__ == "__main__":
    import sys
    sys.path.append(".")

# Import a package module.
from mypkg import mylib

# Main function of our package.
# NOTE: The "main" name is only a convention here.
def main():
    print("Call mylib.hello_world() from 'mymod.py'...")
    mylib.hello_world()

# Interpreter entrypoint.
if __name__ == "__main__":
    main()
