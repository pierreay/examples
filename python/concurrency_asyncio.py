#!/usr/bin/python3

import asyncio

async def count_1():
    print("One")
    # time.sleep() can represent any time-consuming blocking function call.
    # While asyncio.sleep() is used to stand in for a non-blocking call.
    await asyncio.sleep(1)
    print("Two")

async def count_2():
    print("Three")
    await asyncio.sleep(2)
    print("Four")

async def main():
    print("Start of main()")
    await asyncio.gather(count_1(), count_2())
    print("End of main()")

if __name__ == "__main__":
    import time
    s = time.perf_counter()
    print("Start of __main__")
    asyncio.run(main())
    print("End of __main__")
    elapsed = time.perf_counter() - s
    print(f"{__file__} executed in {elapsed:0.2f} seconds.")
