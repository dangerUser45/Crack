#include "../headers/ConstsPatcher.h"
#include "../headers/HackingPatcher.h"
#include "../headers/Color.h"

#include <stdio.h>

//--------------------------------------------------------------------------------------------------------------------------
int Hacking ()
{
    FILE* hacking_file = fopen (NAME_HACKING_PROGRAMM, OPENING_MODE);

    if (hacking_file == NULL)
    {
        printf ("" RED "ERROR> %s %d: Failed to open the file\n" RESET "",  __FILE__, __LINE__);
        return -1;
    }

    const unsigned char jump_correct_password[3] = HACKING_BYTES();
    size_t number = fwrite (jump_correct_password, sizeof(unsigned char), 3, hacking_file);

    if (!number)
        printf ("" RED "ERROR> %s %d: Not all data was recorded\n" RESET "", __FILE__, __LINE__);

    fclose (hacking_file);

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------
