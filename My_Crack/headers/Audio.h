#pragma once 

#include "../headers/Machine.h"

#ifndef SFML_included
    #include <SFML/Audio.hpp>
#endif

sf::Music* CtorMusic ();
SoundStruct* CtorSound (const char* path_to_sound);
