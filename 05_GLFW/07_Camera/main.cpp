// main.cpp
#include <iostream>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <GL/gl.h>

#include "headers/Shader.h"
#include "headers/Camera.h"

#include <SOIL2/SOIL2.h>

#define GLM_FORCE_MESSAGES
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


// http://www.opengl-tutorial.org/

const GLint WIDTH = 800, HEIGHT = 600;
int SCREEN_WIDTH, SCREEN_HEIGHT;

void KeyCallback(GLFWwindow *window, int key, int scanCode, int action, int mode);
void MouseCallback(GLFWwindow * window, double xPos, double yPos);
void ScrollCallback(GLFWwindow *window, double xOffset, double yOffset);
void DoMovement();

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
GLfloat lastX = WIDTH / 2.0f;
GLfloat lastY = HEIGHT / 2.0f;
bool keys[1024];
bool firstMouse = true;

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

int main(int argc, char** argv) {

  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE); // Old opengl methods

  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Hello Window", nullptr, nullptr);

  glfwGetFramebufferSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);

  if (nullptr == window) {
    std::cout << "Failed create GLFW Window" << std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  glfwSetKeyCallback(window, KeyCallback);
  glfwSetCursorPosCallback(window, MouseCallback);
  glfwSetScrollCallback(window, ScrollCallback);

  // Disable Cursor
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


  glewExperimental = GL_TRUE;

  if (GLEW_OK != glewInit()) {
    std::cout << "Failed initialize GLEW" << std::endl;
    return -1;
  }

  // Define the viewport dimensions
  glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

  glEnable(GL_DEPTH_TEST);

  // Enable Alpha color for PNG
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  // Upload the shader
  Shader triangleShader("res/shaders/core.vs", "res/shaders/core.frag");

  GLfloat vertices[] = {
      -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // Back
      0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
      0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
      0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
      -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
      -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

      -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // Front
      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
      -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
      -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

      -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // Right
      -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
      -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
      -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
      -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
      -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

      0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // Left
      0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
      0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
      0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
      0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
      0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

      -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // Bottom
      0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
      -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
      -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

      -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // Top
      0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
      0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
      0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
      -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
      -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
  };

  // Create Array of vectors
  glm::vec3 cubePositions[] = {
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(2.0f, 5.0f, -15.0f),
    glm::vec3(-1.5f, -2.2f, -2.5f),
    glm::vec3(-3.8f, -2.0f, -12.3f),
    glm::vec3(2.4f, -0.4f, -3.5f),
    glm::vec3(-1.7f, 3.0f, 7.5f),
    glm::vec3(1.3f, -2.0f, -2.5f),
    glm::vec3(1.5f, 2.0f, -2.5f),
    glm::vec3(1.5f, 0.2f, -1.5f),
    glm::vec3(-1.3f, 1.0f, -1.5f),
  };


  // Create VBO(Vertex Buffer Object), VAO(Vertex Array Object) and EBO(Elements Buffer Object)
  GLuint VBO, VAO;
  glGenVertexArrays(1, &VAO); // 1 - index of array
  glGenBuffers(1, &VBO); // 1- index of buffer

  // Bing VAO and VBO
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // Pointer Attribute - Create Vertex pointer
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid *) 0 );
  glEnableVertexAttribArray(0);

  // Texture coordinate attribute
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)) );
  glEnableVertexAttribArray(1);

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

  // SetProjection frustrum
  //glm::mat4 projection = glm::perspective(camera->getZoom(), (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 1000.0f);
  //projection = glm::ortho(0.0f, (GLfloat)SCREEN_WIDTH, 0.0f, (GLfloat)SCREEN_HEIGHT, 0.1f, 1000.0f);

  // Game Loop
  while(!glfwWindowShouldClose(window)) {
    GLfloat currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    glfwPollEvents();
    DoMovement();

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Draw Shader
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glUniform1i(glGetUniformLocation(triangleShader.Program, "ourTexture"), 0);

    // Draw TriangleShader
    triangleShader.use();

    glm::mat4 projection = glm::perspective(camera.getZoom(), (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 1000.0f);

    //
    glm::mat4 model(1.0f);
    glm::mat4 view(1.0f);
    view = camera.GetViewMatrix();

    GLint modelLoc = glGetUniformLocation(triangleShader.Program, "model");
    GLint viewLoc = glGetUniformLocation(triangleShader.Program, "view");
    GLint projectionLoc = glGetUniformLocation(triangleShader.Program, "projection");

    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

    glBindVertexArray(VAO);

    for(GLuint i=0; i < 10; i++) {
      glm::mat4 model(1.0f);
      model = glm::translate(model, cubePositions[i]);
      GLfloat angle = 20.0f * i;
      model = glm::rotate(model, angle, glm::vec3(1.0f, 0.3f, 0.5f));
      glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

      glDrawArrays(GL_TRIANGLES, 0, 36);
    }

    glBindVertexArray(0);

    // Swap the screen buffers
    glfwSwapBuffers(window);
  }

  // Deallocated resources
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);

  return 0;
}

void KeyCallback(GLFWwindow *window, int key, int scanCode, int action, int mode) {
  if (GLFW_KEY_ESCAPE == key && GLFW_PRESS == action) {
    glfwSetWindowShouldClose(window, GL_TRUE);
  }

  if (key >=0 && key < 1024) {
    if (GLFW_PRESS == action) {
      keys[key] = true;
    } else if (GLFW_RELEASE == action){
      keys[key] = false;
    }
  }
}

void MouseCallback(GLFWwindow * window, double xPos, double yPos) {
  if (firstMouse) {
    lastX = xPos;
    lastY = yPos;
    firstMouse = false;
  }

  GLfloat xOffset = xPos - lastX;
  GLfloat yOffset = yPos - lastY;

  lastX = xPos;
  lastY = yPos;

  camera.processMouseMovement(xOffset, yOffset);
}

void ScrollCallback(GLFWwindow *window, double xOffset, double yOffset) {
  camera.processMouseScroll(yOffset);
}


void DoMovement() {
  if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP]) {
    camera.processKeyboard(FORWARD, deltaTime);
  }
  if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN]) {
    camera.processKeyboard(BACKWARD, deltaTime);
  }
  if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT]) {
    camera.processKeyboard(LEFT, deltaTime);
  }
  if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT]) {
    camera.processKeyboard(RIGHT, deltaTime);
  }

}


