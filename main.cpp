#define GLEW_STATIC

#include "lesson00/lesson00.h"
#include "hello_window/FirstWindow.h"

int main() {
    GLFWwindow *window = windowCreate();
    contextInit(window);
    initGLEW();
    loopEvent(window);
    return 0;
}