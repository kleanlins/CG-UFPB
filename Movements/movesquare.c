#include <GL/glut.h>
#include <stdio.h>

void graphics();
void keybindings(unsigned char key, int x, int y);
void arrowsAction(int key, int x, int y);
void mouseAction(int button, int state, int x, int y);

const int sizeX = 500;
const int sizeY = 500;

int posX = 250;
int posY = 250;

const int speed = 5;

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(sizeX, sizeY);
    glutCreateWindow("Esta funcionando!");

    glutSpecialFunc(arrowsAction);
    glutMouseFunc(mouseAction);

    glutDisplayFunc(graphics);
    glutMainLoop();
}

void graphics(){

    glClearColor(1,0,0,1);              // COR DE LIMPEZA DA TELA
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,(float)sizeX,0.0,(float)sizeY);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3d(0,0,0);

    //UPPER BODY
    glPointSize(10);
    glBegin(GL_POLYGON);
        glVertex2i(posX-10,posY+10); //left top
        glVertex2i(posX-10,posY-10);//left bottom
        glVertex2i(posX+10,posY-10); //right bottom
        glVertex2i(posX+10,posY+10); //right top
    glEnd();

    glFlush();

}

void keybindings(unsigned char key, int x, int y){
    switch(key){
        case 'w':
            posY++;
            printf("%d\n", posY);
            break;
    }
}

void arrowsAction(int key, int x, int y){
    switch(key){
        case GLUT_KEY_UP:
            posY += speed;
            printf("%d\n", posY);
            break;
        case GLUT_KEY_LEFT:
            posX -= speed;
            break;
        case GLUT_KEY_DOWN:
            posY -= speed;
            break;
        case GLUT_KEY_RIGHT:
            posX += speed;
            break;
    }
    glutPostRedisplay();
}

void mouseAction(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON){ 
        switch (state){
            case GLUT_UP:
                // printf("x: %d -- y: %d", x, y);
                posX = x;
                posY = sizeY - y;
                printf("X:%d Y:%d\n", posX, posY);
                break;
        }
    }
    glutPostRedisplay();
}