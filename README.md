# Fractal_MGSet
This project is one of 42Network graphic projects.
We are going to use the school graphical library: the MiniLibX! This library was developed internally and includes basic necessary tools to open a window, create images and deal with keyboard and mouse events.
This will be the opportunity for you to discover or use the mathematical notion of complex numbers and to take a peek at the concept of optimization in computer graphics and practice event handling.

The term fractal was first used by mathematician Benoit Mandelbrot in 1974. He based it on the Latin word fractus which means "broken" or "fractured".
A fractal is an abstract mathematical object, like a curve or a surface, which pattern remains the same at every scale.
Various natural phenomena – like the romanesco cabbage – have some fractal features.

## Common Instructions
* The project must be written in C.
*  functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors.
*  All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated.
*  A Makefile is required which will compile your source files to the required output with the flags -Wall, -Wextra and -Werror, use cc, and your Makefile must not relink.
*  

## Rendering
* The program must offer the Julia set and the Mandelbrot set.
* The mouse wheel zooms in and out, almost infinitely (within the limits of the computer). This is the very principle of fractals.
* You must be able to create different Julia sets by passing different parameters to the program.
* A parameter is passed on the command line to define what type of fractal will be displayed in a window.
* You can handle more parameters to use them as rendering options.
* If no parameter is provided, or if the parameter is invalid, the program displays a list of available parameters and exits properly.
* You must use at least a few colors to show the depth of each fractal. It’s even better if you hack away on psychedelic effects.

## Graphic management
* The program has to display the image in a window.
* The management of your window must remain smooth (changing to another window, minimizing, and so forth).
* Pressing ESC must close the window and quit the program in a clean way.
* Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.
* The use of the images of the MiniLibX is mandatory.

## Bonus part
You will get some extra points with the following features:
* One more different fractal (more than a hundred different types of fractals are referenced online).
* The zoom follows the actual mouse position.
* In addition to the zoom: moving the view by pressing the arrows keys.
* Make the color range shift.
