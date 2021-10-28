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
  //Shader lampShader("res/shaders/lamp.vs", "res/shaders/lamp.frag");

  // Set up vertex data (and buffer(s)) and attribute pointers
  GLfloat vertices[] =
    {
        // Positions            // Normals              // Texture Coords
        -0.5f, -0.5f, -0.5f,    0.0f,  0.0f, -1.0f,     0.0f,  0.0f,
        0.5f, -0.5f, -0.5f,     0.0f,  0.0f, -1.0f,     1.0f,  0.0f,
        0.5f,  0.5f, -0.5f,     0.0f,  0.0f, -1.0f,     1.0f,  1.0f,
        0.5f,  0.5f, -0.5f,     0.0f,  0.0f, -1.0f,     1.0f,  1.0f,
        -0.5f,  0.5f, -0.5f,    0.0f,  0.0f, -1.0f,     0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,    0.0f,  0.0f, -1.0f,     0.0f,  0.0f,

        -0.5f, -0.5f,  0.5f,    0.0f,  0.0f,  1.0f,     0.0f,  0.0f,
        0.5f, -0.5f,  0.5f,     0.0f,  0.0f,  1.0f,     1.0f,  0.0f,
        0.5f,  0.5f,  0.5f,     0.0f,  0.0f,  1.0f,     1.0f,  1.0f,
        0.5f,  0.5f,  0.5f,     0.0f,  0.0f,  1.0f,  	1.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,    0.0f,  0.0f,  1.0f,     0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,    0.0f,  0.0f,  1.0f,     0.0f,  0.0f,

        -0.5f,  0.5f,  0.5f,    -1.0f,  0.0f,  0.0f,    1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,    -1.0f,  0.0f,  0.0f,    1.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,    -1.0f,  0.0f,  0.0f,    0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,    -1.0f,  0.0f,  0.0f,    0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,    -1.0f,  0.0f,  0.0f,    0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,    -1.0f,  0.0f,  0.0f,    1.0f,  0.0f,

        0.5f,  0.5f,  0.5f,     1.0f,  0.0f,  0.0f,     1.0f,  0.0f,
        0.5f,  0.5f, -0.5f,     1.0f,  0.0f,  0.0f,     1.0f,  1.0f,
        0.5f, -0.5f, -0.5f,     1.0f,  0.0f,  0.0f,     0.0f,  1.0f,
        0.5f, -0.5f, -0.5f,     1.0f,  0.0f,  0.0f,     0.0f,  1.0f,
        0.5f, -0.5f,  0.5f,     1.0f,  0.0f,  0.0f,     0.0f,  0.0f,
        0.5f,  0.5f,  0.5f,     1.0f,  0.0f,  0.0f,     1.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,    0.0f, -1.0f,  0.0f,     0.0f,  1.0f,
        0.5f, -0.5f, -0.5f,     0.0f, -1.0f,  0.0f,     1.0f,  1.0f,
        0.5f, -0.5f,  0.5f,     0.0f, -1.0f,  0.0f,     1.0f,  0.0f,
        0.5f, -0.5f,  0.5f,     0.0f, -1.0f,  0.0f,     1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,    0.0f, -1.0f,  0.0f,     0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,    0.0f, -1.0f,  0.0f,     0.0f,  1.0f,

        -0.5f,  0.5f, -0.5f,    0.0f,  1.0f,  0.0f,     0.0f,  1.0f,
        0.5f,  0.5f, -0.5f,     0.0f,  1.0f,  0.0f,     1.0f,  1.0f,
        0.5f,  0.5f,  0.5f,     0.0f,  1.0f,  0.0f,     1.0f,  0.0f,
        0.5f,  0.5f,  0.5f,     0.0f,  1.0f,  0.0f,     1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,    0.0f,  1.0f,  0.0f,     0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,    0.0f,  1.0f,  0.0f,     0.0f,  1.0f
    };

    // Positions all containers
    glm::vec3 cubePositions[] = {
        glm::vec3(  0.0f,   0.0f,   0.0f),
        glm::vec3(  2.0f,   5.0f,   -15.0f),
        glm::vec3(  -1.5f,  -2.2f,  -2.5f),
        glm::vec3(  -3.8f,  -2.0f,  -12.3f),
        glm::vec3(  2.4f,   -0.4f,  -3.5f),
        glm::vec3(  -1.7f,  3.0f,   -7.5f),
        glm::vec3(  1.3f,   -2.0f,  -2.5f),
        glm::vec3(  1.5f,   2.0f,   -2.5f),
        glm::vec3(  1.5f,   0.2f,   -1.5f),
        glm::vec3(  -1.3f,  1.0f,   -1.5f)
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
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *) 0 );
  glEnableVertexAttribArray(0);
  // Normal Attribute
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *) (3 * sizeof(GLfloat)) );
  glEnableVertexAttribArray(1);

  // Texture Attribute
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *) (6 * sizeof(GLfloat)) );
  glEnableVertexAttribArray(2);
  // Unbind
  glBindVertexArray(0); // Unbind boxVAO

