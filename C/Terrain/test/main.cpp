// g++ main.cpp -lglut -lGL

#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

void setup() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(-0.5f, -0.5f);    // x, y
    glVertex2f( 0.5f, -0.5f);
    glVertex2f( 0.5f,  0.5f);
    glVertex2f(-0.5f,  0.5f);
    glEnd();
    
    glutSwapBuffers();
}
void changeSize(int w, int h) {
	if(h == 0)h = 1;
	float ratio = 1.0* w / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45,ratio,1,1000);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[]){
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowPosition(100,100);
    glutInitWindowSize(640,480);
    glutCreateWindow("Hello World");
    
    setup();
    glutDisplayFunc(display);
	//glutReshapeFunc(changeSize);
    glutIdleFunc(display);
    glutMainLoop();
    
    return 0;
}
