#ifndef _MINI_LIST_H
#define _MINI_LIST_H

/**************************************************************************/
// member requirement to use this list template
/*
class Int {
public:
  Int *next;
  Int *prev;

  int data;
};

int main() {
  MiniList<Int> list;
  Int obj;
  Int obj1;

  list.insertFirst(&obj);
  list.insertLast(&obj1);
}
*/
/**************************************************************************/

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

    objNum--;
  }
};

#endif
