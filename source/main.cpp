#include <recurring/console/logger.hpp>
#include <recurring/core/window.hpp>

using Recurring::System::OpenGL::Context;

int
main (const int argc, char* argv[])
{
    Context context;
    context.create (800, 600, "ReEngine");
    context.run (nullptr);
    return 0;
}