#include <stdio.h> 
#include <stdlib.h> 
#include <termios.h>
#include <bool.h>
#include "main.h"

int moveBuffer(char* buffer, size_t* cursor, int input, size_t* length)
{
    if (isInsertOn)
    {

    }
    else
    {

    }
}

InputType FindInputType(char input)
{
    switch (input) {
        case 3:
            return INPUT_CTRL_C;

        case 4:
            return INPUT_CTRL_D;

        case 9:
            return INPUT_TAB;

        case 10:
        case 13:
            return INPUT_ENTER;

        case 26:
            return INPUT_CTRL_Z;

        case 27:
            return INPUT_ESCAPE;

        case 127:
            return INPUT_BACKSPACE;

        default:
            return INPUT_NORMAL;
    }

}

int handleInputTypes(char* buffer, InputType type, size_t* length , size_t* cursor)
{
    switch(type)
    case INPUT_NORMAL:
        moveBuffer(&buffer, &cursor, input , &length);
    case INPUT_ENTER:
        return -1;
        break;
    case INPUT_INSERT:
        isInsertOn == !isInsertOn;
        return 0;
        break;
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
        type = FindInputType(char input);
        handle = handleInputTypes(&buffer , type, length, cursor);
    } while(s != -1)
}

int main()
{

    char buffer[MAX_INPUT];


    while(1)
    {
        
    }
}