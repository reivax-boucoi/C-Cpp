// g++ main.cpp -lglut -lGL
#include <iostream>
#include <cstdlib>
#include <GL/glut.h>
#include "PerlinNoise.h"

#include "Mesh.h"

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
    
    gluLookAt(	0.0f, 0.0f, 2.5f,
                0.0f, 0.0f,  0.0f,
               0.0f, 1.0f,  0.0f);
    
    if(glutGetWindow()==2){
        glRotatef(angle, 1.0f, 0.0f, 0.0f);
        m->draw(1);
    }else{
        m->draw(0);
    }
    
    glutSwapBuffers();
}
void renderAll(){
    glutSetWindow(2);
    renderScene();
    glutSetWindow(1);
    renderScene();
}
void mouseMove(int x, int y) {
    glutPostRedisplay();
}

void mouseButton(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON) {
        
        if (state == GLUT_UP) {
        }
        else  {// state = GLUT_DOWN
        }
    }else if (button == GLUT_LEFT_BUTTON) {
        
        if (state == GLUT_UP) {
            m->nm->toggleColorMode();
        }
        else  {// state = GLUT_DOWN
        }
    }else if(button == 3 || button == 4){//mouseScroll
        if (state == GLUT_UP) return;
        if(button == 4){
            m->nm->setScale(m->nm->getScale()/1.5f);
        }else{
            m->nm->setScale(m->nm->getScale()*1.5f);
        }
        cout<<"Scale="<<m->nm->getScale()<<endl;
    }
    glutPostRedisplay();
}
void processNormalKeys(unsigned char key, int x, int y) {
    switch(key){
        case 'a':
            angle+=10;
            break;
        case 'e':
            angle-=10;
            break;
    }
    cout << "angle:"<<angle<<endl;
    glutPostRedisplay();
}

void processSpecialKeys(int key, int x, int y) {
    const int speed=10;
    switch(key) {
        case GLUT_KEY_LEFT :
            m->nm->offsets[0]-=speed;
            break;
        case GLUT_KEY_RIGHT :
            m->nm->offsets[0]+=speed;
            break;
        case GLUT_KEY_DOWN :
            m->nm->offsets[1]-=speed;
            break;
        case GLUT_KEY_UP :
            m->nm->offsets[1]+=speed;
            break;
    }
    m->nm->reComputeArray();
    glutPostRedisplay();
    
}

int main(int argc, char **argv) {
    
    glutInit(&argc, argv);
    glEnable(GL_DEPTH_TEST);
    
    m=new Mesh(500);
    m->build();
    
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(640,640);
    glutCreateWindow("FlatMap");
    
    
    glutDisplayFunc(renderAll);
    glutReshapeFunc(changeSize);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);
    
    
    glutInitWindowPosition(660,10);
    glutCreateWindow("3D View");
    
    glutDisplayFunc(renderAll);
    glutReshapeFunc(changeSize);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);
    
    glutMainLoop();
    
    return 1;
}
