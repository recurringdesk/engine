#include "window.hpp"
#include <untitled/string.hpp>
#include <untitled/console/logger.hpp>
#include <GLFW/glfw3.h>
using Log = Untitled::Console::Logger;
namespace Untitled::Engine::System
{
    struct Handle
    {
        int width;
        int height;
        GLFWwindow* id = nullptr;
        const char* title;
        Handle(const int new_width, const int new_height, const char* new_title)
            : width(new_width), height(new_height), title(new_title)
        {
            if (!glfwInit()) throw 1;
            id = glfwCreateWindow(width, height, title, nullptr, nullptr);
            if (!id) throw 2;
            glfwMakeContextCurrent(id);
            swap_buffer();
        }
        ~Handle()
        {
            if (id == nullptr) return;
            glfwDestroyWindow(id);
        }
        void swap_buffer() const
        {
            glfwSwapBuffers(id);
        }
        static void poll_events()
        {
            glfwPollEvents();
        }
        void wait_events() const
        {
            glfwWaitEvents();
        }
        bool should_close() const
        {
            return glfwWindowShouldClose(id);
        }
    };
    Window::Window(const String& title, int width, int height)
        : handler(new Handle(width, height, title.raw()))
    {
    }

    void Window::poll_events() const
    {
        handler->poll_events();
    }

    void Window::wait_events() const
    {
        handler->wait_events();
    }

    void Window::swap_buffer() const
    {
        handler->swap_buffer();
    }

    Window::~Window()
    {
        delete handler;
    }

    String Window::get_title() const
    {
        return title;
    }

    bool Window::should_close() const
    {
        return handler->should_close();
    }

    void Window::set_title(const String& new_title)
    {
        this->title = new_title;
    }
}
