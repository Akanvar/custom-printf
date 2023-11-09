#include <stdio.h>

extern char **environ; // extern declaration for environ

int main() {
    // Print the contents of environ
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }

    return 0;
}

