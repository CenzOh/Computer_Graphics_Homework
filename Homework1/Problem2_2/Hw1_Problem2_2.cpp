///////////////////////////////////
// CSC 470 Hw1
// Vincenzo Mezzio Joseph DeMario Vincent Loretta
///////////////////////////////////

#include <GL/glew.h>
#include <GL/freeglut.h> 
#include<math.h>

// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5.0);

	// ** Start of Vincent's code
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10.0); //sets point size experiment 2.11

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
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

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);//ROAD
	glVertex3f(125.0, 130.0, 0.0);
	glVertex3f(100.0, 0.0, 0.0);
	glVertex3f(150.0, 0.0, 0.0);
	glEnd();

	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_POLYGON);//BIG BUILDING LEFT
	glVertex3f(100.0, 180.0, 0.0);
	glVertex3f(130.0, 180.0, 0.0);
	glVertex3f(130.0, 130.0, 0.0);
	glVertex3f(100.0, 130.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON);// BIG BUILDING MIDDLE
	glVertex3f(170.0, 130.0, 0.0);//BR
	glVertex3f(170.0, 160.0, 0.0);//TR
	glVertex3f(130.0, 160.0, 0.0);//TL
	glVertex3f(130.0, 130.0, 0.0);//BL
	glEnd();

	glBegin(GL_POLYGON);//BIG BUILDING RIGHT
	glVertex3f(200.0, 130.0, 0.0);//BR
	glVertex3f(200.0, 200.0, 0.0);//TR
	glVertex3f(150.0, 200.0, 0.0);//TL
	glVertex3f(150.0, 130.0, 0.0);//BL
	glEnd();

	glColor3f(1.0, 1.0, 0.0);//yellow
	glBegin(GL_POLYGON);//BIG BUILDING RIGHT
	glVertex3f(152.0, 198.0, 0.0);//TL
	glVertex3f(152.0, 194.0, 0.0);//BL
	glVertex3f(154.0, 194.0, 0.0);//BR
	glVertex3f(154.0, 198.0, 0.0);//TR
	glEnd();
	// ** End of Vincent's Code

	// ** Start of Joe's Code Dashed yellow line made by Joe
	glEnable(GL_LINE_STIPPLE); //enable
	glColor3f(1.0, 1.0, 0.0); //yellow
	glLineStipple(2, 0xFF00); //to make the yellow dashed lines
	glBegin(GL_LINE_STRIP);
	glVertex3f(125.0, 130.0, 0.0);
	glVertex3f(125.0, 0.0, 0.0);
	glEnd();

	//Sun
	float theta;
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		theta = i * 3.142 / 180;
		glVertex2f(0 + 30 * cos(theta), 250 + 30 * sin(theta));
	}
	glEnd();

	//Tree 1
	glColor3f(0.3, 0.1, 0.1);
	glBegin(GL_POLYGON);
	glVertex3f(75.0, 130.0, 0.0);
	glVertex3f(85.0, 130.0, 0.0);
	glVertex3f(85.0, 155.0, 0.0);
	glVertex3f(75.0, 155.0, 0.0);
	glEnd();
	float theta2;
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		theta2 = i * 3.142 / 180;
		glVertex2f(80 + 12 * cos(theta2), 160 + 12 * sin(theta2));
	}
	glEnd();

	//Tree 2
	glColor3f(0.3, 0.1, 0.1);
	glBegin(GL_POLYGON);
	glVertex3f(15.0, 130.0, 0.0);
	glVertex3f(35.0, 130.0, 0.0);
	glVertex3f(35.0, 165.0, 0.0);
	glVertex3f(15.0, 165.0, 0.0);
	glEnd();
	float theta3;
	glColor3f(0.7, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		theta3 = i * 3.142 / 180;
		glVertex2f(25 + 18 * cos(theta3), 175 + 18 * sin(theta3));
	}
	glEnd();

	//Tree3
	glColor3f(0.3, 0.1, 0.1);
	glBegin(GL_POLYGON);
	glVertex3f(220.0, 130.0, 0.0);
	glVertex3f(235.0, 130.0, 0.0);
	glVertex3f(235.0, 175.0, 0.0);
	glVertex3f(220.0, 175.0, 0.0);
	glEnd();
	float theta4;
	glColor3f(0.6, 0.9, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		theta4 = i * 3.142 / 180;
		glVertex2f(226.50 + 18 * cos(theta4), 190 + 18 * sin(theta4));
	}
	glEnd();

	//Bushes
	float theta5;
	glColor3f(0.6, 0.9, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		theta5 = i * 3.142 / 180;
		glVertex2f(40 + 7 * cos(theta5), 135 + 7 * sin(theta5));
	}
	glEnd();
	float theta6;
	glColor3f(0.1, 0.9, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		theta6 = i * 3.142 / 180;
		glVertex2f(54 + 9 * cos(theta6), 136 + 9 * sin(theta6));
	}
	glEnd();
	float theta7;
	glColor3f(0.2, 0.9, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		theta7 = i * 3.142 / 180;
		glVertex2f(13 + 10 * cos(theta7), 137 + 10 * sin(theta7));
	}
	glEnd();
	float theta8;
	glColor3f(0.3, 0.9, 0.3);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		theta8 = i * 3.142 / 180;
		glVertex2f(28 + 8 * cos(theta8), 136 + 8 * sin(theta8));
	}
	glEnd();

	float theta9;
	glColor3f(0.3, 0.9, 0.3);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		theta9 = i * 3.142 / 180;
		glVertex2f(215 + 9 * cos(theta9), 137 + 9 * sin(theta9));
	}
	glEnd();
	float theta10;
	glColor3f(0.3, 0.9, 0.3);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		theta10 = i * 3.142 / 180;
		glVertex2f(228 + 6 * cos(theta10), 136 + 6 * sin(theta10));
	}
	glEnd();
	float theta11;
	glColor3f(0.0, 1.0, 0.2);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		theta11 = i * 3.142 / 180;
		glVertex2f(244 + 11 * cos(theta11), 138 + 11 * sin(theta11));
	}
	glEnd();

	//Buildings on left side of the road
		//first house
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(10.0, 20.0, 0.0);
	glVertex3f(50.0, 20.0, 0.0);
	glVertex3f(50.0, 70.0, 0.0);
	glVertex3f(10.0, 70.0, 0.0);
	glEnd();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(10.0, 70.0, 0.0);
	glVertex3f(50.0, 70.0, 0.0);
	glVertex3f(30.0, 95.0, 0.0);
	glEnd();
	//Door
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(25.0, 20.0, 0.0);
	glVertex3f(35.0, 20.0, 0.0);
	glVertex3f(35.0, 40.0, 0.0);
	glVertex3f(25.0, 40.0, 0.0);
	glEnd();
	//Windows
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(13.0, 53.0, 0.0);
	glVertex3f(23.0, 53.0, 0.0);
	glVertex3f(23.0, 65.0, 0.0);
	glVertex3f(13.0, 65.0, 0.0);
	glEnd();
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(37.0, 53.0, 0.0);
	glVertex3f(47.0, 53.0, 0.0);
	glVertex3f(47.0, 65.0, 0.0);
	glVertex3f(37.0, 65.0, 0.0);
	glEnd();

	//second house
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(60.0, 70.0, 0.0);
	glVertex3f(100.0, 70.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(100.0, 110.0, 0.0);
	glVertex3f(60.0, 110.0, 0.0);
	glEnd();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(60.0, 110.0, 0.0);
	glVertex3f(100.0, 110.0, 0.0);
	glVertex3f(80.0, 128.0, 0.0);
	glEnd();
	//Door
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(75.0, 70.0, 0.0);
	glVertex3f(85.0, 70.0, 0.0);
	glVertex3f(85.0, 85.0, 0.0);
	glVertex3f(75.0, 85.0, 0.0);
	glEnd();
	//Windows
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(63.0, 95.0, 0.0);
	glVertex3f(73.0, 95.0, 0.0);
	glVertex3f(73.0, 105.0, 0.0);
	glVertex3f(63.0, 105.0, 0.0);
	glEnd();
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(87.0, 95.0, 0.0);
	glVertex3f(97.0, 95.0, 0.0);
	glVertex3f(97.0, 105.0, 0.0);
	glVertex3f(87.0, 105.0, 0.0);
	glEnd();



	// ** End of Joe's Code

	// ** Start of Vincenzo's Code
	// Buildings
	glDisable(GL_LINE_STIPPLE);

	glColor3f(0.2, 0.2, 0.2); //dark grey for inside the building
	glBegin(GL_POLYGON);
		glVertex3f(165, 10.0, 0.0);
		glVertex3f(165, 60.0, 0.0);
		glVertex3f(195, 60.0, 0.0);
		glVertex3f(195, 10.0, 0.0);
	glEnd();

	glEnable(GL_POLYGON_STIPPLE); //enable the stipple for the mask

	GLubyte brick[] = { //brick mask
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
	 //red color for brick
	glPolygonStipple(brick); //we want this array (brick) to be the polygon stipple (texture)

	glColor3f(1.0, 0.0, 0.0); //red bricks
	glBegin(GL_POLYGON); //brick house
		glVertex3f(165, 10.0, 0.0);
		glVertex3f(165, 60.0, 0.0);
		glVertex3f(195, 60.0, 0.0);
		glVertex3f(195, 10.0, 0.0);
	glEnd();

	glDisable(GL_POLYGON_STIPPLE);

	glColor3f(0.3, 0.1, 0.1); //dark brown door
	glBegin(GL_POLYGON); 
		glVertex3f(170, 10.0, 0.0);
		glVertex3f(170, 24.0, 0.0);
		glVertex3f(178, 24.0, 0.0);
		glVertex3f(178, 10.0, 0.0);
	glEnd();

	glColor3f(0.3, 0.3, 1.0); //blue window
	glBegin(GL_POLYGON); 
		glVertex3f(170, 40.0, 0.0);
		glVertex3f(170, 50.0, 0.0);
		glVertex3f(175, 50.0, 0.0);
		glVertex3f(175, 40.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON); //second window
		glVertex3f(185, 40.0, 0.0); 
		glVertex3f(185, 50.0, 0.0);
		glVertex3f(190, 50.0, 0.0);
		glVertex3f(190, 40.0, 0.0);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP); //multiple triangles v0v1v2 v1v2v3
	glColor3f(0.5, 0.5, 0.5); //little gray	for side walk
		glVertex3f(90.0, 0.0, 0.0);//left side side walk bottom left
		glVertex3f(100.0, 0.0, 0.0); //bottom right
		glVertex3f(125.0, 130.0, 0.0);// top 
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(150.0, 0.0, 0.0);// right sidewalk bottom left
		glVertex3f(160.0, 0.0, 0.0);// bottom right
		glVertex3f(125.0, 130.0, 0.0);// top 
	glEnd();


	glColor3f(0.5, 0.3, 0.0); //lightish brown

	// Draw a polygon with specified vertices.
	glBegin(GL_TRIANGLE_FAN); //draw the shell of the house
		glVertex3f(145.0, 70.0, 0.0); //bottom left of house
		glVertex3f(145.0, 90.0, 0.0); //go up
		glColor3f(0.4, 0.4, 0.0);
		glVertex3f(155.0, 100.0, 0.0); //slant to top for roof
		glVertex3f(165.0, 90.0, 0.0); //slant back down
		glColor3f(0.8, 0.6, 0.0);
		glVertex3f(165.0, 70.0, 0.0); //down to bottom right
	glEnd();

	glBegin(GL_TRIANGLE_FAN); //Chimney
		glColor3f(0.7, 0.6, 0.0);
		glVertex3f(147.0, 92.0, 0.0); //bottom left of chimney
		glVertex3f(147.0, 102.0, 0.0); //top left of chimney
		glVertex3f(152.0, 102.0, 0.0); //top right of chimney
		glColor3f(0.5, 0.3, 0.0);
		glVertex3f(152.0, 97.0, 0.0); //bottom right of chimney
	glEnd();

	glBegin(GL_POLYGON); //left window on the brown house
		glColor3f(0.5, 0.5, 1.0); //blue window on brown house
		glVertex3f(147.0, 90.0, 0.0); //top left
		glVertex3f(147.0, 85.0, 0.0); //bottom left
		glVertex3f(153.0, 85.0, 0.0); //bottom right
		glVertex3f(153.0, 90.0, 0.0); //top right
	glEnd();

	glBegin(GL_LINE_STRIP); //vertical and whole frame 
		glColor3f(0.0, 0.0, 0.0); //black window bars
		glVertex3f(150.0, 85.0, 0.0); //bottom middle
		glVertex3f(150.0, 90.0, 0.0); //top middle
		glVertex3f(147.0, 90.0, 0.0); //top left
		glVertex3f(147.0, 85.0, 0.0); //bottom left
		glVertex3f(153.0, 85.0, 0.0); //bottom right
		glVertex3f(153.0, 90.0, 0.0); //top right
		glVertex3f(150.0, 90.0, 0.0); //back to top middle to close frame
	glEnd();

	glBegin(GL_LINE_STRIP); // horizontal frame
		glVertex3f(153.0, 87.5, 0.0); //right middle
		glVertex3f(147.0, 87.5, 0.0); //left middle, drawing the middle horizontal bar
	glEnd();



	glBegin(GL_POLYGON); // Second window on brown house but to the right
		glColor3f(0.5, 0.5, 1.0); //blue window on brown house
		glVertex3f(157.0, 90.0, 0.0); //top left
		glVertex3f(157.0, 85.0, 0.0); //bottom left
		glVertex3f(163.0, 85.0, 0.0); //bottom right
		glVertex3f(163.0, 90.0, 0.0); //top right
	glEnd();

	glBegin(GL_LINE_STRIP); //vertical and whole frame
		glColor3f(0.0, 0.0, 0.0); //black window bars
		glVertex3f(160.0, 85.0, 0.0); //bottom middle
		glVertex3f(160.0, 90.0, 0.0); //top middle
		glVertex3f(157.0, 90.0, 0.0); //top left
		glVertex3f(157.0, 85.0, 0.0); //bottom left
		glVertex3f(163.0, 85.0, 0.0); //bottom right
		glVertex3f(163.0, 90.0, 0.0); //top right
		glVertex3f(160.0, 90.0, 0.0); //back to top middle to close frame
	glEnd();

	glBegin(GL_LINE_STRIP); // horizontal frame
		glVertex3f(163.0, 87.5, 0.0); //right middle
		glVertex3f(157.0, 87.5, 0.0); //left middle, drawing the middle horizontal bar
	glEnd();
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);// turns into an outline

	glColor3f(0.3, 0.2, 0.0); //the door
	glRectf(150, 70, 155, 80); //T L B R

	glBegin(GL_TRIANGLE_FAN); //fan starts at the first point
	glColor3f(0.2, 0.2, 0.2); // grey building on the right
		glVertex3f(210.0, 75.0, 0.0); //top left
		glVertex3f(220.0, 75.0, 0.0); //top right
		glVertex3f(220.0, 65.0, 0.0); //bottom right
		glVertex3f(210.0, 65.0, 0.0); //bottom left

		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(200.0, 70.0, 0.0); //bottom left ext
		glVertex3f(200.0, 80.0, 0.0); //top left ext
		glVertex3f(210.0, 80.0, 0.0); //top right ext
		glColor3f(0.1, 0.1, 0.1);
		glVertex3f(220.0, 75.0, 0.0); //back to top right


	glEnd();

	glColor3f(0.4, 0.3, 0.0); //the brown door for grey building
	glRectf(218, 65, 214, 71); //x1, y1, x2, y2

	// ** End of Vincenzo's code

	glFlush();
}

// Initialization routine.
void setup(void)
{
	glClearColor(0.2, 0.2, 1.0, 0.0); //rgb background
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 250.0, 0.0, 250.0, -20.0, 20.0);
	//ortho: left, right, bottom, top, near, far

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
int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(900, 900);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Village_Of_Houses");

	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}
