#include "bird.h"
#include "gameconf.h"

#include <iostream>

Bird::Bird(int t) : type(t){

    y = -ground;
    x = ground;

    jump_force = 20;
    velocity = 0;
    radius = 5;

    std::cout << "Bird created.\n" ;
}

void Bird::draw(){

    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLES);
        glVertex3f(x, y+radius, 0);
        glVertex3f(x-15, y+radius+5, 0);
        glVertex3f(x, y-radius, 0);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex3f(x, y+radius, 0);
        glVertex3f(x+15, y+radius+5, 0);
        glVertex3f(x, y-radius, 0);
    glEnd();

}

void Bird::run(){
    
}

void Bird::jump(){
    velocity += -gravity * jump_force;
}

void Bird::update(){
    velocity += gravity;
    y += velocity;

    if(y > height/2){
        y = height/2 - radius;
        velocity = 0;
    }

    if(y <= ground){
        y = ground;
        velocity = 1;
    }
}