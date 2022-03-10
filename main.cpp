#define GLEW_STATIC

#include "lesson00/lesson00.h"
#include "iostream"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

    // 创建 Window
    GLFWwindow *window = glfwCreateWindow(600, 600, "LiJie", nullptr, nullptr);
    if (window == nullptr) {
        printf("failed to create glfw window\n");
        glfwTerminate();
        return -1;
    }
    // 创建 OpenGL 上下文
    glfwMakeContextCurrent(window);

    // init glew
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        printf("fail to init glew");
        return -1;
    }
    glViewport(0, 0, 600, 600);

    // 循环处理
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    // 释放内存
    glfwTerminate();
    return 0;
}