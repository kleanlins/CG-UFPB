#ifndef _FROG_H_
#define _FROG_H_

class Frog {
public:

    float scale;
    float x, y;

    Frog(float s): scale(s){
        this->x = 100 * this->scale;
        this->y = 350 * this->scale;
    }

    void draw();
    void walk();
    void jump();
    void fall();
};


#endif // _FROG_H_