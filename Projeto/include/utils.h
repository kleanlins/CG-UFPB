#ifndef _UTILS_H_
#define _UTILS_H_

void drawAxis(){
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(200, 0, 0);
    glEnd();

    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 200, 0);
    glEnd();

    glColor3f(0, 0, 1);
    glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 200);
    glEnd();
}

#endif // _UTILS_H_