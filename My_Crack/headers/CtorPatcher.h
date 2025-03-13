#pragma once

#ifndef SFML_included
    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
#endif

#include "MachinePatcher.h"

int CtorCommon (Patcher* patcher);

sf::RenderWindow* CtorWindow ();

sf::Music* CtorMusic ();
SoundStruct* CtorSound (const char* path_to_sound);

SpriteContext* CtorSpriteBackground();
SpriteContext* CtorSpriteButton ();
SpriteContext* CtorSpriteAnimationHacking ();

sf::Font* CtorFont(std::string name_font);

sf::Text* CtorGreetingText ( sf::Font* font);
sf::Text* CtorTitleText (sf::Font* font_title_text);
sf::Text* CtorButtonText (sf::Font* font_message_text);
sf::Text* CtorFinalText (sf::Font* font);
sf::Text* CtorMessageHack (sf::Font* font_message_hack);

bool CtorBinaryFrame (SpriteContext** sprites_line_ptr);

SpriteContext* CtorTopLine (sf::Texture* texture_binary_ptr);
SpriteContext* CtorBottomLine (sf::Texture* texture_binary_ptr);
SpriteContext* CtorLeftLine (sf::Texture* texture_binary_ptr);
SpriteContext* CtorRightLine (sf::Texture* texture_binary_ptr);

HackAnimCntxt* CtorHackingAnimation ();

