#pragma once

#ifndef SFML_included
    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
#endif

enum NameLine 
{
    TOP_LINE = 0,
    BOTTOM_LINE,
    LEFT_LINE,
    RIGHT_LINE
};

struct SpriteContext
{
    sf::Sprite* sprite;
    sf::Texture* texture;
    sf::IntRect* rect;
};
