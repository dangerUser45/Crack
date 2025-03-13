#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#define SFML_included

const int ERROR  = -1;

const float TIME_BACKGROUND   = 0.05f;
const float TIME_PROGRESS_BAR = 0.1f;

const int HEIGHT_WINDOW       = 1000;

const int WIDTH_IMAGE_PIX     = 1280;
const int HEIGHT_IMAGE_PIX    = 721;

const int WIDTH_IMAGE_FRAME   = 12;
const int HEIGHT_IMAGE_FRAME  = 21;

const int EMPTY_WIDTH_FRAME   = 8;
const int EMPTY_HEIGTH_FRAME  = 1;

const int CENTRE_RELAT_WINDOW = 320;

const int WIDTH_PIX_OUTLINES  = 16;
const int HEIGHT_PIX_OUTLINES = 28;

const int X_GREETING_TEXT = 82;
const int Y_GREETING_TEXT = 856;

const float X_TEXT_POSITION   = 450.0f;
const float Y_TEXT_POSITION   = 20.0f;

const int X_FINAL_TEXT = 82;
const int Y_FINAL_TEXT = 856;

const int SIZE_FONT_TITLE               = 40;
const int SIZE_FONT_BUTTON_TEXT         = 40;
const int SIZE_FONT_TEXT_HACK_MESSAGE   = 40;

const short int NUMBER_LINE   = 4;

const int BIAS_BOTTOM_RECT_Y  = 26;

const float X_BUTTON_POSITION  = 1055.0f;
const float Y_BUTTON_POSITION  = 850.0f;

const float X_TEXT_HACK_MESSAGE = 82.0f;
const float Y_TEXT_HACK_MESSAGE = 856.0f;

const float X_HACKING_ANIMATION = 412.0f;
const float Y_HACKING_ANIMATION = 800.0f;

const int WIDTH_HACKING_ANIMATION  =  350;
const int HEIGHT_HACKING_ANIMATION =  150;

const int WIDTH_FRAME_PROGRESS_BAR       = 6;
const int HEIGHT_FRAME_PROGRESS_BAR      = 14;
const int EMPTY_WIDTH_FRAME_PROGRESS_BAR = 3;
const char NUMBER_FRAME_PROGRESS_BAR     = 81;

const int X_LEFT_SIDE_BUTTON = 1000;
const int X_RIGHT_SIDE_BUTTON = 1326;
const int Y_TOP_SIDE_BITTON = 822 + 181;
const int Y_BOTTOM_SIDE_BUTTON = 822;

const int WIDTH_BUTTON = 326;
const int HEIGTH_BUTTON = 181;

const sf::Vector2f SCALE_BUTTON{0.6,0.6};
const sf::Vector2f SCALE_PROGRESS_BAR{1.3f, 1.0f};

const int WINDOW_CLOSE = 1;

const sf::Color GreenColorAttributes(0, 198, 49, 255);
const sf::Color GreenButton(0, 255, 63, 255);

#define NAME_HACKING_PROGRAMM "../programm_to_hack/Evgeniuys_Crack.com"
#define OPENING_MODE "rb+"

const unsigned char HACKING_BYTES2[3] = {0xE9, 0x27, 0x00};


#define HACKING_BYTES( ... ) {0xE9, 0x27, 0x00} // 0xEA - опкод near jump
                                                // 0x27  0x00 - смещение адреcа пароля 
                                                //           относительно начала программы 

#define NAME_WINDOW  "KeyGen"

#define IMG_PATH  "../img/"
#define FONT_PATH "../fonts/"
#define AUDIO_PATH "../audio/"

#define FONT_TECHO_TITLE "tekno.otf"
#define FONT_RETRO_TEXT "retro.ttf"

#define MUSIC "mario_music_background.mp3"
#define KEY_SOUND "key_sound.ogg"
#define BUTTON_SOUND "button_sound.mp3"

#define TITLE "C R A C K E D  B Y  D A N E K"
#define BUTTON_TEXT "CRACK"
#define TEXT_HACK_MESSAGE "Program hacking..."
#define GREETING_TEXT "Hello... Click the button to hack the program"
#define FINAL_TEXT "Successful ! Press [R_Ctrl + Del] to close the window"

#define TEXTURE_BACKGROUND "spritesheet.jfif"
#define TEXTURE_OUTLINES "texture_binary.png"
#define TEXTURE_BUTTON "button.png"
#define TEXTURE_HACKING_ANIMATION "ProgressBarSpriteSheet.png"
