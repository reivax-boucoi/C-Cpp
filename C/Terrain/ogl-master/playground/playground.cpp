#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>

#include <GLFW/glfw3.h>
GLFWwindow* window;

#include <glm/glm.hpp>
using namespace glm;

#include <common/shader.hpp>

class Mesh{
public:
    Mesh(int a, int b){
        w=a;
        h=b;
    };
    void hello(){
       	fprintf( stdout, "Hello MESH(%d,%d) !\n",w,h );
    };
    void buildMesh(GLfloat arr[]){
        float xspc=0.9f/w;
        float yspc=0.9f/h;
       	fprintf( stdout, "spc(%f,%f)\n",xspc,yspc);
        GLfloat arr1[] = { 
            -0.8f, -0.8f, 0.0f,
            0.8f, -0.8f, 0.0f,
            0.8f,  0.8f, 0.0f,
            0.8f,  0.8f, 0.0f,
            -0.8f,  0.8f, 0.0f,
            -0.8f, -0.8f, 0.0f,
        };
        int index=0;
        for(int i=0;i<w;i++){
            for(int j=0;j<h;j++){
                fprintf(stdout,"i=%d,j=%d,index=%d\n",i,j,index);
                arr[index++]=(float)i*xspc;
                arr[index++]=(float)j*yspc;
                arr[index++]=0.0f;
                
                arr[index++]=(float)i*xspc;
                arr[index++]=(float)(j+1)*yspc;
                arr[index++]=0.0f;
                
                arr[index++]=(float)(i+1)*xspc;
                arr[index++]=(float)j*yspc;
                arr[index++]=0.0f;
                
                arr[index++]=(float)i*xspc;
                arr[index++]=(float)(j+1)*yspc;
                arr[index++]=0.0f;
                
                arr[index++]=(float)(i+1)*xspc;
                arr[index++]=(float)(j+1)*yspc;
                arr[index++]=0.0f;
                
                arr[index++]=(float)(i+1)*xspc;
                arr[index++]=(float)j*yspc;
                arr[index++]=0.0f;
            }
        }
    };
    int w,h;
private:
    
    
};

int main( void )
{
	// Initialise GLFW
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow( 1024, 768, "Playground", NULL, NULL);
	if( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );
    
    Mesh *m=new Mesh(2,2);
    m->hello();
	GLfloat g_vertex_buffer_data[3*3*2*m->h*m->w];
    
    m->buildMesh(g_vertex_buffer_data);
    
    for(int i=0;i<3*2*(m->w*m->h);i++){
        fprintf(stdout,"%d :[%f,%f,%f]\r\n",i,g_vertex_buffer_data[i*3],g_vertex_buffer_data[i*3+1],g_vertex_buffer_data[i*3+2]);
    }
    
	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
    
    GLfloat g_color_buffer_data[] = { 
            1.0f,  0.0f,  0.0f,
            0.0f,  1.0f,  0.0f,
            0.0f,  0.0f,  1.0f,
            0.0f,  0.0f,  0.0f,
            1.0f,  1.0f,  1.0f,
            0.5f,  0.5f,  0.5f,
    };
	GLuint colorbuffer;
	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
    
	do{

		// Clear the screen
		glClear( GL_COLOR_BUFFER_BIT );

		// Use our shader
		glUseProgram(programID);

		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);
        
        glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glVertexAttribPointer(
			1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
        );
		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 6); // 3 indices starting at 0 -> 1 triangle

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

	// Cleanup VBO
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &colorbuffer);
	glDeleteVertexArrays(1, &VertexArrayID);
	glDeleteProgram(programID);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}

