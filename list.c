#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List *lista0=(List*)malloc(sizeof(List));
  return lista0;
}

void * firstList(List * list) {
  if (list !=NULL && list->head!=NULL){
    list->current=list->head;
    return list->head->data;
  }
  return NULL;
}

void * nextList(List * list) {
  if (list->current!= NULL && list->current->next!=NULL){
    list->current=list->current->next;
    return list->current->data;
  }
  return NULL;
}

void * lastList(List * list) {
  if (list->tail!= NULL){
    list->current=list->tail;
      return list->tail->data;
  }
  return NULL;
}

void * prevList(List * list) {
  if (list->current!= NULL && list->current->prev){
    list->current=list->current->prev;
    return list->current->data;
    }
    return NULL;
}

void pushFront(List * list, void * data) {
  Node* nodede = createNode(data);
  if(list->head!=NULL){
    nodede->next=list->head;
    list->head->prev=nodede;
    list->head=nodede;
    list->current=nodede;
  }else{
    list->head=nodede;
    list->current=nodede;
    list->tail=nodede;
  }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node* nodede = createNode(data);
  if(list->current!=NULL){
    nodede->next=list->current->next;
    nodede->prev =list->current;
    if(list->current -> next != NULL){
      list->current->next->prev=nodede;
      
    }else{
      list->tail = nodede;
    }
    list->current->next =nodede;
    }
  else{
    list->current=nodede;
    list->head=nodede;
    list->tail=nodede;
    }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  if (list != NULL && list->current!=NULL){
    Node *nodede=list->current;
    
    if (nodede->prev!=NULL){
      nodede->prev->next=nodede->next;
    }else{
      list->head=nodede->next;
    }
    if(nodede->next!=NULL){
      nodede->next->prev=nodede->prev;
    }else{
      list->tail=nodede->prev;
    }
    return list->current->data;
  }
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}