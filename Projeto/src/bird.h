#ifndef _BIRD_H_
#define _BIRD_H_

#include "GL/glut.h"

class Bird {
private:
    int type; // selects one of the three available Bird types

    float jump_force;
    float velocity;
    float radius;

public:
    float x, y;

    Bird(int t);

    void draw();
    void run();
    void jump();

    void update();
};

#endif // _BIRD_H_