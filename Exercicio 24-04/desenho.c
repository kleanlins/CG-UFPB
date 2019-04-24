#include <GL/glut.h>
#include <stdio.h>

int firstRun = 1;
int depthEnabled = 1;

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

    // LEFT VIEWPORT
    glViewport(0, 0, 500, 500);
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

    // PLOT SUN
    glColor3d(1,1,0);
    glutSolidTeapot(10);


    glFlush();
}

void arrowsAction(int key, int x, int y){
    switch(key){
        case GLUT_KEY_RIGHT:
            glRotated(10, 0, 0, 1);
            glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:
            glRotated(-10, 0, 0, 1);
            glutPostRedisplay();
            break;
        case GLUT_KEY_UP:
            glRotated(10, 0, 1, 0);
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            glRotated(-10, 0, 1, 0);
            glutPostRedisplay();
            break;
    }
}

void keysAction(unsigned char key, int x, int y){
	switch(key){
		case 'd':
        case 'D':
			if(depthEnabled){
				depthEnabled = 0;
				glutPostRedisplay();
			}
			else{
				depthEnabled = 1;
				glutPostRedisplay();
			}
            break;
        case 'q':
            exit(1);
            break;
	}
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cleanderson Lins");

    glutDisplayFunc(renderSomething);

    glutSpecialFunc(arrowsAction);
	glutKeyboardFunc(keysAction);

    glutMainLoop();
}