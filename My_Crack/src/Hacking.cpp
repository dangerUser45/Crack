#include <stdio.h>
#include <assert.h>
#include "../headers/PatcherConsts.h"
#include "../headers/Hacking.h"

int Hacking ()
{
    FILE* hacking_file = fopen (NAME_HACKING_PROGRAMM, OPENING_MODE);

    if (hacking_file == 0)
    {
        printf ("Failed to open the file\n");
        assert(0);
    }

    const unsigned char jump_correct_password[3] = HACKING_BYTES();
    short number = fwrite (jump_correct_password, sizeof(unsigned char), 3, hacking_file);

    if (!number)
        printf ("ERROR %s %d: Not all data was recorded\n", __FILE__, __LINE__);

    fclose (hacking_file);

    return 0;
}