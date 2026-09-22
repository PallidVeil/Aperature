#ifndef EDITOR_H
#define EDITOR_H

typedef enum {
    INPUT_NORMAL,
    INPUT_ENTER,
    INPUT_BACKSPACE,
    INPUT_TAB,
    INPUT_ESCAPE,
    INPUT_INSERT
} InputType;

typedef struct {
    size_t length;
    size_t cursor;
    char input;
} Editor;

extern bool isInsertOn;

#endif