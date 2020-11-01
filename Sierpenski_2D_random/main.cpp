#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

void myInit()
{
     glClearColor(1.0, 1.0, 1.0, 1.0);
     glColor3f(0.0, 0.0, 1.0);

     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0, 10.0, 0.0, 10.0);
     glMatrixMode(GL_MODELVIEW);
}

void display( void )
{
     float v[3][2] = {{0.0, 0.0},
                      {10.0, 0.0},
                      {5.0, 10.0}}; // Assign co-ordinates to draw 3 points for triangle
     float p[2] = {5.5, 7.5};       // Take an initial point
     int j, i;

     glClear(GL_COLOR_BUFFER_BIT);
     glBegin(GL_POINTS);
     for(i=0; i<50000; i++)
     {
              j=rand()%3;                // Select a vertex randomly in each iteration
              p[0]=(p[0] + v[j][0])/2.0; // Compute the mid-point between P and selected vertex
              p[1]=(p[1] + v[j][1])/2.0; // Compute the mid-point between P and selected vertex

              glVertex2fv(p);            // Display this point on the screen
     }
     glEnd();
     glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Sierpinski Gasket 2D random");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
return 0;
}

