#include "../headers/PatcherConsts.h"
#include "../headers/Machine.h"
#include "../headers/CtorAndDraw.h"

#ifndef SFML_included
    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
#endif

#include <assert.h>

//--------------------------------------------------------------------------------------------------------------------------
int main()
{
    sf::RenderWindow* window_ptr = CtorWindow();

    SpriteContext sprite_bgd = {};
    CtorSpriteBackground(&sprite_bgd);

    sf::Font* font_title = CtorFontTitleText ();
    sf::Text* text_title = CtorTitleText (font_title);

    SpriteContext* ArraySpritesLines[NUMBER_LINE];
    CtorBinaryFrame (ArraySpritesLines);

    sf::Clock clock;

    while (window_ptr -> isOpen())
    {
        ProcessingEvents (window_ptr);
        SetUpAnimatedBackground(&clock,  sprite_bgd.rect, sprite_bgd.sprite);

        window_ptr -> clear();
        window_ptr -> draw(*sprite_bgd.sprite);

        DrawBinaryFrame (window_ptr, ArraySpritesLines);

        window_ptr -> draw(*text_title);
        window_ptr -> display();
    }
}
//--------------------------------------------------------------------------------------------------------------------------
