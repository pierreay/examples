#!/usr/bin/env python3

import pickle

class MyClass():
    name = None
    subclass = None

    def __init__(self, name):
        self.name = name

    def __str__(self):
        string = "name={}".format(self.name)
        if self.subclass is not None:
            string = "{}\nsubclass:\n{}".format(string, str(self.subclass))
        return string

    def add_subclass(self, subclass):
        assert(type(subclass) == MySubclass)
        self.subclass = subclass

class MySubclass():
    name = None

    def __init__(self, name):
        self.name = name

    def __str__(self):
        return "name={}".format(self.name)

myclass = MyClass("myclass")
mysubclass = MySubclass("mysubclass")
myclass.add_subclass(mysubclass)

print(myclass)
print("")

with open("/tmp/myclass.pyc", "wb") as f:
    pickle.dump(myclass, f)
with open("/tmp/myclass.pyc", "rb") as f:
    myclass_pickled = pickle.load(f)

print(myclass_pickled)
