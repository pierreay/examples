#!/usr/bin/env python3

import random
import numpy as np
import scipy.signal as signal
from matplotlib import pyplot as plt

# * DSP

def normalize(arr):
    """Apply min-max feature scaling normalization to a 1D array."""
    return (arr - np.min(arr)) / (np.max(arr) - np.min(arr))

def find_peaks(arr, Fs):
    peaks = signal.find_peaks(arr, distance=Fs/40, prominence=1/4)
    return peaks[0]

# * Plotting

def plot_time(s):
    subplot_1 = plt.subplot(2, 1, 1)
    subplot_1.plot(t, s, 'k-')
    plt.xlabel('Time [s]')
    plt.ylabel('Amplitude')

def plot_freq(s, Fs):
    subplot_2 = plt.subplot(2, 1, 2)
    subplot_2.specgram(s, NFFT=256, Fs=Fs)
    plt.xlabel("Time [s]")
    plt.ylabel("Frequency [Hz]")

def plot_time_freq(s, Fs, title):
    plot_time(s)
    plt.title(title)
    plot_freq(s, Fs)

def plot_time_freq_show(s, Fs, title = ""):
    plot_time_freq(s, Fs, title)
    plt.show()

def plot_time_freq_peaks_show(s, Fs, peaks, title = ""):
    plot_time(s)
    plot_peaks(peaks, Fs)
    plt.title(title)
    plot_freq(s, Fs)
    plt.show()

def plot_peaks(peaks, Fs):
    i = 0
    for idx in peaks:
        i = i + 1
        plt.axvline(x = idx / Fs, color = "b", label = 'peak={}'.format(i), ls = "--", lw = 0.75)

# * Example

if __name__ == "__main__":
    # * Signal initialization.
    # Define signals parameters.
    d  = 1                   # Duration [s]
    Fs = 1000                # Sampling rate [Hz]
    Ts = 1.0/Fs              # Sampling interval [s]
    t  = np.arange(0, d, Ts) # Time vector [0.000 .. 0.999]
    f_min = 1                # Minimum frequency [Hz]
    f_max = Fs/2             # Maximum frequency [Hz]
    s_nb  = 4                # Numbers of signal.
    s     = [0] * s_nb       # List of signal vectors.
    # General individual signals.
    for i in list(range(s_nb)):
        f = random.randint(f_min, f_max)
        print("f_{}={}".format(i, f))
        s[i] = np.sin(2 * np.pi * f * t)
    # Generate a composed signal with Numpy to operate on it.
    s_mix = np.add.reduce(s)
    # Show initial signal.
    plot_time_freq_show(s_mix, Fs)

    # * Demonstrate DSP.
    # Normalization.
    s_mix = normalize(s_mix)
    plot_time_freq_show(s_mix, Fs)
    # Peak finding.
    peaks = find_peaks(s_mix, Fs)
    plot_time_freq_peaks_show(s_mix, Fs, peaks)
