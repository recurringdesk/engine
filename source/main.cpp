#include "rutils/graphics/node.hpp"
#include "rutils/math/objects/vector2d.hpp"
#include <rutils/console/logger.hpp>
#include <rutils/graphics/window.hpp>

#include <GL/glew.h>

using Recurring::Console::Logger;
using Recurring::Core::Node;
using Recurring::Math::Vector2D;
using Recurring::System::OpenGL::Context;

void my_framebuffer_size_callback (Handle*, int, int);

namespace Recurring::Engine
{

    class Mesh
    {
    protected:
        Vector2D* vertices = nullptr;

    public:
        virtual void draw () = 0;

        ~Mesh ()
        {
            if (vertices)
                delete vertices;
        }

        [[nodiscard]]
        Vector2D&
        get_vertex (unsigned index)
        {
            return vertices[index];
        }

        [[nodiscard]]
        Vector2D*
        get_vertices ()
        {
            return vertices;
        }
    };

    class MySquare : public Mesh
    {
    public:
        MySquare (Vector2D* new_vertices)
        {

            if (!vertices)
                vertices = new Vector2D[4];

            if (!new_vertices)
            {
                Logger::print (Logger::WARNING, "NO NEW VERTICES");
                return;
            }

            for (int index = 0; index < 4; ++index)
            {
                vertices[index] = new_vertices[index];
                Logger::print ("this is being set ", vertices[index].x, 'x', vertices[index].y);
            }
        }

        void
        draw () override
        {
            // Logger::print ("Drawing");

            glBegin (GL_QUADS);
            for (int index = 0; index < 4; ++index)
                glVertex2f (vertices[index].x, vertices[index].y);
            glEnd ();
        }
    };

    class MyNode : public Node
    {
    private:
        Vector2D my_vertices[4];
        MySquare* my_square;

    public:
        MyNode ()
        {
        }

        ~MyNode ()
        {
            delete my_square;
        }

        void
        ready () override
        {
            my_vertices[0] = { 1.0f / 2.0f, 1.0f / 2.0f };  // Top, right
            my_vertices[1] = { -1.0f / 2.0f, 1.0f / 2.0f }; // Top, left

            my_vertices[2] = { -1.0f / 2.0f, -1.0f / 2.0f }; // Bottom, left
            my_vertices[3] = { 1.0f / 2.0f, -1.0f / 2.0f };  // Bottom, right
            my_square = new MySquare (my_vertices);
        }

        void
        process () override
        {
            glClear (GL_COLOR_BUFFER_BIT);
            glClearColor (0.1f, 0.2f, 0.1f, 1.0f);
            my_square->draw ();
        }
    };

} // namespace Recurring::Engine

using namespace Recurring::Engine;

int
main (const int argc, char* argv[])
{
    Logger::print (Logger::INFO, "Hello, world!");
    Context my_context;
    my_context.create (800, 600, "ReEngine");
    my_context.set_framebuffer_size_callback (my_framebuffer_size_callback);
    return my_context.run (new MyNode);
}

void
my_framebuffer_size_callback (Handle*, int width, int height)
{
    glViewport (0, 0, width, height);
}