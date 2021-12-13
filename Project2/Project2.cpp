//Project 2 CSC 470
//Vincenzo Mezzio Joseph DeMario Vincent Loretta
#include <windows.h>
#include <GL/glut.h>
using namespace std;
#include <iostream>
#define getrandom(min, max) ((rand() % (int)(((max)+1) - (min))) + (min))

class Point2   //single point w/ floating point coordinates
{
public:
	float x, y;
	Point2() { x = y = 0.0f; } //constructor 1
	Point2(float xx, float yy) { x = xx; y = yy; } //constructor 2
	void set(float xx, float yy) { x = xx; y = yy; }
	float getX() { return x; }
	float getY() { return y; }
	void draw(void)
	{
		glBegin(GL_POINTS); //draw this point
		glVertex2f((GLfloat)x, (GLfloat)y);
		glEnd();
	}

};

Point2 CP;      //current turtle point
float CD = 90;  //current turtle direction
float i = 0.0; //keep track of the iteration
float c = 0.0; //color variable for tree
bool drawTree = false;

float eyex = 4.2; //change perspective in glLookAt fcn
float eyey = 5.0;
float eyez = 5.0;
float centerx = -1.1;
float centery = 0.0;
float centerz = 0.0;
float upx = 0.0;
float upy = 1.0;
float upz = 0.0;
boolean colorChange = false; //changing from spring to winter
boolean pondColorChange = false;

//string production rules
char atom[25] = "F";                      //starting string
char Fstr[30] = "FF-[-F+F+FX]+[+F-F-FX]";//F production rule, L draws the leaf
char Xstr[30] = "X-[FL+FL+FL]+[+FL-FL-FL]"; //X production rule
char Ystr[25] = "";                       //Y production rule
float angle = getrandom(12, 40);           //turn angle
int length = 20;                          //forward length

//"FF-[-F+F+F]+[+F-F-F+L]" // old Fstr

//array of current turtle locations
//better to use a linked list for these :)
//These arrays will allow a maximum of 100 nested [] pairs.   Should be heaps!!
Point2 saveTut[100];
float saveAng[100];
int curr = 0;

//min and max extremes for the window size
float xmin = 0.0, xmax = 0.0, ymin = 0.0, ymax = 0.0;


//-----TURTLE DRAWING FUNCTIONS- TAKEN OUT OF CANVAS.H------------------
void moveTo(float x, float y)
{
	CP.set(x, y);
}

void lineTo(float x, float y)
{
	glLineWidth(20.0f - i); //width of the lines, dynamically decreases in size
	glColor3f(0.6, 0.3, 0.1); //color of trunk
	glDisable(GL_LIGHTING); //this makes tree trunk have correct color but messes up lighting?
	glBegin(GL_LINES);
	glVertex2f((GLfloat)CP.getX(), (GLfloat)CP.getY());
	glVertex2f((GLfloat)x, (GLfloat)y); //draw the line
	glEnd();
	CP.set(x, y); //update current point to new point
	glFlush();
	i += 0.01f; //update iteration
	glEnable(GL_LIGHTING);
}

void turnTo(float angle) { CD = angle; }
void turn(float angle) { CD += angle; }
void forward(float dist, int isVisible)
{
	const float rpd = 0.017453393;
	float x1 = CP.x + dist * cos(rpd * CD);
	float y1 = CP.y + dist * sin(rpd * CD);
	if (isVisible)
		lineTo(x1, y1);
	else
		moveTo(x1, y1);
}

void saveTurtle()
{
	saveTut[curr].set(CP.x, CP.y);
	saveAng[curr] = CD;
	curr++;
}

void restoreTurtle()
{
	curr--;
	moveTo(saveTut[curr].getX(), saveTut[curr].getY());
	turnTo(saveAng[curr]);
}


