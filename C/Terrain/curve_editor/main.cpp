// g++ main.cpp -lglut -lGL
#include <iostream>
#include <cstdlib>
#include <GL/glut.h>
#include "CurveEditor.h"


using namespace std;

Path p;

void renderScene(void) {
    
    glClear(GL_COLOR_BUFFER_BIT);
    
	glColor3f(1.0f, 1.0f, 1.0f);
    
    //p.draw();
    
    glutSwapBuffers();
}

int main(int argc, char **argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(640,480);
    glutCreateWindow("CurveEditor");
    
    glutDisplayFunc(renderScene);
    
    glutMainLoop();
    
    return 1;
}
