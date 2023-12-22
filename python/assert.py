#!/usr/bin/env python3

a = False
b = True
c = True

assert a or b, "False assert!"
assert b and c if a is False else True, "False conditional assert!"
