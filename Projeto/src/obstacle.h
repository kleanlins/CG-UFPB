#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

#include "bird.h"

class Obstacle{
private:
    int r, g, b;
    int w, upper_pipe_height, bottom_pipe_height;

    int difficulty[3] = {100, 70, 50};

    int speed;

public:
    int x;
    Obstacle(int position);

    void draw();
    void move(int &points);
    void reset();

    void collision(Bird &bird);

};

#endif // _OBSTACLE_H_