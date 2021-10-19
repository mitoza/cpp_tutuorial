// main.cpp
#include <iostream>

//#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include <GL/gl.h>


const GLint WIDTH = 800;
const GLint HEIGHT = 600;

const GLchar *vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"void main( )\n"
"{\n"
"gl_Position = vec4(position.x, position.y, position.z, 1.0);"
"}";

const GLchar *fragmentShaderSource = "#version 330 core\n"
"out vec4 color; \n"
"void main()\n"
"{\n"
"color = vec4( 1.0f, 0.5f, 0.2f, 1.0f);\n"
"}";

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

  // Check Variables
  GLint success;
  GLchar infoLog[255];

  // Adding Vertex Shader
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  // Check Vertex Shader
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "Error::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
  }

  // Adding Fragment Shader
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  // Check Fragment Shader
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
  }

  // Linking the Shader's
  GLuint shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  // Linking Check
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
  }

  // Delete Shader's
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  // Create Vertex Data
  GLfloat vertices[] = {
    -0.5f, -0.5f, 0.0f, // Bottom Left
    0.5f, -0.5f, 0.0f,  // Bottom Right
    0.0f, 0.5f, 0.0f, // Top Middle
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
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid * ) 0 );
  glEnableVertexAttribArray(0);

  // Binding the Buffer
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  // Unbind
  glBindVertexArray(0);



  // Game Loop
  while(!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw Triangle

    glUseProgram(shaderProgram);
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
