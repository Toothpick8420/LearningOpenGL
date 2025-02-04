#include "Window.h"

int main() {

    // Create the window 
    Window window(800, 600, "window");

    // Game loop 
    while (true) {
        // Process input 
        window.processInput();


        // Rendering 
        // Set the clear color, probably doesn't need to be done every loop
        glClearColor(0, 0, 0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap buffers and poll events

        window.swapBuffers();
        window.pollEvents();
    }
}
