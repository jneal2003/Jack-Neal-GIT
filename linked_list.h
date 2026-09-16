#ifndef LINKED_LIST_h
#define LINKED_LIST_h

typedef struct node{
  char *data;
  struct node *next;
} node;

typedef struct linked_list{
  int count;
  node *head;
} linked_list;

linked_list* linked_list_create();
void linked_list_destroy(linked_list* ll);
void linked_list_add(linked_list* ll, char* buffer);
void linked_list_delete(linked_list* ll, node* n);
node* linked_list_get(linked_list* ll, int count);
node* linked_list_search(linked_list* ll, char* buffer);
void linked_list_print(linked_list* ll);

#endif
