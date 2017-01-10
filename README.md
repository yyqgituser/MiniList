# MiniList
This is a mini list template.

### To use this list template, you need define two classes with following requirement, refer to unittests for examples ([MiniListTest.cpp](https://github.com/yyqgituser/MiniList/blob/master/unittests/MiniListTest.cpp)).

```c
#include <MiniList.h>

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
```

