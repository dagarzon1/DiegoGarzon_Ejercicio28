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
    d = d - int_analitica
    d = d / int_analitica
    d = d * 100
    dat.append(d[0])
n = np.logspace(2,9,4)

lt.hist(np.log(n),dat)
plt.savefig("integra.pdf")
