#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

void myInit()
{
     glClearColor(1.0, 1.0, 1.0, 1.0);

     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);	// set viewing volume to 2 X 2 X 2
     glMatrixMode(GL_MODELVIEW);
}

void triangle(GLfloat *a, GLfloat *b, GLfloat *c)
{
       glVertex3fv(a);		// draw triangle using vertices a, b, c
       glVertex3fv(b);
       glVertex3fv(c);

}
void draw_triangle(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d)
{
       glColor3f(1.0, 0.0, 0.0);	// assign color for each of the side
       triangle(a, b, c);			// draw triangle between a, b, c
       glColor3f(0.0, 1.0, 0.0);
       triangle(a, b, d);
       glColor3f(0.0, 0.0, 1.0);
       triangle(a, d, c);
       glColor3f(1.0, 0.0, 1.0);
       triangle(d, b, c);
}

void draw_tetrahedra(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d, int k)
{
     int j;
     GLfloat ab[3], bc[3], ac[3], ad[3], bd[3], cd[3];	// mid-points of tetrahedron

     if(k>0)
     {
            for(j=0;j<3;j++) ab[j] = (a[j] + b[j])/2.0;// calculate mid-point between a and b
            for(j=0;j<3;j++) bc[j] = (b[j] + c[j])/2.0;	// calculate mid-point between b and c
            for(j=0;j<3;j++) ac[j] = (a[j] + c[j])/2.0;// calculate mid-point between a and c
            for(j=0;j<3;j++) ad[j] = (a[j] + d[j])/2.0;	// calculate mid-point between a and d
            for(j=0;j<3;j++) bd[j] = (b[j] + d[j])/2.0;	// calculate mid-point between b and d
            for(j=0;j<3;j++) cd[j] = (c[j] + d[j])/2.0; // calculate mid-point between c and d

            draw_tetrahedra(a, ab, ac, ad, k-1); // draw tetrahedra between points a, ab, ac, ad
            draw_tetrahedra(ab, b, bc, bd, k-1); // draw tetrahedra between points ab, b, bc, bd
            draw_tetrahedra(ac, bc, c, cd, k-1); // draw tetrahedra between points ac, bc, c, cd
            draw_tetrahedra(ad, bd, cd, d, k-1); // draw tetrahedra between points ad, bd, cd, d
     }
     else
     {
         draw_triangle(a,b,c,d);	// draw tetrahedra between points a, b, c, d
     }
}

void display()
{
     GLfloat a[3] = {-1.0, -1.0, -1.0}, // co-ordinates in 3D geometry
             b[3] = { 1.0, -1.0, -1.0},
             c[3] = { 0.0,  1.0, -1.0},
             d[3] = { 0.0,  0.0,  1.0};

     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// clear color buffer and depth buffer for HSR

    //glRotatef(0.05, 1.0, 1.0, 1.0);
     glBegin(GL_TRIANGLES);
       draw_tetrahedra(a, b, c, d, 2);
     glEnd();
     glFlush();
}

void idle(void) {
    glRotatef(0.1, 1.0, 1.0, 0.0);
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH );	// use GLUT_DEPTH if HSR is being used
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("3D Sierpinski Gasket");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    myInit();

    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
return 0;
}
