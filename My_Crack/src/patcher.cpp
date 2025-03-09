#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <stdbool.h>
#include <assert.h>
#include "Consts.h"

bool Draw_animated_background (sf::Clock* ptr_clock, sf::IntRect* ptr_rect_background, sf::Sprite* ptr_sprite_background);

//--------------------------------------------------------------------------------------------------------------------------
int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 1000), "KeyGen", sf::Style::Close | sf::Style::Titlebar);
    window.setVerticalSyncEnabled(true);

    window.setPosition(sf::Vector2i(320, 0));

    sf::Texture texture_background;
    if (!texture_background.loadFromFile("img/spritesheet.jfif"))
        assert(0);

    sf::IntRect rect_background({0, 0}, {WIDTH_IMAGE_PIX, HEIGHT_IMAGE_PIX});
    sf::Sprite sprite_background(texture_background, rect_background);
//--------------------------------------------------------------------------------------------------------------------------
    sf::Texture texture_binary;
    if (!texture_binary.loadFromFile("img/texture_binary.png"))
        assert(0);

    //stexture_binary.setRepeated(true);

    //Top_line
    sf::IntRect rect_top_line_binary({0, 0}, {WIDTH_IMAGE_PIX, 28});
    
    sf::Sprite sprite_top_line_binary(texture_binary, rect_background);
    sprite_top_line_binary.setPosition(sf::Vector2f(0.f, 722.f));

    //Bottom_line
    sf::IntRect rect_bottom_line_binary({0, 0}, {WIDTH_IMAGE_PIX, 28});

    sf::Sprite sprite_bottom_line_binary(texture_binary, rect_bottom_line_binary);
    sprite_bottom_line_binary.setPosition(sf::Vector2f(0.f, 1000.0f - 28.0f));

    //Left_line
    sf::IntRect rect_left_line_binary({0, 0}, {16, HEIGHT_WINDOW - HEIGHT_IMAGE_PIX});

    sf::Sprite sprite_left_line_binary(texture_binary, rect_left_line_binary);
    sprite_left_line_binary.setPosition(sf::Vector2f(0.0f, HEIGHT_IMAGE_PIX + 1.0f));

    //Right_line
    sf::IntRect rect_right_line_binary({0, 0}, {16, HEIGHT_WINDOW - HEIGHT_IMAGE_PIX});

    sf::Sprite sprite_right_line_binary(texture_binary, rect_right_line_binary);
    sprite_right_line_binary.setPosition(sf::Vector2f(WIDTH_IMAGE_PIX - 16.0f, HEIGHT_IMAGE_PIX + 1.0f));


    sprite_top_line_binary.setTextureRect(rect_top_line_binary);
    sprite_bottom_line_binary.setTextureRect(rect_bottom_line_binary);
    sprite_left_line_binary.setTextureRect(rect_left_line_binary);
    sprite_right_line_binary.setTextureRect(rect_right_line_binary);

    sprite_top_line_binary.setColor(sf::Color(0, 198, 49, 255)); 
    sprite_bottom_line_binary.setColor(sf::Color(0, 198, 49, 255)); 
    sprite_left_line_binary.setColor(sf::Color(0, 198, 49, 255)); 
    sprite_right_line_binary.setColor(sf::Color(0, 198, 49, 255));

//--------------------------------------------------------------------------------------------------------------------------
    sf::Font font;
    if (!font.loadFromFile("fonts/tekno.otf"))
        assert(0);

//--------------------------------------------------------------------------------------------------------------------------
    sf::Text text_crack;

    // select the font
    text_crack.setFont(font); // font is a sf::Font
        
    // set the string to display
    text_crack.setString("C R A C K E D  B Y  D A N E K");
        
    // set the character size
    text_crack.setCharacterSize(40); // in pixels, not points!
    
    // set the color
    text_crack.setFillColor(sf::Color(0, 198, 49, 255));

    text_crack.setPosition(450.0f, 20.0f);
//--------------------------------------------------------------------------------------------------------------------------    
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                
                case sf::Event::Resized:
                    window.setSize(sf::Vector2u(WIDTH_IMAGE_PIX, HEIGHT_WINDOW));
                    break;
                    
                default:
                    break;
            }
        }

        Draw_animated_background(&clock, &rect_background, &sprite_background);

        window.clear();
        window.draw(sprite_background);
        window.draw(sprite_top_line_binary);
        window.draw(sprite_bottom_line_binary);
        window.draw(sprite_left_line_binary);
        window.draw(sprite_right_line_binary);
        
        window.draw(text_crack);
        window.display();
    }
}
//--------------------------------------------------------------------------------------------------------------------------
bool Draw_animated_background (sf::Clock* ptr_clock, sf::IntRect* ptr_rect_background, sf::Sprite* ptr_sprite_background)
{
    if (ptr_clock->getElapsedTime().asSeconds() > TIME_BACKGROUND)
        {
            if ((ptr_rect_background->top   == HEIGHT_IMAGE_PIX * (HEIGHT_IMAGE_FRAME - 1))
             && (ptr_rect_background->left == WIDTH_IMAGE_PIX  * (EMPTY_WIDTH_FRAME  - 1)))
            {
                ptr_rect_background->top  = 0;
                ptr_rect_background->left = 0;
            }

            if (ptr_rect_background->left == WIDTH_IMAGE_PIX * (WIDTH_IMAGE_FRAME - 1))
            {
                ptr_rect_background->left = 0;
                if (ptr_rect_background->top == HEIGHT_IMAGE_PIX * (HEIGHT_IMAGE_FRAME - 1))
                    ptr_rect_background->top = 0;
                else 
                    ptr_rect_background->top += HEIGHT_IMAGE_PIX;
            }

            else
                ptr_rect_background->left += WIDTH_IMAGE_PIX;

            ptr_sprite_background->setTextureRect(*ptr_rect_background);
            ptr_clock->restart();
        }

    return true;
}
//--------------------------------------------------------------------------------------------------------------------------
