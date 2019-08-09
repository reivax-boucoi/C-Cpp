// g++ main.cpp -lglut -lGL
#include <iostream>
#include <cstdlib>
#include <GL/glut.h>
#include "CurveEditor.h"


using namespace std;


void renderScene(void) {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glBegin(GL_TRIANGLES);
    
    glVertex3f(-0.5,-0.5,0.0);
    glVertex3f(0.5,0.0,0.0);
    glVertex3f(0.0,0.5,0.0);
    glEnd();
    
    glutSwapBuffers();
}

int main(int argc, char **argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(640,480);
    glutCreateWindow("CurveEditor");
    
    glutDisplayFunc(renderScene);
    
    glutMainLoop();
    
    return 1;
}