void drawLeaf()
{
	if (colorChange) { //it is spring
		glColor3f(0 + c, 1, 0); //green
		glPointSize(7);
		glBegin(GL_POLYGON); //drawing actual leaf!
		glVertex2f(CP.x, CP.y); //start, bottom

		glVertex2f(CP.x + 4.0, CP.y + 3.0); // middle bottom right
		glVertex2f(CP.x + 6.0, CP.y + 9.0); // middle right
		glVertex2f(CP.x + 4.0, CP.y + 14.0); // middle top right
		glVertex2f(CP.x, CP.y + 20.0); // top
		glVertex2f(CP.x - 4.0, CP.y + 14.0); // middle top left
		glVertex2f(CP.x - 6.0, CP.y + 9.0); //middle left
		glVertex2f(CP.x - 4.0, CP.y + 3.0); // middle bottom left
		glEnd();
	}
	else {
		//do nothing
	}

}

//Draw L-System from String--------------------------------
void produceString(char* st, int order, int draw)
{
	float sx, sy, sa;
	glLineWidth(order);

	int randNum = rand() % 100 + 1;

	while (*st != '\0')		// scan through each character
	{
		switch (*st)
		{
		case '[': saveTurtle(); break;
		case ']': restoreTurtle(); break;
		case '+': turn(-angle); break;	// right turn
		case '-': turn(angle); break;  // left turn
		case 'L': if (order <= 0) //draw a leaf
			drawLeaf();
			break;
		case 'F': if (order > 0)
			produceString(Fstr, order - 1, draw);
				  else
		{
			forward(length, draw);
			if (!draw)
			{
				if (CP.x < xmin)
					xmin = CP.x;
				if (CP.x > xmax)
					xmax = CP.x;
				if (CP.y < ymin)
					ymin = CP.y;
				if (CP.y > ymax)
					ymax = CP.y;
			}
		}
				  break;
		case 'X': if (order > 0)
			produceString(Xstr, order - 1, draw); break;
		case 'Y': if (order > 0)
			produceString(Ystr, order - 1, draw); break;
		}
		st++;
	}
}

void drawStreet() { //black street, gray side walk, line stipple yellow divider
	//street
	glPushMatrix();
	glRotatef(90.0, 2.0, 0.0, 0.0);
	glColor3f(0.5, 0.5, 0.5); //side walk gray
	glBegin(GL_POLYGON);
	glVertex3f(3.75, 1.5, 0.2);
	glVertex3f(3.75, 3.5, 0.2);
	glVertex3f(-10.0, 3.5, 0.2);
	glVertex3f(-10.0, 1.5, 0.2);
	glEnd();

	glColor3f(0.0, 0.0, 0.0); //side walk lines
	glLineWidth(2.0); //thicken the lines
	for (int i = 2.55; i > -10.0; i = i - 1.0) { // create side walk lines
		glBegin(GL_LINES); //for loop to not repeat myself
		glVertex3f(i, 1.57, 0.1);
		glVertex3f(i, 3.53, 0.1);
		glEnd();
	}

	glLineWidth(3.0); //for yellow divider on road
	glEnable(GL_LINE_STIPPLE); //enable line stipple
	glLineStipple(3, 0xFF00); //factor and pattern
	glColor3f(1.0, 1.0, 0.0); //yellow
	glBegin(GL_LINE_STRIP);
	glVertex3f(3.75, 2.5, -0.1);
	glVertex3f(-9.0, 2.5, -0.1);
	glEnd();
	glDisable(GL_LINE_STIPPLE); //side walk does not need line stipple

	glColor3f(0.0, 0.0, 0.0); // black road and
	glBegin(GL_POLYGON); //actual road
	glVertex3f(3.75, 2.0, 0.0);
	glVertex3f(3.75, 3.0, 0.0);
	glVertex3f(-9.0, 3.0, 0.0);
	glVertex3f(-9.0, 2.0, 0.0);
	glEnd();
	glPopMatrix();
}

