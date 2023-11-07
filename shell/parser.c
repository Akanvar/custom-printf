#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 * @info: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates characters
 * @pathstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct {
    char *path;
} info_t;

char *find_path(info_t *info, const char *pathstr, const char *cmd) {
    // Implementation of find_path to find the command in the specified path
    // ...
    return NULL; // Replace this with the found path or NULL if not found
}

void exeCMD(const char *cmdString) {
    info_t *info = malloc(sizeof(info_t));
    if (info == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    info->path = strdup("PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin");
    if (info->path == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        const char *pathStr = strchr(info->path, '=') + 1; // Get the path after '='

        char *command_path = find_path(info, pathStr, cmdString);
        if (command_path == NULL) {
            fprintf(stderr, "Command not found\n");
            exit(EXIT_FAILURE);
        }

        const char *args[] = {command_path, NULL};
        execve(command_path, args, NULL);

        // If execve fails
        perror("execve");
        exit(EXIT_FAILURE);
    } else {
        wait(NULL);
    }

    free(info->path);
    free(info);
}

int main() {
    exeCMD("ls");
    return 0;
}
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr,  char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				strcat(path, cmd);
			else
			{
				strcat(path, "/");
				strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
