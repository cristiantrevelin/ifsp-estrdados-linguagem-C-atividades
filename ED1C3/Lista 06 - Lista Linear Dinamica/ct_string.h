#include <stdio.h>
#include <stdlib.h>

int ct_get_ssize (char *str)
{
    // This function gets the size of the given <<str>> by
    // counting its characters, including the last '\0'.

    // Returning: the number of characters counted.

    int ssize = 0;

    while (str[ssize] != '\0')
        ssize++;

    ssize++;

    return ssize;
}

int ct_equals (char *str1, char *str2)
{
    // This function compares two given strings, char by char
    // and returns 1 if they are equal - else, returns 0.

    int i = -1;

    do
    {
        i++;

        if (str1[i] != str2[i])
            return 0;

    } while (str1[i] != '\0');

    return 1;
}

char *ct_get_scopy (char *str)
{
    // This function copies the content of the given <<str>> to
    // a dynamic allocated string <<scopy>>, char by char and
    // returns scopy.

    // If any issues occur in the allocation process of scopy,
    // NULL is returned instead.

    char *scopy;
    int i = 0, copy_size;

    copy_size = ct_get_ssize(str);
    scopy = (char *) malloc(copy_size * sizeof(char));

    if (scopy == NULL)
        return NULL;

    while (str[i] != '\0')
    {
        scopy[i] = str[i];
        i++;
    }

    scopy[i] = '\0';

    return scopy;
}

int ct_isalpha (char character)
{
    if ((character >= 'a' && character <= 'z') ||
        (character >= 'A' && character <= 'Z'))
        return 1;

    return 0;
}

int ct_isupperc (char character)
{
    if (character >= 'A' && character <= 'Z')
        return 1;
    return 0;
}

char ct_lowerc (char character)
{
    if (ct_isupperc(character))
        character += 32;

    return character;
}

int ct_scompao (char *str1, char *str2)
{
    // scompao: string compare alphabetical order.

    // This function compares two given strings <<str1>> and
    // <<str2>>, char by char, in order to find out which one
    // comes first in alphabetical order.

    // Returning: if <<str1>> comes first in alphabetical
    // order, 1 is returned; if <<str2>> comes first, 2 is
    // returned. If the given strings are either equal or
    // not words, 0 is returned instead.

    int i = -1;

    do
    {
        i++;

        if (ct_isalpha(str1[i]) && ct_isalpha(str2[i]))
        {
            if (ct_lowerc(str1[i]) < ct_lowerc(str2[i]))
                return 1;
            else if (ct_lowerc(str1[i]) > ct_lowerc(str2[i]))
                return 2;
        }

    } while (str1[i] != '\0' && str2[i] != '\0');

    return 0;
}
