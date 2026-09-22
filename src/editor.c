#include "main.h"
#include "editor.h"

void moveBuffer(char* buffer, Editor *e)
{
    int curr , next;
    int movingWay = 0;
    if (e->input == 127) //backspace
    {
        if (e->cursor > 0)
            movingWay = -1;
    }
    else if (isInsertOn)
    {
        movingWay = 1;
    }
    else
    {
        buffer[(e->cursor)++] = e->input;
    }

    if (movingWay == -1)
    {
        for (int i = e->cursor; i < e->length; i++)
        {
            buffer[i] = buffer[i + 1];
        }
    e->cursor--;
    e->length--;
    buffer[e->length] = '\0';
    }
    else if (movingWay == 1)
    {
        e->length++;
        for(int i = e->length; i > e->cursor ; i--)
        {
            buffer[i + 1] = buffer[i];
        }
        buffer[(e->cursor)++] = e->input;
        buffer[e->length] = '\0';
    }
}

void moveTerminalCursor(int amount)
{
    if (amount > 0)
        printf("\x1b[%dC", amount);
    else if (amount < 0)
        printf("\x1b[%dD", -amount);
}

void cursorLeft(Editor *e)
{
    if (e->cursor > 0)
        e->cursor--;
}

void cursorRight(Editor *e)
{
    if (e->cursor < e->length)
        e->cursor++;
}

void cursorHome(Editor *e)
{
    e->cursor = 0;
}

void cursorEnd(Editor *e)
{
    e->cursor = e->length;
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

int handleInputTypes(char* buffer, Editor *e, InputType type)
{
    switch(type)
    {
    case INPUT_NORMAL:
        moveBuffer(buffer, &e->cursor, e->input, &e->length);
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