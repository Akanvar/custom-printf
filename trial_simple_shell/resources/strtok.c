#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	//char array[] = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
	//char *delim = ":";



	size_t n = 0;
    	char *token;	
	char *buff = NULL;


	getline(&buff, &n, stdin);


	//char *result;

	//result = strtok(array, delim);
	//printf("%s\n", result);
    //char *name = "Kelvin Awiapo A"; // String declaration
   // char *buff = NULL //malloc(strlen(name) + 1); // Allocate memory for buff

    //if (buff == NULL) {
      //  printf("Memory allocation failed\n");
       // return 1; // Exit with an error code
    //}

    //strcpy(buff, name); // Copy the content of name to buff

    //size_t n = 0;
    //char *token;

    token = strtok(buff, " ");

    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    // Free dynamically allocated memory
    //free(buff);

    return 0; // Exit normally
}


/*char *strtok(char *str, const char *delim)
{*/

