set(IN_HOME 1)
if(${IN_HOME})
    cmake_minimum_required(VERSION 3.16.5)
    set(GLEW_H /usr/local/Cellar/glew/2.2.0_1/include)
    set(GLFW_H /usr/local/Cellar/glfw/3.3.6/include)
    set(GLEW_LINK /usr/local/Cellar/glew/2.2.0_1/lib/libGLEW.2.2.0.dylib)
    set(GLFW_LINK /usr/local/Cellar/glfw/3.3.6/lib/libglfw.3.3.dylib)
else()
    cmake_minimum_required(VERSION 3.20)
    set(GLEW_H /opt/homebrew/Cellar/glew/2.2.0_1/include)
    set(GLFW_H /opt/homebrew/Cellar/glfw/3.3.6/include)
    set(GLEW_LINK /opt/homebrew/Cellar/glew/2.2.0_1/lib/libGLEW.2.2.0.dylib)
    set(GLFW_LINK /opt/homebrew/Cellar/glfw/3.3.6/lib/libglfw.3.3.dylib)
endif()
project(MyPractice)

set(CMAKE_CXX_STANDARD 14)

include_directories(${GLEW_H} ${GLFW_H})
link_libraries(${GLEW_LINK} ${GLFW_LINK})

add_executable(MyPractice main.cpp
        lesson00/lesson00.h
        lesson00/lesson00.cpp
        hello_window/FirstWindow.h hello_window/FirstWindow.cpp)

target_link_libraries(MyPractice "-framework OpenGL")
