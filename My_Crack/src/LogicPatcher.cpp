#include "../headers/LogicPatcher.h"
#include "../headers/ConstsPatcher.h"

bool Logic (Patcher* patcher)
{
    ProcessingEvents (patcher);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RControl)
        && (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Delete)))
        {
            patcher -> window_ptr -> close();
            return true;
        }
    
    return false;
}
//--------------------------------------------------------------------------------------------------------------------------
void ProcessingEvents (Patcher* patcher)
{
    sf::Event event;
    patcher -> event = &event;

    while (patcher -> window_ptr -> pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
            patcher -> window_ptr -> close();
            return;
            
            case sf::Event::Resized:
            patcher -> window_ptr -> setSize(sf::Vector2u(WIDTH_IMAGE_PIX, HEIGHT_WINDOW));
            return;
            
            case sf::Event::KeyPressed:
            {
                KeyPressedProcessing (patcher);
                return; 
            }

            default:
                return;
        }
    }
    return;
}
//--------------------------------------------------------------------------------------------------------------------------
void KeyPressedProcessing (Patcher* patcher)
{
    patcher -> key_sound_struct -> sound -> play();
                
    if (patcher -> event-> key.code == sf::Keyboard::Key::Space)
    {
        patcher -> IsPaused = !(patcher -> IsPaused);
        patcher -> MusicPlay = !(patcher -> MusicPlay);
        if (patcher -> MusicPlay == true)
            patcher -> music -> play();
        else 
            patcher -> music -> pause();
    }
    
    return;
}
//--------------------------------------------------------------------------------------------------------------------------
