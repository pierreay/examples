#!/usr/bin/env python3

import csv

if __name__ == "__main__":
    # * CSV Writer.
    numbers = ["1", "2", "3"] # Should be strings and not numbers.
    with open('my.csv', 'w', newline='') as f:
        writer = csv.writer(f)
        writer.writerows(numbers)

    # It will write:
    # $ cat my.csv
    # 1
    # 2
    # 3

    # * CSV Reader.
    with open('my.csv', newline='') as f:
        reader = csv.reader(f)
        for row in reader:
            print(row)

    # It will print:
    # ['1']
    # ['2']
    # ['3']
