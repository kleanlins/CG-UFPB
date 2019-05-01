#include "GL/glut.h"
#include <ctime>
#include <iostream>

#include "gameconf.h"
#include "obstacle.h"

Obstacle::Obstacle():
    x(200),
    w(10),
    ht(100){
        y = 100;
        speed = 2;
        srand( time(NULL) );
    }

void Obstacle::draw(){
    glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(x-w, ground, 0);
        glVertex3f(x-w, ground+ht, 0);
        glVertex3f(x+w, ground+ht, 0);
        glVertex3f(x+w, ground, 0);
    glEnd();
}

void Obstacle::move(){
    x -= speed;
    if(x < -(width/2) - w/2){
        reset();
    }
}

void Obstacle::reset(){
    x = width/2;
    do{
        ht = std::rand() % (200);
    }while(ht < 5);
    std::cout << "obstacle height: " << ht << std::endl;
}