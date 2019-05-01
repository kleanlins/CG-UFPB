#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

class Obstacle{
private:
    int x, y;
    int w, h;

    int speed;

public:
    Obstacle();

    void draw();
    void move();
    void reset();
};

#endif // _OBSTACLE_H_