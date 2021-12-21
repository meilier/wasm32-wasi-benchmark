import numpy as np
import matplotlib.pyplot as plt
import math
from brokenaxes import brokenaxes


class MainProgram(object):
    """
    Main Program used to plot bar chart of different runtime performance of different algorithm
    """
    def __init__(self):
        self.alg = []
        self.runtime = []
        self.data = []
        self.width = 0.35
        self.ax = brokenaxes(ylims=((0, 12), (460, 461)),
                             hspace=.2,
                             despine=False)

    def process_raw_data(self):
        with open('result.csv') as f:
            lines = f.readlines()
            self.runtime = lines[0].strip().split(',')
            for line in lines[1:]:
                raw = line.strip().split(',')
                self.alg.append(raw[0])
                self.data.append(raw[1:])

        for i, algo in enumerate(self.data):
            for j, seconds in enumerate(algo):
                left_bracket_index = seconds.index("(")
                self.data[i][j] = seconds[:left_bracket_index]

    def normalize_data(self):
        self.data = np.transpose(self.data).tolist()
        base = self.data[0]
        for i in range(1, len(self.runtime)):
            for j in range(len(self.alg)):
                self.data[i][j] = float(self.data[i][j]) / float(base[j])
        for i in range(len(self.alg)):
            self.data[0][i] = 1

    def plot(self):
        x = np.arange(1, len(self.alg) + 1)  # the label locations
        for i in range(len(self.runtime)):
            rects = self.ax.bar(x - self.width +
                                2 * i * self.width / len(self.runtime),
                                self.data[i],
                                2 * self.width / len(self.runtime),
                                label=self.runtime[i])

        self.ax.set_title("runtime performance compare of different algorithm",
                          fontsize=8)
        self.ax.set_xticklabels([''] + self.alg, fontsize=3)

        self.ax.legend(fontsize=5, loc=(0.7, 0.6))
        plt.savefig("compare", dpi=500, bbox_inches='tight')

m = MainProgram()
m.process_raw_data()
m.normalize_data()
m.plot()