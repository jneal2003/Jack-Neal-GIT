#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

static void sort_names(linked_list *names)
{
    int swapped;
    node *current;

    if (names == NULL) {
        return;
    }

    do {
        swapped = 0;
        current = names->head;

        while (current != NULL && current->next != NULL) {
            if (strcmp(current->data, current->next->data) > 0) {
                char *temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }

            current = current->next;
        }
    } while (swapped);
}

static void print_names(linked_list *names)
{
    node *current;

    if (names == NULL) {
        return;
    }

    current = names->head;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

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

        linked_list_add(names, entry->d_name);
    }

    if (closedir(directory) != 0) {
        perror(path);
        status = 1;
    }

    if (status == 0) {
        sort_names(names);
        print_names(names);
    }

    linked_list_destroy(names);
    return status;
}
