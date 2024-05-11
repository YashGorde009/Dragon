#include<iostream>
#include<stdlib.h>
#include<GL/glut.h>

#define s 0.86602540

using namespace std;

int n;

void display(void);
void koch(int, int, int, int, int);
void init(void);


int main(int argc, char** argv)
{
    cout << "Enter level of curve generation : ";
    cin >> n;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(650, 650);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Koch Curve");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0); //to specify the color to clear the color buffer, the alpha component, which controls the transparency of the color. Here, it's set to 1.0, indicating fully opaque.
    glColor3f(1.0, 1.0, 1.0); // sets the current drawing color to white.
    gluOrtho2D(0.0, 650.0, 650.0, 0.0); // 2D orthographic projection with the specified viewport size
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    int x1 = 0, x2 = 550, y1 = 200, y2 = 200; // specify line segment
    koch(x1, y1, x2, y2, n); 
    glFlush(); // ensure that all drawing commands are executed and their results are displayed on the screen without delay.
}
void koch(int x1, int y1, int x2, int y2, int n)
{
    // array banv, coordinates assign kar, lxly find kar, use kar 2 ways madhe ani mg 1, 3 assign kar, nivin variable banv values assign kar ani use kar
    int x[5], y[5];

    x[0] = x1;
    y[0] = y1;
    x[4] = x2;
    y[4] = y2;

    int lx = (x2 - x1) / 3;
    int ly = (y2 - y1) / 3;

    x[1] = x[0] + lx;
    y[1] = y[0] + ly;

    x[3] = x[0] + (2*lx);
    y[3] = y[0] + (2*ly);

    int xx = x[3] - x[1];
    int yy = y[3] - y[1];

    x[2] = x[1] + (xx * (0.5) + yy * s);
    y[2] = y[1] + (yy * (0.5) - xx * s); 

    if(n > 0)
    {
        koch(x[0], y[0], x[1], y[1], n - 1);
        koch(x[1], y[1], x[2], y[2], n - 1);
        koch(x[2], y[2], x[3], y[3], n - 1);
        koch(x[3], y[3], x[4], y[4], n - 1);
    }
    else
    {
        glBegin(GL_LINES); // you're telling OpenGL that you're about to specify a series of vertices that define individual line segments
        glVertex2d(x[0], y[0]);
        glVertex2d(x[1], y[1]);
        glEnd();

        glBegin(GL_LINES); // you're telling OpenGL that you're about to specify a series of vertices that define individual line segments
        glVertex2d(x[1], y[1]);
        glVertex2d(x[2], y[2]);
        glEnd();

        glBegin(GL_LINES); // you're telling OpenGL that you're about to specify a series of vertices that define individual line segments
        glVertex2d(x[2], y[2]);
        glVertex2d(x[3], y[3]);
        glEnd();

        glBegin(GL_LINES); // you're telling OpenGL that you're about to specify a series of vertices that define individual line segments
        glVertex2d(x[3], y[3]);
        glVertex2d(x[4], y[4]);
        glEnd();

        glFlush();
    }
}


// The koch function implements the Koch curve generation algorithm, which is a fractal curve with self-similarity properties. Here's a step-by-step explanation of the algorithm used in the koch function:

// Define the initial line segment: The function takes as input four coordinates (x1, y1) and (x2, y2) representing the endpoints of the initial line segment.
// Divide the line segment: Divide the initial line segment into three equal parts. This is done by finding the midpoints of the line segment:
// x[0], y[0] represent the starting point of the segment.
// x[1], y[1] represent the first third of the segment.
// x[2], y[2] represent the midpoint of the segment.
// x[3], y[3] represent the last third of the segment.
// x[4], y[4] represent the ending point of the segment.
// Calculate the coordinates of the new points: Use the midpoints and trigonometric calculations to find the coordinates of two additional points (x[2], y[2]) that form an equilateral triangle with the segment.
// Calculate the vector between x[1], y[1] and x[3], y[3].
// Rotate this vector by 60 degrees (π/3 radians) counterclockwise.
// Add the rotated vector to x[1], y[1] to get x[2], y[2].
// Recursively generate segments: If the recursion depth n is greater than 0, recursively apply the Koch curve generation algorithm to the four smaller line segments:
// koch(x[0], y[0], x[1], y[1], n - 1)
// koch(x[1], y[1], x[2], y[2], n - 1)
// koch(x[2], y[2], x[3], y[3], n - 1)
// koch(x[3], y[3], x[4], y[4], n - 1)
// Draw the line segments: If the recursion depth n is 0, draw the four line segments using glBegin(GL_LINES) and glEnd(). Each segment is drawn between consecutive points x[i], y[i] and x[i+1], y[i+1].
// By recursively applying this algorithm to each line segment, the Koch curve is generated. The depth of recursion n controls the level of detail or resolution of the curve. Higher values of n result in more iterations of the algorithm and a more detailed curve.










