//
// Created by 李杰 on 2022/3/10.
//

#ifndef MYPRACTICE_FIRSTWINDOW_H
#define MYPRACTICE_FIRSTWINDOW_H

#endif //MYPRACTICE_FIRSTWINDOW_H

#include "iostream"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
};

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";

void key_call(GLFWwindow *window, int key, int scancode, int action, int mods);

GLFWwindow *windowCreate();

void contextInit(GLFWwindow *window);

void initGLEW();

void loopEvent(GLFWwindow *window);