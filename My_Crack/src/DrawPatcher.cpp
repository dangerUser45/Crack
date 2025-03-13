#include "../headers/ConstsPatcher.h"
#include "../headers/CtorPatcher.h"
#include "../headers/DrawPatcher.h"
#include "../headers/HackingPatcher.h"

#ifndef SFML_included
    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
#endif

//--------------------------------------------------------------------------------------------------------------------------
int DrawCommon (Patcher* patcher)
{
    if (!(patcher -> IsPaused))
    {
        patcher -> window_ptr -> clear();
        SetUpAnimatedBackground(patcher);

        if (patcher -> HackProgramOnce)
        {
            patcher -> window_ptr -> draw (*patcher -> greeting_text);
            patcher -> window_ptr -> draw (*(patcher -> sprite_context_button -> sprite));
            patcher -> window_ptr -> draw (*patcher -> button_text);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i localPosition = sf::Mouse::getPosition(*patcher -> window_ptr);
                if ((localPosition.x >= X_LEFT_SIDE_BUTTON    && localPosition.x <= X_RIGHT_SIDE_BUTTON)
                &&  (localPosition.y >= Y_BOTTOM_SIDE_BUTTON  && localPosition.y <= Y_TOP_SIDE_BITTON))
                    {
                        Hacking();
                        patcher -> button_sound_struct -> sound -> play();
                        patcher -> HackProgramOnce = false;
                        patcher -> DrawHackingAnimation = true;
                        patcher  -> hacking_anim = CtorHackingAnimation();
                    }
            }
        }

        patcher -> window_ptr -> draw (*(patcher -> sprite_bgd -> sprite));
        DrawBinaryFrame (patcher);

        patcher -> window_ptr -> draw (*patcher -> text_title);

        if ((patcher -> CounterFramesProgressBar) <= NUMBER_FRAME_PROGRESS_BAR - 1)
        {
            if ((patcher -> DrawHackingAnimation))
            {
                patcher -> window_ptr -> draw (*(patcher -> hacking_anim -> text));
                SetUpHackingAnimation (patcher);
                patcher -> window_ptr -> draw (*(patcher -> hacking_anim -> sprite_context -> sprite));
            }
        }

        else
            patcher -> window_ptr -> draw (*patcher -> final_text);

        patcher -> window_ptr -> display ();
    }
    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------
bool SetUpAnimatedBackground (Patcher* patcher)
{

    sf::Clock clock = patcher -> clock_background;
    sf::IntRect rect = *(patcher -> sprite_bgd -> rect);

    if (clock.getElapsedTime().asSeconds() > TIME_BACKGROUND)
        {
            if ((rect.top   == HEIGHT_IMAGE_PIX * (HEIGHT_IMAGE_FRAME - 1))
             && (rect.left == WIDTH_IMAGE_PIX  * (EMPTY_WIDTH_FRAME  - 1)))
            {
                rect.top  = 0;
                rect.left = 0;
            }

            if (rect.left == WIDTH_IMAGE_PIX * (WIDTH_IMAGE_FRAME - 1))
            {
                rect.left = 0;
                if (rect.top == HEIGHT_IMAGE_PIX * (HEIGHT_IMAGE_FRAME - 1))
                    rect.top = 0;
                else 
                    rect.top += HEIGHT_IMAGE_PIX;
            }

            else
            rect.left += WIDTH_IMAGE_PIX;

            *(patcher -> sprite_bgd -> rect) = rect;

            patcher -> sprite_bgd -> sprite -> setTextureRect(*(patcher -> sprite_bgd -> rect));
            patcher -> clock_background.restart();
        }

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------
void DrawBinaryFrame (Patcher* patcher)
{
    sf::RenderWindow* window = patcher -> window_ptr;
    SpriteContext** Array = patcher -> ArraySpritesLines;

    window -> draw(*(Array[TOP_LINE] -> sprite));
    window -> draw(*(Array[BOTTOM_LINE] -> sprite));
    window -> draw(*(Array[LEFT_LINE] -> sprite));
    window -> draw(*(Array[RIGHT_LINE] -> sprite));

    return;
}
//--------------------------------------------------------------------------------------------------------------------------
bool SetUpHackingAnimation (Patcher* patcher)
{
    sf::IntRect rect = *(patcher -> hacking_anim -> sprite_context -> rect);
    sf::Sprite sprite = *(patcher -> hacking_anim ->sprite_context -> sprite);

    sf::Clock clock = patcher -> clock_progress_bar;

    if (clock.getElapsedTime().asSeconds() > TIME_PROGRESS_BAR)
        {
            (patcher -> CounterFramesProgressBar)++;
            if ((rect.top   == HEIGHT_HACKING_ANIMATION * (HEIGHT_FRAME_PROGRESS_BAR - 1))
             && (rect.left == WIDTH_HACKING_ANIMATION  * (EMPTY_WIDTH_FRAME_PROGRESS_BAR  - 1)))
            {
                rect.top  = 0;
                rect.left = 0;
            }

            if (rect.left == WIDTH_HACKING_ANIMATION * (WIDTH_FRAME_PROGRESS_BAR - 1))
            {
                rect.left = 0;
                if (rect.top == HEIGHT_HACKING_ANIMATION * (HEIGHT_FRAME_PROGRESS_BAR - 1))
                rect.top = 0;
                else 
                rect.top += HEIGHT_HACKING_ANIMATION;
            }

            else
            rect.left += WIDTH_HACKING_ANIMATION;

            *(patcher -> hacking_anim -> sprite_context -> rect) = rect;

            patcher -> hacking_anim -> sprite_context -> sprite -> setTextureRect(rect);
            patcher -> clock_progress_bar.restart();
        }

    return true;
}
//--------------------------------------------------------------------------------------------------------------------------
