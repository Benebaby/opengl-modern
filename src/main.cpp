#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main(int argc, char* argv[])
{
  std::cout << "Hello World" << std::endl;
  GLFWwindow *window;

  if(!glfwInit())
  {
    std::cout << "GLFW Not Initialized" << std::endl;
    return -1;
  }

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

  while(!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  glfwTerminate();

  return 0;
}