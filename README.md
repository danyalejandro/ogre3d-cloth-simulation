# An Ogre3D simulation of cloth

[![Simulation Youtube video](https://img.youtube.com/vi/sLcg_QD9dTk/0.jpg)](https://www.youtube.com/watch?v=sLcg_QD9dTk)

*(click image for youtube video)*

A 3D simulation of a cloth using physically based methods (arrangements of 3D springs). Built using C++ and Ogre3D. You can move around using the arrow keys / AWSD and rotate the camera using the mouse.

This cloth simulation was made by connecting a grid of linear springs (a basic application of Hooke's law).

Each point was connected with a spring to its contiguous 8 points and additionally to the 4 points located 2 positions away vertically and horizontally (structural springs). Each white line represents a spring; the red dots are points with a mass and their own force, acceleration and velocity vectors.

Each red point receives forces from all connected springs, a constant gravity, and a simple wind implemented by applying a -x\*x (cuadratic function) to make the wind vector stronger near the middle of the cloth, and multiplied by sin(0.0001 \* frame_number) to make it periodic and soft (negative wind forces are ignored to let the cloth rest).

All physical variables are updated 10 times per frame in small steps. The top row was made to be fixed to give the illusion of a window curtain.

## Building and running

The project was created using Ogre 1.10.9 (cloned from github and built using CMake-GUI) and the CLion IDE on Ubuntu Linux (I was unable to build the same OGRE3D project on mac, despite great efforts). CLion makes it easier to edit the CMakeLists.txt configuration file commonly used in OGRE3D projects. I based my code on the basic examples included in the OGRE3D source code (Samples/Tutorials and Samples/Bootstrap) since the official tutorials are currently outdated. Lines are drawn by creating and updating an Ogre ManualObject.

If you want to build and run this project, make sure you're able to build and run a simple Ogre3D project (I recommend linux & CLion IDE for this purpose) first. This might involve building Ogre3D in your system from scratch as there are a few outdated compiled versions you can download but they might not work out of the box.

If you're able to run Ogre3D projects in your system, open the folder as a new project in CLion and review the contents of CMakeLists.txt so it matches your own system configuration (there's a couple paths you need to change there). That's usually enough to run the simulation.
