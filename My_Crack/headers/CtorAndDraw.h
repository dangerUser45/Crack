#pragma once

#ifndef SFML_included
    #include <SFML/Graphics.hpp>
    #include <SFML/Audio.hpp>
#endif

#include "Machine.h"

void ProcessingEvents (sf::RenderWindow* window_ptr, sf::Event* event, sf::Sound* key_sound, bool* IsPaused, bool* MusicPlay, sf::Music* music);

bool SetUpAnimatedBackground (sf::Clock* ptr_clock, sf::IntRect* ptr_rect_background, sf::Sprite* ptr_sprite_background);

sf::RenderWindow* CtorWindow ();

sf::Text* CtorGreetingText (sf::Font* font);

SpriteContext* CtorSpriteBackground();

HackAnimCntxt* CtorHackingAnimation();
SpriteContext* CtorSpriteAnimationHacking ();
sf::Text* CtorMessageHack (sf::Font* font_message_hack);
bool SetUpHackingAnimation (sf::Clock* clock, SpriteContext* sprite_context, char* const counter_frames);

sf::Font* CtorFont(std::string name_font);

sf::Text* CtorTitleText (sf::Font* font_title_text);
sf::Text* CtorButtonText (sf::Font* font_message_text);
SpriteContext* CtorSpriteButton ();

bool CtorBinaryFrame (SpriteContext** sprites_line_ptr);
SpriteContext* CtorTopLine (sf::Texture* texture_binary_ptr);
SpriteContext* CtorBottomLine (sf::Texture* texture_binary_ptr);
SpriteContext* CtorLeftLine (sf::Texture* texture_binary_ptr);
SpriteContext* CtorRightLine (sf::Texture* texture_binary_ptr);
void DrawBinaryFrame (sf::RenderWindow* window_ptr, SpriteContext** ArraySpritesLines);

sf::Text* CtorFinalText (sf::Font* font);
