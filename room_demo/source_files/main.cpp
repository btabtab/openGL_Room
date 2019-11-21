#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/gl.h>

#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */

#include "../header_files/float_to_GLfloat_header.h"

#include "../class_files/room_class.h"
#include "../class_files/ceiling_class.h"

#include "../header_files/sfml_variables_header.h"
#include "../class_files/class_mouse.h"
#include "../code_for_rendering/room_code.h"

#include "../class_files/camera_class.h"


using namespace std;

sf::VertexArray cameraline(sf::Lines, 4);// the line from the current point to the camera

sf::Clock time_elapsed; //main_clock

sf::RectangleShape background;

void old_draw()
{

    window.clear();


    //window.draw(background);
    window.draw(X_hair.body);


    window.display();
    //window.setView(camera);



}

void world_grid()
{
    glBegin(GL_LINE);/// X - red
    glVertex3f(1.f,1.f,1.f); glColor3f(1,0,0);
    glVertex3f(3.f,1.f,1.f); glColor3f(1,0,0);
    glEnd();

    glBegin(GL_LINE);/// Y - green
    glVertex3f(1.f,1.f,1.f); glColor3f(0,1,0);
    glVertex3f(1.f,3.f,1.f); glColor3f(0,1,0);
    glEnd();

    glBegin(GL_LINE);/// Z - blue
    glVertex3f(1.f,1.f,1.f); glColor3f(0,0,1);
    glVertex3f(1.f,1.f,3.f); glColor3f(0,0,1);
    glEnd();

}

void draw()
{
    window.clear();
        window.popGLStates();

        window.pushGLStates();


        ///...[code_goes_here]...///
///
        cam.input();

        world_grid();///draws the XYZ axis thingy.

        start_floor.render();
        start_ceiling.render();
///
        ///...[^^^^^^^^^^^^^^]...///

        window.draw(X_hair.body);

        window.display();

        X_hair.pos_apply();
        window.setView(camera);
}


int main()
{
//camera.zoom(0.02);

background.setFillColor(sf::Color::White);
background.setSize(sf::Vector2f(window.getSize()));

window.setMouseCursorVisible(false);
X_hair.sprite_load_apply();


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        /// ////////////////////////////////////////////

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
            cout << "feef" << endl;



        draw();

        /// ////////////////////////////////////////////
    }

    return 0;
}
