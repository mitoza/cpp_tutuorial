// main.cpp
#include <iostream>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <GL/gl.h>

#include "headers/Shader.h"

#include <SOIL2/SOIL2.h>

#define GLM_FORCE_MESSAGES
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


// http://www.opengl-tutorial.org/

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

  // Enable Alpha color for PNG
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  // Upload the shader
  Shader triangleShader("res/shaders/core.vs", "res/shaders/core.frag");

  // Create Vertex Data
  GLfloat vertices[] = {
    // Position         // Colors           // Texture Coordinates
    0.5f, 0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // Top Right
    0.5f, -0.5f, 0.0f,  1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // Bottom Right
    -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,   0.0f, 0.0f,   // Bottom Left
    -0.5f, 0.5f, 0.0f,  1.0f, 0.0f, 1.0f,   0.0f, 1.0f    //Top Left
  };

  GLuint indices[] = { // Quadric Triangle
    0, 1, 3,  // First Triangle
    1, 2, 3   // Second Triangle
  };


  // Create VBO(Vertex Buffer Object), VAO(Vertex Array Object) and EBO(Elements Buffer Object)
  GLuint VBO, VAO, EBO;
  glGenVertexArrays(1, &VAO); // 1 - index of array
  glGenBuffers(1, &VBO); // 1- index of buffer
  glGenBuffers(1, &EBO); // 1- index of buffer

  // Bing VAO, VBO and EBO
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  // Pointer Attribute - Create Vertex pointer
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *) 0 );
  glEnableVertexAttribArray(0);
  // Color attribute
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)) );
  glEnableVertexAttribArray(1);
  // Texture coordinate attribute
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *)(6 * sizeof(GLfloat)) );
  glEnableVertexAttribArray(2);

  // Unbind
  glBindVertexArray(0); // Unbind VAO

  // Create GLuint for texture
  GLuint texture;

  int width, height;
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  // Set texture params
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  // Load Image
  unsigned char *image = SOIL_load_image("res/images/image1.jpg", &width, &height, 0, SOIL_LOAD_RGBA);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
  //Generate Texture mipmap
  glGenerateMipmap(GL_TEXTURE_2D);
  // Free image
  SOIL_free_image_data(image);
  glBindTexture(GL_TEXTURE_2D, 0);


  // Game Loop
  while(!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw Triangle
    triangleShader.use();

    // Transformation create
    glm::mat4 transf = glm::mat4(1.0f);
    transf = glm::translate(transf, glm::vec3(0.5f, -0.5f, 0.0f));
    transf = glm::rotate(transf, (GLfloat)glfwGetTime() * -1.0f, glm::vec3(0.0f, 0.0f, 1.0f));
    // Apply transformation
    GLint transformLocation = glGetUniformLocation(triangleShader.Program, "transform");
    glUniformMatrix4fv(transformLocation, 1, GL_FALSE, glm::value_ptr(transf)); // 4 float variables


    // Draw Shader
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glUniform1i(glGetUniformLocation(triangleShader.Program, "ourTexture"), 0);

    // Draw triangle
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

    glfwSwapBuffers(window);
  }

  // Deallocated resources
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);

  return 0;
}
