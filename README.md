# MiniList
This is a mini list template.

## To use this list template, you need define two class, refer to unittests for examples.

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

