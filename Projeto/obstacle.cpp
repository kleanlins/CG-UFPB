#include "GL/glut.h"

#include "gameconf.h"
#include "obstacle.h"

Obstacle::Obstacle():
    x(200),
    w(40),
    h(100){
        y = 100;
        speed = 10;
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



}

void Obstacle::reset(){
    
}