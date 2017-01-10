#include "MiniList.h"
#include "gtest/gtest.h"

class Int;

class IntList {
public:
  Int *head;
  Int *tail;
  unsigned int size;
};

class Int {
public:
  Int *next;
  Int *prev;
  IntList *owner;
  int data;
};

TEST(listInsertFirstTest, InsertFirestTestCase) {
  IntList list;
  Int obj;
  Int obj1;

  listInit(&list);  
  listInsertFirst(&list, &obj);
  EXPECT_EQ(list.head, &obj); 
  EXPECT_EQ(list.tail, &obj); 
  EXPECT_EQ(list.size, 1); 
  EXPECT_EQ(obj.prev, (void *)0); 
  EXPECT_EQ(obj.owner, &list); 

  listInsertFirst(&list, &obj1);
  EXPECT_EQ(list.head, &obj1); 
  EXPECT_EQ(list.size, 2); 
  EXPECT_EQ(obj1.prev, (void *)0); 
  EXPECT_EQ(obj1.next, &obj); 
  EXPECT_EQ(obj.prev, &obj1); 
  EXPECT_EQ(obj.owner, &list); 
}

TEST(listInsertLastTest, InsertLastTestCase) {
  IntList list;
  Int obj;
  Int obj1;

  listInit(&list);  
  listInsertLast(&list, &obj);
  EXPECT_EQ(obj.prev, (void *)0); 
  EXPECT_EQ(list.head, &obj); 
  EXPECT_EQ(obj.next, (void *)0); 
  EXPECT_EQ(obj.owner, &list); 
  EXPECT_EQ(list.tail, &obj); 
  EXPECT_EQ(list.size, 1); 

  listInsertLast(&list, &obj1);
  EXPECT_EQ(obj1.prev, &obj); 
  EXPECT_EQ(obj.next, &obj1); 
  EXPECT_EQ(obj1.next, (void *)0); 
  EXPECT_EQ(obj1.owner, &list); 
  EXPECT_EQ(list.tail, &obj1); 
  EXPECT_EQ(list.size, 2); 
}

// To do: add more unit test
