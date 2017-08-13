#include <Core/Window.h>
#include <Core/Input.h>
#include <iostream>
#include "Core/Components/Camera.h"

Window::Window() {

}

Window::~Window() {
    this->Destroy();
}

int Window::InitWindow(int width, int height, const char *title) {
    this->_title = title;
    this->_width = width;
    this->_height = height;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4.5);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw window creation
    // --------------------
    this->_window = glfwCreateWindow(this->_width, this->_height, this->_title, NULL, NULL);
    if (this->_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(this->_window);
    glfwSetFramebufferSizeCallback(this->_window, framebuffer_size_callback);
    glfwSetKeyCallback(this->_window, key_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


	glEnable(GL_DEPTH_TEST);

	glDepthFunc(GL_LESS);

    return 0;
}

void Window::Refresh() {

    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(this->_window);
    glfwPollEvents();
}

void Window::Destroy() {
    glfwTerminate();
}

void Window::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
// make sure the viewport matches the new window dimensions; note that m_width and
    // m_height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
	if(Camera::MainCamera != nullptr)
		Camera::MainCamera->CreateProjectionMatrix(0, height, 0, width, 0.1f, 1000.0f);
}

bool Window::ShouldClose() {
    return glfwWindowShouldClose(this->_window);
}

void Window::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    Input::SetState(key, action);
}
