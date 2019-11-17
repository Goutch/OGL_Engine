
#pragma once
#include <GLFW/glfw3.h>

class Window
{
public:
    Window(int sizeX,int sizeY);
    ~Window();
    bool open();
    void close();
    bool shouldClose();
    void swapBuffer();
    void pollEvents();
private:
    GLFWwindow* window;
    int sizeX=600, sizeY=400;
};
