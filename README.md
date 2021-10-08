# Computer_Graphics_Homework_1
First homework in my Computer Graphics class Fall 2021. We made drawings with color interpolation, masks, menus, and drew a village of houses. We created the programs with C++ and utilized OpenGL and GLUT

## Problem 1 Part 1
Design a drawing including two geometric figures with solid colors, 2 figures with color interpolation (more than one color), and 3 filled with given masks

For the masks, we utilized the campfire, fly, and brick masks

![Problem1_1](/Images/Hw1Problem1.PNG)

## Problem 1 Part 2 
Creative drawing, include two geometric figures different than triangles and rectangles filled with your own masks or menu which implements different options

We decided to creat a menu in which the image will be redrawn to either have a blue or black sky with a yellow sun or white moon. Right click on the screen and th emenu will appear. We utilized color interpolation with the background, sidewalk, and the ground

![Problem1_2](/Images/Hw1Problem1Creative_1.PNG)

Day time


![Problem1_2](/Images/Hw1Problem1Creative_2.PNG)

Night time

## Problem 2 Part 1
Draw a village of houses utilizing at least the following GL primities (triangles, triangle fans, line strip, masks). Incorporate stippling and masks as a way to model the façade of the houses and/or chimneys, windows, etc. Use colors (background, foreground, filling) and utilize relative drawing (discussed in class: line-to, move-to)

We decided to create a simple village of houses with two windows, a door, and a triangle roof. We altered the colors on each house. This was very simple compared to the next part

![Problem2_1](/Images/Hw1Problem2.PNG)

## Problem 2 Part 2
Creative drawing, which is defined as utilization of drawing primitives, complexity of the houses and the scenery and etc. 

We utilized line stipple to create the divider in the road, we wanted the road to be drawn out into the distance as a triangle (same with the sidewalk). We also wanted to create buildings in the background which is composed of multiple polygons. FInally, we drew a sun, trees, and bushes as circles utlizing a function to draw the shape with 360 points. The grey building on the right was drawn as a triangle fan, first drawing a grey square and then changing the color to white for the background. This was an attempt to make a 2D drawing look 3D

![Problem2_2](/Images/Hw1Problem2Creative.PNG)
