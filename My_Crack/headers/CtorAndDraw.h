#pragma once

#ifndef SFML_included
    #include <SFML/Graphics.hpp>
    #include <SFML/Audio.hpp>
#endif

#include "Machine.h"

bool Logic (Patcher* patcher);
int DrawCommon (Patcher* patcher);
void DrawBinaryFrame (Patcher* patcher);
void ProcessingEvents (Patcher* patcher);
bool SetUpAnimatedBackground (Patcher* patcher);
void KeyPressedProcessing (Patcher* patcher);

int CtorCommon (Patcher* patcher);
sf::RenderWindow* CtorWindow ();
sf::Text* CtorGreetingText ( sf::Font* font);
SpriteContext* CtorSpriteBackground();
sf::Font* CtorFont(std::string name_font);
sf::Text* CtorTitleText (sf::Font* font_title_text);
sf::Text* CtorButtonText (sf::Font* font_message_text);
SpriteContext* CtorSpriteButton ();
bool CtorBinaryFrame (SpriteContext** sprites_line_ptr);
SpriteContext* CtorTopLine (sf::Texture* texture_binary_ptr);
SpriteContext* CtorBottomLine (sf::Texture* texture_binary_ptr);
SpriteContext* CtorLeftLine (sf::Texture* texture_binary_ptr);
SpriteContext* CtorRightLine (sf::Texture* texture_binary_ptr);
sf::Text* CtorFinalText (sf::Font* font);
HackAnimCntxt* CtorHackingAnimation ();

int DtorCommon (Patcher* patcher);
int DtorSpriteBackground (Patcher* patcher);
int DtorWindowPtr (Patcher* patcher);
int DtorMusic (Patcher* patcher);
int DtorSpriteContextButton (Patcher* patcher);
int DtorFont (Patcher* patcher);
int DtorText (Patcher* patcher);
int DtorSoundsBuffers (Patcher* patcher);
int DtorBinaryFrame (Patcher* patcher);
int DtorOneLineFrame (Patcher* patcher, NameLine number);
int DtorHackingAnimation (Patcher* patcher);

SpriteContext* CtorSpriteAnimationHacking ();
sf::Text* CtorMessageHack (sf::Font* font_message_hack);
bool SetUpHackingAnimation (Patcher* patcher);