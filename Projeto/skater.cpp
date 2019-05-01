#include "skater.h"
#include "gameconf.h"

#include <iostream>

Skater::Skater(int t) : type(t){

    y = ground;
    x = -130;

    jump_force = 15;
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
    velocity += -gravity * jump_force;
}

void Skater::update(){
    velocity += gravity;
    y += velocity;

    if(y > height/2){
        y = height/2 - radius;
        velocity = 0;
    }

    std::cout << y << " " << velocity << std::endl;    

    if(y <= ground){
        y = ground;
        velocity = 1;
    }
}