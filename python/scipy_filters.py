#!/usr/bin/env python3

import random
import numpy as np
from matplotlib import pyplot as plt
from scipy import signal
from scipy.signal import butter, lfilter

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

# * Example

if __name__ == "__main__":
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

    # Bandstop filter.
    s_mix_bandstop = butter_bandstop_filter(s_mix, 2e2, 4e2, Fs)
    # Bandpass filter.
    s_mix_bandpass = butter_bandpass_filter(s_mix, 2e2, 4e2, Fs)
    # Lowpass filter.
    s_mix_lowpass = butter_lowpass_filter(s_mix, 2.5e2, Fs)
    # Highpass filter.
    s_mix_highpass = butter_highpass_filter(s_mix, 2.5e2, Fs)

    # Show results.
    plot_time_freq_show(s_mix, Fs)
    plot_time_freq_show(s_mix_bandstop, Fs, "bandstop{2e2, 4e2}")
    plot_time_freq_show(s_mix_bandpass, Fs, "bandpass{2e2, 4e2}")
    plot_time_freq_show(s_mix_lowpass, Fs, "lowpass{2.5e2}")
    plot_time_freq_show(s_mix_highpass, Fs, "highpass{2.5e2}")
