#include <untitled/console/logger.hpp>
#include "program.hpp"
using namespace Untitled;
using namespace Console;

int main(const int argc, char* argv[])
{
    Engine::Program program;
    return program.execute();
}