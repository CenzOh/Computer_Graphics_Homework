// CSC 470 Project 1
// Vincenzo Mezzio Joseph DeMario Vincent Loretta 
#include <windows.h>
//#include <iostream.h> //ran into errors
#include <GL/glut.h>
using namespace std;
#include <iostream>

void display() {
	/* clear window */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/* future matrix manipulations should affect the modelview matrix */
	glMatrixMode(GL_MODELVIEW);
	/* draw scene */
	glPushMatrix();
	// house
	glPushMatrix();
	glutSolidCube(2); // building
		 //......... // roof

	glEnable(GL_COLOR_MATERIAL); //add color
	glEnable(GL_LIGHTING); //enables lighting

	//positioned light
	//GLfloat light0[] = { 0.5, 0.5, 0.5, 1.0 }; //intensity r,g,b. mild white
	//GLfloat pos0[] = { 2.0, 2.0, 0.0, 1.0 }; //x,y,z. top right of scene
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, light0); //place color of first light
	//glLightfv(GL_LIGHT0, GL_POSITION, pos0); //place position of first light

	////directed light
	//GLfloat light1[] = { 0.2, 0.4, 0.2, 1.0 };
	//GLfloat pos1[] = { -2.0, 2.0, 0.0, 0.0 }; // to the back of house
	//glLightfv(GL_LIGHT1, GL_DIFFUSE, light1);
	//glLightfv(GL_LIGHT1, GL_POSITION, pos1);

	// start of the drawing
	glTranslated(0.0, 1.0, 0.0); //this moves the object
	glRotatef(-90.0, 1.0, 0.0, 0.0); //rotate the roof
	glutSolidCone(1.5, 1, 16, 8); // do all transformations BEFORE drawing object
	glPushMatrix(); //don't keep the same translations and rotations for rest or save positions

		//......... // chimney
	glTranslated(0.8, 0.6, 0.4);
	glRotatef(0.0, 0.0, 0.0, 1.0);
	glScalef(0.7, 0.9, 2.2);
	glutSolidCube(.25);

	// car

	glPopMatrix();
	glPopMatrix();

	//....... // body
	glScalef(2.0, .6, 1.0);
	glTranslated(0.0, 0.0, 2.5);
	glutSolidCube(.5);
	glPushMatrix();

	// left rear wheel	
	glScalef(0.7, 1.0, 1.0);
	glTranslated(-0.25, -0.35, 0.30);
	glutSolidTorus(.05, .1, 8, 8);
	glPushMatrix();

	// left front wheel
	glPopMatrix();
	glTranslated(0.50, 0.0, 0.0);
	glutSolidTorus(.05, .1, 8, 8);
	glPushMatrix(); //keep the position of the first wheel to start for the second one

				// right front wheel
	glPopMatrix();
	glTranslated(0.0, 0.0, -0.57);
	glutSolidTorus(.05, .1, 8, 8);
	glPushMatrix();

	// right rear wheel
	glPopMatrix();
	glTranslated(-0.45, 0.0, 0.0);
	glutSolidTorus(.05, .1, 8, 8); // wheel
	glPushMatrix();


	glPopMatrix();
	glPopMatrix(); // tree 2 bottom left most


	glPopMatrix();
	glPopMatrix();




	glClearColor(0.0, 0.0, 0.0, 1.0); // black background

	/* flush drawing routines to the window */
	glFlush();
}

void reshape(int width, int height) {
	/* define the viewport transformation */
	glViewport(0, 0, width, height);
}

int main(int argc, char * argv[]) {
	/* initialize GLUT, using any commandline parameters passed to the
	program */
	glutInit(&argc, argv);
	/* setup the size, position, and display mode for new windows */
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	/* create and set up a window */
	glutCreateWindow("hello, house!");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	/* set up depth-buffering */
	glEnable(GL_DEPTH_TEST);
	/* turn on default lighting */
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	/* define the projection transformation */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40, 1, 4, 20);
	/* define the viewing transformation */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	/* tell GLUT to wait for events */
	glutMainLoop();
	return 0;
}