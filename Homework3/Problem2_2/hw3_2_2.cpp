//CSC 470	Homework 3_2_2
// Vincenzo Mezzio Vincent Loretta Joseph DeMario
#include <stdio.h>   // use as needed for your system
#include <math.h>
#include <GL/glut.h>
#define getrandom(min, max) ((rand()%(int)(((max) + 1)-(min)))+ (min))

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

//string production rules
char atom[25] = "F";                      //starting string
char Fstr[30] = "FF-[-FX+FX+FX]+[+FX-FX-FX]";//F production rule, L draws the leaf
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
	glBegin(GL_LINES);
	glColor3f(0.4, 0.2, 0.0); //color of trunk
	glVertex2f((GLfloat)CP.getX(), (GLfloat)CP.getY());
	glVertex2f((GLfloat)x, (GLfloat)y); //draw the line
	glEnd();
	CP.set(x, y); //update current point to new point
	glFlush();
	i += 0.01f; //update iteration
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

//draw red apple function
void drawRedApple()
{
	float ltheta;
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		ltheta = i * 3.142 / 180;
		glVertex2f(CP.x + 7 * cos(ltheta), CP.y + 7 * sin(ltheta));
	}
	glEnd();
}

void drawOranges()
{
	float ltheta;
	glColor3f(1.0, 0.95, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		ltheta = i * 3.142 / 180;
		glVertex2f(CP.x + 7 * cos(ltheta), CP.y + 7 * sin(ltheta));
	}
	glEnd();
}

void drawLemons()
{
	float ltheta;
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		ltheta = i * 3.142 / 180;
		glVertex2f(CP.x + 7 * cos(ltheta), CP.y + 7 * sin(ltheta));
	}
	glEnd();
}

//draw flower function
void drawFlower()
{
	float ltheta;
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		ltheta = i * 3.142 / 180;
		glVertex2f(CP.x + 3 * cos(ltheta), CP.y + 3 * sin(ltheta));
	}
	glEnd();

	//top flower petal
	float toptheta;
	glColor3f(1.0, 0.36, 0.83);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		toptheta = i * 3.142 / 180;
		glVertex2f(CP.x + 7 * cos(toptheta), (10 + CP.y) + 20 * sin(toptheta));
	}
	glEnd();

	//bottom flower petal
	float bottomtheta;
	glColor3f(1.0, 0.36, 0.83);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		bottomtheta = i * 3.142 / 180;
		glVertex2f(CP.x + 7 * cos(bottomtheta), (-20 + CP.y) + 7 * sin(bottomtheta));
	}
	glEnd();

	//left flower petal
	float lefttheta;
	glColor3f(1.0, 0.36, 0.83);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		lefttheta = i * 3.142 / 180;
		glVertex2f((-20 + CP.x) + 7 * cos(lefttheta), CP.y + 7 * sin(lefttheta));
	}
	glEnd();

	//right flower petal
	float righttheta;
	glColor3f(1.0, 0.36, 0.83);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		righttheta = i * 3.142 / 180;
		glVertex2f((20 + CP.x) + 7 * cos(righttheta), CP.y + 7 * sin(righttheta));
	}
	glEnd();
}

