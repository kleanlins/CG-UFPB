#include <GL/glut.h>
#include <stdio.h>

int firstRun = 1;
int runToSide = 0;

void renderSomething(){
    
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0,100.0,-100.0,100.0, -100, 100);

    glMatrixMode(GL_MODELVIEW);

    if(firstRun){
        glRotated(90, 1, 0, 0);
        firstRun = 0;
    }

    glRotated(runToSide, 0, 0, 1);

    glColor3d(1,1,0);
    glutWireSphere(18, 10, 10);

    glTranslated(80, 0, 0);
    glColor3d(0,1,1);
    glutWireSphere(5, 10, 10);

    glTranslated(-80, 0, 0);

    glFlush();
}

void arrowsAction(int key, int x, int y){
    switch(key){
        case GLUT_KEY_RIGHT:
            runToSide = 10;
            glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:
            runToSide = -10;
            glutPostRedisplay();
            break;
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cleanderson Lins");

    glutSpecialFunc(arrowsAction);

    glutDisplayFunc(renderSomething);
    glutMainLoop();
}
