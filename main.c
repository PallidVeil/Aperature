#include "main.h"
#include "editor.h"

int ReadInput(char* buffer, Editor *editor)
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
        handle = handleInputTypes(buffer, editor, type);
    } while(handle != -1);
}

int main()
{
    char buffer[BUFFER_SIZE];
    Editor editor = {0};

    while(1)
    {
        ReadInput(buffer, &editor);
        printf("\nYou entered: %s\n", buffer);
        
    }
}