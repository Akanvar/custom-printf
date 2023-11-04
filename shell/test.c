#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *str = "jdjk:ashdjdajfj";
    char *pt;
    size_t i = 0;

    while (str[i] != ':' && str[i] != '\0') {
        i++;
    }

    pt = malloc(i + 1);
    if (pt == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    strncpy(pt, str, i);
    pt[i] = '\0';

    printf("%s\n", pt);

    free(pt); 
    return 0;
}

