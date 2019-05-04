#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

#include "skater.h"

class Obstacle{
private:
    int x;
    int r, g, b;
    int w, upper_pipe_height, bottom_pipe_height;

    int difficulty[3] = {100, 70, 50};

    int speed;

public:
    Obstacle(int position);

    void draw();
    void move();
    void reset();

    void collision(Skater &skater);

};

#endif // _OBSTACLE_H_