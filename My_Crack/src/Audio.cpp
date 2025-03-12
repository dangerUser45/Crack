#include "../headers/PatcherConsts.h"
#include "../headers/Audio.h"
#include "../headers/Machine.h"

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
SoundStruct* CtorSound (const char* path_to_sound)
{
    SoundStruct* sound_struct = new SoundStruct;

    sf::SoundBuffer* buffer = new sf::SoundBuffer;
    if (!buffer -> loadFromFile(path_to_sound))
        assert(0);

    sf::Sound* sound = new sf::Sound;
    sound -> setBuffer(*buffer);
    
    sound_struct -> sound_buffer = buffer;
    sound_struct -> sound = sound;

    return sound_struct;
}
//--------------------------------------------------------------------------------------------------------------------------
