#include "Window.h"

int main() {

    Window window(1280, 720, "window");


    while (!window.shouldClose()) {
    
        // Clear the screen
        glClearColor(0.5, 0.8, 0.3, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        window.swapBuffers();
        window.pollEvents();
    }

    return 0;
}
