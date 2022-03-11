//
// Created by 李杰 on 2022/3/10.
//
#include "FirstWindow.h"

void key_call(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        printf("on key ESC pressed");
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

GLFWwindow *windowCreate() {
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
    }
    return window;
}

void contextInit(GLFWwindow *window) {
    // 设置按键事件
    glfwSetKeyCallback(window, key_call);
    // 创建 OpenGL 上下文
    glfwMakeContextCurrent(window);
}

void initGLEW() {
    // init glew
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        printf("fail to init glew");
    }
    glViewport(0, 0, 600, 600);
}

void loopEvent(GLFWwindow *window) {
    // 循环处理
    while (!glfwWindowShouldClose(window)) {

        // 渲染指令
        // 设置清空屏幕所用的颜色
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // 清空屏幕的颜色缓冲
        glClear(GL_COLOR_BUFFER_BIT);

        // 事件检查并交换缓冲区
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    // 释放内存
    glfwTerminate();
}