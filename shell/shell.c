#include "shell.h"
/**
 * main - a simple shell program
 *
 */

int main(void) {
    char command[120];

    while (true) {
        show_prompt();
        userCMD(command, sizeof(command));
        exeCMD(command);
    }

    return 0;
}
