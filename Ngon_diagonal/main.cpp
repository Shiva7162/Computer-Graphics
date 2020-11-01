#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

void myInit()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(1.0,0.0,0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-25,25,-25,25);
    glMatrixMode(GL_MODELVIEW);
}
void ngon(int N){
float theta;
    int i,j;
    GLfloat x[N],y[N];
    theta = 360.0/N;
    for(i=0;i<N;i++){
            x[i]=25*cos(i*theta*3.142/180.0);
            y[i]=25*sin(i*theta*3.142/180.0);
    }
    for(i=0;i<N-1;i++){
        glBegin(GL_LINE_LOOP);
        for(j=i+1;j<N;j++){
                glVertex2f(x[i],y[i]);
                glVertex2f(x[j],y[j]);
            }
    }

    glEnd();
    glFlush();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
        ngon(5);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("N-gon");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
    return 0;
}

