#!/bin/bash

# * cat

cat << EOF > /tmp/outfile
Text to display (or redirect inside outfile if specified) from script
EOF

# * python

python3 << EOF
import numpy as np
print(np.pi)
EOF
