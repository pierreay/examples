#!/usr/bin/env python3

import sys
import math

def print_number(x, label="x"):
    print("{}_base2_size={} bits".format(label, len("{:b}".format(x))))
    print("{}_base2=0b{:b}".format(label, x))
    print("{}_base10={}".format(label, x))
    print("{}_base16=0x{:x}".format(label, x))

maxword = sys.maxsize * 2 + 1
print("Maximum value representable by an interpreter's unsigned word:")
print(maxword)
print("Number of bits of the latter:")
print(int(math.log2(maxword)))
# Another method to compute number of bits:
assert(len("{:b}".format(maxword)) == math.log2(maxword))

print("int type is unbouded, example with a 128-bits number:")
int128 = (0b1111 << 124) | 0xdeadbeefdeadbeef
print_number(int128, "int128")
