#ifndef UNTITLED_ENGINE_WINDOW_GUARD
#define UNTITLED_ENGINE_WINDOW_GUARD
#include <untitled/string.hpp>
namespace Untitled::Engine::System
{
    struct Handle;
    class Window
    {
        Handle* handler;
        String title;
    public:
        Window(const String& title = "Window", int width = 800, int height = 600);
        ~Window();
        void set_title(const String& new_title);
        bool should_close() const;
        String get_title() const;
        void show();
        void hide();
        void poll_events() const;
        void swap_buffer() const;
        void wait_events() const;
    };
}
#endif // UNTITLED_ENGINE_WINDOW_GUARD