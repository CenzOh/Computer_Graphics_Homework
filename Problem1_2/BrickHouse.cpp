///////////////////////////////////
// First OpenGL WE made borrowing code from square
//  F7 to "build solution" and F5 to "debug". F5 draws the graphics in a new window
// Vincenzo Mezzio Vincent Loretta Joseph DeMario
//Self note: Ctrl + k + c to comment. Ctrl + k + u to uncomment
///////////////////////////////////

#include <GL/glew.h>
#include <GL/freeglut.h> 
#include<math.h>

bool tod = 0; //time of day, default 0

void myinit() { //unsure if needed? Including it anyway
	glClearColor(0.0, 0.0, 0.0, 1.0); //setting bckgnd to black
	glClear(GL_COLOR_BUFFER_BIT); //clearing the background
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	//glFlush();
	glutPostRedisplay();
}

void time() { //really didn't need to make another fcn but the code was not working before
	//background
	if (tod == 0) {
		glColor3f(0.0, 0.0, 1.0); //blue
	}
	else if (tod == 1) {
		glColor3f(0.0, 0.0, 0.0); //black
	}

	glBegin(GL_POLYGON); //sky
		glVertex3f(0.0, 100.0, 0.0);
		glVertex3f(100.0, 100.0, 0.0);
		if (tod == 0) {
			glColor3f(1.0, 1.0, 1.0); //white
		}
		glVertex3f(100.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
	glEnd();

	//sun or moon, circle
	if (tod == 0) { //if day time
		glColor3f(1.0, 1.0, 0.0); //yellow sun
	}
	else if (tod == 1) {
		glColor3f(1.0, 1.0, 1.0); //white moon
	}

	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i <= 360; i++) {
		float theta = i * 3.142 / 180;
		glVertex2f(90 + 8 * cos(theta), 95 + 8 * sin(theta)); //needed math lib for this
	} // 90 is x, 8 is radius, 95 y
	glEnd();

}

