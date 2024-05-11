#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;
void simple_line(){
	int x1,x2,Y1,y2;
	cout<<"Enter value for 1st coordinate : \n";
	cin>>x1>>Y1;
	cout<<"Enter value for 2nd coordinate : \n";
	cin>>x2>>y2;
	
	int dx,dy,e,x,y,i;
	dx=x2-x1;
	dy=y2-Y1;
	e=(2*dy)-dx;
	x=x1;
	y=Y1;
	glBegin(GL_POINTS);
	glColor3f(1,0,0);
	glVertex2i(x,y);
	i=0;
	while(i<dx){
		while(e>=0){
			y=y+1;
			e=e-(2*dx);
		}
		x=x+1;
		e=e+(2*dy);
		
		glVertex2i(x,y);
		
		i++;
	}
	glEnd();
	
}
void dotted_line(){
	int x1,x2,Y1,y2;
	cout<<"Enter value for 1st coordinate : \n";
	cin>>x1>>Y1;
	cout<<"Enter value for 2nd coordinate : \n";
	cin>>x2>>y2;
	
	int dx,dy,e,x,y,i;
	dx=x2-x1;
	dy=y2-Y1;
	e=(2*dy)-dx;
	x=x1;
	y=Y1;
	glBegin(GL_POINTS);
	glColor3f(1,0,0);
	glVertex2i(x,y);
	i=0;
	while(i<dx){
		while(e>=0){
			y=y+1;
			e=e-(2*dx);
		}
		x=x+1;
		e=e+(2*dy);
		if(i%5==0){
			glVertex2i(x,y);
		}
		i++;
	}
	glEnd();
	
}
void dashed_line(){
	int x1,x2,Y1,y2;
	cout<<"Enter value for 1st coordinate : \n";
	cin>>x1>>Y1;
	cout<<"Enter value for 2nd coordinate : \n";
	cin>>x2>>y2;
	
	int dx,dy,e,x,y,i;
	dx=x2-x1;
	dy=y2-Y1;
	e=(2*dy)-dx;
	x=x1;
	y=Y1;
	glBegin(GL_POINTS);
	glColor3f(1,0,0);
	glVertex2i(x,y);
	i=0;
	while(i<dx){
		while(e>=0){
			y=y+1;
			e=e-(2*dx);
		}
		x=x+1;
		e=e+(2*dy);
		if(i%5!=0){
			glVertex2i(x,y);
		}
		i++;
	}
	glEnd();
	
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	cout<<"simple line\n";
	simple_line();
	cout<<"dotted line\n";
	dotted_line();
	cout<<"dashed line \n";
	dashed_line();
	glFlush();
}

void init(){ 
glClearColor(1.0,1.0,1.0,1.0);
glMatrixMode(GL_PROJECTION);
glPointSize(5);
glLoadIdentity();
gluOrtho2D(-100,100,-100,100);
}


int main(int argc,char **argv){
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("dda");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
    return 0;
}
