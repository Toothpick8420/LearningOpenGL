#ifndef WINDOW_H
#define WINDOW_H

#define GLFW_INCLUDE_NONE
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Error callback function called by any glfw error, just prints to std::cerr 
void errorCallback(int error_num, const char * descr);

// Class that contains the GLFWwindow * 
// Basically just a layer over the GLFW functions 
class Window {
public:
    Window(GLint width, GLint height, std::string title);
    ~Window();

    bool shouldClose() const;
    void swapBuffers();
    void pollEvents() const;
    void processInput();

private:
    GLFWwindow * pwindow_;
    GLint width_, height_;
    std::string title_;
};

#endif
