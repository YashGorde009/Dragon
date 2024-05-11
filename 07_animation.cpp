#include<iostream>
#include<stdlib.h>
#include<GL/glut.h>

using namespace std;

float rt = 0.0f;
float ballX = -0.5f;
float ballY = 0.0f;
float ballZ = 0.0f;

void init (int, int);
void draw(void);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Animation");
    glutDisplayFunc(draw);
    glutIdleFunc(draw); // sets the function Draw() as the idle callback function which means Draw() function will be called repeatedly to update the display
    init(640, 480);
    glutMainLoop();
    return 0;
}


void init (int width, int height)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION); // is used to specify which matrix stack is the target for subsequent matrix operations. texture matrix stack, Projection matrix stack and Modelview matrix stack
    gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 50.0f); // sets up a perspective projection matrix with a specified field of view, aspect ratio, and clipping planes and Far clipping plane distance, allowing for realistic rendering of 3D scenes
    glMatrixMode(GL_MODELVIEW); //  used to specify that subsequent matrix operations will affect the modelview matrix stack.
}


void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // is used to clear the color buffer and the depth buffer.
    glLoadIdentity(); // replaces the current matrix with the identity matrix.
    glTranslatef(rt, 0.0f, -6.0f); // glTranslatef(x, y, z), translate the coordinate system by (x, y, z)

    glBegin(GL_POLYGON); // define the vertices of a polygon

    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f(0.4f, 1.0f, 0.0f);
    glVertex3f(1.0f, 0.4f, 0.0f);

    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(-1.0f, 0.0f, 0.0f);

    glEnd(); // function call marks the end of the sequence of vertices

    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(ballX,ballY,ballZ); // apply a translation transformation to the current matrix. 
    glutSolidSphere (0.3, 20, 20); // glutSolidSphere(radius, slices, stacks) is used to render a solid sphere 
    glTranslatef(ballX+1.5,ballY,ballZ);
    glutSolidSphere (0.3, 20, 20);

    rt+=0.005f;

    if(rt>2)
        rt=-2.0f;

    glutSwapBuffers(); //  to swap the front and back buffers of the current window.
}



