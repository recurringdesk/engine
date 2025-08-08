#include "window.hpp"
#include <untitled/string.hpp>
#include <GLFW/glfw3.h>
namespace Untitled::Engine
{
    struct WindowHandle
    {
        int width;
        int height;
        GLFWwindow* window;
        const char* title;
        WindowHandle(const int new_width, const int new_height, const char* new_title)
            : width(new_width), height(new_height), title(new_title)
        {
            glfwInit();
            window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        }
        [[nodiscard]] bool should_close() const
        {
            return glfwWindowShouldClose(window);
        }
    };
    Window::Window()
        : handle(new WindowHandle(800, 600, "Title"))
    {

    }

    Window::~Window()
    {
    }

    String Window::get_title() const
    {
        return title;
    }

    bool Window::should_close() const
    {
        return handle->should_close();
    }

    void Window::set_title(const String& new_title)
    {
        this->title = new_title;
    }
}