void drawHouse(float x, float y, float z, int c) { //parameters are where house will be located
	glPushMatrix(); // building
	if (c == 1) { glColor3f(1.0, 0.0, 0.0); } // red
	else if (c == 2) { glColor3f(0.8, 0.5, 0.0); } //orange
	else { glColor3f(0.1, 0.1, 0.1); } //dark gray
	glTranslated(x + 1.0, y + 0.0, z + 0.0);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix(); //roof
	if (c == 1) { glColor3f(0.0, 1.0, 1.0); }// cyan
	else if (c == 2) { glColor3f(0.0, 0.0, 0.3); } //navy blue
	else { glColor3f(0.2, 0.2, 0.2); } //gray
	glTranslated(x + 1.0, y + 0.5, z + 0.0); //this moves the object
	glRotatef(-90.0, 1.0, 0.0, 0.0); //rotate the roof
	glutSolidCone(0.85, 1.25, 16, 8); // do all transformations BEFORE drawing object
	glPopMatrix();

	glPushMatrix(); //door 
	if (c == 1) { glColor3f(0.9, 0.5, 0.0); }// brown
	else if (c == 2) { glColor3f(0.4, 0.1, 0.4); } //magenta
	else { glColor3f(0.0, 0.2, 0.0); } //green
	glScalef(1.0, 2.5, 1.0);
	glTranslated(x + 1.0, y + -0.1, z + 0.41);
	glutSolidCube(0.2);
	glPopMatrix();

	glPushMatrix(); //walkway
	glRotatef(90.0, 2.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(x + 0.8, y + 0.45, z + 0.47);
	glVertex3f(x + 1.2, y + 0.45, z + 0.47);
	glVertex3f(x + 1.2, y + 1.5, z + 0.47);
	glVertex3f(x + 0.8, y + 1.5, z + 0.47);
	glEnd();
	glPopMatrix();
}

void drawSnowman(float x, float y, float z) { //snowmen during the winter
	if (colorChange == true) { //draw a wide green bush if spring
		glPushMatrix();
		glColor3f(0.0, 0.6, 0.0);
		glTranslated(x, y, z);
		glutSolidSphere(0.3, 9, 10); //bush
		glColor3f(0.0, 0.0, 0.0);
		glPopMatrix();
	}
	else { //draw the snowman
		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); //white
		glTranslated(x, y, z);
		glutSolidSphere(0.25, 10, 10); //base
		glTranslated(0.0, 0.3, 0.0);
		glutSolidSphere(0.15, 10, 10); //mid
		glTranslated(0.0, 0.2, 0.0);
		glutSolidSphere(0.10, 10, 10); //head
		glTranslated(0.1, 0.0, 0.0);
		glColor3f(1.0, 0.7, 0.0); //orange
		glRotatef(90.0, 0.0, 2.0, 0.0);
		glutSolidCone(0.025, 0.1, 10, 10); // nose
		glTranslated(0.05, 0.05, -0.03);
		glColor3f(0.0, 0.0, 0.0); //black
		glutSolidSphere(0.025, 10, 10); //right eye
		glTranslated(-0.1, 0.0, 0.0);
		glutSolidSphere(0.025, 10, 10); //left eye
		glTranslated(0.01, 0.075, -0.02);
		glColor3f(1.0, 1.0, 1.0);
		glRotatef(90.0, 2.0, 0.0, 0.0);
		glutSolidTorus(0.02, 0.08, 15, 15); //santa hat bottom
		glColor3f(1.0, 0.0, 0.0);
		glRotatef(-180.0, 0.0, 0.0, 0.0);
		glutSolidCone(0.09, 0.21, 10, 10); //red part of hat
		glColor3f(1.0, 1.0, 1.0);
		glTranslated(0.0, 0.0, 0.2);
		glutSolidSphere(0.04, 10, 10); //white tip of hat
		glPopMatrix();
	}
}

void drawGround() { //simply the white or green ground
	glPushMatrix();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	if (colorChange == true) {
		glColor3f(0.0, 1.0, 0.0);
	}
	else {
		glColor3f(1.0, 1.0, 1.0);
	}
	glBegin(GL_POLYGON);
	glVertex3f(-11.0, 4.0, 0.50);
	glVertex3f(3.0, 4.0, 0.50);
	glVertex3f(3.0, -8.0, 0.50);
	glVertex3f(-11.0, -8.0, 0.50);
	glEnd();
	glPopMatrix();
}

