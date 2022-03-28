import kitsune as kit
import numpy as np
import matplotlib.pyplot as plt

params = [0,3*np.pi,100]
x,y = kit.sinusoid(params)
plt.plot(x,y)
plt.show()
