#!/usr/bin/env python3

# Binary numbers demonstrations.

def hw(n):
    """Return the Hamming Weight of the number N."""
    # NOTE: Alternative implementation using str built-in class.
    # return bin(n).count("1")
    return n.bit_count()

def hd(n, m):
    """Return the Hamming Distance between numbers N and M."""
    return hw(n ^ m)

if __name__ == "__main__":
    print(hw(0b10001010))             # 3
    print(hd(0b10001010, 0b10000011)) # 2
