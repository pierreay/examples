#!/usr/bin/env python3

# The file was originally called "http.py", but it throws the following error:
# "AttributeError: partially initialized module"

import requests

resp = requests.get('http://whatu.info')

print("Returned body: {}".format(resp.text))
print("Returned code: {}".format(resp))
