#include <GL/glut.h>
#include <stdio.h>

int firstRun = 1;
int depthEnabled = 1;
int lightEnabled = 1;

GLfloat teapot_spec[] = {1.0, 1.0, 1.0, 1.0};
GLfloat teapot_dif[] = {1.0, 0.0, 0.0, 1.0};

GLfloat luz_posicao[] = {700.0, 0.0, 0.0, 1.0};
GLfloat luz_difusa[] = {1.0, 0.0, 1.0, 1.0};
GLfloat luz_ambiente[] = {1.0, 0.0, 1.0, 1.0};
GLfloat luz_especular[] = {1.0, 0.0, 1.0, 1.0};

GLfloat luz_posicao2[] = {0.0, 700.0, 0.0, 1.0};
GLfloat luz_difusa2[] = {1.0, 1.0, 1.0, 1.0};
GLfloat luz_ambiente2[] = {1.0, 1.0, 1.0, 1.0};
GLfloat luz_especular2[] = {1.0, 1.0, 1.0, 1.0};


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

    glViewport(0, 0, 800, 800);
    glOrtho(-100.0,100.0,-100.0,100.0, -100, 100);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glRotated(10, 1, 0, 0);

    glLightfv(GL_LIGHT0, GL_POSITION, luz_posicao);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luz_difusa);
    glLightfv(GL_LIGHT0, GL_AMBIENT, luz_ambiente);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luz_especular);

    glLightfv(GL_LIGHT1, GL_POSITION, luz_posicao2);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, luz_difusa2);
    glLightfv(GL_LIGHT1, GL_AMBIENT, luz_ambiente2);
    glLightfv(GL_LIGHT2, GL_SPECULAR, luz_especular2);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    drawAxis();

    if(firstRun){
        glClearDepth(1.0f);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
        glDepthFunc(GL_LEQUAL);
        glRotated(90, 1, 0, 0);
        firstRun = 0;
    }

    // PLOT SUN
    glPopMatrix();
    glMaterialfv(GL_FRONT, GL_SPECULAR, teapot_spec);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, teapot_dif);
    glColor3d(1,1,1);
    glutSolidTeapot(40);

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
                glDisable(GL_DEPTH);
				glutPostRedisplay();
			}
			else{
				depthEnabled = 1;
                glEnable(GL_DEPTH);
				glutPostRedisplay();
			}
            break;
        case 'l':
        case 'L':
            if(lightEnabled){
                lightEnabled = 0;
                glDisable(GL_LIGHTING);
            }else{
                lightEnabled = 1;
                glEnable(GL_LIGHTING);
            }
            glutPostRedisplay();
            break;
        case 'q':
            exit(1);
            break;
	}
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Cleanderson Lins");

    glutDisplayFunc(renderSomething);

    glutSpecialFunc(arrowsAction);
	glutKeyboardFunc(keysAction);

    glutMainLoop();
}