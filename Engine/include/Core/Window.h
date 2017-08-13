#pragma once

#ifdef _WIN32
#define APIENTRY __stdcall
#endif

// GLAD
#include <glad/glad.h>


// GLFW
#include <GLFW/glfw3.h>

class Window{
public:
    Window();
    ~Window();
    int InitWindow(int width, int height, const char *title);
    void Refresh();
    void Destroy();
    bool ShouldClose();

	int Width() const { return _width; }
	int Height() const { return _height; }

private:
    int _width, _height;
    const char* _title;
    GLFWwindow* _window;

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

};