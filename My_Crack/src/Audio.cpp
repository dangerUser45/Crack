#include "../headers/PatcherConsts.h"
#include "../headers/Audio.h"

#ifndef SFML_included
    #include <SFML/Audio.hpp>
#endif

#include <assert.h>

//--------------------------------------------------------------------------------------------------------------------------
sf::Music* CtorMusic ()
{
    sf::Music* music = new sf::Music;
    if (!music -> openFromFile(AUDIO_PATH MUSIC))
        assert(0);
    
    music -> setVolume(50.f);

    music -> play();

    return music;
}
//--------------------------------------------------------------------------------------------------------------------------
sf::Sound* CtorSound (const char* path_to_sound)
{
    sf::SoundBuffer* buffer = new sf::SoundBuffer;
    if (!buffer -> loadFromFile(path_to_sound))
        assert(0);

    sf::Sound* sound = new sf::Sound;
    sound -> setBuffer(*buffer);
    
    return sound;
}
//--------------------------------------------------------------------------------------------------------------------------
