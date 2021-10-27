#include <windows.h> 
#include <math.h>
#include <GL/GL.h>
#include <GL/glut.h>
#include <fstream>
using namespace std;


const int screenWidth = 640;
const int screenHeight = 480;
GLdouble A, B, C, D;


void setWindow(float left, float right, float bottom, float top)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);
}


void setViewport(float left, float right, float bottom, float top)
{
	glViewport(left, bottom, right - left, top - bottom);
}


void drawPolyLineFile(const char* fileName)
{
	fstream inStream;
	inStream.open("Brontoi.dat", ios::in);
	if (inStream.fail())
		return;
	GLint numpolys, numLines, x, y;
	inStream >> numpolys;
	for (int j = 0; j < numpolys; j++)
	{
		inStream >> numLines;
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < numLines; i++)
		{
			inStream >> x >> y;
			glVertex2i(x, y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}


void myInit(void)
{
	glClearColor(1.0, 0.0, 1.0, 0.0); // background color is purple 
	glColor3f(0.0f, 0.0f, 1.0f); // draw color is white
	glPointSize(2.0); // a 'dot' is 2 by 2 pixels
	glMatrixMode(GL_PROJECTION); // set "camera shape"
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);

	A = screenWidth / 4.0; // set values used for scaling and shifting
	B = 0.0;
	C = D = screenHeight / 2.0;
}
void DrawDinosaurPic1(float cx, float cy, float r, int num_segments)
{

	for (int i = 0; i < num_segments; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle

		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component

		glViewport(x + cx + 40, y + cy + 60, 64, 44);//output vertex
		drawPolyLineFile("Brontoi.dat");

	}

}
void DrawDinosaurPic2(float cx, float cy, float r, int num_segments)
{
	float angle = 0;
	for (int i = 0; i < num_segments; i++)
	{
		angle = i * (360 / num_segments) + 30;
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glPushMatrix();
		glTranslatef(x + cx + 40, y + cy + 60, 0);
		glScalef(0.07, 0.07, 1);
		glRotatef(angle, 0.0, 0.0, 1.0);
		drawPolyLineFile("Brontoi.dat");
		glPopMatrix();



	}


}
void DrawDinosaurPic3(float cx, float cy, float r, int num_segments)
{

	float angle = 0;
	for (int i = 0; i < num_segments; i++)
	{
		angle = i * (360 / num_segments) + 270;
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glPushMatrix();
		glTranslatef(x + cx + 40, y + cy + 60, 0);
		glScalef(0.07, 0.07, 1);
		glRotatef(angle, 0.0, 0.0, 1.0);
		drawPolyLineFile("Brontoi.dat");
		glPopMatrix();



	}

}
void DrawDinosaurPic4(float cx, float cy, float r, int num_segments)
{

	float angle = 0;
	for (int i = 0; i < num_segments; i++)
	{
		angle = 90;
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glPushMatrix();
		glTranslatef(x + cx + 40, y + cy + 60, 0);
		glScalef(0.07, 0.07, 1);
		glRotatef(angle, 0.0, 0.0, 1.0);
		drawPolyLineFile("Brontoi.dat");
		glPopMatrix();



	}

}

void myDisplay(void)
{
	setWindow(0, 640.0, 0, 480.0); // set a fixed window
	glColor3f(1.0, 1.0, 1.0);
	glViewport(100, 100, 64, 44);
	DrawDinosaurPic1(64, 44, 80, 12);
	glViewport(0, 0, 640, 480);
	DrawDinosaurPic2(80, 280, 80, 12);
	DrawDinosaurPic3(400, 280, 80, 12);
	DrawDinosaurPic4(410, 40, 80, 12);
	glColor3f(1.0, 1.0, 1.0);
	glEnd();
	glFlush();
}


void main(int argc, char** argv)
{
	glutInit(&argc, argv); // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(screenWidth, screenHeight); // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("HW2 Problem 1"); // open the screen window
	glutDisplayFunc(myDisplay); // register redraw function
	myInit();
	glutMainLoop(); // go into a perpetual loop
}