void drawPond() {
	if (pondColorChange == true) {
		//outer pond 
		glPushMatrix();
		glColor3f(0.59, 0.29, 0.0);
		glTranslated(-2.5, -0.1, -4.5);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glutSolidTorus(0.03f, 2.00f, 32, 32);
		glPopMatrix();

		//inner pond 
		glPushMatrix();
		float ltheta;
		glColor3f(0.0, 0.41, 0.58);
		glRotatef(90.0, 2.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++) {
			ltheta = i * 3.142 / 180;
			glVertex3f(-2.5 + 2.0 * cos(ltheta), -4.5 + 2.0 * sin(ltheta), 0.1);
		}
		glEnd();
		glPopMatrix();
	}
	else {
		//outer pond 
		glPushMatrix();
		glColor3f(0.59, 0.29, 0.0);
		glTranslated(-2.5, -0.1, -4.5);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glutSolidTorus(0.03f, 2.00f, 32, 32);
		glPopMatrix();

		//inner pond 
		glPushMatrix();
		float ltheta;
		glColor3f(0.8, 0.92, 0.94);
		glRotatef(90.0, 2.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++) {
			ltheta = i * 3.142 / 180;
			glVertex3f(-2.5 + 2.0 * cos(ltheta), -4.5 + 2.0 * sin(ltheta), 0.1);
		}
		glEnd();
		glPopMatrix();
	}
}

void drawBoat() {
	if (colorChange == false) {
		//winter there will be no boats drawn
	}
	else {
		//base
		glPushMatrix();
		glColor3f(0.8, 0.0, 0.9);
		//glRotated(25.0, 0.0, 1.0, 0.0);
		glTranslated(-2.8, -1.1, -0.9);
		glBegin(GL_POLYGON);
		glVertex3f(0.0, 1.5, -2.5);
		glVertex3f(1.5, 1.5, -2.5);
		glVertex3f(1.2, 1.2, -2.5);
		glVertex3f(0.3, 1.2, -2.5);
		/*glVertex3f(-0.5, 0.5, -2.5);
		glVertex3f(0.4, 0.5, -2.5);
		glVertex3f(1.2, 1.1, -2.5);
		glVertex3f(-0.9, 1.1, -2.5);*/
		glEnd();
		glPopMatrix();

		//flagpole
		glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);
		glTranslated(-2.0, -0.6, -0.9);
		glBegin(GL_POLYGON);
		glVertex3f(0.0, 1.72, -2.5);
		glVertex3f(0.1, 1.72, -2.5);
		glVertex3f(0.1, 1.0, -2.5);
		glVertex3f(0.0, 1.0, -2.5);
		glEnd();
		glPopMatrix();

		//flag
		glPushMatrix();
		glColor3f(1.0, 1.0, 0.0);
		glTranslated(-1.95, 0.75, -0.85);
		glBegin(GL_TRIANGLES);
		glVertex3f(0.0, 0.4, -2.5);
		glVertex3f(0.0, 0.0, -2.5);
		glVertex3f(0.3, 0.2, -2.5);
		glEnd();
		glPopMatrix();
	}
}

void display() {

	CP.set(0, 0);
	/* clear window */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/* future matrix manipulations should affect the modelview matrix */
	glMatrixMode(GL_MODELVIEW);

	/* define the viewing transformation */
	//Moving this from MAIN to DISPLAY allows the menu to properly function
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz); // eyeX,Y,Z, centerX,Y,Z, upX,Y,Z. Def mess with this for unique perspective

	/* draw scene */

	drawPond();

	drawBoat();

	drawGround();

	//street
	drawStreet();

	drawHouse(0.0, 0.0, 0.0, 1);
	drawHouse(-3.0, 0.0, 0.0, 2);
	drawHouse(-6.7, 0.0, 0.0, 3);

	drawSnowman(2.0, 0.0, 1.0);
	drawSnowman(-2.5, 0.0, 1.2);

	if (drawTree) {
		//draw first to determine window coordinates
		moveTo(0.0, 0.0);
		turnTo(90);
		produceString(atom, 4, 0);
		gluOrtho2D(xmin - 10, xmax + 10, ymin - 10, ymax + 10);

		i = 0.0; // I being defined here keeps the tree trunk thick even after redraw
		//this time draw the curve
		glTranslatef(0, 1.0, 5.0);
		moveTo(-2200.0, 250.0);
		turnTo(90);
		produceString(atom, 4, 1);
	}
	

	glEnable(GL_COLOR_MATERIAL); //add color
	glEnable(GL_LIGHTING); //enables lighting
	glEnable(GL_LIGHT0); //enable two light sources
	glEnable(GL_LIGHT1);

	//positioned light
	GLfloat light0[] = { 0.7, 0.7, 0.7, 1.0 }; //intensity r,g,b. mild white
	GLfloat pos0[] = { 2.0, 2.0, 0.0, 1.0 }; //x,y,z. top right of scene for winter
	if (colorChange) { //spring, make sun on top left
		pos0[0] = -16.0;
		pos0[1] = 7.0;
		pos0[2] = 6.0;
	}
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0); //place color of first light
	glLightfv(GL_LIGHT0, GL_POSITION, pos0); //place position of first light

	//directed light
	GLfloat light1[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat pos1[] = { 4.0, 2.0, 0.0, 0.0 }; // gives block shading 
	if (colorChange) { //spring, make sun on top left
		pos1[0] = -4.0;
		pos1[1] = 3.0;
		pos1[2] = 0.0;
	}
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1);
	glLightfv(GL_LIGHT1, GL_POSITION, pos1);

	//change bckg color, not working ********************
	//if (colorChange) { //spring
	glClearColor(0.53, 0.81, 0.92, 1.0); // sky blue background
