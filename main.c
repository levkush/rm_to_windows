#include <stdio.h>
#include <string.h>

char buildCommand(char args[], char path[])
{
    char command[1000] = "powershell.exe -Command Remove-Item ";

    size_t length = strlen(args);

    for (size_t iter = 0; iter < length; iter++)
    {
        if (args[iter] == 'f') {
            strcat(command, "-Force ");
        }

        else if (args[iter] == 'c') {
            strcat(command, "-Confirm ");
        }
        
        else if (args[iter] == 'r') {
            strcat(command, "-Recurse ");
        }
    }

    strcat(command, path);
    
    system(command);
    return 0;
}

int main(int argc, char const *argv[])
{
    if( argc == 3 ) {
        if (argv[1][0] == '-')
        {
            buildCommand(argv[1], argv[2]);
        }
        else {
            printf("Invalid arguments.\n");
        }
    }
    else if( argc > 3 ) {
        printf("Too many arguments supplied.\n");
    }
    else {
        printf("Two arguments expected.\n");
    }
    return 0;
}