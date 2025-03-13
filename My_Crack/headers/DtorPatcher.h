#include "MachinePatcher.h"

int DtorCommon (Patcher* patcher);

int DtorWindowPtr (Patcher* patcher);

int DtorSpriteBackground (Patcher* patcher);
int DtorSpriteContextButton (Patcher* patcher);


int DtorFont (Patcher* patcher);
int DtorText (Patcher* patcher);

int DtorMusic (Patcher* patcher);
int DtorSoundsBuffers (Patcher* patcher);

int DtorBinaryFrame (Patcher* patcher);
int DtorOneLineFrame (Patcher* patcher, NameLine number);

int DtorHackingAnimation (Patcher* patcher);