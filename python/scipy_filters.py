#!/usr/bin/env python3

import random
import numpy as np
from matplotlib import pyplot as plt
from scipy import signal
from scipy.signal import butter, lfilter

# * Statistics

def normalize(arr):
    """Apply min-max feature scaling normalization to a 1D array."""
    return (arr - np.min(arr)) / (np.max(arr) - np.min(arr))

# * Filters

def butter_bandstop(lowcut, highcut, fs, order=5):
    nyq = 0.5 * fs
    low = lowcut / nyq
    high = highcut / nyq
    b, a = butter(order, [low, high], btype="bandstop")
    return b, a

def butter_bandstop_filter(data, lowcut, highcut, fs, order=5):
    b, a = butter_bandstop(lowcut, highcut, fs, order=order)
    y = lfilter(b, a, data)
    return y

def butter_bandpass(lowcut, highcut, fs, order=5):
    nyq = 0.5 * fs
    low = lowcut / nyq
    high = highcut / nyq
    b, a = butter(order, [low, high], btype="band")
    return b, a

def butter_bandpass_filter(data, lowcut, highcut, fs, order=5):
    b, a = butter_bandpass(lowcut, highcut, fs, order=order)
    y = lfilter(b, a, data)
    return y

def butter_lowpass(cutoff, fs, order=5):
    nyq = 0.5 * fs
    normal_cutoff = cutoff / nyq
    b, a = butter(order, normal_cutoff, btype="low", analog=False)
    return b, a

def butter_lowpass_filter(data, cutoff, fs, order=5):
    b, a = butter_lowpass(cutoff, fs, order=order)
    y = lfilter(b, a, data)
    return y

def butter_highpass(cutoff, fs, order=5):
    nyq = 0.5 * fs
    normal_cutoff = cutoff / nyq
    b, a = butter(order, normal_cutoff, btype="high", analog=False)
    return b, a

def butter_highpass_filter(data, cutoff, fs, order=5):
    b, a = butter_highpass(cutoff, fs, order=order)
    y = lfilter(b, a, data)
    return y

# * Plotting

def plot_time_freq(s):
    plt.plot(t, s, 'k-')
    plt.xlabel('Time')
    plt.ylabel('Amplitude')
    plt.axis([None, None, -1, 1])

# * Example

if __name__ == "__main__":
    # Define signals parameters.
    d  = 1                   # Duration [s]
    Fs = 1000                # Sampling rate [Hz]
    Ts = 1.0/Fs              # Sampling interval [s]
    t  = np.arange(0, d, Ts) # Time vector [0.000 .. 0.999]
    f_min = 1                # Minimum frequency [Hz]
    f_max = 1000             # Maximum frequency [Hz]
    s_nb  = 4                # Numbers of signal.
    s     = [0] * s_nb       # List of signal vectors.
    # General individual signals.
    for i in list(range(s_nb)):
        f = random.randint(f_min, f_max)
        print("f_{}={}".format(i, f))
        s[i] = np.sin(2 * np.pi * f * t)
    # Generate a composed signal with Numpy to operate on it.
    s_mix = np.multiply.reduce(s)

    plot_time_freq(s_mix)
    plt.show()
