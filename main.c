#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

int main(int argc, char *argv[])
{
    const char *path;
    DIR *directory;
    struct dirent *entry;
    linked_list *names;
    int status;

    if (argc > 2) {
        fprintf(stderr, "Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    if (argc == 2) {
        path = argv[1];
    } else {
        path = ".";
    }

    directory = opendir(path);
    if (directory == NULL) {
        perror(path);
        return 1;
    }

    names = linked_list_create();
    if (names == NULL) {
        fprintf(stderr, "Could not allocate linked list\n");
        closedir(directory);
        return 1;
    }

    status = 0;
    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue;
        }

        if (linked_list_add_sorted(names, entry->d_name) != 0) {
            fprintf(stderr, "Could not allocate list node\n");
            status = 1;
            break;
        }
    }

    if (closedir(directory) != 0) {
        perror(path);
        status = 1;
    }

    if (status == 0) {
        linked_list_print(names);
    }

    linked_list_destroy(names);
    return status;
}
