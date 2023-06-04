#!/usr/bin/python3

# Author: Pierre AYOUB
# Institution: EURECOM
# Title: Python Chirp Signal Generation
# Date: 2022

# Completely under construction when left as-it, highly probable that something
# is false. The problem with this implementation is that the chirp is
# incrementing in frequency at each step.

import numpy as np
import matplotlib.pyplot as plt

# Digitization.
Fs = 10000 # Sample rate [samples / s], hence defining the bandwidth of the spectrum.
Ts = 1/Fs  # Sample period [s].
d  = 1     # Sample time [s].

# Chirp.
f  = 200   # Base frequency of the generated chirp [Hz].
B  = 400   # Bandwidth of the chirp from the base frequency [Hz].
#D  = .1    # Duration of the chirp [s].

f0 = f
f1 = f0 + B
T = .1
k = (f1 - f0) / T

if __name__ == "__main__":
    # Signal generation.
    t   = np.arange(0, d, Ts)     # Time vector (during "d" seconds).
    n   = len(t)                  # Number of samples to generate.
    #c   = np.arange(0, B, B*Ts/D) # Chirp frequency's incrementation vector.
    #ft  = (((k) * t) + f0) % f1
    s   = [0] * n                 # Signal vector.
    for i in range(n):
        ft = (((k) * t[i]) + f0) % f1
        #s_w = 2 * np.pi * (f + c[i % len(c)])           # Angular Speed [rad/s].
        s_w = 2 * np.pi * ft
        #s[i] = np.exp(1j * s_w * (pow(t[i],2)))
        s[i] = np.exp(1j * s_w * t[i])

    # Signal visualization.
    fig, axs = plt.subplots(3)
    axs[0].plot(t, s)
    axs[1].psd(s, Fs=Fs, Fc=0)
    axs[2].specgram(s, Fs=Fs, Fc=0)
    plt.show()
