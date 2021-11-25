# Computer Graphics Project 1
The first project utilizes data structures including the functions push() and pop() as well as transformations and lighting.

## Problem 1
Given the sample code, fill in the missing statements utilizing push(), pop(), and necessary transformations. Include extra transformations and different colors. As a bonus, include different lighting, shading, and matieral properities. Another bonus is to add enviornmental elements into the scene.

### Sub Problem 1
Basic drawing, fill in the missing code. Nothing special

![Problem1_1](/Project1/Images/P1P1_1.PNG)

### Sub Problem 2
Include three additional transformations to the above program as well as 3 different colors. We made three seperate versions with simple scaling, transformations, and color changes.

![Problem1_2_1](/Project1/Images/P1P1_2_1.PNG)

![Problem1_2_2](/Project1/Images/P1P1_2_2.PNG)

![Problem1_2_3](/Project1/Images/P1_1_2_3.PNG)

For the creative portion of the problem, I added extra scenary such as trees (cones and rectangles), bushes (spheres), the road (long rectangle) and grass (another massive rectangle). The project required the house (giant cube and cone) as well as the car (rectangle and torus). I added lighting to the top right area of the scene so the light will hit the right side of the house. 

I also included another light source on the back left side of the scene, however, I realize it is too difficult to actually see it. I was not sure how to correctly add the shading to the top of the rectangular objects which is why the top of the car and the grass seem just a little unrealistic with the lack of shadows. I will hopefully be able to correct this error in the next assignment.

![Problem1](/Project1/Images/p1p1.PNG)

## Problem 2
Draw teapots in a matrix formation. The camera must face the teapots. Rearrange the statements within the sample code and recreate the provided sample image. As a bonus, make the teapots spin in place as well as make the lights spin around all teapots.

We were able to create the matrix of teapots by utilizing two for loops. The outer loop deicdes the row while the inner loop decided which column to draw the teapot. The teapots are drawn from the top left to the botoom right of the screen. We were unable to make the teapots spin in place or make the lights spin around the teapot. If we had more time, I am certain we would have been able to implement these features. The way we changed the color of the teapot was by simply creating if statements based on the column and multiply a certain value by the column incrementor variable. As compared to the sample image, I believe we did a great job. I am sure we could have achieved this through another method as well. I also realize for the colors of the object in the column, I could have made certain values be multiplied by the row incrementor variable within the color function inside the if statement.

![Problem2](/Project1/Images/p1p2.PNG)
