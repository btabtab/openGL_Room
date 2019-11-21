#ifndef CLASS_MOUSE_H_INCLUDED
#define CLASS_MOUSE_H_INCLUDED
#include <SFML/System.hpp>

#include <iostream>
using namespace std;
class mouse
{
public:
    sf::Vector2f position;

    sf::Sprite body;
    sf::Texture texture;
    sf::Image image;

    void sprite_load_apply()
    {
        if(!image.loadFromFile("cursor.bmp"));

        for(int y = 0; y <=30; y++)
        {
            for(int x = 0; x <= 30; x++)
            {
                cout << "x = " << x << " y = " << y << endl;
                if(image.getPixel(x, y) == sf::Color::Black)
                    image.setPixel(x, y, sf::Color(0, 0, 0, 0));
            }
        }

        texture.loadFromImage(image);
        body.setTexture(texture);

        body.setOrigin(15, 15);//the center of the sprite used for the cursor.
    }

    void pos_apply()
    {
        body.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
    }
};

mouse X_hair;
#endif // CLASS_MOUSE_H_INCLUDED
