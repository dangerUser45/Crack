#pragma once

#ifndef SFML_included
    #include <SFML/Graphics.hpp>
#endif

#include "Machine.h"

void ProcessingEvents (sf::RenderWindow* window_ptr);
bool SetUpAnimatedBackground (sf::Clock* ptr_clock, sf::IntRect* ptr_rect_background, sf::Sprite* ptr_sprite_background);
sf::RenderWindow* CtorWindow ();
bool CtorSpriteBackground(SpriteContext*);
sf::Font* CtorFontTitleText ();
sf::Text* CtorTitleText (sf::Font* font_title_text);
bool CtorBinaryFrame (SpriteContext** sprites_line_ptr);
SpriteContext* CtorTopLine (sf::Texture* texture_binary_ptr);
SpriteContext* CtorBottomLine (sf::Texture* texture_binary_ptr);
SpriteContext* CtorLeftLine (sf::Texture* texture_binary_ptr);
SpriteContext* CtorRightLine (sf::Texture* texture_binary_ptr);
void DrawBinaryFrame (sf::RenderWindow* window_ptr, SpriteContext** ArraySpritesLines);
