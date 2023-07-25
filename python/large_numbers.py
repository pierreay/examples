#!/usr/bin/env python3

import sys
import math

maxword = sys.maxsize * 2 + 1
print("Maximum value representable by an interpreter's unsigned word:")
print(maxword)
print("Number of bits of the latter:")
print(int(math.log2(maxword)))
# Another method to compute number of bits:
assert(len("{:b}".format(maxword)) == math.log2(maxword))

print("int type is unbouded, example with a 128-bits number:")
int128 = (0b1111 << 124) | 0xdeadbeefdeadbeef
print("int128_base2_len={}".format(len("{:b}".format(int128))))
print("int128_base2=0b{:b}".format(int128))
print("int128_base10={}".format(int128))
print("int128_base16=0x{:x}".format(int128))
