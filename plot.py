import matplotlib.pyplot as plt
import math

def plot():
	x = [10, 20, 25, 40, 50, 75, 100, 200, 250, 400, 500, 750, 1000]
	y = [0.651519, 0.40076, 0.347946, 0.260492, 0.18676, 0.13646, 0.11114, 0.0571594, 0.0567517, 0.0317366, 0.0260112, 0.0169984, 0.0140981]

	x2 = [10, 20, 25, 40, 50, 75, 100, 200, 250, 400, 500, 750, 1000]
	y2 = [0.745652, 0.573714, 0.517564, 0.436024, 0.40975, 0.35371, 0.337998, 0.20531, 0.189087, 0.139335, 0.118071, 0.102092, 0.0970225]

	x3 = [10, 20, 25, 40, 50, 75, 100, 200, 250, 400, 500, 750, 1000]
	y3 = [0.979197, 0.793558, 0.712112, 0.626676, 0.596674, 0.489322, 0.447741, 0.354042, 0.3198, 0.309258, 0.267824, 0.223133, 0.212155]

	x4 = [10, 20, 25, 40, 50, 75, 100, 200, 250, 400, 500, 750, 1000]
	y4 = [0.969117, 0.823985, 0.746553, 0.746553, 0.625537, 0.575671, 0.580593, 0.459054, 0.459054, 0.438691, 0.387574, 0.341622, 0.334807]

	plt.plot(x, y)
	#plt.plot(x2, y2)
	#plt.plot(x3, y3)
	#plt.plot(x4, y4)
	plt.xlabel('n')
	plt.ylabel('k(n)')
	plt.show()

plot()