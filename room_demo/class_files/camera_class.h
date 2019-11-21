#ifndef CAMERA_CLASS_H_INCLUDED
#define CAMERA_CLASS_H_INCLUDED

class viewpoint
{
public:
    void input()
    {
        glRotatef(angle, X, Y, Z);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            X += 0.05;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            X -= 0.05;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            Y += 0.05;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            Y -= 0.05;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            Z += 0.05;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
            Z -= 0.05;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))
            angle -= 1;;

            std::cout << Y << std::endl;
    }

private:
    GLfloat angle;

    GLfloat X;
    GLfloat Y;
    GLfloat Z;
};

viewpoint cam;

#endif // CAMERA_CLASS_H_INCLUDED
