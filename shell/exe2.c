#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
void exeCMD(const char *cmdString) {
    int i = 0, j = 0;
    char pathStr[256];

    info_t *info = malloc(sizeof(info_t));
    if (info == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    // Ensure info_t structure is not declared as const
    info->path = strdup("PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin");
    if (info->path == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    for (i = 5; info->path[i] != '\0'; i++) {
        pathStr[j++] = info->path[i];
    }
    pathStr[j] = '\0';

    char command_path[256];
    snprintf(command_path, sizeof(command_path), "/%s", cmdString);

    const char *argv[] = {command_path, NULL};
    char *const env[] = {info->path, NULL}; // Use char *const * for env

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        execve(command_path, argv, env);

        // If execve fails
        perror("execve");
        exit(EXIT_FAILURE);
    } else {
        wait(NULL);
    }

    // Free allocated memory
    free(info->path);
    free(info);
}

