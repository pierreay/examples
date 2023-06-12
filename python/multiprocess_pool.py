#!/usr/bin/python3

from multiprocessing import Pool
import time

def f(x):
    print("Enter in subprocess")
    time.sleep(1)
    print("Exit from subprocess")
    return x*x

if __name__ == "__main__":
    print("Enter in main")
    with Pool() as p:
        print(p.map(f, [1, 2, 3]))
    print("Exit from main")
