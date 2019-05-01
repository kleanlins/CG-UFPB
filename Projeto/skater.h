#ifndef _SKATER_H_
#define _SKATER_H_

#include "GL/glut.h"

class Skater {
private:
    int type; // selects one of the three available skater types
    float x, y;

    int jump_force;
    int velocity;
    int radius;

    bool jumping;


public:
    Skater(int t);

    void draw();
    void run();
    void jump();

    void update();
};

#endif // _SKATER_H_