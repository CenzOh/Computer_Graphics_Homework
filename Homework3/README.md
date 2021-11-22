# Computer Graphics Homework 3
Utilize fractals, turtle graphics, and L-systems

## Problem 1_1
Basic Version, create a tree using the provided L-systems code. Randomize the angle of the tree with getrandom() function. Modify the code as to make the tree branches decrease in thickness from the trunk to the outermost branches. That means you must keep a thickness variable that is made smaller with each branch. To keep track, keep in mind the '[' and ']' characters. '[' denotes the start of a new branch while ']' denotes the end.
Add leaves to the code as well with the included drawLeaf() function. Add the case 'L' to draw the leaf at the end of a branch. Modify the F production string to add the leaves as well char Fstr[100] = "FF-[F+F+F+L] ... "

Overall, this was not too difficult to develop, the most challenging aspect was ensuring the tree branches thickness would stay since, for some reason, the code redraws the image twice. Overall, I believe the end product looks good, the way L-systems work is still a tad confusing to me.

![Problem 1_1](/Homework3/Images/3_1_1_a.PNG)

## Problem 1_2
Make a seasonal park tree alley, utilize colors. 

The way I interpreted the question was to create several trees as if they were in a park. Reusing the code for the tree was pretty simple, just move the turtle pointer and draw the tree. I wanted to make each tree look a little different so I modified the code to randomize thickness and the sway of the branches.

![Problem 1_2](/Homework3/Images/3_1_2.PNG)

## Problem 2_1
Creativity version, modify the drawLeaf() function to draw a different, more realistic leaf shape.

To achieve this, I took problem 1_1's code and edited the drawLeaf function. I shaped the leaves to kind of look like a tear drop shape, since leaves are shaped similar to that object. Overall, the design came out well. I was not sure how to angle the leaves based on where the branches were.

![Problem_2_1](/Homework3/Images/3_2_1_a.PNG)

## Problem 2_2
Modify your code to add red apples, flowers, trees in the fall, additional enviornment elements, funny yards, fractal mountains, etc. into the scene.

We were able to draw oranges, lemons, and apples in the tree. Based on a random number that is generated for each instance of where the leaf function would be called, a series of if statements would collect the random number (generated between 1 - 100) and divide by a certain number to select if the end of the branch would have a leaf, apple, orange, or lemon. The flowers were simple to draw, we utilized the for loop code we used to draw a circle for the flower's petals. For the trees in the fall, I made the leaves a light orange and decided to give the picture a nice sunset with color itnerpolation. I tried to make the sun look like a realistic sunset by modifying the color within the for loop. I believe it came out nicely. The fractal mountains were the most difficult thing to figure out. Initially, I drew triangles to represent mountains, however, finding out we had to make them fractal became a real challenge. We referenced drawing a fractal mountain on the Koch curve, however, the Koch curve can effectively draw a snowflake. We could not find any other way to design the fractal curve for a mountain so hopefully the end product will suffice.

![Problem 2_2](/Homework3/Images/3_2_2.PNG)
