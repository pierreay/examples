#!/usr/bin/python3

from concurrent.futures import ProcessPoolExecutor
import time

def f(x):
    print("Enter in synchronous subprocess")
    time.sleep(1)
    print("Exit from synchronous subprocess")
    return x*x

if __name__ == "__main__":
    print("Enter in main")
    with ProcessPoolExecutor(max_workers=1) as executor:
        print("Launch one process asynchronously")
        future = executor.submit(f, 3)
        print("Result one process asynchronously")
        print(future.result())
    print("Exit from main")
