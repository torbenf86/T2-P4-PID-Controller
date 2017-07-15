# T2-P4-PID-Controller
Udacity Car ND Term 2 Project 4 - PID Controller


In order to find the a suitable set of hyperparemeters, I first tuned the PID Controller using the Ziegler Nichols Method. 
It is done by first setting the integral and derivative gain to zero and then increasing the proportional gain to a point, where the system begins to oscillate. The integral and derivative gain is then calculated based on this value. The result was (Kp=0.1,Ki=1e-3,Kd=5). This was input for the twiddle algorithm, which lead after some hundred iterations to the following result: (Kp=0.203682,Ki=0.000107897,Kd=4.89904).

