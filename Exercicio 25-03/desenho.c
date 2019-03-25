#include <GL/glut.h>
#include <stdio.h>

void SOMETHING();

int angle = 10;
int run = 0;

void arrowsAction(int key, int x, int y);

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cleanderson Lins");

    glutSpecialFunc(arrowsAction);

    glutDisplayFunc(SOMETHING);
    glutMainLoop();
}

void SOMETHING(){

    glClearColor(0,0,0,1);              // COR DE LIMPEZA DA TELA
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100.0,100.0,-100.0,100.0);

    glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    glColor3d(1,1,1);

    if(run != 0){
        glPopMatrix();
        glLoadIdentity();
    }

    glRotated(angle, 0, 0, 1);
    glBegin(GL_POLYGON);
        glVertex2i(10,70); //left top
        glVertex2i(10,10); //left bottom
        glVertex2i(70,10); //right bottom
        glVertex2i(70,70); //right top
    glEnd();

    glPushMatrix();
    run++;

    glFlush();
}

void arrowsAction(int key, int x, int y){
    switch(key){
        case GLUT_KEY_UP:
            glutPostRedisplay();
            break;
    }
}