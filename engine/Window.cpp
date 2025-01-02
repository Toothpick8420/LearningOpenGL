#include <iostream>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "Window.h"

// Error callback function is called when any GLFW function has an error
// Simple printing
void errorCallback(int error_num, const char * descr) {
    std::cerr << "ErrorNum " << error_num << ": " << descr << std::endl; 
}

Window::Window(GLint width, GLint height, std::string title) 
    : width_(width), height_(height)
{

    // Make sure glfw inits right
    if (!glfwInit()) {
        std::cerr << "GLFW initilization failed" << std::endl;
        return;
    }

    // make sure we set the right open gl version 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
 
    // Set the error callback function, must be set
    glfwSetErrorCallback(errorCallback);

    
    // Create the window and OpenGL context
    window_ = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

    // Make sure window creation worked
    if (!window_) {
        std::cerr << "Window/Context creation failed" << std::endl;
        return;
    }

    // OpenGl context
    glfwMakeContextCurrent(window_);

    // Glad setup so I can use more opengl functions than 1.1
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "GLAD initilization failed" << std::endl;  
        return;
    }

    // OpenGL viewport so it can know the size of the rendering window
    glViewport(0, 0, width, height);


    // Set the clear color to black
}


// Destructor to cleanup 
Window::~Window() {
    // Cleanup
    glfwDestroyWindow(window_);
    glfwTerminate();
}
