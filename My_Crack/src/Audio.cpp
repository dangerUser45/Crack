#include "../headers/PatcherConsts.h"
#include "../headers/Audio.h"

#ifndef SFML_included
    #include <SFML/Audio.hpp>
#endif

//--------------------------------------------------------------------------------------------------------------------------
sf::Music* CtorMusic ()
{
    sf::Music* music = new sf::Music;
    if (!music -> openFromFile(AUDIO_PATH MUSIC))
        exit(0);

    music -> play();

    return music;
}
//--------------------------------------------------------------------------------------------------------------------------
