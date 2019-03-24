#include <GL/glut.h>
#include <stdio.h>

void SOMETHING();

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cleanderson Lins");

    glutDisplayFunc(SOMETHING);
    glutMainLoop();
}

void SOMETHING(){

    glClearColor(1,0,0,1);              // COR DE LIMPEZA DA TELA
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,100.0,0.0,100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3d(0,0,0);

    //UPPER BODY
    glBegin(GL_POLYGON);

        glVertex2i(48,65); //left top
        glVertex2i(43,57); //left
        glVertex2i(43,50); //left bottom
        glVertex2i(57,50); //right bottom
        glVertex2i(57,57); //right 
        glVertex2i(52,65); //right top

    glEnd();

    glFlush();

}