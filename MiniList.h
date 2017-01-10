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

template<typename T> class MiniList {
private:
  T *head;
  T *tail;
  unsigned int objNum;

public:
  MiniList(): head(0), tail(0), objNum(0) {
  }

  inline bool isEmpty() {
    return (objNum == 0);
  }

  inline T* first() {
    return head;
  }

  inline T* last() {
    return tail;
  }

  inline unsigned int size() {
    return objNum;
  }

  inline void insertFirst(T *object) {
    if(head != 0) {
      object->next = head;
      object->next->prev = object;
    }
    else {
      object->next = 0;
      tail = object;
    }
    object->prev = 0;
    head = object;

    objNum++;
  }

  inline void insertLast(T *object) {
    if(tail != 0) {
      object->prev = tail;
      object->prev->next = object;
    }
    else {
      object->prev = 0;
      head = object;
    }
    object->next = 0;
    tail = object;

    objNum++;
  }

  inline void insertAfter(T *object, T *newObject) {
    newObject->prev = object;

    if(object->next != 0) {
      newObject->next = object->next;
      newObject->next->prev = newObject;
      object->next = newObject;
    }
    else {
      newObject->next = 0;
      tail = newObject;
      object->next = newObject;

    }

    objNum++;
  }

  inline void insertBefore(T *object, T *newObject) {
    newObject->next = object;

    if(object->prev != 0) {
      newObject->prev = object->prev;
      newObject->prev->next = newObject;
      object->prev = newObject;
    }
    else {
      newObject->prev = 0;
      head = newObject;
      object->prev = newObject;

    }

    objNum++;
  }

  inline void remove(T *object) {
    if(object->prev != 0) {
      object->prev->next = object->next;
    }
    else {
      head = object->next;
    }

    if(object->next != 0) {
      object->next->prev = object->prev;
    }
    else {
      tail = object->prev;
    }

    object->owner->size--;
  }
};

#endif
