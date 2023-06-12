#!/usr/bin/env python3

if __name__ == "__main__":
    import time
    s = time.perf_counter()

    print("Insert task's code to measure here")
    
    elapsed = time.perf_counter() - s
    print(f"{__file__} executed in {elapsed:0.2f} seconds.")
