#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>

// user made models
#include "frog.h"
#include "obstacle.h"

// performance metrics
int fps = 60;

// main variables
int width = 400;
int height = 600;

Frog frog(1);
Obstacle obstacle(width);

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


void display(){

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    drawAxis();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex2d(40, 40);
        glVertex2d(40, 70);
        glVertex2d(70, 40);
    glEnd();
    
    glFlush();
}

void init(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-width/2, width/2, -height/2, height/2, -1.0, 0.0);
}

// redisplay makes the screen update itself after a predefined time.
void redisplay(){
    glRotated(0.1, 0, 0, 1);
    glutPostRedisplay();
}

void keyboard(unsigned char k, int x, int y){
    switch(k){
        case 's':
            glutIdleFunc(redisplay);
            break;
        case 'q':
            exit(0);
    }
}

int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_SINGLE );
    glutInitWindowSize(width, height);
    glutInitWindowPosition(300,100);
    glutCreateWindow("Froggy");
    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

}