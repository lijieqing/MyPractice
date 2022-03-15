//
// Created by 李杰 on 2022/3/10.
//

#ifndef MYPRACTICE_FIRSTWINDOW_H
#define MYPRACTICE_FIRSTWINDOW_H

#endif //MYPRACTICE_FIRSTWINDOW_H

#include "iostream"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void key_call(GLFWwindow *window, int key, int scancode, int action, int mods);

GLFWwindow *windowCreate();

void contextInit(GLFWwindow *window);

void initGLEW();

unsigned int initShader();

void loopEvent(GLFWwindow *window);