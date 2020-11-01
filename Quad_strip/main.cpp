#include<stdio.h>
#include<GL/gl.h>
#include<stdio.h>
#include<GL/glut.h>

void myInit()
{
    glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUAD_STRIP);

	glColor3d(0,0,0);

    glVertex2f(-6.0,-4.0);
    glColor3d(0,1,0);
    glVertex2f(-6.0,4.0);
    glColor3d(1,0,1);
    glVertex2f(-3.0,-3.0);
	glVertex2f(-3.0,3.0);
    glColor3d(1,0,0);
    glVertex2f(4.0,-4.0);
    glColor3d(1,1,0);
    glVertex2f(4.0,4.0);
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Quad Strip");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
    return 0;
}

