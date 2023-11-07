/*#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LINE 80 // Maximum length of command
#define MAX_ARGS  10 // Maximum number of arguments

int main(void) { */
/*    char *args[MAX_ARGS]; // Array to store command-line arguments
      char cmd[MAX_LINE]; // Buffer to store user input

      while (1) {
      printf("shell> "); // Print shell prompt
      fgets(cmd, MAX_LINE, stdin); // Read user input

      if (strcmp(cmd, "exit 98\n") == 0) { // Check if user wants to exit
      return(-1);
      }

// Tokenize the command
char *token = strtok(cmd, " \n");
int i = 0;
while (token != NULL) {
args[i++] = token;
token = strtok(NULL, " \n");
}
args[i] = NULL; // Set the last argument to NULL

// Fork a child process
pid_t pid = fork();

if (pid < 0) { // Error handling for forking
fprintf(stderr, "Fork failed\n");
return 1;
} else if (pid == 0) { // Child process
execvp(args[0], args); // Execute the command
fprintf(stderr, "Execution failed\n");
return 1;
} else { // Parent process
wait(NULL); // Wait for the child process to finish
}
}
return 0;
} */

/* char path_value[1024] = "/usr/local/bin:/usr/bin:/bin"; // Example PATH value
   if (setenv("PATH", path_value, 0) != 0) {
   perror("setenv");
   return 1;
   }

// Check if the PATH variable was set successfully
char *path = getenv("PATH");
if (path != NULL) {
printf("PATH set to: %s\n", path);
} else {
printf("PATH not set\n");
}

return 0;
} */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
	char *path_value = "/usr/local/bin:/usr/bin:/bin"; // Example PATH value
	setenv("PATH", path_value, 0); // Set the PATH environment variable

	char *args[] = {"ls", "-l", NULL}; // Command and its arguments
	char *envp[] = {NULL}; // Initialize the environment array to NULL

	char *path = getenv("PATH");
		printf("%s\n", path); 
			// Execute the command with the specified environment
	if (execve("/bin/ls", args, NULL) == -1) 
	{
		perror("execve");
		return 1;
	}

	return 0;
}

