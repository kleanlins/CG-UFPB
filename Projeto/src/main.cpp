#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <thread>

// user made models
#include "gameconf.h"
#include "skater.h"
#include "obstacle.h"

Skater skater(1);
Obstacle obstacle;

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

    skater.draw();
    obstacle.draw();
    
    glFlush();
}

void init(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-width/2, width/2, -height/2, height/2, -1.0, 0.0);

}

// update makes the screen update itself after a predefined time.
void update(){
    skater.update();
    obstacle.move();
    glutPostRedisplay();
    std::this_thread::sleep_for(std::chrono::milliseconds(17));
}

void keyboard(unsigned char k, int x, int y){
    switch(k){
        case 'W':
        case 'w':
            std::cout << "JUMP\n";
            skater.jump();
            glutIdleFunc(update);
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
    glutCreateWindow("Skater");
    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
}