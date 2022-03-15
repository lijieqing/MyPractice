//
// Created by 李杰 on 2022/3/10.
//
#include "FirstWindow.h"

float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
};

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "\n"
                                   "void main()\n"
                                   "{\n"
                                   "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                   "}\0";

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

unsigned int initShader() {

    // 创建顶点着色器对象
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    // 编译顶点着色器源码
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // 创建片段着色器对象
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    // 编译片段着色器对象
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // 创建着色器程序
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    // attach
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    // link 着色器程序
    glLinkProgram(shaderProgram);

    // 移除顶点着色器对象
    glDeleteShader(vertexShader);
    // 移除片段着色器对象
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

void loopEvent(GLFWwindow *window) {
    unsigned int shaderProgram = initShader();
    // 循环处理
    while (!glfwWindowShouldClose(window)) {

        // 渲染指令
        // 设置清空屏幕所用的颜色
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // 清空屏幕的颜色缓冲
        glClear(GL_COLOR_BUFFER_BIT);

        // draw angel
        // 生成 VBO 对象
        unsigned int VBO;
        glGenBuffers(1, &VBO);
        // 将 VBO 绑定到 GL_ARRAY_BUFFER 目标上
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        // 将之前定义的顶点数据复制到缓冲的内存中
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        // 激活着色器程序
        glUseProgram(shaderProgram);

        // 声明顶点数据解析方式
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // 事件检查并交换缓冲区
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    // 释放内存
    glfwTerminate();
}