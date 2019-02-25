#include <GL/glut.h>
#include <stdio.h>

void SOMETHING();

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Esta funcionando!");

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

    //LOWER BODY
    glBegin(GL_POLYGON);

        glVertex2i(44,50); //left top
        glVertex2i(40,45); //left
        glVertex2i(45,25); //left bottom
        glVertex2i(55,25); //right bottom
        glVertex2i(60,45); //right 
        glVertex2i(56,50); //right top

    glEnd();

    //TEETH
    glBegin(GL_TRIANGLES);
        glVertex2i(54,73); //top
        glVertex2i(55,65); //left
        glVertex2i(58,68); //right
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2i(46,73); //top
        glVertex2i(42,68); //left
        glVertex2i(45,65); //right
    glEnd();


    //LEFT PAWS
    glLineWidth(10);
    glBegin(GL_LINES);
        glVertex2i(43,57);
        glVertex2i(30,58);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(30,58);
        glVertex2i(37,80);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(43,55);
        glVertex2i(25,55);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(25,55);
        glVertex2i(32,80);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(43,53);
        glVertex2i(23,43);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(23,43);
        glVertex2i(26,20);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(43,51);
        glVertex2i(37,48);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(37,48);
        glVertex2i(42,10);
    glEnd();

    //RIGHT PAWS
    glBegin(GL_LINES);
        glVertex2i(57,57);
        glVertex2i(70,58);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(70,58);
        glVertex2i(63,80);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(57,55);
        glVertex2i(75,55);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(75,55);
        glVertex2i(68,80);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(57,53);
        glVertex2i(77,43);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(77,43);
        glVertex2i(74,20);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(57,51);
        glVertex2i(63,48);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(63,48);
        glVertex2i(58,10);
    glEnd();

    glFlush();

}