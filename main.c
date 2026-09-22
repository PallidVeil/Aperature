#include "main.h"

void moveBuffer(char* buffer, size_t* cursor, int input, size_t* length)
{
    int curr , next;
    int movingWay = 0;
    if (input == 127) //backspace
    {
        if (*cursor > 0)
            movingWay = -1;
    }
    else if (isInsertOn)
    {
        movingWay = 1;
    }
    else
    {
        buffer[(*cursor)++] = input;
    }

    if (movingWay == -1)
    {
        for (int i = *cursor; i < *length; i++)
        {
            buffer[i] = buffer[i + 1];
        }
    (*cursor)--;
    (*length)--;
    buffer[*length] = '\0';
    }
    else if (movingWay = 1)
    {
        for(int i = (*length)++; i > *cursor ; i--)
        {
            buffer[i + 1] = buffer[i];
        }
        buffer[(*cursor)++] = input;
        buffer[*length] = '\0';
    }
}

InputType FindInputType(char input)
{
    switch (input) {
        case 9:
            return INPUT_TAB;

        case 10:
        case 13:
            return INPUT_ENTER;

        case 27:
            return INPUT_ESCAPE;

        case 127:
            return INPUT_BACKSPACE;

        default:
            return INPUT_NORMAL;
    }

}

int handleInputTypes(char* buffer, char input, InputType type, size_t* length , size_t* cursor)
{
    switch(type)
    {
    case INPUT_NORMAL:
        moveBuffer(&buffer, &cursor, input , &length);
        break;
    case INPUT_ENTER:
        return -1;
        break;
    case INPUT_INSERT:
        isInsertOn = !isInsertOn;
        return 0;
        break;
}
}

int ReadInput(char* buffer)
{
    size_t length = 0;
    size_t cursor = 0;
    
    char input; 
    InputType type;

    int handle;
    
    do
    {
        read(STDIN_FILENO, &input, 1);
        type = FindInputType(input);
        handle = handleInputTypes(&buffer , input, type, &length, &cursor);
    } while(handle != -1);
}

int main()
{

    char buffer[BUFFER_SIZE];


    while(1)
    {
        
    }
}