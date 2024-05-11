#include<iostream>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

using namespace std;

void init(void);
void world(void); // to draw the object
void mouse(int btn, int state, int x, int y); // mouse call back function
void boundary_fill(int x, int y, float* fc, float* bc);

int main(int argc, char** argv)
{
    glutInit(&argc, argv); //initialization of the GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  //to intialize the display mode
    glutInitWindowSize(640, 480);   //to set the size of the window
    glutInitWindowPosition(50, 50); //to set the position of the window
    glutCreateWindow("Boundary Fill"); //to give user defined name to the window
    glutDisplayFunc(world);  //to creat the object
    glutMouseFunc(mouse);  //glutMouseFunc sets the mouse callback for the current window.
    init();
    glutMainLoop();
    return 0;
}


void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void world(void) //  to draw the object
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(2);
    glPointSize(2);
    glBegin(GL_LINE_LOOP);
    glVertex2i(150, 100);
    glVertex2i(300, 300);
    glVertex2i(450, 100);
    glEnd();
    glFlush();
} 

void mouse(int btn, int state, int x, int y) // mouse call back function
{
    y = 480 - y;

    if(btn == GLUT_LEFT_BUTTON)
    {
        if(state == GLUT_DOWN)
        {
            float bc[] = {1.0, 0.0, 0.0};
            float fc[] = {0.0, 1.0, 0.0};
            boundary_fill(x, y, fc, bc);
        }
    }
} 
 
void boundary_fill(int x, int y, float* fc, float* bc)
{
    float color[3];
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, color); //to read the current pixel information
    if((color[0]!=bc[0] || color[1]!=bc[1] || color[2]!=bc[2]) &&(color[0]!=fc[0] || color[1]!=fc[1] || color[2]!=fc[2]))
    {
        glColor3f(fc[0], fc[1], fc[2]); //to fill the pixel by new color
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();

        boundary_fill(x + 1, y, fc, bc);
        boundary_fill(x, y + 1, fc, bc);

        boundary_fill(x - 2, y, fc, bc);
        boundary_fill(x, y - 2, fc, bc);

    }
}
