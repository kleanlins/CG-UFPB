#include <GL/glut.h>
#include <stdio.h>

int firstRun = 1;
int leftOrRight = 0;
int upOrDown = 0;

void drawAxis(){
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(100, 0, 0);
    glEnd();

    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 100, 0);
    glEnd();


    glColor3f(0, 0, 1);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 100);
    glEnd();
}

void renderSomething(){
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0,100.0,-100.0,100.0, -100, 100);

    glMatrixMode(GL_MODELVIEW);

    drawAxis();

    if(firstRun){
        glClearDepth(1.0f);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
        glRotated(90, 1, 0, 0);
        firstRun = 0;
    }

    if(upOrDown){
        glRotated(upOrDown, 0, 1, 0);
        upOrDown = 0;
    }

    glPushMatrix();
    glTranslated(80, 0, 0);
    glRotated(10, 0, 0, 1);
    // PLOT EARTH
    glColor3d(0,1,1);
    glutWireSphere(5, 10, 10);
    glTranslated(-80, 0, 0);
    
    glPopMatrix();
    glRotated(leftOrRight, 0, 0, 1);
    // PLOT SUN
    glColor3d(1,1,0);
    glutSolidSphere(18, 10, 10);

    glFlush();
}

void arrowsAction(int key, int x, int y){
    switch(key){
        case GLUT_KEY_RIGHT:
            leftOrRight = 10;
            glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:
            leftOrRight = -10;
            glutPostRedisplay();
            break;
        case GLUT_KEY_UP:
            upOrDown = 10;
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            upOrDown = -10;
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

    glutDisplayFunc(renderSomething);

    glutSpecialFunc(arrowsAction);

    glutMainLoop();
}
