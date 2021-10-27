// CSC 470 Homework 2 Problem 3
// Vincenzo Mezzio Vincent Loretta Joseph DeMario

#include <GL/glew.h>
#include <GL/freeglut.h> 
#include <math.h>

int draw = 0;
int color = 0;

// Which drawing will the user choose ? Call the function //

void triagram(void) { //draw == 0 function to draw triagram
	glBegin(GL_TRIANGLES); //background triangle
		glVertex3f(20.0, 20.0, 0.0); //bottom left
		glVertex3f(40.0, 60.0, 0.0); //top
		glVertex3f(60.0, 20.0, 0.0); //bottom right
	glEnd();
	glBegin(GL_TRIANGLES); 
		//first triangle - bottom 
		glColor3f(1.0, 1.0, 0.0); //yellow
		glVertex3f(20.0, 20.0, 0.0); //bottom left
		glVertex3f(40.0, 30.0, 0.0); //top
		glVertex3f(60.0, 20.0, 0.0); //bottom right
		//second triangle - left
		glVertex3f(20.0, 20.0, 0.0); //bottom left
		glVertex3f(37.0, 37.0, 0.0); //middle
		glVertex3f(40.0, 60.0, 0.0); //top
		//third triangle - right
		glVertex3f(60.0, 20.0, 0.0); //bottom right
		glVertex3f(43.0, 37.0, 0.0); //middle
		glVertex3f(40.0, 60.0, 0.0); //top
	glEnd();
}

void pentagram(void) { //draw == 1
	glBegin(GL_POLYGON); //pentagon
		glVertex3f(20.0, 20.0, 0.0); //bottom left
		glVertex3f(10.0, 55.0, 0.0); //middle left
		glVertex3f(40.0, 75.0, 0.0); //top
		glVertex3f(70.0, 55.0, 0.0); //middle right
		glVertex3f(60.0, 20.0, 0.0); //bottom right
	glEnd();

	glBegin(GL_TRIANGLES);
		//first triangle - bottom left
		glColor3f(1.0, 1.0, 0.0); //yellow
		glVertex3f(20.0, 20.0, 0.0); //bottom left
		glVertex3f(32.0, 42.5, 0.0); // middle piece
		glVertex3f(10.0, 55.0, 0.0); //middle left
		//second triangle - top left
		glVertex3f(10.0, 55.0, 0.0); //middle left
		glVertex3f(35.0, 50.0, 0.0); // middle piece
		glVertex3f(40.0, 75.0, 0.0); //top
		//third triangle - top right
		glVertex3f(40.0, 75.0, 0.0); //top
		glVertex3f(45.0, 50.0, 0.0); // middle piece
		glVertex3f(70.0, 55.0, 0.0); //middle right
		//fourth triangle - bottom right
		glVertex3f(70.0, 55.0, 0.0); //middle right
		glVertex3f(48.0, 42.5, 0.0); // middle piece
		glVertex3f(60.0, 20.0, 0.0); //bottom right
		//fifth triangle - bottom
		glVertex3f(60.0, 20.0, 0.0); //bottom right
		glVertex3f(40.0, 40.0, 0.0); // middle piece
		glVertex3f(20.0, 20.0, 0.0); //bottom left
	glEnd();
}

void star(void) { //7 pointed
	glBegin(GL_POLYGON);
		glVertex3f(45.0, 42.0, 0.0); // middle piece betweem bottom right and bottom
		glVertex3f(60.0, 20.0, 0.0); //bottom right
		glVertex3f(40.0, 40.0, 0.0); // middle piece - middle
		glVertex3f(20.0, 20.0, 0.0); //bottom left
		glVertex3f(35.0, 42.0, 0.0); // middle piece - bottom left and left
		glVertex3f(15.0, 40.0, 0.0); //left piece
		glVertex3f(33.0, 46.0, 0.0); // middle piece - left and top left
		glVertex3f(22.0, 60.0, 0.0); //top left
		glVertex3f(38.0, 52.0, 0.0); // middle piece - top left and top
		glVertex3f(40.0, 75.0, 0.0); //top
		glVertex3f(42.0, 51.0, 0.0);// middle piece - top and top right
		glVertex3f(58.0, 60.0, 0.0); //top right
		glVertex3f(47.0, 47.0, 0.0);// middle piece - top right and right
		glVertex3f(65.0, 40.0, 0.0); //right piece
	glEnd();

}

