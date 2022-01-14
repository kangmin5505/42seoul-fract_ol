# 42seoul-fract_ol

## Summary
This project is meant to create graphically beautiful fractal.

## Objectives
Now that you took over your first graphical library: the <b>miniLibX</b>,\
it's time for you to light all the pixels of your screen at the same time!\
\
This new project will be the opportunity for you to hone your <b>miniLibX</b> skills, to\
make you discover/use the mathematical notion of <b>complex numbers</b> and to take a peek\
at the concept of <b>optimization</b> in computer graphics.

## General Instructions
- This project will be corrected by humans only. So, feel free to organize and name\
  your files as you wish, but within the constraints listed here.
- You cannot use global variables.
- You must code in <b>C</b>.
- Your project must follow <b>the Norm</b>.
- You have to handel errors carefully. In no way can your program quit unexpectely\
  (Segmentation falut, bus error, double free, etc).
- Your program cannot have memory leaks.
- You must use the <b>miniLibX</b>. Either in the version that is available on the system,\
  or from its sources. If you choose to work with the sources, you will need to apply\
  the same rules for your <b>libft</b> as those written above.
  
## Mandetory part - fractol
![image](https://user-images.githubusercontent.com/74703501/149436693-24fce2e6-9159-470b-ba4b-df7664be6ae8.png)\
\
This project's goal is to create a small fractal exploration program. Start by seeing\
what a fractal is.\
\
The constraints are as follows:
- Your software should offer the Julia set and Mandelbrot set.
- The mouse wheel zooms in and out, almost infinitely (within the limits of the\
  computer). This is the very principle of fractals.
- You must use at least a few colors to show the depth of each fractal. It's even better\
  if you hack away on psychedelic effects.
- A parameter is passed on the command line to define what type of fractal will be\
  viewed. If no parameter is provided, or if the parameter is invalid, the program\
  displays a list of available parameters and exits properly.
- More parameters must be used for fractal parameters or ignored.
- You must be able to create differenet Julia set with the parameters of the program.
\
As for the graphic representation:
- ESC will exit the program.
- The use of images of the minilibX is strongly recommended.

## Bonus part
Here are some interesting ideas for the bonuses.
- One more different fractal (there are more than a hundred different types of fractals\
  referenced online).
- The zoom follows the actual mouse position.
- In addition to the zoom: moving with the arrows.
- Make the color range shift.
