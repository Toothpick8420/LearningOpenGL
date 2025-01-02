#include <iostream>
#include <GLFW/glfw3.h>

const int WIDTH = 1280;
const int HEIGHT = 720;

int main(void) {

    GLFWwindow * window;

    /* Init lib */
    if (!glfwInit()) {
        return -1;
    }

    /* Create a windowed mode window and its opengl context */
    window = glfwCreateWindow(WIDTH, HEIGHT, "New Program", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make context current */
    glfwMakeContextCurrent(window);

    std::cout << glGetString(GL_VERSION) << std::endl;

    /* Loop until closes */
    while (!glfwWindowShouldClose(window)) {
        /* Render */ 

        glClearColor(0.0, 1.0, 0.0, 0.0);

        glClear(GL_COLOR_BUFFER_BIT);


        /* Swap buffers */
        glfwSwapBuffers(window);

        /* Poll events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
