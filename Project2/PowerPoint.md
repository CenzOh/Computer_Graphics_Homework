Here is the text dump of the PowerPoint

![image](https://user-images.githubusercontent.com/48773747/145900540-9e3481c4-4c58-4cf9-b3cc-10cefea12bf7.png)

## 1. Initial Idea
We initially wanted to develop a city scene for our second project. We based the project on our previous homeworks and projects so we can combine as many techniques we have learned throughout the semester. 

When creating the actual project, we wanted to ensure our lighting features were improved compared to our previous assignments. We drew a cube in the scene and played around with the values of the lighting. 

Afterwards, we wanted to start creating a building and altered values for glRotate as well as GL_POLYGON to see how it would look within our scene. The rest seemed to naturally arise as we continued to work on the project.

## 2. House function

We wanted to create multiple houses. To do so, we drew the house within a function. To define multiple houses, the function would take in the x, y, and z values to determine where to draw the house. These values were also used by the function to initially define the glTranslated position.

The fourth parameter determines the color pattern of the house. We decided to create only three different predetermined color patterns to remain within the scope of our project.

## 3. Street function

The street was designed in parts with the main road, sidewalk, yellow divider, and sidewalk divider. When placed on the same layer, there were clipping issues with the objects. We instead placed each feature on different layers (y values) to avoid this clipping. 

Looking at the street on a sideways angle, you are able to view the objects on different layers. 

The yellow divider was created with a line stipple and the sidewalk divider was created with a for loop.

## 4. Ground function

The ground function is a simple polygonal shape to give our scene a form of background. 

We used glBegin and glVertex3f to draw this. 

We first had to rotate the object to ensure the rectangular object would look like ground rather than be a wall. 

We also gave the ground the ability to change color which we will go over within the next few slides.

## 5. Menu function

With many features we wanted to add to our scene, we wanted to include a menu. Within the main function, we created menu entries with glutAddMenuEntry. 

We also wanted to categorize the features into submenus. To do this, we used the glutCreateMenu function to create a menu and store that ID into a variable which would then be included in the glutAddSubMenu function. 

After initializing the sub menu, we defined the actual menu options within the submenu with glutAddMenuEntry. 

To activate each option, we added a simple integer variable and switch statement. Each menu option would not all be activated at once, so this approach worked in our favor.

## 6. Winter to Spring function

One of the features we wanted to implement was the scene having different color palettes.  

We thought the change of seasons would be a great way to implement this feature. 

There were many aspects we changed, one of them being the color of the ground. To do this, we simply created a boolean global variable named colorChange and had the menu update the status of this variable depending on the season the user selected. 

By default, the scene is set to a Winter setting; if the user wants the scene to change to Spring, the colorChange variable re-initialize to true. 

## 7. Snowmen and bushes function

It would not make sense to include a snowman during the springtime, so when the season changes to spring, the snowman turns into a bush. 

Again, the colorChange variable takes care of this. 

The bush is created with one solid Sphere. 

As for the snowmen, they comprise of three white spheres for the body and head, one orange cone for the nose, and two spheres for eyes. The Santa hat was created with a white torus for the base, a red cone for the middle part, and a white sphere for the tip. 
The snowmen, similar to the house, have coordinates defined in the function which allows for multiple snowmen to be drawn based on their coordinates. 

For instance, the bottom left snowman is drawn 2 units to the right on the x axis and 1 unit up on the z axis.

## 8. Pond function

For background elements, we drew a pond that will alter the color based on the selected season. 

We split the pond into two parts: 

Outer pond - uses the torus shape 

Inner pond - draws a 2D circle using a for loop and utilizes GL_POLYGON, glBegin and glEnd. 

The color of the inner pond would change based on the season with the colorChange variable (winter - ice blue, spring - aqua blue)

## 9. Draw Boat

To complement the pond, we drew a boat. This boat will only be drawn during the springtime as it’s unlikely for boats to sail during the winter season.

Once again, this is being tracked via the colorChange variable. 

The actual boat was drawn with GL_POLYGON, glBegin, and glEnd. 

The bottom of the boat was designed as an upside down trapezoid which was easily defined with GL_POLYGON and glVertex3f. 

The flagpole was also drawn as with GL_POLYGON as a simple rectangle. 

The flag, however, was drawn with GL_TRIANGLES. 

## 10. Camera function

We wanted to allow the user to see the scene at different angles. We also wanted to ensure everything we drew was to scale and accurate. To achieve this, we were able to update the gluLookAt function to change the position of the camera. This worked in favor for us for debugging purposes. 

We decided to utilize the menu to set specific positions on how the camera angle should view the scene. 

The initial view angle is a semi-top down / bird’s eye view of the town. 

The second angle faces the houses forward / faces the + z axis. 

Finally, in the third angle, we wanted to look down the street / face the - x axis. We did not want the picture to look flat which is why the angles are not exactly facing the certain direction.

## 11. Lighting function

An object can be differentiated from 2D to 3D by having multiple sides within a 3D space. However, this 3D object may look flat if each side has the exact amount of shading and lighting. 

We created two light sources to ensure the scene looked appealing with a nice amount of shading. 

The first light source is a positioned light source while the second light source is a directed light source. 

During the winter, the lighting is on the right side of the picture to give shading on the left side of the roof and near the front door. 

During spring, the lighting has switched to the right side of the scene to give shading on the right side of the roof as well as right side of the house. 

The position was changed with the array appropriately named pos0 and pos1. 

Pos0 was for positioned light while pos1 was for directed light. Which position the light should be was tracked with the colorChange variable.

## 12. Tree function

An interesting (although challenging) topic we learned and wanted to implement in the scene was the L-System trees. We borrowed the code from our previous assignment to draw the tree within the picture. The leaves on the tree would be drawn only when the colorChange variable was set to true. 

We included an option in the menu to toggle the tree being drawn or not. To do this, we utilized another global variable called drawTree. In the menu, if drawTree was enabled, it would disable and vice versa. An issue we encountered with the tree was the color of the tree would not change appropriately when the GL_LIGHTING was enabled, which is why we toggled the drawing of the tree. 

## 13. Next Steps - Future Aspirations

We attempted to make snow fall down during the winter season as well as allow the boat to animate and move across the pond. Due to time constraints, we were unable to include these features. This would have assisted in making the scene feel more lively. 
Overall, we are very happy with the output of our project and spent a lot of time and effort to make the scene as high quality as possible.

## 14. Final Output

![image](https://user-images.githubusercontent.com/48773747/145901133-9bbea8c1-5618-498c-9e69-e20f6df69ad8.png)
