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

void triangle(GLfloat *a, GLfloat *b, GLfloat *c)
{
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
}

void draw_triangle(GLfloat *a, GLfloat *b, GLfloat *c,int k)
{
    GLfloat v0[2],v1[2],v2[2];
    int j;
    if(k>0){
        for(j=0;j<2;j++) v0[j]=(a[j]+b[j])/2;
        for(j=0;j<2;j++) v1[j]=(a[j]+c[j])/2;
        for(j=0;j<2;j++) v2[j]=(b[j]+c[j])/2;
        draw_triangle(a,v0,v1,k-1);
        draw_triangle(c,v1,v2,k-1);
        draw_triangle(b,v2,v0,k-1);
    }
    else triangle(a,b,c);
}

void display()
{
    GLfloat a[2]={1.0,1.0};
    GLfloat b[2]={6.0,1.0};
    GLfloat c[2]={3.5,5.0};

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
      draw_triangle(a,b,c,4);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Seirpenski Gasket 2D recursive");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
    return 0;
}

