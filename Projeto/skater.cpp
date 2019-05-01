#include "skater.h"
#include "gameconf.h"

#include <iostream>

Skater::Skater(int t) : type(t){

    y = 200;
    x = -130;

    jump_size = 50;
    velocity = 0;
    radius = 5;

    std::cout << "Skater created.\n" ;

}

void Skater::draw(){

    glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(x-radius, y-radius, 0);
        glVertex3f(x-radius, y+radius, 0);
        glVertex3f(x+radius, y+radius, 0);
        glVertex3f(x+radius, y-radius, 0);
    glEnd();

}

void Skater::run(){
    
}

void Skater::jump(){
    if(y > ground)
        velocity += gravity;
        y += velocity;
}

void Skater::fall(){
    
}