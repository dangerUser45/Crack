#include "../headers/PatcherConsts.h"
#include "../headers/Machine.h"
#include "../headers/CtorAndDraw.h"
#include "../headers/Hacking.h"
#include "../headers/Audio.h"

#ifndef SFML_included
    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
#endif

#include <iostream>
#include <assert.h>

//--------------------------------------------------------------------------------------------------------------------------
int main()
{
    sf::RenderWindow* window_ptr = CtorWindow();

    SpriteContext* sprite_bgd = CtorSpriteBackground();

    SpriteContext* sprite_context_button = CtorSpriteButton ();

    sf::Font* font_techo_text = CtorFont (FONT_TECHO_TITLE);
    sf::Font* font_retro_text = CtorFont (FONT_RETRO_TEXT);

    sf::Text* button_text   = CtorButtonText (font_techo_text);
    sf::Text* text_title    = CtorTitleText (font_techo_text);
    sf::Text* greeting_text = CtorGreetingText (font_retro_text);
    sf::Text* final_text    = CtorFinalText (font_retro_text);

    SpriteContext* ArraySpritesLines[NUMBER_LINE];
    CtorBinaryFrame (ArraySpritesLines);

    sf::Clock clock_background;
    sf::Clock clock_progress_bar;
    HackAnimCntxt* hacking_anim = 0;

    sf::Music* music = CtorMusic ();

    bool MusicPlay = true;
    bool HackProgrammOnce = true;
    bool DrawHackingAnimation = false;
    bool IsPaused = false;
    char CounterFramesProgressBar = 0;

    while (window_ptr -> isOpen())
    {
        sf::Event event;
        ProcessingEvents (window_ptr, &event);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RControl)
        && (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Delete)))
        {
            window_ptr -> close();
            break;
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Space)
        {
            IsPaused = !IsPaused;
            MusicPlay = !MusicPlay;
            if (MusicPlay == true)
                music -> play();
            else music -> pause();
        }
        
        if (!IsPaused)
        {
            window_ptr -> clear();
            SetUpAnimatedBackground(&clock_background,  sprite_bgd -> rect, sprite_bgd -> sprite);

            if (HackProgrammOnce)
            {
                window_ptr -> draw (*greeting_text);
                window_ptr -> draw (*(sprite_context_button -> sprite));
                window_ptr -> draw (*button_text);

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    sf::Vector2i localPosition = sf::Mouse::getPosition(*window_ptr);
                    if ((localPosition.x >= 1000 && localPosition.x <= 1000 + 326) 
                    &&  (localPosition.y >= 822  && localPosition.y <= 822 + 181))
                        {
                            Hacking();
                            HackProgrammOnce = false;
                            DrawHackingAnimation = true;
                            hacking_anim = CtorHackingAnimation();
                        }
                }
            }


            window_ptr -> draw (*(sprite_bgd -> sprite));
            DrawBinaryFrame (window_ptr, ArraySpritesLines);

            window_ptr -> draw (*text_title);

            if (CounterFramesProgressBar <= NUMBER_FRAME_PROGRESS_BAR - 1)
            {
                if (DrawHackingAnimation)
                {
                    window_ptr -> draw (*(hacking_anim -> text));
                    SetUpHackingAnimation (&clock_progress_bar, hacking_anim -> sprite_context, &CounterFramesProgressBar);
                    window_ptr -> draw (*(hacking_anim -> sprite_context -> sprite));
                }
            }

            else
                window_ptr -> draw (*final_text);

            window_ptr -> display ();
        }
    }
}
//--------------------------------------------------------------------------------------------------------------------------
