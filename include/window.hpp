#ifndef UNTITLED_ENGINE_WINDOW_GUARD
#define UNTITLED_ENGINE_WINDOW_GUARD
#include <untitled/string.hpp>
namespace Untitled::Engine
{
    struct WindowHandle;
    class Window
    {
        WindowHandle* handle;
        String title;
    public:
        Window();
        ~Window();
        void set_title(const String& new_title);
        [[nodiscard]] bool should_close() const;
        [[nodiscard]] String get_title() const;
        void show();
        void hide();
    };
}
#endif // UNTITLED_ENGINE_WINDOW_GUARD