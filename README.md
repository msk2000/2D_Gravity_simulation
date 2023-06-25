# 2D Gravity Simulation

<div align="center">
  <img src="https://github.com/msk2000/2D_Gravity_simulation/assets/129243151/084f31f1-2563-4fad-a124-1c1cacabfbaa" width="400" height="300">
</div>


This is a simple 2-body simulation of bodies in space and how their gravitation impacts the trajectories of one another. 

## Some of the numerical details
Change in distance calcualted from: 

$$dx = x_2 - x_1 \\ dy = y_2 - y_1$$

Distance between the two bodies calculated from:

$$r = \sqrt{(dx)^2 + (dy)^2}$$

Force between the two bodies calculated from:

$$F = \frac{GM_1M_2}{r^2}$$

Horizontal and Vertical components of Force calculated from:

$$F^{(x)} = F \cos(\theta)$$

$$F^{(y)} = F \sin(\theta)$$

Angle(theta) between the two bodies calcualted from:

$$\theta = \arctan\left(\frac{dx}{dy}\right)$$

Horizontal and Vertical Components of acceleration calculated from:

$$a^{(x)} = \frac{F^{(x)}}{M}$$

$$a^{(y)} = \frac{F^{(y)}}{M}$$

Initial and final velocities calculated from:

$$v^{(x)} = u^{(x)} + a^{(x)}dt$$

Change in position calculated from:

$$v^{(x)}dt - \frac{1}{2}a^{(x)} dt^2$$


## Dependencies

Make sure you follow the instructions at [matplotlibcpp](https://github.com/lava/matplotlib-cpp) to setup the matplotlib extension for C++. This is what is being used to produce the visual output.