/*
  // Create Lighting
  GLuint lightVAO;
  glGenVertexArrays(1, &lightVAO); // 1 - index of array
  glGenBuffers(1, &VBO); // 1- index of buffer
  // Bing lightVAO and VBO
  glBindVertexArray(lightVAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  // Pointer Attribute - Create Vertex pointer
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid *) 0 );
  glEnableVertexAttribArray(0);
  // Unbind
  glBindVertexArray(0); // Unbind lightVAO
*/

  // Create Texture
  GLuint diffuseMap, specularMap, emissionMap;
  glGenTextures(1, &diffuseMap);
  glGenTextures(1, &specularMap);
  glGenTextures(1, &emissionMap);

  int textureWidth, textureHeight;
  unsigned char *image;

  // diffuse map
  image = SOIL_load_image("res/images/container2.png", &textureWidth, &textureHeight, 0, SOIL_LOAD_RGB);
  glBindTexture(GL_TEXTURE_2D, diffuseMap);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
  // generate mipmap
  glGenerateMipmap(GL_TEXTURE_2D);
  SOIL_free_image_data(image);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);

  // specular map
  image = SOIL_load_image("res/images/container2_specular2.png", &textureWidth, &textureHeight, 0, SOIL_LOAD_RGB);
  glBindTexture(GL_TEXTURE_2D, specularMap);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
  glGenerateMipmap(GL_TEXTURE_2D);
  SOIL_free_image_data(image);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);

  glBindTexture(GL_TEXTURE_2D, 0);

  lightingShader.use();
  glUniform1i(glGetUniformLocation(lightingShader.Program, "material.diffuse"), 0);
  glUniform1i(glGetUniformLocation(lightingShader.Program, "material.specular"), 1);

  // Setup Projection
  glm::mat4 projection = glm::perspective(camera.getZoom(), (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 1000.0f);

  // Game Loop
  while(!glfwWindowShouldClose(window)) {
    //lightPos.x -=0.005;
    //lightPos.z -=0.005;

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
    GLint lightPosLoc = glGetUniformLocation(lightingShader.Program, "light.position");
    GLint lightSpotDirLoc = glGetUniformLocation(lightingShader.Program, "light.direction");
    GLint lightSpotCutOffLoc = glGetUniformLocation(lightingShader.Program, "light.cutOff");
    GLint lightSpotOuterCutOffLoc = glGetUniformLocation(lightingShader.Program, "light.outerCutOff");
    GLint viewPosLoc = glGetUniformLocation(lightingShader.Program, "viewPos");

    //glUniform3f(lightPosLoc, lightPos.x, lightPos.y, lightPos.z);
    glUniform3f(lightPosLoc, camera.getPosition().x, camera.getPosition().y, camera.getPosition().z);

    glUniform3f(lightSpotDirLoc, camera.getFront().x, camera.getFront().y, camera.getFront().z);
    glUniform1f(lightSpotCutOffLoc, glm::cos(glm::radians(12.5f)));
    glUniform1f(lightSpotOuterCutOffLoc, glm::cos(glm::radians(17.5f)));

    glUniform3f(viewPosLoc, camera.getPosition().x, camera.getPosition().y, camera.getPosition().z);

    glUniform3f(glGetUniformLocation(lightingShader.Program, "light.ambient"), 0.1f, 0.1f, 0.1f);
    glUniform3f(glGetUniformLocation(lightingShader.Program, "light.diffuse"), 0.8f, 0.8f, 0.8f);
    glUniform3f(glGetUniformLocation(lightingShader.Program, "light.specular"), 1.0f, 1.0f, 1.0f);

    glUniform1f(glGetUniformLocation(lightingShader.Program, "light.constant"), 1.0f);
    glUniform1f(glGetUniformLocation(lightingShader.Program, "light.linear"), 0.09f);
    glUniform1f(glGetUniformLocation(lightingShader.Program, "light.quadratic"), 0.032f);

    glUniform1f(glGetUniformLocation(lightingShader.Program, "material.shininess"), 32.0f);

    glm::mat4 view;
    view = camera.GetViewMatrix();

    GLint modelLoc = glGetUniformLocation(lightingShader.Program, "model");
    GLint viewLoc = glGetUniformLocation(lightingShader.Program, "view");
    GLint projectionLoc = glGetUniformLocation(lightingShader.Program, "projection");

    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, diffuseMap);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, specularMap);


    glm::mat4 model;
    glBindVertexArray(boxVAO);
    for(GLint i = 0; i < 10; i++) {
      model = glm::mat4(1.0f);
      model = glm::translate(model, cubePositions[i]);
      GLfloat angle = 20.0f * i;
      model = glm::rotate(model, angle, glm::vec3(1.0f, 0.3f, 0.5f));

      glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
      glDrawArrays(GL_TRIANGLES, 0, 36);

    }
    glBindVertexArray(0);

/*
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
*/

    // Swap the screen buffers
    glfwSwapBuffers(window);
  }

  // Deallocated resources
  glDeleteVertexArrays(1, &boxVAO);
  //glDeleteVertexArrays(1, &lightVAO);
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


