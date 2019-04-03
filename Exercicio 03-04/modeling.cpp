#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <iostream>

int firstRun = 1;
int leftOrRight = 0;
int upOrDown = 0;
int cube;

struct coordinate{
    float x, y, z;
    coordinate(float a, float b, float c):
    x(a), y(b), z(c){}
};

struct face{
    int facenum;
    bool four;
    int faces[4];
    face(int facen, int f1, int f2, int f3):
    facenum(facen){
        faces[0] = f1;
        faces[1] = f2;
        faces[2] = f3;
        four = false;
    }
    face(int facen, int f1, int f2, int f3, int f4):
    facenum(facen){
        faces[0] = f1;
        faces[1] = f2;
        faces[2] = f3;
        faces[3] = f4;
        four = true;
    }
};

int loadObject(const char *filename){
    std::vector<std::string *> coord;
    std::vector<coordinate *> vertex;
    std::vector<face *> faces;
    std::vector<coordinate *> normals;

    std::ifstream in(filename);
    if(!in.is_open()){
        std::cout << "File coudn't be opened." << std::endl;
        return -1;
    }

    // pushes every file line into coord vector
    char buff[256];
    while(!in.eof()){
        in.getline(buff, 256);
        coord.push_back(new std::string(buff));
    }

    for(int i = 0; i < coord.size(); i++){
        if(coord[i]->c_str()[0] == '#')
            continue;
        // if it's just a vertex
        else if(coord[i]->c_str()[0] == 'v' && coord[i]->c_str()[1] == ' '){  
            float temp_x, temp_y, temp_z;
            sscanf(coord[i]->c_str(), "v %f %f %f", &temp_x, &temp_y, &temp_z);
            vertex.push_back(new coordinate(temp_x, temp_y, temp_z));
        // if it's a normal
        }else if(coord[i]->c_str()[0] == 'v' && coord[i]->c_str()[1] == 'n'){ 
            float temp_x, temp_y, temp_z;
            sscanf(coord[i]->c_str(), "vn %f %f %f", &temp_x, &temp_y, &temp_z);
            normals.push_back(new coordinate(temp_x, temp_y, temp_z));
        // if it's a face
        }else if(coord[i]->c_str()[0] == 'f'){                                
            int a, b, c, d, e;
            if(std::count(coord[i]->begin(), coord[i]->end(), ' ') == 3){
                sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
                faces.push_back(new face(b,a,c,d));
            }else{
                sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
                faces.push_back(new face(b,a,c,d,e));
            }
        }
    }

    int listNumber;
    listNumber = glGenLists(1);

    glNewList(listNumber, GL_COMPILE);
        for(int i = 0; i < faces.size(); i++){
            if(faces[i]->four){
                glBegin(GL_QUADS);
                    glNormal3f(normals[faces[i]->facenum-1]->x,
                    normals[faces[i]->facenum-1]->y, 
                    normals[faces[i]->facenum-1]->z);

                    // draw the face
                    glVertex3f(vertex[faces[i]->faces[0]-1]->x,
                    vertex[faces[i]->faces[0]-1]->y,
                    vertex[faces[i]->faces[0]-1]->z);

                    glVertex3f(vertex[faces[i]->faces[1]-1]->x,
                    vertex[faces[i]->faces[1]-1]->y,
                    vertex[faces[i]->faces[1]-1]->z);

                    glVertex3f(vertex[faces[i]->faces[2]-1]->x,
                    vertex[faces[i]->faces[2]-1]->y,
                    vertex[faces[i]->faces[2]-1]->z);

                    glVertex3f(vertex[faces[i]->faces[3]-1]->x,
                    vertex[faces[i]->faces[3]-1]->y,
                    vertex[faces[i]->faces[3]-1]->z);
                glEnd();
            }else{
                glBegin(GL_TRIANGLES);
                    glNormal3f(normals[faces[i]->facenum-1]->x,
                    normals[faces[i]->facenum-1]->y, 
                    normals[faces[i]->facenum-1]->z);

                    // draw the face
                    glVertex3f(vertex[faces[i]->faces[0]-1]->x,
                    vertex[faces[i]->faces[0]-1]->y,
                    vertex[faces[i]->faces[0]-1]->z);

                    glVertex3f(vertex[faces[i]->faces[1]-1]->x,
                    vertex[faces[i]->faces[1]-1]->y,
                    vertex[faces[i]->faces[1]-1]->z);

                    glVertex3f(vertex[faces[i]->faces[2]-1]->x,
                    vertex[faces[i]->faces[2]-1]->y,
                    vertex[faces[i]->faces[2]-1]->z);
                glEnd();
            }
        }
    glEndList();    
    // free memory
    for(int i = 0; i < coord.size(); i++)
        delete coord[i];
    for(int i = 0; i < normals.size(); i++)
        delete normals[i];
    for(int i = 0; i < faces.size(); i++)
        delete faces[i];
    for(int i = 0; i < vertex.size(); i++)
        delete vertex[i];

    return listNumber;
}

void init(){
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(20,1280.0/720.0,1.0,500.0);
    // glOrtho(-100.0,100.0,-100.0,100.0, -100, 100);
    // glFrustum(500, 500, 500, 500, 10, 100);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);

    cube = loadObject("cube.obj");

    glEnable(GL_LIGHTING);  // enabling light
    glEnable(GL_LIGHT0);

    float col[]={1.0,1.0,1.0,1.0};  // light color
    glLightfv(GL_LIGHT0,GL_DIFFUSE,col);

}

void renderSomething(){
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    float pos[]={-1.0,1.0,-2.0,1.0}; // light position
    glLightfv(GL_LIGHT0,GL_POSITION,pos);

    glTranslatef(0.0,0.0,-10.0);
    glRotated(leftOrRight, 0, 0, 1);

    if(upOrDown){
        glRotated(upOrDown, 0, 1, 0);
        upOrDown = 0;
    }

    glCallList(cube); // finally draws the cube

    glFlush();
}

void arrowsAction(int key, int x, int y){
    switch(key){
        case GLUT_KEY_RIGHT:
            leftOrRight = 5;
            glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:
            leftOrRight = -5;
            glutPostRedisplay();
            break;
        case GLUT_KEY_UP:
            upOrDown = 10;
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            upOrDown = -10;
            glutPostRedisplay();
            break;
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cleanderson Lins");

    init();
    glutDisplayFunc(renderSomething);
    glutSpecialFunc(arrowsAction);

    glutMainLoop();
}