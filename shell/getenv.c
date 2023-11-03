#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
    char *str;
    struct list *next;
} list_t;

typedef struct {
    list_t *env;
} info_t;

char *starts_with(const char *str, const char *prefix) {
    size_t len_str = strlen(str);
    size_t len_prefix = strlen(prefix);

    if (len_str < len_prefix) {
        return NULL;
    }

    return (strncmp(str, prefix, len_prefix) == 0) ? (char *)(str + len_prefix) : NULL;
}

char *_getenv(info_t *info, const char *name) {
    list_t *node = info->env;
    char *p;

    while (node) {
        p = starts_with(node->str, name);
        if (p && *p) {
            return p;
        }
        node = node->next;
    }
    return NULL;
}

// Function to create a new node in the list
list_t *new_node(char *str) {
    list_t *node = (list_t *)malloc(sizeof(list_t));
    if (node == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
    node->str = str;
    node->next = NULL;
    return node;
}

int main() {
    // Initializing an example environment list
    list_t *env1 = new_node("PATH=/usr/local/bin:/usr/bin:/bin");
    list_t *env2 = new_node("HOME=/home/user");
    list_t *env3 = new_node("USER=user123");

    // Creating the info_t structure
    info_t info;
    info.env = env1;
    env1->next = env2;
    env2->next = env3;

    // Example usage of _getenv
    char *result = _getenv(&info, "HOME");
    if (result != NULL) {
        printf("Value of HOME: %s\n", result);
    } else {
        printf("Environment variable not found.\n");
    }

    // Freeing allocated memory
    free(env1);
    free(env2);
    free(env3);

    return 0;
}

