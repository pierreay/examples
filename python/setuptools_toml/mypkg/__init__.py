#!/usr/bin/env python3

"""My package initialization file."""

# NOTE: Allows to call scripts directly from project root.
if __name__ == "__main__":
    import sys
    sys.path.append(".")

# Import a package module.
from mypkg import mylib

# Initialize the package.
print("Call mylib.hello_world() from '__init__.py'...")
mylib.hello_world()
