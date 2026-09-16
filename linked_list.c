#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

linked_list *linked_list_create(void)
{
    linked_list *ll = malloc(sizeof(linked_list));

    if (ll == NULL) {
        return NULL;
    }

    ll->count = 0;
    ll->head = NULL;

    return ll;
}

void linked_list_destroy(linked_list *ll)
{
    node *current;

    if (ll == NULL) {
        return;
    }

    current = ll->head;
    while (current != NULL) {
        node *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }

    free(ll);
}

int linked_list_add_sorted(linked_list *ll, const char *name)
{
    node *new_node;
    node *current;
    node *previous;

    if (ll == NULL || name == NULL) {
        return 1;
    }

    new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        return 1;
    }

    new_node->data = malloc(strlen(name) + 1);
    if (new_node->data == NULL) {
        free(new_node);
        return 1;
    }

    strcpy(new_node->data, name);
    new_node->next = NULL;

    previous = NULL;
    current = ll->head;

    while (current != NULL && strcmp(current->data, name) < 0) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        new_node->next = ll->head;
        ll->head = new_node;
    } else {
        new_node->next = current;
        previous->next = new_node;
    }

    ll->count++;
    return 0;
}

void linked_list_print(const linked_list *ll)
{
    node *current;

    if (ll == NULL) {
        return;
    }

    current = ll->head;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}
