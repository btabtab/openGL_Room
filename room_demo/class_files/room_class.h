#ifndef ROOM_CLASS_H_INCLUDED
#define ROOM_CLASS_H_INCLUDED

class floor
{
public:

    void render()
    {
        //glRotatef(theta, 0.0f, 0.0f, 0.0f);
        glBegin(GL_TRIANGLE_FAN);



        for(int i = 0; i != coord_count; i++)
        {
            glColor3f(color[0], color[1], color[2]);
            glVertex3f(coords_X[i], coords_Y[i], coords_Z[i]);
        }


        glEnd();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::J))
        {
            std::cout << "theta = " << theta << std::endl;
            std::cin >> theta;

        }

    }

private:

    GLfloat theta = 95;

    GLfloat color[11]
    =
    {
        0.0f,///R
        1.0f,///G
        0.0f///B
    };

    GLfloat coords_X[10]
    =
    {
        -0.6,
        0.6,
        0.6,
        -0.6
    };

    GLfloat coords_Y[10]=
    {
        0.6,
        0.6,
        -0.6,
        -0.6
    };

    GLfloat coords_Z[10]
    =
    {
        0.5,
        0.5,
        0.5,
        0.5
    };

    int coord_count = 4;

};

floor start_floor;

#endif // ROOM_CLASS_H_INCLUDED