void hexagram(void) {
	glBegin(GL_POLYGON); //hexagon
		glVertex3f(40.0, 20.0, 0.0); //bottom
		glVertex3f(15.0, 35.0, 0.0); //bottom left
		glVertex3f(15.0, 60.0, 0.0); //top left
		glVertex3f(40.0, 75.0, 0.0); //top
		glVertex3f(65.0, 60.0, 0.0); //top right
		glVertex3f(65.0, 35.0, 0.0); //bottom right
	glEnd();

	glBegin(GL_TRIANGLES); //triangles
		glColor3f(1.0, 1.0, 0.0); //yellow
		//first triangle - bottom 
		glVertex3f(45.0, 41.0, 0.0); // middle piece right - bottom and bottom right
		glVertex3f(40.0, 20.0, 0.0); //bottom
		glVertex3f(35.0, 41.0, 0.0); // middle piece left - bottom and bottom right
		//second triangle - bottom left
		glVertex3f(36.0, 41.0, 0.0); // middle piece bottom
		glVertex3f(15.0, 35.0, 0.0); //bottom left
		glVertex3f(32.0, 48.0, 0.0); // middle piece top
		//third triangle - top left
		glVertex3f(32.0, 48.0, 0.0); // middle piece left
		glVertex3f(15.0, 60.0, 0.0); //top left
		glVertex3f(36.0, 54.0, 0.0); // middle piece right
		//fourth triangle - top
		glVertex3f(36.0, 54.0, 0.0); // middle piece left
		glVertex3f(40.0, 75.0, 0.0); //top
		glVertex3f(45.0, 47.0, 0.0); // middle piece right
		//fifth triangle - top right
		glVertex3f(45.0, 47.0, 0.0); // middle piece top
		glVertex3f(65.0, 60.0, 0.0); //top right
		glVertex3f(42.0, 54.0, 0.0); // middle piece bottom
		//sixth triangle - bottom right
		glVertex3f(42.0, 54.0, 0.0); // middle piece right
		glVertex3f(65.0, 35.0, 0.0); //bottom right
		glVertex3f(45.0, 41.0, 0.0); // middle piece left

	glEnd();

	//circle 
	float theta;
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(40 + 8 * cos(theta), 47.5 + 8 * sin(theta));
	}
	glEnd();
	
}

// Drawing routine.
void drawScene(void) //drawing the actual image
{
	glClear(GL_COLOR_BUFFER_BIT);

	if (color == 0) { //change the color in submenu
		glColor3f(1.0, 0.0, 0.0);
	}
	else {
		glColor3f(0.0, 0.0, 1.0);
	}

	if (draw == 0) {
		triagram();
	}
	else if (draw == 1) {
		pentagram();
	}
	else if (draw == 2) {
		star();
	}
	else {
		hexagram();
	}

	glFlush();
}

// *** Initialization routine.
void setup(void)
{
	glClearColor(0.2, 0.2, 0.2, 0.0); //background color

}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);

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

// menu
void myMenu(int value) {
	switch (value) {
	case 1: //triagram
		draw = 0;
		break;
	case 2: //hexagram
		draw = 1;
		break;
	case 3:
		draw = 2;
		break;
	case 4:
		draw = 3;
		break;
	case 5:
		exit(0);
		break;

	}
	glutPostRedisplay(); //redraws image
}

//submenu
void colormenu(int value) {
	switch (value) {
	case 6: //red
		color = 0;
		break;
	case 7: //blue
		color = 1;
		break;
	case 8: //make window larger
		glutReshapeWindow(1000, 1000);
		break;
	}
}

//second submenu
void size(int value) {
	switch(value) {
	case 8: //make window smaller
		glutReshapeWindow(500, 500);
		break;
	case 9: //make window medium size
		glutReshapeWindow(750, 750);
		break;
	case 10: //make window bigger
		glutReshapeWindow(1000, 1000);
		break;
	}
}

// Main routine.
int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Homework 2 Problem 3");

	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	//create a submenu first
	static int submenuid, menuid, submenuid2;
	submenuid = glutCreateMenu(colormenu); //sub menu options first
	glutAddMenuEntry("Red", 6);
	glutAddMenuEntry("Blue", 7);
	submenuid2 = glutCreateMenu(size); //second sub menu
	glutAddMenuEntry("Smalleen", 8);
	glutAddMenuEntry("Medium screen", 9);
	glutAddMenuEntry("Large screen", 10);
	menuid = glutCreateMenu(myMenu); //main menu options
	glutAddSubMenu("Change Color", submenuid); //submenu option
	glutAddSubMenu("Change Size", submenuid2); //second submenu
	glutAddMenuEntry("Triagram", 1);
	glutAddMenuEntry("Pentagram", 2);
	glutAddMenuEntry("Star", 3);
	glutAddMenuEntry("Hexagram", 4);
	glutAddMenuEntry("Exit", 5);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
}