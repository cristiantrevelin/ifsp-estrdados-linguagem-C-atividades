#include <stdio.h>
#define LINE_SIZE 50

void ct_flushsa ()
{
    // flushsa: flush stdin after.

    // This function flushes the stdin buffer after a previous input,
    // consuming remaining characters, until '\n' or EOF is reached.

    // If stdin is already clean, the function may wait for a new input.

    int aux;
    while ((aux = getchar()) != '\n' && aux != EOF) {}
}

void ct_scanline (char *buffer, int buffer_size, char *msg)
{
    // This function reads a line input from the user and stores into
    // the given <<buffer>>, until '\n' is read or <<buffer_size>> is
    // reached. Before reading process, <<msg>> is displayed.

    // If the line input is bigger than <<buffer_size>>, ct_flushsa is
    // called to clean the exceeding characters from stdin buffer.

    char character;
    int i = 0;

    printf("%s", msg);

    do
    {
        character = getchar();

        if (character != '\n')
        {
            buffer[i] = character;
            i++;
        }

    } while (character != '\n' && i < buffer_size - 1);

    buffer[i] = '\0';
    i++;

    if (i == buffer_size)
        ct_flushsa();
}

char *ct_getline (int initial_size, char *msg)
{
    // This function reads a line input from the user and stores into
    // a dynamic buffer of <<initial_size>> size, until '\n' is read or
    // <<initial_size>> is reached. Before reading process, <<msg>> is
    // displayed.

    // If the line input is bigger than <<initial_size>>, ct_flushsa is
    // called to clean the exceeding characters from stdin buffer, else,
    // the buffer is reallocated to fit the line accordingly.

    // Returning: if any error occurs during the whole process, NULL is
    // returned, else, a pointer to the line buffer is returned.

    char character, *line;
    int i = 0;

    line = (char *) malloc(initial_size * sizeof(char));

    if (line == NULL)
        return NULL;

    printf("%s", msg);

    do
    {
        character = getchar();

        if (character != '\n')
        {
            line[i] = character;
            i++;
        }

    } while (character != '\n' && i < initial_size - 1);

    line[i] = '\0';
    i++;

    if (i == initial_size)
        ct_flushsa();
    else
    {
        line = (char *) realloc(line, i * sizeof(char));

        if (line == NULL)
            return NULL;
    }

    return line;
}

int ct_stoint (char *str, int *receiver)
{
    // stoint: string to int.

    // This function reads the given <<str>> and extract int values,
    // storing them into <<receiver>> as a single value.

    // Returning: if no int value could be read from the given string,
    // 1 is returned. Else, the value is written into <<receiver>> and 0
    // is returned.

    int i = 0, int_value = 0, ints_found = 0;
    int negative = 0;

    while (str[i] != '\0')
    {
        if (ints_found == 0 && str[i] == '-')
            negative = 1;

        if (str[i] >= '0' && str[i] <= '9')   // it's a numeric char.
        {
            int_value = (int_value * 10) + str[i] - '0';
            ints_found++;
        }

        i++;
    }

    if (ints_found == 0)
        return 1;   // Error - no int value found in the string.

    if (negative)
        int_value *= -1;

    *receiver = int_value;
    return 0;
}

int ct_scanint (int *receiver, char *msg)
{
    // This function uses ct_scanline and ct_stoint to show <<msg>> and
    // read an integer input, which will be written into <<receiver>>,
    // in case everything goes well.

    // Returning: this function returns the same as ct_stoint called.

    int value, return_status;
    char str_buffer[LINE_SIZE];

    ct_scanline(str_buffer, LINE_SIZE, msg);
    return_status = ct_stoint(str_buffer, receiver);

    return return_status;
}

void ct_uscanint (int *receiver, char *msg, char *error_msg)
{
    // This function calls ct_scanint in a do-while loop to collect
    // an integer input from stdin, writing it into <<receiver>>.

    // Before the first call of ct_scanint, <<msg>> is showed - then,
    // <<error_msg>> will be showed after every call, until the given
    // input is valid.

    int return_status;

    do
    {
        return_status = ct_scanint(receiver, msg);

        if (return_status != 0)
            printf("%s", error_msg);

    } while (return_status != 0);
}
