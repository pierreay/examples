#!/usr/bin/env python3

# NOTE: Allows to call scripts directly from project root.
if __name__ == "__main__":
    import sys
    sys.path.append(".")

# Import a package module.
from mypkg import lib

# Initialize the package.
print("Call lib.hello_world() from '__init__.py'...")
lib.hello_world()
