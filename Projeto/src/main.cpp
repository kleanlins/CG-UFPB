#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <thread>
#include "utils.h"

// user made models
#include "gameconf.h"
#include "skater.h"
#include "obstacle.h"

Skater skater(1);
Obstacle obstacle(200);
Obstacle obstacle2(328);
Obstacle obstacle3(456);

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    drawAxis();

    skater.draw();
    obstacle.draw();
    obstacle2.draw();
    obstacle3.draw();
    
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
    obstacle2.move();
    obstacle3.move();
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