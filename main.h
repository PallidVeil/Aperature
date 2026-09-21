#ifndef main.h

typedef enum {
    INPUT_NORMAL,
    INPUT_ENTER,
    INPUT_BACKSPACE,
    INPUT_TAB,
    INPUT_CTRL_C,
    INPUT_CTRL_D,
    INPUT_CTRL_Z,
    INPUT_ESCAPE,
    INPUT_INSERT
} InputType;

int isInsertOn = 1;

#endif