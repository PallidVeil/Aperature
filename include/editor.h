#ifndef EDITOR_H
#define EDITOR_H

typedef enum {
    INPUT_NORMAL,
    INPUT_ENTER,
    INPUT_BACKSPACE,
    INPUT_TAB,
    INPUT_ESCAPE,
    INPUT_INSERT,
    INPUT_DELETE
} InputType;

typedef struct {
    size_t length;
    size_t cursor;
    char input;
} Editor;

void moveCursorLeft(Editor *editor);
void moveCursorRight(Editor *editor);
void moveCursorHome(Editor *editor);
void moveCursorEnd(Editor *editor);

InputType FindInputType(char input);
int handleInputTypes(char *buffer, Editor *editor, InputType type);

void setInsertOrOverwriteCursor(void);
void HandleInputMovement(char *buffer, Editor *editor);

extern bool isInsertOn;

#endif