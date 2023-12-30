#!/usr/bin/env python3

# NOTE: Allows to call scripts directly from project root.
if __name__ == "__main__":
    import sys
    sys.path.append(".")

# Import a package module.
from setuptools_toml import lib

# Main function of our package.
def main():
    print("Call lib.hello_world() from 'main.py'...")
    lib.hello_world()

# Script entrypoint.
if __name__ == "__main__":
    main()
