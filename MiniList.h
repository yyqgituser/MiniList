#ifndef _MINI_LIST_H
#define _MINI_LIST_H

/**************************************************************************/
// member(must public) requirement to use this list template

/*
class TList; // List with node type T
class T; // List Node.

class TList {
public:
  T *head; // point to first object in list
  T *tail; // point last object in list
  unsigned int size; // the number of nodes
};

class T {
public:
  T *next; // next object, 0 if no
  T *prev; // previous object, 0 if no
  TList *owner; // who own this object

  int data; // any other data
};

*/
/**************************************************************************/

// TList: Type of List
// T: Type of List Node

// TList *list: list
// initialize a list

template<typename TList> inline void listInit(TList *list) {
  list->head = 0;
  list->tail = 0;
  list->size = 0;
}

template<typename TList> inline bool listIsEmpty(TList *list) {
  return (list->size == 0);
}

template<typename TList> inline unsigned int listSize(TList *list) {
  return list->size;
}

template<typename TList, typename T> inline void listInsertFirst(TList *list, T *object) {
  if(list->head != 0) {
    object->next = list->head;
    object->next->prev = object;
  }
  else {
    object->next = 0;
    list->tail = object;
  }
  object->prev = 0;
  object->owner = list;
  list->head = object;

  list->size++;
}

template<typename TList, typename T> inline void listInsertLast(TList *list, T *object) {
  if(list->tail != 0) {
    object->prev = list->tail;
    object->prev->next = object;
  }
  else {
    object->prev = 0;
    list->head = object;
  }
  object->next = 0;
  object->owner = list;
  list->tail = object;

  list->size++;
}

template<typename T> inline void listInsertAfter(T *object, T *toIns) {
  toIns->prev = object;

  if(object->next != 0) {
    toIns->next = object->next;
    toIns->next->prev = toIns;
    object->next = toIns;
  }
  else {
    toIns->next = 0;
    object->owner->tail = toIns;
    object->next = toIns;

  }
  toIns->owner = object->owner;

  toIns->owner->size++;
}

template<typename T> inline void listInsertBefore(T *object, T *toIns) {
  toIns->next = object;

  if(object->prev != 0) {
    toIns->prev = object->prev;
    toIns->prev->next = toIns;
    object->prev = toIns;
  }
  else {
    toIns->prev = 0;
    object->owner->head = toIns;
    object->prev = toIns;

  }
  toIns->owner = object->owner;

  toIns->owner->size++;
}

template<typename T> inline void listRemove(T *object) {
  if(object->prev != 0) {
    object->prev->next = object->next;
  }
  else {
    // remove first object
    object->owner->head = object->next;
  }

  if(object->next != 0) {
    object->next->prev = object->prev;
  }
  else {
    // remove last object
    object->owner->tail = object->prev;
  }

  object->owner->size--;
}

#endif
