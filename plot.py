import matplotlib.pyplot as plt
import math

def plot():
	x = [10, 20, 25, 40, 50, 75, 100, 200, 250, 400, 500, 750, 1000]
	y = [0.745652, 0.573714, 0.517564, 0.436024, 0.40975, 0.35371, 0.337998, 0.20531, 0.189087, 0.139335, 0.118071, 0.102092, 0.0970225]

	plt.plot(x, y)
	plt.xlabel('n')
	plt.ylabel('k(n)')
	plt.show()

plot()