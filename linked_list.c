#include <stdlib.h>
#include <string.h>
#include "linked_list.h"


linked_list* linked_list_create(){
  linked_list *ll;
  ll = (linked_list*)malloc(sizeof(linked_list));

  ll->count = 0;
  ll->head = NULL;

  return ll;
}
void linked_list_destroy(linked_list* ll){
  node *current = ll->head;
  node *next;

  while (current != NULL) {
    next = current->next;
    free(current->data);
    free(current);
    current = next;
  }

  free(ll);
}
void linked_list_add(linked_list* ll, char* buffer){
  node *temp = ll->head;
  node *new = (node*)malloc(sizeof(node));

  new->data = malloc(strlen(buffer) + 1);
  strcpy(new->data, buffer);
  new->next = NULL;

  if (ll->head == NULL) {
        ll->head = new;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = new;
    }

    ll->count++;
}
void linked_list_delete(linked_list* ll, node* n){
  node *temp = ll->head;
  node *last;
  if (temp == NULL) {
    return;
  }
  if (temp == n) {
    ll->head = temp->next;
    free(temp->data);
    free(temp);
    ll->count--;
return;
  }
  while (temp != n) {
    if (temp->next == NULL){
      return;
    }
    last = temp;
    temp = temp->next;
  }

  last->next = temp->next;
  free(temp->data);
  free(temp);
  ll->count--;
}
node* linked_list_get(linked_list* ll, int count){
  int i = 0;
  node* temp = ll->head;
  while (i != count) {
    if (temp == NULL) {
      return NULL;
    }
    temp = temp->next;
    i++;
  }
  return temp;
}
node* linked_list_search(linked_list* ll, char* buffer){
  node *temp = ll->head;
  if (temp != NULL) {
    while(strcmp(temp->data, buffer) != 0) {
      if (temp->next == NULL) {
        return NULL;
      }
      temp = temp->next;
    }
    return temp;
  }
  else {
    return NULL;
  }
}
void linked_list_print(linked_list* ll){
  if (ll->count == 0) {
    printf("Linked List Empty\n");
    return;
  }
  int i = 0;
  node *temp = ll->head;
  while (temp != NULL) {
    printf("%i %s\n", i, temp->data);
    temp = temp->next;
    i++;
  }
  return;
}
