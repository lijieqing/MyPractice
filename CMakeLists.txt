cmake_minimum_required(VERSION 3.20)
project(MyPractice)

set(CMAKE_CXX_STANDARD 14)

set(GLEW_H /opt/homebrew/Cellar/glew/2.2.0_1/include)
set(GLFW_H /opt/homebrew/Cellar/glfw/3.3.6/include)
include_directories(${GLEW_H} ${GLFW_H})

set(GLEW_LINK /opt/homebrew/Cellar/glew/2.2.0_1/lib/libGLEW.2.2.0.dylib)
set(GLFW_LINK /opt/homebrew/Cellar/glfw/3.3.6/lib/libglfw.3.3.dylib)
link_libraries(${GLEW_LINK} ${GLFW_LINK})

add_executable(MyPractice main.cpp
        lesson00/lesson00.h
        lesson00/lesson00.cpp
        )

target_link_libraries(MyPractice "-framework OpenGL")
