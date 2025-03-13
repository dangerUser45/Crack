#pragma once

#include "ConstsPatcher.h"

#ifndef SFML_included
    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
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

struct HackAnimCntxt
{
    SpriteContext* sprite_context;
    sf::Text* text;
    sf::Font* font;
};

struct SoundStruct
{
    sf::SoundBuffer* sound_buffer;
    sf::Sound* sound;
};

struct Patcher
{
    SpriteContext* sprite_bgd;

    sf::RenderWindow* window_ptr;
    sf::Music* music;

    SpriteContext* sprite_context_button;

    sf::Font* font_techo_text;
    sf::Font* font_retro_text;

    sf::Text* button_text;
    sf::Text* text_title;
    sf::Text* greeting_text;
    sf::Text* final_text;

    SoundStruct* key_sound_struct;
    SoundStruct* button_sound_struct;

    SpriteContext* ArraySpritesLines[NUMBER_LINE];

    sf::Clock clock_background;
    sf::Clock clock_progress_bar;

    sf::Event* event;
    
    HackAnimCntxt* hacking_anim;

    bool MusicPlay;
    bool HackProgramOnce;
    bool DrawHackingAnimation;
    bool IsPaused;
    char CounterFramesProgressBar;
};
 
#define DELETE(ptr) delete ptr; ptr == NULL
