#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
int main() {
    size_t n = 0;
    char *buff = NULL;
    char *token;
    char **array = NULL;
    char full_path[1024];
    pid_t pid;

    while (1) {
        kelm_prompt();
        if (getline(&buff, &n, stdin) == -1) {
            free(buff);
            exit(EXIT_FAILURE);
        }

        token = strtok(buff, " \n");
        int token_count = 0;
        while (token) {
            array = realloc(array, (token_count + 1) * sizeof(char *));
            array[token_count++] = token;
            token = strtok(NULL, " \n");
        }
        array = realloc(array, (token_count + 1) * sizeof(char *));
        array[token_count] = NULL;

        if (strcmp(array[0], "exit") == 0) {
            free(buff);
            free(array);
            break;
        }

        char *path_value = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
        if (setenv("PATH", path_value, 1) != 0)
            perror("setenv");

        char *path = getenv("PATH");
        if (path == NULL)
            perror("getenv");

        char *path_array = strdup(path);
        token = strtok(path_array, ":");
        while (token) {
            snprintf(full_path, sizeof(full_path), "%s/%s", token, array[0]);
            if (access(full_path, F_OK) != -1) {
                if ((pid = fork()) == -1) {
                    perror("error");
                    exit(EXIT_FAILURE);
                }
                if (pid == 0) {
                    if (execve(full_path, array, NULL) == -1)
                        perror("error");
                    exit(EXIT_FAILURE); // In case execve fails
                } else {
                    wait(NULL);
                    break; // Breaks the loop for the parent process to re-display the prompt
                }
            }
            token = strtok(NULL, ":");
        }

        free(path_array);
        free(array);
        free(buff);
        buff = NULL;
        array = NULL;
    }

    return 0;
}

