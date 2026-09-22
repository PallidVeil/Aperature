#include "common.h"
#include "editor.h"

bool isInsertOn = true;

void moveCursorLeft(Editor *editor)
{
    if (editor->cursor <= 0)
    return;
    editor->cursor--;
    printf("\033[D");
}

void moveCursorRight(Editor *editor)
{
    if (editor->cursor >= editor->length)
        return;
    editor->cursor++;
    printf("\033[C");
}

void moveCursorHome(Editor *editor)
{
    editor->cursor = 0;
    printf("\033[%zuD", editor->cursor);
}

void moveCursorEnd(Editor *editor)
{
    editor->cursor = editor->length;
    printf("\033[%zuC", editor->length - editor->cursor);
}

void HandleEscSequence(char* buffer, Editor *editor)
{
    char sequenceBuffer[MAX_ESCAPE_SEQUENCE_LENGTH] = {0};
    int i = 0;
    int timeoutcheck;
    while (1)
    {
        timeoutcheck = poll(stdin,  POLLTIMEOUT);
        if (i >= MAX_ESCAPE_SEQUENCE_LENGTH - 1)
            break;
        if (timeoutcheck == 0)
            break;
        if (timeoutcheck == -1)// error add a check later
            break;
        read(STDIN_FILENO, &sequenceBuffer[i], 1);
        i++;
    }
    findEscapeSequenceType(sequenceBuffer[0]);
}

InputType FindEscapeSequenceType(char input)
{
    switch (input) {
        case 'A':
            return INPUT_UP;
        case 'B':
            return INPUT_DOWN;
        case 'C':
            return INPUT_RIGHT;
        case 'D':
            return INPUT_LEFT;
        default:
            return INPUT_NORMAL;
    }
}

void HandleInputMovement(char* buffer, Editor *editor)
{
    int movingWay = 0;
    if (editor->input == 127) //backspace
    {
        if (editor->cursor > 0)
            movingWay = -1;
    }
    else if (isInsertOn)
    {
        movingWay = 1;
    }
    else
    {
        buffer[(editor->cursor)] = editor->input;
        moveCursorRight(editor);
    }

    if (movingWay == -1)
    {
        for (size_t i = editor->cursor; i < editor->length; i++)
        {
            buffer[i] = buffer[i + 1];
        }
    moveCursorLeft(editor);
    editor->length--;
    buffer[editor->length] = '\0';
    }
    else if (movingWay == 1)
    {
        editor->length++;
        for(size_t i = editor->length; i > editor->cursor ; i--)
        {
            buffer[i + 1] = buffer[i];
        }
        buffer[(editor->cursor)] = editor->input;
        moveCursorRight(editor);
        buffer[editor->length] = '\0';
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

void setInsertOrOverwriteCursor(void)
{
    if (isInsertOn)
        printf("\033[2 q");
    else    
        printf("\033[6 q");
}

int handleInputTypes(char* buffer, Editor *editor, InputType type)
{
    switch(type)
    {
    case INPUT_NORMAL:
        HandleInputMovement(buffer, editor);
        break;
    case INPUT_ENTER:
        return -1;
        break;
    case INPUT_INSERT:
        isInsertOn = !isInsertOn;
        setInsertOrOverwriteCursor();
        return 0;
        break;
    case INPUT_BACKSPACE:
        HandleInputMovement(buffer, editor);
        break;
    case INPUT_TAB:
        return 0;
        break;
    case INPUT_ESCAPE:
        HandleEscSequence(buffer, editor);
        return 0;
        break;
}
return 0;
}