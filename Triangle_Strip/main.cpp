#include<stdio.h>
#include<GL/glut.h>

void myInit()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0,0.0,0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,10.0,0.0,10.0);
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.0);
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(1.0,1.0);
        glVertex2f(4.0,1.0);
        glVertex2f(2.5,4.0);
        glColor3f(0.0,1.0,0.0);
        glVertex2f(1.0,1.0);
        glVertex2f(2.5,4.0);
        glVertex2f(5.5,4.0);
        glColor3f(0.0,0.0,1.0);
        glVertex2f(5.5,4.0);
        glVertex2f(4.0,1.0);
        glVertex2f(7.0,1.0);
        //glColor3f(0.0,1.0,1.0);
        //glVertex2f(9.0,9.0);
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

