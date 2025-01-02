#ifndef WINDOW_H
#define WINDOW_H

#include <string>
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

private:
    GLFWwindow * window_;
    GLint width_, height_;
    GLfloat clear_r_ = 0, clear_g_ = 0, clear_b_ = 0;
};

#endif
