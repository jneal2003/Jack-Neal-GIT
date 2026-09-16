#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node {
    char *data;
    struct node *next;
} node;

typedef struct linked_list {
    int count;
    node *head;
} linked_list;

linked_list *linked_list_create(void);
void linked_list_destroy(linked_list *ll);
int linked_list_add_sorted(linked_list *ll, const char *name);
void linked_list_print(const linked_list *ll);

#endif
