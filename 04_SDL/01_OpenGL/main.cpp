// main.cpp
#include <iostream>

#include <GL/glew.h>

#include <SDL2/SDL.h>

#include <GL/gl.h>

#include <SDL2/SDL_opengl.h>

const GLint WIDTH = 800;
const GLint HEIGHT = 600;

int main(int argc, char** argv) {

  std::cout << "SDL OpenGL" << std::endl;

  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  // Setup OpenGL 3.3
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

  SDL_Window *window = SDL_CreateWindow("SDL OpenGl", 0, 0, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);

  SDL_GLContext context = SDL_GL_CreateContext(window);

  glewExperimental = GL_TRUE;

  if (GLEW_OK != glewInit()) {
    std::cout << "Failed init GLEW" << std::endl;

    return EXIT_FAILURE;
  }

  return 0;
}
