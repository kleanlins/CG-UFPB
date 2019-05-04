#include "GL/glut.h"
#include <iostream>

#include "gameconf.h"
#include "obstacle.h"

Obstacle::Obstacle(int position):
    x(position),
    w(10){
        speed = 2;
        srand( position );

        r = 0, g = 1, b = 0;

        int min, max;

        min = 50;
        max = (height + ground) * 0.7;
        bottom_pipe_height = std::rand() % (max - min) + min;

        min = (height + ground) - (bottom_pipe_height + 2*difficulty[0]);
        max = (height + ground) - (bottom_pipe_height + difficulty[0]);
        upper_pipe_height = std::rand() % (max - min) + min;

    }

void Obstacle::draw(){
        
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
        glVertex3f(x-w, ground, 0);
        glVertex3f(x-w, ground+bottom_pipe_height, 0);
        glVertex3f(x+w, ground+bottom_pipe_height, 0);
        glVertex3f(x+w, ground, 0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(x-w-5, ground+bottom_pipe_height, 0);
        glVertex3f(x-w-5, ground+bottom_pipe_height-10, 0);
        glVertex3f(x+w+5, ground+bottom_pipe_height-10, 0);
        glVertex3f(x+w+5, ground+bottom_pipe_height, 0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(x-w, sky, 0);
        glVertex3f(x-w, sky-upper_pipe_height, 0);
        glVertex3f(x+w, sky-upper_pipe_height, 0);
        glVertex3f(x+w, sky, 0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3f(x-w-5, sky-upper_pipe_height, 0);
        glVertex3f(x-w-5, sky-upper_pipe_height+10, 0);
        glVertex3f(x+w+5, sky-upper_pipe_height+10, 0);
        glVertex3f(x+w+5, sky-upper_pipe_height, 0);
    glEnd();
}

void Obstacle::move(int &points){
    x -= speed;
    if(x < -(width/2) - w/2){
        points++;
        std::cout << points << std::endl;
        reset();
    }
}

void Obstacle::reset(){
    x = width/2;
    int min, max;

    min = 50;
    max = (height + ground) * 0.7;
    bottom_pipe_height = std::rand() % (max - min) + min;

    min = (height + ground) - (bottom_pipe_height + 2*difficulty[0]);
    max = (height + ground) - (bottom_pipe_height + difficulty[0]);
    upper_pipe_height = std::rand() % (max - min) + min;

    std::cout << "obstacle height: " << bottom_pipe_height << std::endl;
}

void Obstacle::collision(Bird &bird){
    if((bird.x > x-w && bird.x < x+w) // SIZES
        && (bird.y < bottom_pipe_height+ground // BOTTOM
        || bird.y > sky-upper_pipe_height)){ // TOP
            r = 1;
            g = 0;
            // std::cout << "HIT" << std::endl;
        }
    else{
            r = 0;
            g = 1;
    }
}