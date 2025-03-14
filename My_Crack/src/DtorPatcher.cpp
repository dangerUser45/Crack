#include "../headers/DtorPatcher.h"

int DtorCommon (Patcher* patcher)
{
    DtorSpriteBackground (patcher);

    DtorWindowPtr (patcher);
    DtorMusic (patcher);

    DtorSpriteContextButton (patcher);

    DtorFont (patcher);
    DtorText (patcher);

    DtorSoundsBuffers (patcher);

    DtorBinaryFrame (patcher);

    if (patcher -> DrawHackingAnimation == true)
        DtorHackingAnimation (patcher);

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------
int DtorSpriteBackground (Patcher* patcher)
{
    delete patcher -> sprite_bgd -> rect;
    delete patcher -> sprite_bgd -> sprite;
    delete patcher -> sprite_bgd -> texture;
    delete patcher -> sprite_bgd;

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------
int DtorWindowPtr (Patcher* patcher)
{
    delete patcher -> window_ptr;

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------
int DtorMusic (Patcher* patcher)
{
    delete patcher -> music;

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------
int DtorSpriteContextButton (Patcher* patcher)
{
    delete patcher -> sprite_context_button -> rect;
    delete patcher -> sprite_context_button -> sprite;
    delete patcher -> sprite_context_button -> texture;
    delete patcher -> sprite_context_button;

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------
int DtorFont (Patcher* patcher)
{
    delete patcher -> font_techo_text;
    delete patcher -> font_retro_text;

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------
int DtorText (Patcher* patcher)
{
    delete patcher -> button_text;
    delete patcher -> text_title;
    delete patcher -> greeting_text;
    delete patcher -> final_text;

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------
int DtorSoundsBuffers (Patcher* patcher)
{
    delete patcher -> key_sound_struct -> sound;
    delete patcher -> key_sound_struct -> sound_buffer;
    delete patcher -> key_sound_struct;

    delete patcher -> button_sound_struct -> sound;
    delete patcher -> button_sound_struct -> sound_buffer;
    delete patcher -> button_sound_struct;

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------
int DtorBinaryFrame (Patcher* patcher)
{
    delete patcher -> ArraySpritesLines[0] -> texture;

    DtorOneLineFrame (patcher, TOP_LINE);
    DtorOneLineFrame (patcher, BOTTOM_LINE);
    DtorOneLineFrame (patcher, LEFT_LINE);
    DtorOneLineFrame (patcher, RIGHT_LINE);

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------
int DtorOneLineFrame (Patcher* patcher, NameLine number)
{
    delete patcher -> ArraySpritesLines[number] -> rect;
    delete patcher -> ArraySpritesLines[number] -> sprite;
    delete patcher -> ArraySpritesLines[number];

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------
int DtorHackingAnimation (Patcher* patcher)
{
    delete patcher -> hacking_anim -> sprite_context -> rect;
    delete patcher -> hacking_anim -> sprite_context -> texture;
    delete patcher -> hacking_anim -> sprite_context ->sprite;
    delete patcher -> hacking_anim -> sprite_context;
    delete patcher -> hacking_anim -> font;
    delete patcher -> hacking_anim -> text;
    delete patcher -> hacking_anim;

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------
