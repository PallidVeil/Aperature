#ifndef main.h
#define main.h

#include <stdbool.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <termios.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

typedef enum {
    INPUT_NORMAL,
    INPUT_ENTER,
    INPUT_BACKSPACE,
    INPUT_TAB,
    INPUT_ESCAPE,
    INPUT_INSERT
} InputType;

extern bool isInsertOn;

#endif