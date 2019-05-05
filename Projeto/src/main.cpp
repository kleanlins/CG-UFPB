#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "utils.h"

// user made models
#include "gameconf.h"
#include "bird.h"
#include "obstacle.h"

int points = 0;

Bird bird(1);
Obstacle obstacle(200);
Obstacle obstacle2(200 + (385/3));
Obstacle obstacle3(200 + (385/3)*2);

void init(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-width/2, width/2, -height/2, height/2, -1.0, 0.0);
}

// update treats all calculus data and updates the entities.
void update(){
    bird.update();
    obstacle.move(points);
    obstacle2.move(points);
    obstacle3.move(points);

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
            // std::cout << "JUMP\n";
            bird.jump();
            glutIdleFunc(update);
            break;
        case 'q':
            exit(0);
    }
}

void score(){
    glColor3f(1, 1, 1);
    char buf[100] = {0};
    sprintf(buf, std::to_string(points).c_str());
    renderBitmap(170, 280, GLUT_BITMAP_TIMES_ROMAN_24, buf);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    // drawAxis();
    drawEnvironment();

    bird.draw();
    obstacle.draw();
    obstacle2.draw();
    obstacle3.draw();

    score();
    
    glFlush();
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