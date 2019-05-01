#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

class Obstacle{
private:
    int position;
    int w, h;

public:
    Obstacle(int p);

    void draw();
    void move();
    void reset();
};

#endif // _OBSTACLE_H_