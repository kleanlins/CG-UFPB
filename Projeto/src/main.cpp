#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <thread>
#include "utils.h"

// user made models
#include "gameconf.h"
#include "bird.h"
#include "obstacle.h"

Bird bird(1);
Obstacle obstacle(200);
Obstacle obstacle2(200 + (385/3));
Obstacle obstacle3(200 + (385/3)*2);

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    drawAxis();

    bird.draw();
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

// update treats all calculus data and updates the entities.
void update(){
    bird.update();
    obstacle.move();
    obstacle2.move();
    obstacle3.move();

    obstacle.collision(bird);
    obstacle2.collision(bird);
    obstacle3.collision(bird);

    glutPostRedisplay();
    std::this_thread::sleep_for(std::chrono::milliseconds(17));
}

void keyboard(unsigned char k, int x, int y){
    switch(k){
        case 'W':
        case 'w':
            std::cout << "JUMP\n";
            bird.jump();
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
    glutCreateWindow("bird");
    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
}