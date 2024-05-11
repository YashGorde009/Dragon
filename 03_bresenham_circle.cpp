#include<iostream>
#include<stdlib.h>
#include<GL/glut.h>

using namespace std;

int xc = 340, yc = 210;

void init(void);
void display(void);
void bresenham_circle(int);
void plot_point(int, int);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham_circle");
	glutDisplayFunc(display);
	init();
    glutMainLoop();
	return 0;
}

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void display(void)
{
	int radius = 50;
	glClear(GL_COLOR_BUFFER_BIT);
	bresenham_circle(radius);
}

void bresenham_circle(int r)
{
	int x = 0, y = r; 
	float d = 3 - 2 * r;

	plot_point(x, y);

	while(x < y)
	{
		x += 1;
		
		if(d < 0)
		{
			d += 4 * x  + 6;
		}
		else
		{	
			y -= 1;
			d += 4 * (x - y) + 10;
		}

		plot_point(x, y);
	}

	glFlush();
}

void plot_point(int x, int y)
{
	glBegin(GL_POINTS);

	glVertex2i(xc + x, yc + y);
	glVertex2i(xc + y, yc + x);

	glVertex2i(xc - x, yc - y);
	glVertex2i(xc - y, yc - x);

	glVertex2i(xc + x, yc - y);
	glVertex2i(xc - y, yc + x);

	glVertex2i(xc - x, yc + y);
	glVertex2i(xc + y, yc - x);

	glEnd();
}
