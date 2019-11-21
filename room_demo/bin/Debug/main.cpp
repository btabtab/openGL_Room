#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */

using namespace std;

sf::RectangleShape background(sf::Vector2f(800.f, 800.f));

sf::RenderWindow window(sf::VideoMode(800, 800), "fungi farm v1.4"); // creates the window
sf::View camera(sf::Vector2f(400.f, 400.f), sf::Vector2f(800.f, 800.f));// the code to crreate the sfml view for the program
sf::VertexArray cameraline(sf::Lines, 4);// the line from the current point to the camera
sf::Clock time_elapsed; //main_clock

sf::Clock spore_cycle;

float AX; float AY;
float BX; float BY;
float ABX; float ABY;

int randmovmax = 1; int randmovmin = 0;

void rand_move_generate()
{
    AX = rand() % randmovmax + randmovmin;
    AY = rand() % randmovmax + randmovmin;

    BX = rand() % randmovmax + randmovmin;
    BY = rand() % randmovmax + randmovmin;

    ABX = AX - BX;
    ABY = AY - BY;

    ABX = (ABX) + (AX - BX);
    ABY = (ABY) + (AY - BY);

}

float cursorX; float cursorY;
float movespeed = 0.5;
void cursor_move()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        cursorY = cursorY - movespeed;
        cout << "W" << endl;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        cursorY = cursorY + movespeed;
        cout << "S" << endl;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        cursorX = cursorX - movespeed;
        cout << "A" << endl;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        cursorX = cursorX + movespeed;
        cout << "D" << endl;
    }


}

int spore_count = 10;
sf::VertexArray spore_vertex(sf::Points, spore_count);

void draw()
{

    window.clear();
    //window.draw(background);
    window.draw(spore_vertex);

    window.display();
    window.setView(camera);

}

int counter; int spore;
float spore_X; float spore_Y; int d;
int move_max_reset;

float R = 255; float G = 255; float B = 255;
float tempnum;
void randcolegenerate()
{

    tempnum = rand() % 3 + 0;
    tempnum = tempnum - rand() % 3 + 0;
    R = R + tempnum;

    tempnum = rand() % 3 + 0;
    tempnum = tempnum - rand() % 3 + 0;
    G = G + tempnum;

    tempnum = rand() % 3 + 0;
    tempnum = tempnum - rand() % 3 + 0;
    B = B + tempnum;


}

void spore_life_cycle()
{

        spore_vertex.resize(spore_count);
        spore_count++; cout << " >" << spore_count << "< ";

        spore_X = spore_X + ABX;
        spore_Y = spore_Y + ABY;
        spore = rand() % spore_count + 1;
        spore_vertex[spore].position = sf::Vector2f(spore_X, spore_Y);

        spore_vertex[spore].color = sf::Color(R, G, B);
        randcolegenerate();

        counter++;

        cout << randmovmax << " " << randmovmin << " " << d <<" " << counter <<" " << spore_cycle.getElapsedTime().asMilliseconds() << endl;
        randmovmax = counter + randmovmin;
        if(counter == 100)
            counter = 0;

        if(spore_cycle.getElapsedTime().asMilliseconds() >= 1000)
        {
                randmovmin++;randmovmax++;
                move_max_reset++;
                d = 0;

                spore_cycle.restart();

        }
        else
        {
            d++;
        }
        spore_X = 0;
        spore_Y = 0;



}
int w;

void alternate_lifecycle()
{

        spore_vertex.resize(spore_count);
        spore_count++;

        spore_X = spore_X + ABX;
        spore_Y = spore_Y + ABY;

        spore_vertex[w].position = sf::Vector2f(spore_X, spore_Y);
        spore_vertex[w].color = sf::Color(R, G, B);
        randcolegenerate();

        counter++;

        cout << randmovmax << " " << randmovmin << " :w=:" << w <<" " << counter <<" " << spore_cycle.getElapsedTime().asMilliseconds() << endl;
        randmovmax = counter + randmovmin;
        if(counter == 100)
            counter = 0;

        if(spore_cycle.getElapsedTime().asMilliseconds() >= 1000)
        {
                randmovmin++;randmovmax++;
                move_max_reset++;
                d = 0;

                spore_cycle.restart();

        }
        else
        {
            d++;
        }
        spore_X = 0;
        spore_Y = 0;
        w++;


}

int seed;
int mode_limitless = 8;
void query()
{
    cout << "enter seed" << endl;
    cin >> seed;
    srand(seed);


    while (mode_limitless > 1 || mode_limitless < 0)
    {
        cout << "do you want immortal cells? (1 = yes, 0 = no)" << endl;
        cin >> mode_limitless;

    }

    if(mode_limitless == 1)
    {

    }
    cout << mode_limitless;
}

void mode_choice()
{

        if(mode_limitless == 1)
        {
            alternate_lifecycle();
        }
        else
        {
            spore_life_cycle();

        }

}

void key_detect()
{
if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
{
    spore_vertex.setPrimitiveType(sf::Points);
}
if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))
{
    spore_vertex.setPrimitiveType(sf::TriangleFan);
}

if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
    {
        spore_vertex.clear();
    }
}

if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
{
    camera.zoom(1.1);
}

if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
{
    camera.zoom(0.9);
}

}

void boring_stuff()
{
    background.setOrigin(400.f, 400.f);
}

int main()
{

query();


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        /// ////////////////////////////////////////////

        rand_move_generate();


        camera.setCenter(cursorX, cursorY);
        cursor_move();
        mode_choice();

        boring_stuff();
        key_detect();

        draw();

        /// ////////////////////////////////////////////
    }

    return 0;
}
