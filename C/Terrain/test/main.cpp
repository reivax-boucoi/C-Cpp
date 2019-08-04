// g++ main.cpp -lglut -lGL

#include <GL/glew.h>

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
	
    gluLookAt(	0.0f, 0.0f, 10.0f,
				0.0f, 0.0f,  0.0f,
				0.0f, 1.0f,  0.0f);

	//glRotatef(angle, 1.0f, 0.0f, 0.0f);
    
    glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_TRIANGLES);
		glVertex3f(-2.0f,-2.0f, 0.0f);
		glVertex3f( 2.0f, 0.0f, 0.0);
		glVertex3f( 0.0f, 2.0f, 0.0);
	glEnd();
    
    glColor3f(0.0f,1.0f,0.0f);
	glBegin(GL_QUADS);
		glVertex3f(-0.5f,-0.5f, 0.0f);
		glVertex3f(-0.5f,0.5f, 0.0f);
		glVertex3f( 0.5f, 0.5f, 0.0);
		glVertex3f( 0.5f, -0.5f, 0.0);
	glEnd();

	glutSwapBuffers();
}

int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(480,320);
	glutCreateWindow("Test");

	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutMainLoop();

	return 1;
}
