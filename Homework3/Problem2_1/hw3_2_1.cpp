//CSC 470	Homework 3_2_1
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

//string production rules
char atom[25] = "F";                      //starting string
char Fstr[30] = "FF-[-FX+FX+FX]L+[+FX-FX-FX]L";//F production rule, L draws the leaf
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
	glColor3f(0.6, 0.3, 0.1); //color of trunk
	glVertex2f((GLfloat)CP.getX(), (GLfloat)CP.getY());
	glVertex2f((GLfloat)x, (GLfloat)y); //draw the line
	glEnd();
	CP.set(x, y); //update current point to new point
	glFlush();
	i += 0.005f; //update iteration
}

void turnTo(float angle) { CD = angle; }
void turn(float angle) { CD += angle; }
void forward(float dist, int isVisible)
{
	const float rpd = 0.017453393;
	float x1 = CP.x + dist * cos(rpd*CD);
	float y1 = CP.y + dist * sin(rpd*CD);
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

//draw leaf function
void drawLeaf()
{
	glColor3f(0.1, 0.9, 0); //green
	glPointSize(7);
	glBegin(GL_POLYGON); //drawing actual leaf!
		glVertex2f(CP.x, CP.y); //start, bottom

		glVertex2f(CP.x+4.0, CP.y+3.0); // middle bottom right
		glVertex2f(CP.x+6.0, CP.y+9.0); // middle right
		glVertex2f(CP.x+4.0, CP.y+14.0); // middle top right
		glVertex2f(CP.x, CP.y+20.0); // top
		glVertex2f(CP.x-4.0, CP.y+14.0); // middle top left
		glVertex2f(CP.x-6.0, CP.y+9.0); //middle left
		glVertex2f(CP.x-4.0, CP.y+3.0); // middle bottom left
	glEnd();
}

//Draw L-System from String--------------------------------
void produceString(char *st, int order, int draw)
{
	float sx, sy, sa;
	glLineWidth(order);

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


//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	CP.set(0, 0);
	glClearColor(0.0, 0.0, 0.2, 0.3); //background color, dark blue
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 0);
	glLineWidth(10.0f);

	//setup initial turtle position
	//run through once to determine window coordinates
	moveTo(0.0, 0.0);
	turnTo(90);
	produceString(atom, 4, 0); //4,0
	gluOrtho2D(xmin - 10, xmax + 10, ymin - 10, ymax + 10);

	i = 0.0; // I being defined here keeps the tree trunk thick even after redraw
	//this time draw the curve
	moveTo(0.0, 0.0);
	turnTo(90);
	produceString(atom, 4, 1); //4,1
	glFlush();		                 // send all output to display
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set display mode
	glutInitWindowSize(600, 600);     // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("L-System Tree 3_2_1"); // open the screen window and set the name
	glutDisplayFunc(myDisplay);     // register redraw function
	glutMainLoop();
	//return 1; //prevents running the code
}