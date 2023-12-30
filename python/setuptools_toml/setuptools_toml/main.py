#!/usr/bin/env python3

# Import local modules from current directory if ran from source.
try:
    import lib
# Import local modules from system directory if run from installation.
except ModuleNotFoundError as e:
    from setuptools_toml import lib

# Main function of our package.
def main():
    print("Call lib.hello_world() from 'main.py'...")
    lib.hello_world()

# Bash entrypoint.
if __name__ == "__main__":
    main()
