#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>

// user made models
#include "frog.h"
#include "obstacle.h"

// global variables
int width = 400;
int height = 600;

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

    glClearColor(1, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100, -100.0, 100, -1.0, 0.0);

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
    gluOrtho2D(0.0, 100, 0.0, 100);
}

void redisplay(){
    glRotated(0.1, 0, 1, 0);
}


void keyboard(unsigned char k, int x, int y){
    switch(k){
        case 's':
            glRotated(30, 0, 0, 1);
            std::cout << "pressed " << k << "\n";
            glutPostRedisplay();
    }
}

int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_SINGLE );
    glutInitWindowSize(width, height);
    glutInitWindowPosition(300,100);
    glutCreateWindow("Froggy");
    //init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

}