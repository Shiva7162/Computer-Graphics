#include<stdio.h>
#include<GL/glut.h>

void myInit() {
 glClearColor(1.0, 1.0, 1.0, 1.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
}

void display() {
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3d(0,0,0);
 glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0,0.0);
    glVertex2f(0.0,3.0);
    glVertex2f(2.0,3.0);
    glColor3d(0,0,1.0);
    glVertex2f(3.0,2.0);
    glColor3d(0,1.0,0);
    glVertex2f(3.50,.50);
    glColor3d(1.0,0,0);
    glVertex2f(3.0,-1.0);
    glColor3d(1.0,1.0,0);
    glVertex2f(2.0,-2.0);
    glColor3d(1.0,0,1.0);
    glVertex2f(0.0,-2.50);
    glColor3d(0.0,1.0,1.0);
    glVertex2f(-2.0,-2.0);
 glEnd();
 glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Triangle Strip");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
    return 0;
}

