#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

class Obstacle{
public:
    
    int position;
    int width, height;

    Obstacle(int p):
        position(p),
        width(40){}

    void draw();
    void move();
    void reset();

};

#endif // _OBSTACLE_H_