#ifndef _SKATER_H_
#define _SKATER_H_

#include "GL/glut.h"

class Skater {
private:
    int type; // selects one of the three available skater types
    float x, y;

    float jump_force;
    float velocity;
    float radius;

public:
    Skater(int t);

    void draw();
    void run();
    void jump();

    void update();
};

#endif // _SKATER_H_