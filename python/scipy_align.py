#!/usr/bin/env python3

"""Python script used to align signals."""

import numpy as np
import scipy.signal as signal
from scipy.signal import butter, lfilter

def butter_lowpass(cutoff, fs, order=5):
    nyq = 0.5 * fs
    normal_cutoff = cutoff / nyq
    b, a = butter(order, normal_cutoff, btype="low", analog=False)
    return b, a

def butter_lowpass_filter(data, cutoff, fs, order=5):
    assert(cutoff < fs / 2) # Nyquist
    b, a = butter_lowpass(cutoff, fs, order=order)
    y = lfilter(b, a, data)
    return y

def shift(sig, shift):
    """Shift a signal SIG from the SHIFT offset.

    Shift a signal SIG to left (positive SHIFT) or right (negative
    SHIFT). Empty parts of the signal are completed using np.zeros of same
    dtype as SIG.

    SHIFT can be the output of the signal.correlate() function.

    """
    if shift > 0:
        sig = sig[shift:]
        sig = np.append(sig, np.zeros(shift, dtype=sig.dtype))
    elif shift < 0:
        sig = sig[:shift]
        sig = np.insert(sig, 0, np.zeros(-shift, dtype=sig.dtype))
    return sig

def align(template, target, sr):
    """Align a signal against a template.

    Return the TARGET signal aligned (1D np.array) using cross-correlation
    along the TEMPLATE signal, where SR is the sampling rates of signals. The
    shift is filled with zeros shuch that shape is not modified.

    NOTE: The cross-correlation shift is computed based on amplitude
    (np.float64) of signals.

    """
    # +++===+++++++++
    # +++++++===+++++ -> shift > 0 -> shift left target -> shrink template from right or pad target to right
    # ===++++++++++++ -> shift < 0 -> shift right target -> shrink template from left or pad target to left
    assert template.shape == target.shape, "Traces to align should have the same length!"
    assert template.ndim == 1 and target.ndim == 1, "Traces to align should be 1D-ndarray!"
    # Compute the cross-correlation and find shift across amplitude.
    lpf_freq     = sr / 4
    template_lpf = butter_lowpass_filter(np.abs(template), lpf_freq, sr)
    target_lpf   = butter_lowpass_filter(np.abs(target), lpf_freq, sr)
    corr         = signal.correlate(target_lpf, template_lpf)
    shift        = np.argmax(corr) - (len(template) - 1)
    # Apply shift on the raw target signal.
    return analyze.shift(target, shift)

def align_nb(s, nb, sr, template):
    s_aligned = [0] * nb
    for idx in list(range(0, nb)):
        s_aligned[idx] = align(template, s[idx], sr)
    s_aligned = np.array(s_aligned, dtype=s.dtype)
    return s_aligned

def align_all(s, sr, template=None):
    """Align the signals contained in the S 2D np.array of sampling rate
    SR. Use TEMPLATE signal (1D np.array) as template/reference signal if
    specified, otherwise use the first signal of the S array.

    """
    return align_nb(s, len(s), sr, template if template is not None else s[0])

if __name__ == "__main__":
    print("TODO: Module test must be implemented!")
