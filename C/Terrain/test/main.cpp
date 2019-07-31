// g++ main.cpp -lglut -lGL

#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

void setup() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    
}
/*
void display(){
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glColor3f(0.0f, 0.0f, 0.0f);
      glRectf(-0.75f,0.75f, 0.75f, -0.75f);
      glutSwapBuffers();
}*/
void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer
 
   // Draw a Red 1x1 Square centered at origin
   glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      glColor3f(1.0f, 0.0f, 0.0f); // Red
      glVertex2f(-0.5f, -0.5f);    // x, y
      glVertex2f( 0.5f, -0.5f);
      glVertex2f( 0.5f,  0.5f);
      glVertex2f(-0.5f,  0.5f);
   glEnd();
 
   glFlush();  // Render now
}

int main(int argc, char *argv[]){
    
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
     glutInitWindowSize(640,480);
     glutCreateWindow("Hello World");

     setup();
     glutDisplayFunc(display);
     glutMainLoop();
    
     return 0;
  }
