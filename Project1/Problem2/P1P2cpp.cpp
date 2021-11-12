// Project 1 CSC 470
// Vincenzo Mezzio Joseph DeMario Vincent Loretta
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <math.h>
#define W 600
#define H 600
void displayTeapot1(void)
{

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-W, W, -H, H, -W, W);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 10, 0, 0, 0, 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glTranslated(-450, 500, 0);
	glutSolidTeapot(80); //the first tea pot

	glEnable(GL_COLOR_MATERIAL);
	

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	//Direction / intensity of the light.
	GLfloat lightPosition[] = { 0.0f,0.0f,100.0f, 0.0f };
	GLfloat lightIntensity[] = { 0.9f, 0.9f, 0.9f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

	//Add ambient light.
	//Materials.
	GLfloat mat_ambient[] = { 0.5f, 0.5f, 0.6f, 1.0f };
	GLfloat mat_diffuse[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat mat_shininess[] = { 90.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glPushMatrix(); // keep original position
	//glColor4f(0.0, 0.8, 0.0, 1.0);

	for (int i = 0; i < 5; i++) { // matrix teapot
		for (int j = 0; j < 5; j++) {
			glPushMatrix(); // keep positions
			glColor4f(j* 0.2, 0.8, 0.0, 1.0); // green to yellow
			if (i == 0 && j == 0) {
				glColor4f(0.0, 0.8, 0.0, 1.0);
			}
			if (i == 1) { //tealish to pinkish orange
				glColor4f(j* 0.2, 0.5, 0.4, 1.0);
			}
			if (i == 2) { //bluish to red
				glColor4f(j* 0.3, 0.4, 0.5, 1.0);
			}
			if (i == 3) { // blue to salmon
				glColor4f(j* 0.3, 0.2, 0.7, 1.0);
			}
			if (i == 4) { //dark blue to pink
				glColor4f(j* 0.4, 0.2, 0.6, 1.0);
			}
			glTranslated(j*230.0, 0.0, 0.0);
			glutSolidTeapot(80);
			//glPushMatrix();
			glPopMatrix();
		}
		//glPopMatrix();
		glTranslated(0.0, -230.0, 0.0);
	}

	//glTranslated(230.0, 0.0, 0.0);
	glColor4f(0.0, 0.8, 0.0, 1.0); //fixed a problem
	glutSolidTeapot(80);




	GLfloat mat_ambient1[] = { 0.5f, 0.5f, 0.6f, 1.0f };
	GLfloat mat_diffuse1[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	GLfloat mat_specular1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat mat_shininess1[] = { 90.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);
	//glutSolidSphere(50, 20, 20);

	glFlush(); //moved from top to bottom
	glutSwapBuffers();

}






int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(W, H);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My Teapot");
	glutDisplayFunc(displayTeapot1);
	glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
	glViewport(0, 0, W, H);
	glutMainLoop();
	return 1;




}
