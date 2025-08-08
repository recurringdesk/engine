#ifndef UE_APP_GUARD
#define UE_APP_GUARD
#include "window.hpp"
namespace Untitled::Engine
{
    class App
    {
        Window* window;
    public:
        App(int argc, char* argv[]);
        int exec() const;
    };
}
#endif // UE_APP_GUARD