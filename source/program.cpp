#include "program.hpp"
#include "window.hpp"
#include <untitled/console/logger.hpp>

namespace Untitled::Engine
{
    int Program::execute()
    {
        Console::Logger::print("Hello, world!\n");
        System::Window window;
        while (!window.should_close())
        {
            window.swap_buffer();
            window.wait_events();
        }
        return 0;
    }
};