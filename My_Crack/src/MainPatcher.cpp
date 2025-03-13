#include "../headers/CtorPatcher.h"
#include "../headers/LogicPatcher.h"
#include "../headers/DrawPatcher.h"
#include "../headers/DtorPatcher.h"

#ifndef SFML_included
    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Audio.hpp>
#endif

//--------------------------------------------------------------------------------------------------------------------------
int main()
{
    Patcher patcher = {};
    CtorCommon(&patcher);

    while (patcher.window_ptr -> isOpen())
    {
        if(Logic (&patcher))
            break;

        DrawCommon(&patcher);
    }

    DtorCommon (&patcher);
}
//--------------------------------------------------------------------------------------------------------------------------
