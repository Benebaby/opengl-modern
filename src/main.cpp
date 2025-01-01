#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(int argc, char* argv[])
{
  GLFWwindow *window;

  if(!glfwInit())
  {
    std::cout << "GLFW Not Initialized" << std::endl;
    return -1;
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window = glfwCreateWindow(1600, 900, "OpenGL Tutorial", 0, 0);

  if(!window)
  {
    std::cout << "Window wasn't created" << std::endl;
    return -1;
  }

  glfwMakeContextCurrent(window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
      std::cout << "Failed to initialize GLAD" << std::endl;
      return -1;
  }
  std::cout << "OPENGL Version" << glGetString(GL_VERSION) << std::endl;

  while(!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  glfwTerminate();

  return 0;
}