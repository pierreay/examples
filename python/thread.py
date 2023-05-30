#!/usr/bin/python3

import threading
import time

class BackgroundTasks(threading.Thread):
    def run(self, *args, **kwargs):
        while True:
            print("Enter in thread")
            time.sleep(1)
            print("Exit from thread")

if __name__ == "__main__":
    t = BackgroundTasks()
    t.start()
    
    print("Enter in main")
    print("Exit from main")
