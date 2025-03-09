#include "../headers/PatcherConsts.h"
#include "../headers/CtorAndDraw.h"

#ifndef SFML_included
    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
#endif

#include <assert.h>

sf::RenderWindow* CtorWindow ()
{
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(WIDTH_IMAGE_PIX, HEIGHT_WINDOW), NAME_WINDOW, sf::Style::Close | sf::Style::Titlebar);
    
    window->setVerticalSyncEnabled(true);
    window->setPosition(sf::Vector2i(CENTRE_RELAT_WINDOW, 0)); 
    
    return window;
}
//--------------------------------------------------------------------------------------------------------------------------
void ProcessingEvents (sf::RenderWindow* window_ptr)
{
    sf::Event event;
    while (window_ptr -> pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
            window_ptr -> close();
            return;
            
            case sf::Event::Resized:
            window_ptr -> setSize(sf::Vector2u(WIDTH_IMAGE_PIX, HEIGHT_WINDOW));
            return;
            
            default:
            return;
        }
    }
    return;
}
//--------------------------------------------------------------------------------------------------------------------------
bool SetUpAnimatedBackground (sf::Clock* ptr_clock, sf::IntRect* ptr_rect_background, sf::Sprite* ptr_sprite_background)
{
    if (ptr_clock->getElapsedTime().asSeconds() > TIME_BACKGROUND)
        {
            if ((ptr_rect_background->top   == HEIGHT_IMAGE_PIX * (HEIGHT_IMAGE_FRAME - 1))
             && (ptr_rect_background->left == WIDTH_IMAGE_PIX  * (EMPTY_WIDTH_FRAME  - 1)))
            {
                ptr_rect_background->top  = 0;
                ptr_rect_background->left = 0;
            }

            if (ptr_rect_background->left == WIDTH_IMAGE_PIX * (WIDTH_IMAGE_FRAME - 1))
            {
                ptr_rect_background->left = 0;
                if (ptr_rect_background->top == HEIGHT_IMAGE_PIX * (HEIGHT_IMAGE_FRAME - 1))
                    ptr_rect_background->top = 0;
                else 
                    ptr_rect_background->top += HEIGHT_IMAGE_PIX;
            }

            else
                ptr_rect_background->left += WIDTH_IMAGE_PIX;

            ptr_sprite_background->setTextureRect(*ptr_rect_background);
            ptr_clock->restart();
        }

    return true;
}
//--------------------------------------------------------------------------------------------------------------------------
bool CtorSpriteBackground(SpriteContext* sprite_context_background)
{
    sf::Texture* texture_background = new sf::Texture;
    if (!texture_background->loadFromFile(IMG_PATH TEXTURE_BACKGROUND))
        assert(0);

    sf::IntRect* rect_background  = new sf::IntRect({0, 0}, {WIDTH_IMAGE_PIX, HEIGHT_IMAGE_PIX});
    sf::Sprite* sprite_background = new sf::Sprite(*texture_background, *rect_background);

    sprite_context_background->texture = texture_background;
    sprite_context_background->rect    = rect_background;
    sprite_context_background->sprite  = sprite_background;

    return true;
}
//--------------------------------------------------------------------------------------------------------------------------
sf::Font* CtorFontTitleText ()
{
    sf::Font* font = new sf::Font;
    if (!font -> loadFromFile(FONT_PATH FONT_TXT_TITLE))
        assert(0);

    return font;
}
//--------------------------------------------------------------------------------------------------------------------------
sf::Text* CtorTitleText (sf::Font* font_title_text)
{
    sf::Text* text_title = new sf::Text;
    text_title->setFont(*font_title_text);
    text_title->setString(TITLE);
    text_title->setCharacterSize(SIZE_FONT); // in pixels, not points!
    text_title->setFillColor(GreenColorAttributes);
    text_title->setPosition(X_TEXT_POSITION, Y_TEXT_POSITION);

    return text_title;
}
//--------------------------------------------------------------------------------------------------------------------------
bool CtorBinaryFrame (SpriteContext** sprites_lines_ptr)
{
    sf::Texture* texture_binary = new sf::Texture;

    if (!texture_binary -> loadFromFile(IMG_PATH TEXTURE_OUTLINES))
        assert(0);

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
void DrawBinaryFrame (sf::RenderWindow* window_ptr, SpriteContext** ArraySpritesLines)
{
    window_ptr -> draw(*(ArraySpritesLines[TOP_LINE]->sprite));
    window_ptr -> draw(*(ArraySpritesLines[BOTTOM_LINE]->sprite));
    window_ptr -> draw(*(ArraySpritesLines[LEFT_LINE]->sprite));
    window_ptr -> draw(*(ArraySpritesLines[RIGHT_LINE]->sprite));

    return;
}
//--------------------------------------------------------------------------------------------------------------------------
