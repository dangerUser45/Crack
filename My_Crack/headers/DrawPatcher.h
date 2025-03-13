#pragma once

#ifndef SFML_included
    #include <SFML/Graphics.hpp>
    #include <SFML/Audio.hpp>
#endif

#include "MachinePatcher.h"

int DrawCommon (Patcher* patcher);
void DrawStartFrames (Patcher* patcher);

void CheckButton (Patcher* patcher);
void CheckProgressBar (Patcher* patcher);

void DrawBinaryFrame (Patcher* patcher);
bool SetUpAnimatedBackground (Patcher* patcher);

SpriteContext* CtorSpriteAnimationHacking ();
sf::Text* CtorMessageHack (sf::Font* font_message_hack);
bool SetUpHackingAnimation (Patcher* patcher);
