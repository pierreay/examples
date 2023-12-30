#!/usr/bin/env python3

# Import local modules from current directory if ran from source.
try:
    import lib
# Import local modules from system directory if run from installation.
except ModuleNotFoundError as e:
    from setuptools_toml import lib

print("Call lib.hello_world() from '__init__.py'...")
lib.hello_world()
