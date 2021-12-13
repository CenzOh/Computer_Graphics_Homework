# Computer Graphics Project 2 / Final Project

Our final project allows us to demonstrate our udnerstanding of 3D implementation and transformations / animations in computer graphics. The only specific directions the Professor has given us is to develop an OpenGL program to draw a set of more than 3 objects utilizing different colors, transfromations (scaling, translation, rotation), perspective projection, shading, and at least one light source.

We designed a powerpoint to demonstrate everything we have done. Below are some screenshots.

![def_win](/Project2/Images/def_win.PNG)

We created a simple suburban scene with different houses. We wanted the houses to be freely created by defining the x,y,z coordinates which we utilized with more objects. We were able to change the camera angles which will be shown in the next images. 

![house_win](/Project2/Images/house_win.PNG)

This perspective faces the houses which helped us in debugging purposes of creating the hats for snowmen.

![street_win](/Project2/Images/street_win.PNG)

This other perspective faces down the street. We did not want to make the scene flat by making the camera directly face down the street so we placed it at an angle.

![def_spring](/Project2/Images/def_spring.PNG)

At first the scene was designed for a winter season, however, we decided to include a spring season to add to our menu. For lighting, the winter scene has the lighting on the right side of the scene while the spring scene has lighting on the left side.

![house_spring](/Project2/Images/house_spring.PNG)

For background elements, we designed snowmen for the winter, bushes for spring, a pond, a boat for winter, and trees.

![street_spring](/Project2/Images/street_spring.PNG)

To change the background elements, we created a global variable to keep track of what the user selects. If they selected for the scene to be in spring, this global variable would update and all of the functions would respond accordingly.

![menu](/Project2/Images/menu.PNG)

This is what our menu options look like. We have a menu option to draw and not draw the tree because for some reason, drawing the tree changes the way the lighting looked.
