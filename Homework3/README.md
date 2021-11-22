# Computer Graphics Homework 3
Utilize fractals and L-systems

## Problem 1
Basic Version, create a tree using the provided L-systems code. Randomize the angle of the tree with getrandom() function. Modify the code as to make the tree branches decrease in thickness from the trunk to the outermost branches. That means you must keep a thickness variable that is made smaller with each branch. To keep track, keep in mind the '[' and ']' characters. '[' denotes the start of a new branch while ']' denotes the end.
Add leaves to the code as well with the included drawLeaf() function. Add the case 'L' to draw the leaf at the end of a branch. Modify the F production string to add the leaves as well char Fstr[100] = "FF-[F+F+F+L] ... "

Overall, this was not too difficult to develop, the most challenging aspect was ensuring the tree branches thickness would stay since, for some reason, the code redraws the image twice.

![Problem 1_1](/Homework3/Images/3_1_1_a.PNG)



![Problem 1_2](/Homework3/Images/3_1_2.PNG)
