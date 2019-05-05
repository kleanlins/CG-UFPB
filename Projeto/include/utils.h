#ifndef _UTILS_H_
#define _UTILS_H_

#include "gameconf.h"

void drawAxis(){
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(width/2, 0, 0);
    glEnd();

    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(0, width/2, 0);
    glEnd();

    glColor3f(0, 0, 1);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, width/2);
    glEnd();
}

void drawEnvironment(){
    // SKY
    glColor3f(0, 0.8, 1);
    glBegin(GL_QUADS);
        glVertex3f(-width/2, 300, 0);
        glVertex3f(-width/2, ground, 0);
        glVertex3f(width/2, ground, 0);
        glVertex3f(width/2, 300, 0);
    glEnd();

    // GROUND
    glColor3f(0.5, 0.3, 0.1);
    glBegin(GL_QUADS);
        glVertex3f(-width/2, ground, 0);
        glVertex3f(-width/2, -300, 0);
        glVertex3f(width/2, -300, 0);
        glVertex3f(width/2, ground, 0);
    glEnd();

    // CLOUDS
    int h = 0;
    int sum = 2;
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
        glVertex3f(-width/2, ground, 0);
        glVertex3f(-width/2, -80, 0);
        for(int i = -width/2; i <= width; i++){
            if(h >= 30){
                sum = -3;
            }
            if(h <= 0){
                sum = 3;
            }
                
            glVertex3f(i, -80 + h, 0);
            h += sum;
        }
        glVertex3f(width/2, ground, 0);
    glEnd();

    // GRASS
    glColor3f(0.1, 0.5, 0.1);
    glBegin(GL_POLYGON);
        glVertex3f(width/2, ground, 0);
        for(int i = width/2; i >= -width/2; i--){
            h = std::rand() % 30;   
            glVertex3f(i, ground + 20 + h, 0);
        }
        glVertex3f(-width/2, ground + 20, 0);
        glVertex3f(-width/2, ground, 0);
    glEnd();

    
}

void renderBitmap(float x, float y, void *font, char *string){
    char *c;
    glRasterPos2f(x, y);
    for(char *c=string; *c != '\0'; c++)
        glutBitmapCharacter(font, *c);
}

#endif // _UTILS_H_