// Drawing routine.
void drawScene(void)
{	//Problem 1, Second Drawing, Demonstrate Creativity
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5.0); //sets point size experiment 2.11

	//create sky and sun/moon first
		time(); //fcn to draw sun/moon and sky color first based on menu choice



	glColor3f(0.0, 1.0, 0.0); //green
	glBegin(GL_POLYGON); //ground
	glVertex3f(0.0, 10.0, 0.0);
	glVertex3f(100.0, 10.0, 0.0);
	glColor3f(0.39, 0.26, 0.12); //brown
	glVertex3f(100.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();

	glColor3f(1.0, 1.0, 1.0); //2.21 red
	// Draw a polygon with specified vertices.
	glBegin(GL_POLYGON); //2.5 and 2.6 //Make this a house, build square base first
	glVertex3f(10.0, 10.0, 0.0); //Up to experiment 2.14 and figure 2.21 CONTINUE
	glVertex3f(60.0, 10.0, 0.0);
	glVertex3f(60.0, 60.0, 0.0);
	glVertex3f(10.0, 60.0, 0.0);
	glEnd();

	glColor3f(1.0, 0.5, 0.0); //Orange
	glBegin(GL_TRIANGLES); //3 vertex for a triangle. Make this roof
	glVertex3f(8.0, 60.0, 0.0);
	glVertex3f(35.0, 80.0, 0.0);
	glVertex3f(62.0, 60.0, 0.0);
	glEnd();

	glViewport(0, 0, 480, 480); //TESTING??

	glEnable(GL_POLYGON_STIPPLE);

	GLubyte brick[] = { //brick
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
	0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
	0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
	0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
	0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
	0xFF, 0xF3, 0xFF, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC,
	0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC,
	0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC,
	0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC,
	0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC,
	0xFF, 0xFF, 0xFF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFC
	};
	glColor3f(1.0, 0.0, 0.0); //white brick
	glPolygonStipple(brick);

	glBegin(GL_POLYGON);
		glVertex3f(10, 10, 0); //bottom left
		glVertex3f(60, 10, 0); //top left
		glVertex3f(60, 60, 0); //top right
		glVertex3f(10, 60, 0); //bottom right
	glEnd();
	glDisable(GL_POLYGON_STIPPLE);

	glBegin(GL_POLYGON); //left window
		glColor3f(1.0, 0.8, 0.0); //yellow window
		glVertex3f(12, 58, 0); //top left
		glVertex3f(22, 58, 0); //top right
		glColor3f(1.0, 0.3, 0.0); //more red within the window
		glVertex3f(22, 48, 0); //bottom right
		glVertex3f(12, 48, 0); //bottom left
	glEnd();

	glLineWidth(2.0); //setting the window frame thickness
	glBegin(GL_LINE_STRIP); //window frame and vertical frame
		glColor3f(0.0, 0.0, 0.0); //black frame
		glVertex3f(12, 58, 0); //top left
		glVertex3f(22, 58, 0); //top right
		glVertex3f(22, 48, 0); //bottom right
		glVertex3f(12, 48, 0); //bottom left
		glVertex3f(12, 58, 0); //back to top left
		glVertex3f(17, 58, 0); //top middle
		glVertex3f(17, 48, 0); //bottom middle
	glEnd();
	glBegin(GL_LINE_STRIP); //horizontal frame
		glVertex3f(12, 53, 0); //middle left
		glVertex3f(22, 53, 0); 
	glEnd();


	glBegin(GL_POLYGON); //right window
		glColor3f(1.0, 0.8, 0.0); //yellow window
		glVertex3f(48, 58, 0); //top left
		glVertex3f(58, 58, 0); //top right
		glColor3f(1.0, 0.3, 0.0); //more red within the window
		glVertex3f(58, 48, 0); //bottom right
		glVertex3f(48, 48, 0); //bottom left
	glEnd();

	glBegin(GL_LINE_STRIP); //window frame and vertical frame
		glColor3f(0.0, 0.0, 0.0); //black frame
		glVertex3f(48, 58, 0); //top left
		glVertex3f(58, 58, 0); //top right
		glVertex3f(58, 48, 0); //bottom right
		glVertex3f(48, 48, 0); //bottom left
		glVertex3f(48, 58, 0); //back to top left
		glVertex3f(53, 58, 0); //top middle
		glVertex3f(53, 48, 0); //bottom middle
	glEnd();
	glBegin(GL_LINE_STRIP); //horizontal frame
		glVertex3f(48, 53, 0); //middle left
		glVertex3f(58, 53, 0);
	glEnd();


	// door
	glColor3f(0.4, 0.2, 0.0); //brown
	glBegin(GL_POLYGON);
		glVertex3f(30, 10, 0); //bottom left
		glVertex3f(40, 10, 0); //bottom right
		glVertex3f(40, 28, 0); //top right
		glVertex3f(30, 28, 0); //top left
	glEnd();

	glColor3f(1.0, 1.0, 0.0); // door knob
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i <= 360; i++) {
		float theta = i * 3.142 / 180;
		glVertex2f(38 + 1 * cos(theta), 19 + 1 * sin(theta)); //needed math lib for this
	} 
	glEnd();

	glColor3f(0.3, 0.1, 0.0); //dark brown
	glBegin(GL_POLYGON); // top left door indent
		glVertex3f(36, 21, 0); //bottom left
		glVertex3f(39, 21, 0); //bottom right
		glVertex3f(39, 27, 0); //top right
		glVertex3f(36, 27, 0); //top left
	glEnd();

	glBegin(GL_POLYGON); // top right door indent
		glVertex3f(31, 21, 0); //bottom left
		glVertex3f(34, 21, 0); //bottom right
		glVertex3f(34, 27, 0); //top right
		glVertex3f(31, 27, 0); //top left
	glEnd();

	glBegin(GL_POLYGON); // bottom left door indent
		glVertex3f(36, 11, 0); //bottom left
		glVertex3f(39, 11, 0); //bottom right
		glVertex3f(39, 17, 0); //top right
		glVertex3f(36, 17, 0); //top left
	glEnd();

	glBegin(GL_POLYGON); // bottom right door indent
		glVertex3f(31, 11, 0); //bottom left
		glVertex3f(34, 11, 0); //bottom right
		glVertex3f(34, 17, 0); //top right
		glVertex3f(31, 17, 0); //top left
	glEnd();


	glBegin(GL_POLYGON); // cement walkway
		glColor3f(0.5, 0.5, 0.5); //grey
		glVertex3f(45, 0, 0); //bottom right
		glColor3f(0.2, 0.2, 0.2); //dark grey
		glVertex3f(25, 0, 0); //bottom left
		glVertex3f(30, 10, 0); //top left
		glVertex3f(40, 10, 0); //top right
	glEnd();

	glBegin(GL_LINE_STRIP); // top line to split up walkway
		glColor3f(0.0, 0.0, 0.0); //black
		glVertex3f(29, 8, 0); // left
		glVertex3f(41, 8, 0); // right
	glEnd();

	glBegin(GL_LINE_STRIP); // bottom line to split up walkway
		glVertex3f(27, 4, 0); // left
		glVertex3f(43, 4, 0); // right
	glEnd();



	glFlush();
	glutSwapBuffers();
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
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0); //2.3

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

// menu, was not happy inside of main
void myMenu(int value) {
	switch (value) {
	case 1: //day time
		tod = 0;
		break;
	case 2: //night time
		tod = 1;
		//glutInitWindowSize(1000, 500);
		break;
	case 3:
		exit(0);
		break;
	}
	//if (value == 1) glClear();
	//else if (value == 2) exit();
	glutPostRedisplay();
}

// Main routine.
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(500, 500); //2.2 square and window shape change size
	glutInitWindowPosition(0, 0); //2.4 where the window will be placed onscreen

	glutCreateWindow("BrickHouse.cpp");

	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	// menu
	glutCreateMenu(myMenu);
	glutAddMenuEntry("Day", 1);
	glutAddMenuEntry("Night", 2);
	glutAddMenuEntry("Exit", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	myinit(); //initializing fcn of course, nothing happens

	glutMainLoop();

}