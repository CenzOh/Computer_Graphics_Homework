#include <GL/glew.h>
#include <GL/freeglut.h> 

//// Drawing routine.
void House1(void) {
	//Problem 1, Basic Drawing 
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10.0); //sets point size experiment 2.11

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);//sky
	glVertex3f(0.0, 250.0, 0.0);
	glVertex3f(250.0, 250.0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(250.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();

	glColor3f(0.0, 1.0, 0.0); //green
	glBegin(GL_POLYGON); //ground
	glVertex3f(0.0, 130.0, 0.0);
	glVertex3f(250.0, 130.0, 0.0);
	glColor3f(0.0, 0.3, 0.0); //brown
	glVertex3f(250.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();

	// TOP HOUSE 1 START
	glColor3f(1.0, 0.0, 1.0);//house 
	glBegin(GL_POLYGON);
	glVertex3f(59, 70, 0);
	glVertex3f(102, 70, 0);
	glVertex3f(102, 110, 0);
	glVertex3f(59, 110, 0);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);//roof
	glVertex3f(105, 110, 0);
	glVertex3f(80, 140, 0);
	glVertex3f(57, 110, 0);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);//DOOR
	glBegin(GL_POLYGON);
	glVertex3f(76, 70, 0);
	glVertex3f(84, 70, 0);
	glVertex3f(84, 90, 0);
	glVertex3f(76, 90, 0);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);//LEFT WINDOW 
	glBegin(GL_POLYGON);
	glVertex3f(60, 93, 0);
	glVertex3f(75, 93, 0);
	glVertex3f(75, 107, 0);
	glVertex3f(60, 107, 0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);//LEFT WINDOW PANE VERTICAL  
	glBegin(GL_POLYGON);
	glVertex3f(67, 93, 0);
	glVertex3f(68, 93, 0);
	glVertex3f(68, 107, 0);
	glVertex3f(67, 107, 0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);//LEFT WINDOW PANE HORIZONTAL 
	glBegin(GL_POLYGON);
	glVertex3f(60, 99, 0);
	glVertex3f(75, 99, 0);
	glVertex3f(75, 100, 0);
	glVertex3f(60, 100, 0);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);//RIGHT WINDOW 
	glBegin(GL_POLYGON);
	glVertex3f(85, 93, 0);
	glVertex3f(100, 93, 0);
	glVertex3f(100, 107, 0);
	glVertex3f(85, 107, 0);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);//RIGHT WINDOW PANE VERTICAL
	glBegin(GL_POLYGON);
	glVertex3f(93, 93, 0);
	glVertex3f(92, 93, 0);
	glVertex3f(92, 107, 0);
	glVertex3f(93, 107, 0);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);//RIGHT WINDOW PANE HORIZONTAL
	glBegin(GL_POLYGON);
	glVertex3f(85, 99, 0);
	glVertex3f(100, 99, 0);
	glVertex3f(100, 100, 0);
	glVertex3f(85, 100, 0);
	glEnd();
	//TOP HOUSE 1 END 

	//TOP HOUSE 2 START

	glColor3f(1.0, 0.5, 0.0);//house 
	glBegin(GL_POLYGON);
	glVertex3f(145, 70, 0);
	glVertex3f(190, 70, 0);
	glVertex3f(190, 110, 0);
	glVertex3f(145, 110, 0);
	glEnd();

	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);//roof
	glVertex3f(193, 110, 0);
	glVertex3f(167, 140, 0);
	glVertex3f(143, 110, 0);
	glEnd();

	glColor3f(1.0, 0.0, 1.0);//DOOR
	glBegin(GL_POLYGON);
	glVertex3f(162, 70, 0);
	glVertex3f(172, 70, 0);
	glVertex3f(172, 90, 0);
	glVertex3f(162, 90, 0);
	glEnd();

	glColor3f(1.0, 0.0, 1.0);//LEFTT WINDOW 
	glBegin(GL_POLYGON);
	glVertex3f(148, 93, 0);
	glVertex3f(162, 93, 0);
	glVertex3f(162, 107, 0);
	glVertex3f(148, 107, 0);
	glEnd();


	glColor3f(0.0, 0.0, 0.0);//RIGHT WINDOW PANE VERTICAL
	glBegin(GL_POLYGON);
	glVertex3f(179, 93, 0);
	glVertex3f(180, 93, 0);
	glVertex3f(180, 107, 0);
	glVertex3f(179, 107, 0);
	glEnd();



	glColor3f(1.0, 0.0, 1.0);//RIGHT WINDOW 
	glBegin(GL_POLYGON);
	glVertex3f(173, 93, 0);
	glVertex3f(187, 93, 0);
	glVertex3f(187, 107, 0);
	glVertex3f(173, 107, 0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);//LEFT WINDOW PANE VERTICAL  
	glBegin(GL_POLYGON);
	glVertex3f(155, 93, 0);
	glVertex3f(156, 93, 0);
	glVertex3f(156, 107, 0);
	glVertex3f(155, 107, 0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);//LEFTT WINDOW PLANE HORIZONTAL
	glBegin(GL_POLYGON);
	glVertex3f(148, 99, 0);
	glVertex3f(162, 99, 0);
	glVertex3f(162, 100, 0);
	glVertex3f(148, 100, 0);
	glEnd();




	glColor3f(0.0, 0.0, 0.0);//RIGHT WINDOW PANE VERTICAL
	glBegin(GL_POLYGON);
	glVertex3f(179, 93, 0);
	glVertex3f(180, 93, 0);
	glVertex3f(180, 107, 0);
	glVertex3f(179, 107, 0);
	glEnd();




	glColor3f(0.0, 0.0, 0.0);//RIGHT WINDOW  PANE HORIZONTAL 
	glBegin(GL_POLYGON);
	glVertex3f(173, 99, 0);
	glVertex3f(187, 99, 0);
	glVertex3f(187, 100, 0);
	glVertex3f(173, 100, 0);
	glEnd();



	//HOUSE 1 START
	glColor3f(1.0, 0.0, 0.0);//house 
	glBegin(GL_POLYGON);
	glVertex3f(10, 30, 0);
	glVertex3f(60, 30, 0);
	glVertex3f(60, 80, 0);
	glVertex3f(10, 80, 0);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);//roof
	glVertex3f(62, 80, 0);
	glVertex3f(35, 100, 0);
	glVertex3f(8, 80, 0);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);//door
	glVertex3f(30, 50, 0);
	glVertex3f(40, 50, 0);
	glVertex3f(40, 30, 0);
	glVertex3f(30, 30, 0);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);//Windows left
	glVertex3f(15, 75, 0);
	glVertex3f(30, 75, 0);
	glVertex3f(30, 60, 0);
	glVertex3f(15, 60, 0);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);//Windows right
	glVertex3f(40, 75, 0);
	glVertex3f(55, 75, 0);
	glVertex3f(55, 60, 0);
	glVertex3f(40, 60, 0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);//Windows pane
	glVertex3f(22, 75, 0);
	glVertex3f(23, 75, 0);
	glVertex3f(23, 60, 0);
	glVertex3f(22, 60, 0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);//Windows pane
	glVertex3f(15, 68, 0);
	glVertex3f(30, 68, 0);
	glVertex3f(30, 67, 0);
	glVertex3f(15, 67, 0);
	glEnd();


	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);//Windows right
	glVertex3f(47, 75, 0);
	glVertex3f(48, 75, 0);
	glVertex3f(48, 60, 0);
	glVertex3f(47, 60, 0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);//Windows right
	glVertex3f(40, 68, 0);
	glVertex3f(55, 68, 0);
	glVertex3f(55, 67, 0);
	glVertex3f(40, 67, 0);
	glEnd();
	//HOUSE 1 END 










	//HOUSE 2 START 
	glColor3f(0.0, 0.0, 1.0);//house 
	glBegin(GL_POLYGON);
	glVertex3f(100, 30, 0);
	glVertex3f(150, 30, 0);
	glVertex3f(150, 80, 0);
	glVertex3f(100, 80, 0);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);//roof
	glVertex3f(152, 80, 0);
	glVertex3f(125, 100, 0);
	glVertex3f(98, 80, 0);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);//door
	glVertex3f(120, 50, 0);
	glVertex3f(130, 50, 0);
	glVertex3f(130, 30, 0);
	glVertex3f(120, 30, 0);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);//WINDOW LEFT
	glVertex3f(105, 75, 0);
	glVertex3f(120, 75, 0);
	glVertex3f(120, 60, 0);
	glVertex3f(105, 60, 0);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);//WINDOW RIGHT
	glVertex3f(130, 75, 0);
	glVertex3f(145, 75, 0);
	glVertex3f(145, 60, 0);
	glVertex3f(130, 60, 0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);//WINDOW LEFT PANE VERTICAL
	glVertex3f(112, 75, 0);
	glVertex3f(113, 75, 0);
	glVertex3f(113, 60, 0);
	glVertex3f(112, 60, 0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);//WINDOW LEFT HORIZONTAL
	glVertex3f(105, 68, 0);
	glVertex3f(120, 68, 0);
	glVertex3f(120, 67, 0);
	glVertex3f(105, 67, 0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);//WINDOW RIGHT PANE VERTICAL 
	glVertex3f(137, 75, 0);
	glVertex3f(138, 75, 0);
	glVertex3f(138, 60, 0);
	glVertex3f(137, 60, 0);
	glEnd();


	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);//WINDOW RIGHT PANE HORIZONTAL 
	glVertex3f(130, 68, 0);
	glVertex3f(145, 68, 0);
	glVertex3f(145, 67, 0);
	glVertex3f(130, 67, 0);
	glEnd();
	//HOUSE 2 END 

	//HOUSE 3 START 
	glColor3f(0.0, 1.0, 0.0);//house 
	glBegin(GL_POLYGON);
	glVertex3f(185, 30, 0);
	glVertex3f(230, 30, 0);
	glVertex3f(230, 80, 0);
	glVertex3f(185, 80, 0);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);//roof
	glVertex3f(233, 80, 0);
	glVertex3f(206, 100, 0);
	glVertex3f(182, 80, 0);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);//door
	glVertex3f(203, 50, 0);
	glVertex3f(213, 50, 0);
	glVertex3f(213, 30, 0);
	glVertex3f(203, 30, 0);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);//WINDOW LEFT  
	glBegin(GL_POLYGON);
	glVertex3f(189, 74, 0);
	glVertex3f(205, 74, 0);
	glVertex3f(205, 60, 0);
	glVertex3f(189, 60, 0);
	glEnd();


	glColor3f(1.0, 0.0, 0.0);//WINDOW RIGHT 
	glBegin(GL_POLYGON);
	glVertex3f(225, 74, 0);
	glVertex3f(210, 74, 0);
	glVertex3f(210, 60, 0);
	glVertex3f(225, 60, 0);
	glEnd();


	glColor3f(0.0, 0.0, 0.0);//WINDOW LEFT PANE VERTICAL PANE
	glBegin(GL_POLYGON);
	glVertex3f(198, 74, 0);
	glVertex3f(197, 74, 0);
	glVertex3f(197, 60, 0);
	glVertex3f(198, 60, 0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);//WINDOW LEFT HORIZONTAL PANE 
	glBegin(GL_POLYGON);
	glVertex3f(189, 67.5, 0);
	glVertex3f(205, 67.5, 0);
	glVertex3f(205, 66.5, 0);
	glVertex3f(189, 66.5, 0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);//WINDOW RIGHT PANE VERTICAL 
	glBegin(GL_POLYGON);
	glVertex3f(218, 74, 0);
	glVertex3f(217, 74, 0);
	glVertex3f(217, 60, 0);
	glVertex3f(218, 60, 0);
	glEnd();


	glColor3f(0.0, 0.0, 0.0);//WINDOW RIGHT PANE HORIZONTAL
	glBegin(GL_POLYGON);
	glVertex3f(225, 67, 0);
	glVertex3f(210, 67, 0);
	glVertex3f(210, 66, 0);
	glVertex3f(225, 66, 0);
	glEnd();
	// HOUSE 3 END

	glFlush();
}





// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 250.0, 0.0, 250.0, -20.0, 20.0); //2.3

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

// Main routine.
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(900, 900); //2.2 square and window shape change size
	glutInitWindowPosition(0, 0); //2.4 where the window will be placed onscreen

	glutCreateWindow("Homework 1 Problem 2.cpp");

	glutDisplayFunc(House1);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);


	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}