#include <GL/glew.h>
#include <GL/freeglut.h> 
#include<math.h>

// Drawing routine.
void drawScene(void) {

	//Top Semicircle
	float theta;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 180; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(125 + 70 * cos(theta), 125 + 70 * sin(theta));
	}
	glEnd();

	//Bottom Semicircle
	float bstheta;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 180; i < 360; i++) {
		bstheta = i * 3.142 / 180;
		glVertex2f(125 + 70 * cos(bstheta), 127 + 70 * sin(bstheta));
	}
	glEnd();

	//Left Big Circle 
	float lctheta;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		lctheta = i * 3.142 / 180;
		glVertex2f(90 + 35 * cos(lctheta), 125 + 35 * sin(lctheta));
	}
	glEnd();

	//Left Small Circle
	float ltheta;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		ltheta = i * 3.142 / 180;
		glVertex2f(85 + 13 * cos(ltheta), 125 + 13 * sin(ltheta));
	}
	glEnd();

	//Right Big Circle 
	float rctheta;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		rctheta = i * 3.142 / 180;
		glVertex2f(160 + 35 * cos(rctheta), 125 + 35 * sin(rctheta));
	}
	glEnd();

	//Right Small Circle
	float rtheta;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		rtheta = i * 3.142 / 180;
		glVertex2f(160 + 13 * cos(rtheta), 125 + 13 * sin(rtheta));
	}
	glEnd();

	//glDisable(GL_LINE_STIPPLE);

	glFlush();

}

// Initialization routine.
void setup(void)
{
	glClearColor(0.5, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
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
int main(int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(1000, 1000); //2.2 square and window shape change size
	glutInitWindowPosition(0, 0); //2.4 where the window will be placed onscreen

	glutCreateWindow("test.cpp");

	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}