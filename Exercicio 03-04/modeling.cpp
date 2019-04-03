#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <iostream>

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
        else if(coord[i]->c_str()[0] == 'v' && coord[i]->c_str()[1] == ' '){ // if it's just a vertex
            float temp_x, temp_y, temp_z;
            sscanf(coord[i]->c_str(), "v %f %f %f", &temp_x, &temp_y, &temp_z);
            vertex.push_back(new coordinate(temp_x, temp_y, temp_z));
        }else if(coord[i]->c_str()[0] == 'v' && coord[i]->c_str()[1] == 'n'){ // if it's a normal
            float temp_x, temp_y, temp_z;
            sscanf(coord[i]->c_str(), "vn %f %f %f", &temp_x, &temp_y, &temp_z);
            normals.push_back(new coordinate(temp_x, temp_y, temp_z));
        }else if(coord[i]->c_str()[0] == 'f'){ // if it's a face
            int a, b, c, d, e;
            if(std::count(coord[i]->begin(), coord[i]->end(), " ") == 3){
                sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b);
                faces.push_back(new face(b,a,c,d));
            }else{
                sscanf(coord[i]->c_str(),"f %d//%d %d//%d %d//%d %d//%d",&a,&b,&c,&b,&d,&b,&e,&b);
                faces.push_back(new face(b,a,c,d,e));
            }
        }
    }

    //free memory
    for(int i = 0; i < coord.size(); i++)
        delete coord[i];

}

void init(){
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45, 640.0/480.0, 1.0, 500.0);

    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);

    //glClearDepth(1.0f);
    //glDepthFunc(GL_LEQUAL);

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
}