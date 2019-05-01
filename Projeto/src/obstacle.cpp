#include "GL/glut.h"

#include "gameconf.h"
#include "obstacle.h"

Obstacle::Obstacle():
    x(200),
    w(10),
    h(50){
        y = 100;
        speed = 2;
    }

void Obstacle::draw(){
    glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(x-w, ground, 0);
        glVertex3f(x-w, h, 0);
        glVertex3f(x+w, h, 0);
        glVertex3f(x+w, ground, 0);
    glEnd();
}

void Obstacle::move(){
    x -= speed;
    if(x < -(width/2) - w/2){
        x = width/2;
    }
}

void Obstacle::reset(){
    
}