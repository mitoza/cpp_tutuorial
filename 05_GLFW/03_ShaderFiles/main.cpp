// main.cpp
#include <iostream>

//#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include <GL/gl.h>

#include "Shader.h"


const GLint WIDTH = 800;
const GLint HEIGHT = 600;


int main(int argc, char** argv) {

  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE); // Old opengl methods

  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Hello Window", nullptr, nullptr);

  int screenWidth, screenHeight;

  glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

  if (nullptr == window) {
    std::cout << "Failed create GLFW Window" << std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  glewExperimental = GL_TRUE;

  if (GLEW_OK != glewInit()) {
    std::cout << "Failed initialize GLEW" << std::endl;
    return -1;
  }

  // Define the viewport dimensions
  glViewport(0, 0, screenWidth, screenHeight);

  Shader triangle("res/shaders/core.vs", "res/shaders/core.frag");

  // Create Vertex Data
  /*
  GLfloat vertices[] = {
    -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,// Bottom Left
    0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, // Bottom Right
    0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f // Top Middle
  };
  */
  GLfloat vertices[] = {
    -1.0f, -1.0f, 0.0f, /* Bottom Left */ 1.0f, 0.0f, 0.0f, /* red color*/
    1.0f, -1.0f, 0.0f,  /* Bottom Right */ 0.0f, 1.0f, 0.0f, /* green color */
    0.0f, 1.0f, 0.0f, /* Top Middle */ 0.0f, 0.0f, 1.0f /* blue color */
  };

  // Create VBO(Vertex Buffer Object) and VAO(Vertex Array Object)
  GLuint VBO, VAO;
  glGenVertexArrays(1, &VAO); // 1 - index of array
  glGenBuffers(1, &VBO); // 1- index of buffer

  // Bing VAO and VBO
  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // Create Vertex pointer
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *) 0 );
  glEnableVertexAttribArray(0);
  // Add Color attribute
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)) );
  glEnableVertexAttribArray(1);

  // Binding the Buffer
  //glBindBuffer(GL_ARRAY_BUFFER, 0);

  // Unbind
  glBindVertexArray(0);



  // Game Loop
  while(!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw Triangle

    //glUseProgram(shaderProgram);
    triangle.use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);

    glfwSwapBuffers(window);
  }

  // Dealocated resources
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);


  return 0;
}