//draw leaf function
void drawLeaf()
{
	glColor3f(0.9, 0.6, 0); //orange leaf
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
			if (randNum % 2 == 0) {
				drawRedApple();
			}
			else if (randNum % 3 == 0) {
				drawOranges();
			}
			else if (randNum % 4 == 0) {
				drawLemons();
			}
			else {
				drawLeaf();
			}
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

void drawKoch(double dir, double len, int n)
{
	double dirRad = 0.0174533 * dir;
	// in radians
	if (n == 0)
		forward(len, 1);
	else {
		n--;// reduce the order
		len /= 3;// and the length
		drawKoch(dir, len, n);
		dir += 60;
		turnTo(dir);
		drawKoch(dir, len, n);
		dir -= 120;
		turnTo(dir);
		drawKoch(dir, len, n);
		dir += 60;
		turnTo(dir);
		drawKoch(dir, len, n);
	}
}


//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	CP.set(0, 0);
	glClearColor(1.0, 0.65, 0.0, 0.3); //background color, light orange
	//glClearColor(0.9, 0.7, 0.0, 0.1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 0);
	glLineWidth(10.0f);

	//background
	glColor3f(1.0, 0.1, 0.0); //interpolation red
	glBegin(GL_POLYGON);
		glVertex3f(-1.0, 1.0, 0.0); //top left
		glVertex3f(1.0, 1.0, 0.0); //top right
		glColor3f(1.0, 0.65, 0.0); //orange
		glVertex3f(1.0, -0.5, 0.0); //bottom right
		glVertex3f(-1.0, -0.5, 0.0); //bottom left
	glEnd();

	//sun
	glColor3f(1.0, 1.0, 1.0);
	float ltheta;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		ltheta = i * 3.142 / 180;
		glVertex2f(0.00 + 0.22 * cos(ltheta), -0.2 + 0.22 * sin(ltheta));
		glColor3f(1.0, 1.0, 1.0/ltheta);
	}
	glEnd();

	//grass 
	glColor3f(0.5, 0.4, 0.0); //redish orange
	glBegin(GL_POLYGON); //grass
		glVertex3f(-1.0, -1.0, 0.0); //top left
		glVertex3f(1.0, -1.0, 0.0); //top right
		glColor3f(0.0, 0.6, 0.0); // green, color interpolation
		glVertex3f(1.0, -0.5, 0.0); //bottom right
		glVertex3f(-1.0, -0.5, 0.0); //bottom left
	glEnd();

	//Middle Flower
	//Stem
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.22, -0.79, 0.0);
	glVertex3f(-0.24, -0.81, 0.0);
	glVertex3f(-0.22, -0.87, 0.0);
	glVertex3f(-0.24, -0.87, 0.0);
	glEnd();
	//middle petal
	//float ltheta;
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		ltheta = i * 3.142 / 180;
		glVertex2f(-0.25 + 0.02 * cos(ltheta), -0.75 + 0.02 * sin(ltheta));
	}
	glEnd();
	//top flower petal
	float toptheta;
	glColor3f(1.0, 0.36, 0.83);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		toptheta = i * 3.142 / 180;
		glVertex2f(-0.25 + 0.025 * cos(toptheta), -0.71 + 0.025 * sin(toptheta));
	}
	glEnd();
	//bottom flower petal
	float bottomtheta;
	glColor3f(1.0, 0.36, 0.83);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		bottomtheta = i * 3.142 / 180;
		glVertex2f(-0.25 + 0.025 * cos(bottomtheta), -0.79 + 0.025 * sin(bottomtheta));
	}
	glEnd();
	//right flower petal
	float lefttheta;
	glColor3f(1.0, 0.36, 0.83);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		lefttheta = i * 3.142 / 180;
		glVertex2f(-0.21 + 0.025 * cos(lefttheta), -0.75 + 0.025 * sin(lefttheta));
	}
	glEnd();
	//left flower petal
	float righttheta;
	glColor3f(1.0, 0.36, 0.83);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		righttheta = i * 3.142 / 180;
		glVertex2f(-0.29 + 0.025 * cos(righttheta), -0.75 + 0.025 * sin(righttheta));
	}
	glEnd();

	//Left Flower
	//Stem
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.82, -0.79, 0.0);
	glVertex3f(-0.84, -0.81, 0.0);
	glVertex3f(-0.82, -0.87, 0.0);
	glVertex3f(-0.84, -0.87, 0.0);
	glEnd();
	//middle petal
	//float ltheta = 0.0;
	glColor3f(0.4, 0.2, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		ltheta = i * 3.142 / 180;
		glVertex2f(-0.85 + 0.02 * cos(ltheta), -0.75 + 0.02 * sin(ltheta));
	}
	glEnd();
	//top flower petal
	//float toptheta = 0.0;
	glColor3f(0.9, 0.9, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		toptheta = i * 3.142 / 180;
		glVertex2f(-0.85 + 0.025 * cos(toptheta), -0.71 + 0.025 * sin(toptheta));
	}
	glEnd();
	//bottom flower petal
	//float bottomtheta = 0.0;
	//glColor3f(1.0, 0.36, 0.83);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		bottomtheta = i * 3.142 / 180;
		glVertex2f(-0.85 + 0.025 * cos(bottomtheta), -0.79 + 0.025 * sin(bottomtheta));
	}
	glEnd();
	//right flower petal
	//float lefttheta = 0.0;
	//glColor3f(1.0, 0.36, 0.83);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		lefttheta = i * 3.142 / 180;
		glVertex2f(-0.81 + 0.025 * cos(lefttheta), -0.75 + 0.025 * sin(lefttheta));
	}
	glEnd();
	//left flower petal
	//float righttheta = 0.0;
	//glColor3f(1.0, 0.36, 0.83);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		righttheta = i * 3.142 / 180;
		glVertex2f(-0.89 + 0.025 * cos(righttheta), -0.75 + 0.025 * sin(righttheta));
	}
	glEnd();


	//Right Flower
	//Stem
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.31, -0.82, 0.0);
	glVertex3f(0.29, -0.84, 0.0);
	glVertex3f(0.31, -0.90, 0.0);
	glVertex3f(0.29, -0.90, 0.0);
	glEnd();
	float theta1;
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		theta1 = i * 3.142 / 180;
		glVertex2f(0.30 + 0.02 * cos(theta1), -0.78 + 0.02 * sin(theta1));
	}
	glEnd();
	//top flower petal
	float ttheta;
	glColor3f(0.68, 0.85, 0.90);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		ttheta = i * 3.142 / 180;
		glVertex2f(0.30 + 0.025 * cos(ttheta), -0.74 + 0.025 * sin(ttheta));
	}
	glEnd();
	//bottom flower petal
	float btheta;
	glColor3f(0.68, 0.85, 0.90);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		btheta = i * 3.142 / 180;
		glVertex2f(0.30 + 0.025 * cos(btheta), -0.82 + 0.025 * sin(btheta));
	}
	glEnd();
	//right flower petal
	float rftheta;
	glColor3f(0.68, 0.85, 0.90);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		rftheta = i * 3.142 / 180;
		glVertex2f(0.34 + 0.025 * cos(rftheta), -0.78 + 0.025 * sin(rftheta));
	}
	glEnd();
	//left flower petal
	float lftheta;
	glColor3f(0.68, 0.85, 0.90);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		lftheta = i * 3.142 / 180;
		glVertex2f(0.26 + 0.025 * cos(lftheta), -0.78 + 0.025 * sin(lftheta));
	}
	glEnd();

	//Last Flower
	//Stem
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.79, -0.81, 0.0);
	glVertex3f(0.81, -0.84, 0.0);
	glVertex3f(0.79, -0.89, 0.0);
	glVertex3f(0.81, -0.89, 0.0);
	glEnd();
	float m;
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		m = i * 3.142 / 180;
		glVertex2f(0.80 + 0.02 * cos(m), -0.78 + 0.02 * sin(m));
	}
	glEnd();
	//top flower petal
	float t;
	glColor3f(0.60, 0.28, 0.17);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		t = i * 3.142 / 180;
		glVertex2f(0.80 + 0.025 * cos(t), -0.74 + 0.025 * sin(t));
	}
	glEnd();
	//bottom flower petal
	float b;
	glColor3f(0.60, 0.28, 0.17);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		b = i * 3.142 / 180;
		glVertex2f(0.80 + 0.025 * cos(b), -0.82 + 0.025 * sin(b));
	}
	glEnd();
	//right flower petal
	float r;
	glColor3f(0.60, 0.28, 0.17);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		r = i * 3.142 / 180;
		glVertex2f(0.76 + 0.025 * cos(r), -0.78 + 0.025 * sin(r));
	}
	glEnd();
	//left flower petal
	float l;
	glColor3f(0.60, 0.28, 0.17);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++) {
		l = i * 3.142 / 180;
		glVertex2f(0.84 + 0.025 * cos(l), -0.78 + 0.025 * sin(l));
	}
	glEnd();



	 //fractal mountains in the background
	glBegin(GL_TRIANGLES); //fractal mountain left cutoff
		glColor3f(0.4, 0.4, 0.4); //dark grey
		glVertex3f(-1.9, -0.5, 0.0);
		glVertex3f(-1.4, 0.4, 0.0);
		glVertex3f(-0.9, -0.5, 0.0);
	glEnd();
	glBegin(GL_TRIANGLES); //fractal mountain left
		glColor3f(0.3, 0.3, 0.3); //dark grey
		glVertex3f(-1.0, -0.5, 0.0);
		glVertex3f(-0.5, 0.4, 0.0);
		glColor3f(0.5, 0.5, 0.5); //lighter grey
		glVertex3f(0.0, -0.5, 0.0);
	glEnd();
	glBegin(GL_TRIANGLES); //fractal mountain middle
		glColor3f(0.6, 0.6, 0.6); //light grey
		glVertex3f(-0.4, -0.5, 0.0);
		glVertex3f(-0.1, 0.6, 0.0);
		glColor3f(0.4, 0.4, 0.4); //darker grey
		glVertex3f(0.2, -0.5, 0.0);
	glEnd();
	glBegin(GL_TRIANGLES); //fractal mountain right
		glColor3f(0.5, 0.5, 0.5); //light grey
		glVertex3f(0.2, -0.5, 0.0);
		glColor3f(0.7, 0.7, 0.7); //ligher grey
		glVertex3f(0.5, 0.2, 0.0);
		glVertex3f(0.9, -0.5, 0.0);
	glEnd();
	glBegin(GL_TRIANGLES); //fractal mountain right cutoff
		glColor3f(0.3, 0.3, 0.3); //dark grey
		glVertex3f(0.8, -0.5, 0.0);
		glVertex3f(1.2, 0.2, 0.0);
		glColor3f(0.1, 0.1, 0.1); //darker grey
		glVertex3f(1.6, -0.5, 0.0);
	glEnd();


	//setup initial turtle position
	//run through once to determine window coordinates
	moveTo(0.0, 0.0);
	turnTo(90);
	produceString(atom, 4, 0);
	gluOrtho2D(xmin - 10, xmax + 10, ymin - 10, ymax + 10);

	i = 11.5; // I being defined here keeps the tree trunk thick even after redraw
	//this time draw the curve, first tree, right side
	moveTo(170.0, 100.0);
	turnTo(90);
	produceString(atom, 3, 5); //same with editing third parameter
	i = 13.0;
	angle = getrandom(20, 25);

	//second tree, middle
	moveTo(-100.0, 100.0);
	turnTo(90);
	produceString(atom, 3, 5);
	i = 15.0;
	angle = getrandom(30, 40);

	//third tree, left side
	moveTo(-350.0, 100.0);
	turnTo(90);
	produceString(atom, 3, 5);

	moveTo(0.0, 200.0);
	turnTo(90);
	glColor3f(0.0, 0.0, 1.0);
	drawKoch(45.0, 50, 10.0); //fractal has not been working

	glFlush();		                 // send all output to display
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(600, 600);     // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("L-System Tree 3_2_2"); // open the screen window and set the name
	glutDisplayFunc(myDisplay);     // register redraw function
	glutMainLoop();
	//return 1; //prevents running the code
}
