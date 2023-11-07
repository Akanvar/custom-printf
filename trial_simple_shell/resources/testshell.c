#include "shell.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    size_t n = 0;
    char *buff = NULL;
    char *token;
    char **array;
    int i = 0, j = 0;
    char full_path[1024];
    pid_t pid;

    while (1)
    {
        kelm_prompt();
        if (getline(&buff, &n, stdin) == -1)
        {
            perror("getline");
            break;
        }

        token = strtok(buff, " ");
        array = malloc(sizeof(char *));
        if (array == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        while (token)
        {
            array = realloc(array, (i + 1) * sizeof(char *));
            if (array == NULL)
            {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
            array[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        array[i - 1][strlen(array[i - 1]) - 1] = '\0'; // Remove newline character
        array = realloc(array, (i + 1) * sizeof(char *));
        array[i] = NULL;

        if (strcmp(array[0], "exit") == 0)
            break;

        char *path_value = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
        if (setenv("PATH", path_value, 1) != 0)
            perror("setenv");

        char *path = getenv("PATH");
        if (path == NULL)
            perror("getenv");

        char path_array[1024];
        strncpy(path_array, path, sizeof(path_array) - 1);
        path_array[sizeof(path_array) - 1] = '\0'; // Ensure null-termination

        char *path_token = strtok(path_array, ":");
        char **command_path = malloc(sizeof(char *));
        if (command_path == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        while (path_token)
        {
            command_path = realloc(command_path, (j + 1) * sizeof(char *));
            if (command_path == NULL)
            {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
            command_path[j] = path_token;
            path_token = strtok(NULL, ":");
            j++;
        }
        command_path = realloc(command_path, (j + 1) * sizeof(char *));
        command_path[j] = NULL;

        for (int k = 0; command_path[k] != NULL; k++)
        {
            snprintf(full_path, sizeof(full_path), "%s/%s", command_path[k], array[0]);
            if (access(full_path, F_OK) != -1)
            {
                if ((pid = fork()) == -1)
                {
                    perror("fork");
                    exit(EXIT_FAILURE);
                }

                if (pid == 0)
                {
                    if (execve(full_path, array, NULL) == -1)
                    {
                        perror("execve");
                        exit(EXIT_FAILURE);
                    }
                }
                else
                {
                    wait(NULL);
                }
            }
        }
        free(array);
        free(command_path);
    }
    free(buff);
    return 0;
}

