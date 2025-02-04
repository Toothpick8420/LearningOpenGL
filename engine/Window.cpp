#include <iostream>

// Makes sure that glfw does not include the opengl headers 
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "Window.h"

// Error Callback function called when any GLFW function has occured 
// Simple Printing 
void errorCallback(int error_num, const char * descr) {
    std::cerr << "ErrorNum: " << error_num << " : " << descr << std::endl;
}


// Window constructor, initializes glfw/opengl context and creates the window pointer
Window::Window(GLint width, GLint height, std::string title) 
    : width_(width), height_(height), title_(title)
{
    // Initialize glfw 
    if (!glfwInit()) {
        std::cerr << "GLFW initialization failed" << std::endl;
        return;
    }

    // Set the correct opengl version -> 3.3 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Set the error callback function
    glfwSetErrorCallback(errorCallback);

    // Create the window and opengl context
    pwindow_ = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

    // Check window creation 
    if (!pwindow_) {
        std::cerr << "Window/Context Creation Failed" << std::endl;
        return;
    }

    // Set the opengl context to the pwindow_ 
    glfwMakeContextCurrent(pwindow_);

    // Glad setup to use opengl functions 
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "GLAD initialization failed" << std::endl; 
        return;
    }

    // opengl viewport 
    glViewport(0, 0, width, height);
}


// Destructor to cleanup 
Window::~Window() {
    // Cleanup 
    glfwDestroyWindow(pwindow_);
    glfwTerminate();
}


// Return true if the window should close 
bool Window::shouldClose() const { 
    return glfwWindowShouldClose(pwindow_);
}


// Swap the buffers for the windows -> look up double buffering
void Window::swapBuffers() {
    glfwSwapBuffers(pwindow_);
}


// Poll all window events like mouse input, keyboard input, etc
void Window::pollEvents() const {
    glfwPollEvents();
}


// FIXME: Maybe move this out of the window function or figure something out for handling
// inputs better
// Process window input 
void Window::processInput() {
    if (glfwGetKey(pwindow_, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(pwindow_, true);
    }
}