//}
//else {
//	glClearColor(0.01, 0.01, 0.1, 1.0);
//}

/* flush drawing routines to the window */
	glFlush();
}

void reshape(int width, int height) {
	/* define the viewport transformation */
	glViewport(0, 0, width, height);
}

void myMenu(int value) { //submenu for season
	switch (value) {
	case 6: //draw the tree
		if (drawTree) {
			drawTree = false;
		}
		else {
			drawTree = true;
		}
		break;

	case 7: //quit program
		exit(0);
		break;
	}
	
	glutPostRedisplay();
}

void perspective(int value) {
	switch (value) {
	case 1: //perspective 1
		eyex = 4.2;
		eyey = 5.0;
		eyez = 5.0;
		centerx = -1.1;
		centery = 0.0;
		centerz = 0.0;
		upx = 0.0;
		upy = 1.0;
		upz = 0.0;
		break;
	case 2: //perspective 2
		eyex = 0.0;
		eyey = 3.0;
		eyez = 10.0;
		centerx = -2.0;
		centery = 1.0;
		centerz = 0.0;
		upx = 0.0;
		upy = 6.0;
		upz = 0.0;
		break;
	case 3: //perspective 3 *****************************
		eyex = 6.5;
		eyey = 2.4;
		eyez = 3.0;
		centerx = -7.1;
		centery = -1.0;
		centerz = 0.0;
		upx = 0.0;
		upy = 1.0;
		upz = 0.0;
		break;
	}
	glutPostRedisplay();
}

void season(int value) {
	switch (value) {
	case 4: //change to spring default winter
		colorChange = true;
		pondColorChange = true;
		break;
	case 5: //winter, default
		colorChange = false;
		pondColorChange = false;
		break;
	}
}

int main(int argc, char* argv[]) {
	/* initialize GLUT, using any commandline parameters passed to the
	program */
	glutInit(&argc, argv);
	/* setup the size, position, and display mode for new windows */
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
	/* create and set up a window */
	glutCreateWindow("Project 2");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	//menu
	static int submenuid, submenuid2;
	submenuid = glutCreateMenu(perspective); //first submenu created
	glutAddMenuEntry("Default", 1); //first sub menu options
	glutAddMenuEntry("House", 2);
	glutAddMenuEntry("Street", 3);
	submenuid2 = glutCreateMenu(season); //second sub menu created
	glutAddMenuEntry("Spring", 4);
	glutAddMenuEntry("Winter", 5);
	glutCreateMenu(myMenu); //the main menu
	glutAddSubMenu("Alter Perspective", submenuid); //first submenu
	glutAddSubMenu("Change Season", submenuid2);
	glutAddMenuEntry("Toggle Tree", 6);
	glutAddMenuEntry("Quit", 7);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	/* set up depth-buffering */
	glEnable(GL_DEPTH_TEST);
	/* turn on default lighting */
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	/* define the projection transformation */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40, 1, 4, 20);

	/* tell GLUT to wait for events */
	glutMainLoop();
	return 0;
}