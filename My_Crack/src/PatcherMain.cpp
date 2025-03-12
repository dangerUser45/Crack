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
