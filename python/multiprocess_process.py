#!/usr/bin/python3

from multiprocessing import Process, Queue
import os
import time

def f(q, x):
    print("Enter in subprocess of PID {} with q={} and x={}".format(os.getpid(), q, x))
    time.sleep(x)
    q.put(x * x)
    print("Exit in subprocess of PID {}".format(os.getpid()))

if __name__ == "__main__":
    import time
    s = time.perf_counter()
    print("Enter in main of PID {}".format(os.getpid()))

    q = Queue()
    ps = []
    ps.append(Process(target=f, args=(q, 5,)))
    ps.append(Process(target=f, args=(q, 10,)))
    ps[0].start()
    ps[1].start()
    # Block until having a result in the queue.
    print(q.get())
    print(q.get())
    ps[0].join()
    ps[1].join()
    
    print("Exit from main")
    elapsed = time.perf_counter() - s
    print(f"{__file__} executed in {elapsed:0.2f} seconds.")
