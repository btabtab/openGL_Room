#ifndef WORL_VISUALISATION_HEADER_H_INCLUDED
#define WORL_VISUALISATION_HEADER_H_INCLUDED

#include <SFML/OpenGL.hpp>
#include "sfml_variables_header.h"

#include <windows.h>
#include <gl/gl.h>
#include <GL/gl.h>

class world
{
public:
    sf::Vector3f global_coords;

    sf::VertexArray cube;


    void test()
    {

        glClearColor (0.0f, 0.0f, 0.0f, 0.0f);
            glClear (GL_COLOR_BUFFER_BIT);

            glPushMatrix ();
            glRotatef (0, 0.0f, 0.0f, 1.0f);
            glBegin (GL_TRIANGLES);
            glColor3f (1.0f, 0.0f, 0.0f);   glVertex2f (0.0f, 1.0f);
            glColor3f (0.0f, 1.0f, 0.0f);   glVertex2f (0.87f, -0.5f);
            glColor3f (0.0f, 0.0f, 1.0f);   glVertex2f (-0.87f, -0.5f);
            glEnd ();
            glPopMatrix ();

    }

};



world ZA;
#endif // WORL_VISUALISATION_HEADER_H_INCLUDED
