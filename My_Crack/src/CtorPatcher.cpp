#include "../headers/ConstsPatcher.h"
#include "../headers/CtorPatcher.h"
#include "../headers/Color.h"

#ifndef SFML_included
    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
#endif

#include <stdio.h>

//--------------------------------------------------------------------------------------------------------------------------
int CtorCommon (Patcher* patcher)
{
    CtorBinaryFrame (patcher -> ArraySpritesLines);

    patcher -> sprite_bgd = CtorSpriteBackground();

    patcher -> window_ptr = CtorWindow();
    patcher -> music      = CtorMusic ();

    patcher -> sprite_context_button = CtorSpriteButton ();

    patcher -> font_techo_text = CtorFont (FONT_TECHO_TITLE);
    patcher -> font_retro_text = CtorFont (FONT_RETRO_TEXT);

    patcher -> button_text   = CtorButtonText (patcher -> font_techo_text);
    patcher -> text_title    = CtorTitleText (patcher -> font_techo_text);
    patcher -> greeting_text = CtorGreetingText (patcher -> font_retro_text);
    patcher -> final_text    = CtorFinalText (patcher -> font_retro_text);

    patcher -> key_sound_struct    = CtorSound (AUDIO_PATH KEY_SOUND);
    patcher -> button_sound_struct = CtorSound (AUDIO_PATH BUTTON_SOUND);

    patcher -> MusicPlay = true;
    patcher -> HackProgramOnce = true;
    patcher -> DrawHackingAnimation = false;
    patcher -> IsPaused = false;

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------
sf::RenderWindow* CtorWindow ()
{
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(WIDTH_IMAGE_PIX, HEIGHT_WINDOW), NAME_WINDOW, sf::Style::Close | sf::Style::Titlebar);
    
    window -> setVerticalSyncEnabled(true);
    window -> setPosition(sf::Vector2i(CENTRE_RELAT_WINDOW, 0)); 
    
    return window;
}
//--------------------------------------------------------------------------------------------------------------------------
sf::Text* CtorGreetingText (sf::Font* font)
{
    sf::Text* greeting_text = new sf::Text;
    greeting_text -> setFont(*font);
    greeting_text -> setString(GREETING_TEXT);
    greeting_text -> setCharacterSize(SIZE_FONT_TITLE); // in pixels, not points!
    greeting_text -> setFillColor(GreenColorAttributes);
    greeting_text -> setPosition(X_GREETING_TEXT, Y_GREETING_TEXT);

    return greeting_text;
}
//--------------------------------------------------------------------------------------------------------------------------
SpriteContext* CtorSpriteBackground()
{
    SpriteContext* sprite_context_background = new SpriteContext;

    sf::Texture* texture_background = new sf::Texture;
    if (!texture_background->loadFromFile(IMG_PATH TEXTURE_BACKGROUND))
        {
            printf("" RED "ERROR> %s, %d: The texture of background has not been loaded\n" RESET "", __FILE__, __LINE__);
            exit(-1);
        }
        

    sf::IntRect* rect_background  = new sf::IntRect({0, 0}, {WIDTH_IMAGE_PIX, HEIGHT_IMAGE_PIX});
    sf::Sprite* sprite_background = new sf::Sprite(*texture_background, *rect_background);

    sprite_context_background -> texture = texture_background;
    sprite_context_background -> rect    = rect_background;
    sprite_context_background -> sprite  = sprite_background;

    return sprite_context_background;
}
//--------------------------------------------------------------------------------------------------------------------------
sf::Font* CtorFont(std::string name_font)
{
    sf::Font* font = new sf::Font;                   
    if (!font -> loadFromFile(FONT_PATH + name_font))  
    {
        printf("" RED "ERROR> %s, %d: The font \"%s\" has not been loaded\n" RESET "", __FILE__, __LINE__, name_font.c_str());
        exit(-1);
    }                                
                                                     
    return font;                                     
}
//--------------------------------------------------------------------------------------------------------------------------
sf::Text* CtorTitleText (sf::Font* font_title_text)
{
    sf::Text* text_title = new sf::Text;
    text_title -> setFont(*font_title_text);
    text_title -> setString(TITLE);
    text_title -> setCharacterSize(SIZE_FONT_TITLE); // in pixels, not points!
    text_title -> setFillColor(GreenColorAttributes);
    text_title -> setPosition(X_TEXT_POSITION, Y_TEXT_POSITION);

    return text_title;
}
//--------------------------------------------------------------------------------------------------------------------------
bool CtorBinaryFrame (SpriteContext** sprites_lines_ptr)
{
    sf::Texture* texture_binary = new sf::Texture;

    if (!texture_binary -> loadFromFile(IMG_PATH TEXTURE_OUTLINES))
    {
        printf("" RED "ERROR> %s, %d: The texture binary has not been loaded\n" RESET "", __FILE__, __LINE__);
        exit(-1);
    }

    SpriteContext* sprite_context_top_line = CtorTopLine (texture_binary);
    SpriteContext* sprite_context_bottom_line = CtorBottomLine(texture_binary);
    SpriteContext* sprite_context_left_line = CtorLeftLine(texture_binary);
    SpriteContext* sprite_context_right_line = CtorRightLine(texture_binary);

    sprites_lines_ptr[TOP_LINE] = sprite_context_top_line;
    sprites_lines_ptr[BOTTOM_LINE] = sprite_context_bottom_line;
    sprites_lines_ptr[LEFT_LINE] = sprite_context_left_line;
    sprites_lines_ptr[RIGHT_LINE] = sprite_context_right_line;

    return true;
}
//--------------------------------------------------------------------------------------------------------------------------
SpriteContext* CtorTopLine (sf::Texture* texture_binary_ptr)
{
    sf::IntRect* rect_top_line_binary = new sf::IntRect({0, 0}, {WIDTH_IMAGE_PIX, HEIGHT_PIX_OUTLINES});
    
    sf::Sprite* sprite_top_line_binary = new sf::Sprite(*texture_binary_ptr, *rect_top_line_binary);

    sprite_top_line_binary -> setPosition(sf::Vector2f(0.0f, (float) HEIGHT_IMAGE_PIX + 1.0f));
    sprite_top_line_binary -> setTextureRect(*rect_top_line_binary);
    sprite_top_line_binary -> setColor(GreenColorAttributes); 

    SpriteContext* sprite_context_top_line = new SpriteContext;
    sprite_context_top_line -> texture = texture_binary_ptr;
    sprite_context_top_line -> rect = rect_top_line_binary;
    sprite_context_top_line -> sprite = sprite_top_line_binary;

    return sprite_context_top_line;
}
//--------------------------------------------------------------------------------------------------------------------------
SpriteContext* CtorBottomLine (sf::Texture* texture_binary_ptr)
{
    sf::IntRect* rect_bottom_line_binary = new sf::IntRect({0, BIAS_BOTTOM_RECT_Y}, {WIDTH_IMAGE_PIX, HEIGHT_PIX_OUTLINES});
    
    sf::Sprite* sprite_bottom_line_binary = new sf::Sprite(*texture_binary_ptr, *rect_bottom_line_binary);

    sprite_bottom_line_binary -> setPosition(sf::Vector2f(0.f, (float) (HEIGHT_WINDOW - HEIGHT_PIX_OUTLINES)));
    sprite_bottom_line_binary -> setTextureRect(*rect_bottom_line_binary);
    sprite_bottom_line_binary -> setColor(GreenColorAttributes);

    SpriteContext* sprite_context_bottom_line = new SpriteContext;
    sprite_context_bottom_line -> texture = texture_binary_ptr;
    sprite_context_bottom_line -> rect = rect_bottom_line_binary;
    sprite_context_bottom_line -> sprite = sprite_bottom_line_binary;

    return sprite_context_bottom_line;
}
//--------------------------------------------------------------------------------------------------------------------------
SpriteContext* CtorLeftLine (sf::Texture* texture_binary_ptr)
{
    sf::IntRect* rect_left_line_binary = new sf::IntRect({0, 0}, {WIDTH_PIX_OUTLINES, HEIGHT_WINDOW - HEIGHT_IMAGE_PIX});
    
    sf::Sprite* sprite_left_line_binary = new sf::Sprite(*texture_binary_ptr, *rect_left_line_binary);

    sprite_left_line_binary -> setPosition(sf::Vector2f(0.0f, HEIGHT_IMAGE_PIX + 1.0f));
    sprite_left_line_binary -> setTextureRect(*rect_left_line_binary);
    sprite_left_line_binary -> setColor(GreenColorAttributes); 

    SpriteContext* sprite_context_left_line = new SpriteContext;
    sprite_context_left_line -> texture = texture_binary_ptr;
    sprite_context_left_line -> rect = rect_left_line_binary;
    sprite_context_left_line -> sprite = sprite_left_line_binary;

    return sprite_context_left_line;
}
//--------------------------------------------------------------------------------------------------------------------------
SpriteContext* CtorRightLine (sf::Texture* texture_binary_ptr)
{
    sf::IntRect* rect_right_line_binary = new sf::IntRect({0, 0}, {WIDTH_PIX_OUTLINES, HEIGHT_WINDOW - HEIGHT_IMAGE_PIX});
    
    sf::Sprite* sprite_right_line_binary = new sf::Sprite(*texture_binary_ptr, *rect_right_line_binary);

    sprite_right_line_binary -> setPosition(sf::Vector2f(WIDTH_IMAGE_PIX - WIDTH_PIX_OUTLINES, HEIGHT_IMAGE_PIX + 1.0f));
    sprite_right_line_binary -> setTextureRect(*rect_right_line_binary);
    sprite_right_line_binary -> setColor(GreenColorAttributes); 

    SpriteContext* sprite_context_right_line = new SpriteContext;
    sprite_context_right_line -> texture = texture_binary_ptr;
    sprite_context_right_line -> rect = rect_right_line_binary;
    sprite_context_right_line -> sprite = sprite_right_line_binary;

    return sprite_context_right_line;
}
//--------------------------------------------------------------------------------------------------------------------------
SpriteContext* CtorSpriteButton ()
{
    SpriteContext* sprite_context_button = new SpriteContext;

    sf::Texture* texture_button = new sf::Texture;
    if (!texture_button->loadFromFile(IMG_PATH TEXTURE_BUTTON))
    {
        printf("" RED "ERROR> %s, %d: The texture of button has not been loaded\n" RESET "", __FILE__, __LINE__);
        exit(-1);
    }

    sf::IntRect* rect_button = new sf::IntRect({0, 0}, {WIDTH_BUTTON, HEIGTH_BUTTON});
    sf::Sprite* sprite_button = new sf::Sprite (*texture_button, *rect_button);

    sprite_button -> scale(SCALE_BUTTON);
    sprite_button -> setTextureRect (*rect_button);
    sprite_button -> setColor(GreenColorAttributes);
    sprite_button -> setPosition(sf::Vector2f((float)X_LEFT_SIDE_BUTTON, (float) Y_BOTTOM_SIDE_BUTTON));

    sprite_context_button -> texture = texture_button;
    sprite_context_button -> rect = rect_button;
    sprite_context_button -> sprite = sprite_button;

    return sprite_context_button;
}
//--------------------------------------------------------------------------------------------------------------------------
sf::Text* CtorButtonText (sf::Font* font_button_text)
{
    sf::Text* button_text = new sf::Text;
    button_text -> setFont(*font_button_text);
    button_text -> setString(BUTTON_TEXT);
    button_text -> setCharacterSize(SIZE_FONT_BUTTON_TEXT); // in pixels, not points!
    button_text -> setFillColor(GreenButton);
    button_text -> setPosition(X_BUTTON_POSITION, Y_BUTTON_POSITION);

    return button_text;
}
//--------------------------------------------------------------------------------------------------------------------------
HackAnimCntxt* CtorHackingAnimation()
{
    HackAnimCntxt* hacking_anim = new HackAnimCntxt;
    
    sf::Font* font_message_hack = CtorFont(FONT_RETRO_TEXT);
    sf::Text* text_hacking_animation = CtorMessageHack (font_message_hack);

    SpriteContext* sprite_animation_hacking = CtorSpriteAnimationHacking ();

    hacking_anim -> sprite_context = sprite_animation_hacking;
    hacking_anim -> text = text_hacking_animation;
    hacking_anim -> font = font_message_hack;

    return hacking_anim;
}
//--------------------------------------------------------------------------------------------------------------------------
sf::Text* CtorMessageHack (sf::Font* font_message_hack)
{
    sf::Text* text_message_hack = new sf::Text;
    text_message_hack -> setFont (*font_message_hack);
    text_message_hack -> setString (TEXT_HACK_MESSAGE);
    text_message_hack -> setCharacterSize (SIZE_FONT_TEXT_HACK_MESSAGE); // in pixels, not points!
    text_message_hack -> setFillColor (GreenColorAttributes);
    text_message_hack -> setPosition (X_TEXT_HACK_MESSAGE, Y_TEXT_HACK_MESSAGE);

    return text_message_hack;
}
//--------------------------------------------------------------------------------------------------------------------------
SpriteContext* CtorSpriteAnimationHacking ()
{
    SpriteContext* sprite_context_animation = new SpriteContext;
    sf::Texture* texture_animation = new sf::Texture;
    if(!texture_animation->loadFromFile(IMG_PATH TEXTURE_HACKING_ANIMATION))
    {
        printf("" RED "ERROR> %s, %d: The texture of progress bar has not been loaded\n" RESET "", __FILE__, __LINE__);
        exit(-1);
    }
    
    sf::IntRect* rect_animation = new sf::IntRect({0, 0}, {WIDTH_HACKING_ANIMATION, HEIGHT_HACKING_ANIMATION});
    sf::Sprite* sprite_animation = new sf::Sprite(*texture_animation, *rect_animation);

    sprite_animation -> setScale (SCALE_PROGRESS_BAR);
    sprite_animation -> setPosition (sf::Vector2f(X_HACKING_ANIMATION, Y_HACKING_ANIMATION));
    sprite_animation -> setTextureRect (*rect_animation);
    sprite_animation -> setColor (GreenColorAttributes); 

    sprite_context_animation -> texture = texture_animation;
    sprite_context_animation -> rect    = rect_animation;
    sprite_context_animation -> sprite  = sprite_animation;
    
    return sprite_context_animation;
}
//--------------------------------------------------------------------------------------------------------------------------
sf::Text* CtorFinalText (sf::Font* font)
{
    sf::Text* final_text = new sf::Text;
    final_text -> setFont(*font);
    final_text -> setString(FINAL_TEXT);
    final_text -> setCharacterSize(SIZE_FONT_TITLE); // in pixels, not points!
    final_text -> setFillColor(GreenColorAttributes);
    final_text -> setPosition(X_FINAL_TEXT, Y_FINAL_TEXT);

    return final_text;
}
//--------------------------------------------------------------------------------------------------------------------------
sf::Music* CtorMusic ()
{
    sf::Music* music = new sf::Music;
    if (!music -> openFromFile(AUDIO_PATH MUSIC))
    {
        printf("" RED "ERROR> %s, %d: The music has not been loaded\n" RESET "", __FILE__, __LINE__);
        exit(-1);
    }
    
    music -> setVolume(50.f);

    music -> play();

    return music;
}
//--------------------------------------------------------------------------------------------------------------------------
SoundStruct* CtorSound (const char* path_to_sound)
{
    SoundStruct* sound_struct = new SoundStruct;

    sf::SoundBuffer* buffer = new sf::SoundBuffer;
    if (!buffer -> loadFromFile(path_to_sound))
    {
        printf("" RED "ERROR> %s, %d: The sound has not been loaded\n" RESET "", __FILE__, __LINE__);
        exit(-1);
    }
    sf::Sound* sound = new sf::Sound;
    sound -> setBuffer(*buffer);
    
    sound_struct -> sound_buffer = buffer;
    sound_struct -> sound = sound;

    return sound_struct;
}
//--------------------------------------------------------------------------------------------------------------------------
