#!/usr/bin/python3

# Author: Pierre AYOUB
# Institution: EURECOM
# Title: Signal Generation and Modulation (AM-FM)
# Date: 2021

import numpy as np
import matplotlib.pyplot as plt

# Signal generation.

d  = 1                   # Duration [s]
Fs = 1000                # Sampling Rate [Hz]
Ts = 1.0/Fs              # Sampling Interval [s]
t  = np.arange(0, d, Ts) # Time Vector [0.000 .. 0.999]
ns = len(t)              # Number of samples

# Data Signal.
s1_a = 1                       # Amplitude [Arbitrary]
s1_f = 3                       # Frequency [Hz]
s1_w = 2 * np.pi * s1_f        # Angular Speed [rad/s]
s1   = s1_a * np.sin(s1_w * t) # Signal

# Carrier Signal.
s2_a = 2                       # Amplitude [Arbitrary]
s2_f = 40                      # Frequency [Hz]
s2_w = 2 * np.pi * s2_f        # Angular Speed [rad/s] 
s2   = s2_a * np.sin(s2_w * t) # Signal

# Simple Derived Signals.
s3 = s1 + s2 # Data + Carrier
s4 = s1 * s2 # Data * Carrier

# Amplitude Modulation [AM]
s5 = (s2_a + s1) * np.sin(s2_w * t) # Signal

# Frequency Modulation [FM]
s6_k = 0.15     # Deviation Coefficient
s6   = [0] * ns # Signal
# Need a 'for loop' to use the sum as an integral for discrete series.
for i in range(0, ns):
    s6[i] = s2_a * np.sin(s2_w * t[i] + s6_k * sum(s1[0:i])) 

# Plot a signal.
def plot_signal(signal, title, plot_number):
    plt.subplot(row, col, plot_number)
    plt.plot(t, signal, 'k-')
    plt.title(title)
    plt.xlabel('Time')
    plt.ylabel('Amplitude')
    plt.axis([None, None, -3.2, 3.2])

# Plot all the signals and display the result.
row = 3                               # Number of row
col = 2                               # Number of columns
plot_signal(s1, "Data", 1)
plot_signal(s2, "Carrier", 2)
plot_signal(s3, "Data + Carrier", 3)
plot_signal(s4, "Data * Carrier", 4)
plot_signal(s5, "AM", 5)
plot_signal(s6, "FM", 6)
plt.show()
