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
void DoMovement();

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
GLfloat lastX = WIDTH / 2.0f;
GLfloat lastY = HEIGHT / 2.0f;
bool keys[1024];
bool firstMouse = true;

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

int main(int argc, char** argv) {

  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
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
  Shader lightingShader("res/shaders/lighting.vs", "res/shaders/lighting.frag");
  Shader lampShader("res/shaders/lamp.vs", "res/shaders/lamp.frag");


  GLfloat vertices[] = {
      -0.5f, -0.5f, -0.5f,  // Back
      0.5f, -0.5f, -0.5f,
      0.5f,  0.5f, -0.5f,
      0.5f,  0.5f, -0.5f,
      -0.5f,  0.5f, -0.5f,
      -0.5f, -0.5f, -0.5f,

      -0.5f, -0.5f,  0.5f,  // Front
      0.5f, -0.5f,  0.5f,
      0.5f,  0.5f,  0.5f,
      0.5f,  0.5f,  0.5f,
      -0.5f,  0.5f,  0.5f,
      -0.5f, -0.5f,  0.5f,

      -0.5f,  0.5f,  0.5f,  // Right
      -0.5f,  0.5f, -0.5f,
      -0.5f, -0.5f, -0.5f,
      -0.5f, -0.5f, -0.5f,
      -0.5f, -0.5f,  0.5f,
      -0.5f,  0.5f,  0.5f,

      0.5f,  0.5f,  0.5f,  // Left
      0.5f,  0.5f, -0.5f,
      0.5f, -0.5f, -0.5f,
      0.5f, -0.5f, -0.5f,
      0.5f, -0.5f,  0.5f,
      0.5f,  0.5f,  0.5f,

      -0.5f, -0.5f, -0.5f,  // Bottom
      0.5f, -0.5f, -0.5f,
      0.5f, -0.5f,  0.5f,
      0.5f, -0.5f,  0.5f,
      -0.5f, -0.5f,  0.5f,
      -0.5f, -0.5f, -0.5f,

      -0.5f,  0.5f, -0.5f,  // Top
      0.5f,  0.5f, -0.5f,
      0.5f,  0.5f,  0.5f,
      0.5f,  0.5f,  0.5f,
      -0.5f,  0.5f,  0.5f,
      -0.5f,  0.5f, -0.5f
  };


  // Create VBO(Vertex Buffer Object), boxVAO(Vertex Array Object) and EBO(Elements Buffer Object)
  GLuint VBO;

  GLuint boxVAO;
  glGenVertexArrays(1, &boxVAO); // 1 - index of array
  glGenBuffers(1, &VBO); // 1- index of buffer

  // Bing boxVAO and VBO
  glBindVertexArray(boxVAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  // Pointer Attribute - Create Vertex pointer
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *) 0 );
  glEnableVertexAttribArray(0);
  // Unbind
  glBindVertexArray(0); // Unbind boxVAO


  // Create Lighting
  GLuint lightVAO;
  glGenVertexArrays(1, &lightVAO); // 1 - index of array
  glGenBuffers(1, &VBO); // 1- index of buffer
  // Bing lightVAO and VBO
  glBindVertexArray(lightVAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  // Pointer Attribute - Create Vertex pointer
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *) 0 );
  glEnableVertexAttribArray(0);
  // Unbind
  glBindVertexArray(0); // Unbind lightVAO

  // Setup Projection
  glm::mat4 projection = glm::perspective(camera.getZoom(), (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 1000.0f);

  // Game Loop
  while(!glfwWindowShouldClose(window)) {
    // Count deltaTime
    GLfloat currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    // Get events
    glfwPollEvents();
    DoMovement();

    // Set Background
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    // Create Cube
    lightingShader.use();
    GLint objectColorLoc = glGetUniformLocation(lightingShader.Program, "objectColor");
    GLint lightColorLoc = glGetUniformLocation(lightingShader.Program, "lightColor");
    glUniform3f(objectColorLoc, 1.0f, 0.5f, 0.31f);
    glUniform3f(lightColorLoc, 1.0f, 0.5f, 1.0f);

    glm::mat4 view;
    view = camera.GetViewMatrix();

    GLint modelLoc = glGetUniformLocation(lightingShader.Program, "model");
    GLint viewLoc = glGetUniformLocation(lightingShader.Program, "view");
    GLint projectionLoc = glGetUniformLocation(lightingShader.Program, "projection");

    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

    glBindVertexArray(boxVAO);
    glm::mat4 model(1.0f);
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);


    // Create Light

    lampShader.use();
    view = camera.GetViewMatrix();

    modelLoc = glGetUniformLocation(lampShader.Program, "model");
    viewLoc = glGetUniformLocation(lampShader.Program, "view");
    projectionLoc = glGetUniformLocation(lampShader.Program, "projection");

    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

    model = glm::mat4(1.0f);
    model = glm::translate(model, lightPos);
    model = glm::scale(model, glm::vec3(0.2f));
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    glBindVertexArray(lightVAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);



    // Swap the screen buffers
    glfwSwapBuffers(window);
  }

  // Deallocated resources
  glDeleteVertexArrays(1, &boxVAO);
  glDeleteVertexArrays(1, &lightVAO);
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


