#ifndef WINDOW_H
#define WINDOW_H

#define GLFW_INCLUDE_NONE
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Error callback function must be set
void errorCallback(int error_num, const char * descr);

// A container for the GLFWwindow * to be passed around
class Window {
public:
    Window(GLint width, GLint height, std::string title);
    ~Window(); 

    bool shouldClose() const { return glfwWindowShouldClose(window_); }
    void swapBuffers() { glfwSwapBuffers(window_); }
    void pollEvents()  { glfwPollEvents(); } 

    void processInput();
private:
    GLFWwindow * window_;
    GLint width_, height_;
};

#endif
