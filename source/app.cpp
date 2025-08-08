#include "app.hpp"

namespace Untitled::Engine
{
    App::App(int argc, char* argv[])
        : window(new Window)
    {

    }
    int App::exec() const
    {
        while (!window->should_close())
        {

        }
        return 0;
    }
} // namespace Untitled::Engine