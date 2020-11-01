#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

void myInit()
{
     glClearColor(1.0, 1.0, 1.0, 1.0);
     glColor3f(0.0, 0.0, 1.0);

     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
     glMatrixMode(GL_MODELVIEW);
}
void idle(void) {

    glRotatef(-0.1, 1.0, 0.0, 0.0);
    glutPostRedisplay();
}

void display()
{
     GLfloat v[4][3] = {{-1.0, -1.0, -1.0},
                        { 1.0, -1.0, -1.0},
                        { 0.0,  1.0, -1.0},
                        { 0.0,  0.0,  1.0}};
     GLfloat p[3] = {-0.5, 0.5, 0.25};      // Take an initial point
     int j, i;
     glClear(GL_COLOR_BUFFER_BIT);
     glBegin(GL_POINTS);
     //glRotatef(1, 1.0, 0.0, 0.0);
     for(i=0; i<100000; i++)
     {
              j=rand()%4;                // Select a vertex randomly in each iteration
              p[0]=(p[0] + v[j][0])/2.0; // Compute the mid-point between P and selected vertex
              p[1]=(p[1] + v[j][1])/2.0; // Compute the mid-point between P and selected vertex
              p[2]=(p[2] + v[j][2])/2.0;
              glVertex3fv(p);            // Display this point on the screen
     }
     glEnd();
     glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Sierpinski Gasket 3D random");
    glutDisplayFunc(display);
    glutIdleFunc(idle);

    myInit();
    glutMainLoop();
return 0;
}
