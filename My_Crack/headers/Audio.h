#pragma once 

#ifndef SFML_included
    #include <SFML/Audio.hpp>
#endif

sf::Music* CtorMusic ();
sf::Sound* CtorSound (const char* path_to_sound);
