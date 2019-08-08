// g++ main.cpp -lglut -lGL
#include <iostream>
#include <cstdlib>
#include <GL/glut.h>
#include "PerlinNoise.h"

#include "Mesh.h"
#include "NoiseMap.h"
#include "Terrain.h"

using namespace std;


Mesh *m;

void changeSize(int w, int h) {
    
    if (h == 0)h = 1;
    float ratio =  w * 1.0 / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

float angle = 0.0f;

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glLoadIdentity();
    
    gluLookAt(	0.0f, 0.0f, 1.5f,
                0.0f, 0.0f,  0.0f,
               0.0f, 1.0f,  0.0f);
    
    //glRotatef(angle, 1.0f, 0.0f, 0.0f);
    
    m->draw();
    glutSwapBuffers();
}
void mouseMove(int x, int y) { 	
}

void mouseButton(int button, int state, int x, int y) {
    
}
int main(int argc, char **argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(480,320);
    glutCreateWindow("Test");
    
    m=new Mesh(5);
    m->build();
    
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
    
    glEnable(GL_DEPTH_TEST);
    
    glutMainLoop();
    
    return 1;
}
