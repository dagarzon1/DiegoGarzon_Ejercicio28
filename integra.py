import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
import glob
import os

k = sorted(glob.glob("*.txt"))
dat = []

int_analitica = np.exp(1) - 1

for i in k:
    d = np.loadtxt(i)
    d = np.abs(d - int_analitica)
    d = d / int_analitica
    d = d * 100
    dat.append(d)
n = np.logspace(2,8,7)

plt.plot(np.log(n),dat)
plt.savefig("integra.pdf")

