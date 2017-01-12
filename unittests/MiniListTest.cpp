#include "MiniList.h"
#include "gtest/gtest.h"

class Int {
  public:
    Int *next;
    Int *prev;

    int data;
};

TEST(initTest, initTestCase) {
  MiniList<Int> list;

  EXPECT_EQ(list.first(), (void *)0);
  EXPECT_EQ(list.last(), (void *)0);
  EXPECT_EQ(list.size(), 0);
  EXPECT_EQ(list.isEmpty(), true);
}

TEST(insertFirstTest, insertFirstTestCase) {
  MiniList<Int> list;
  Int obj;
  Int obj1;

  list.insertFirst(&obj);
  EXPECT_EQ(obj.next, (void *)0);
  EXPECT_EQ(list.last(), &obj);
  EXPECT_EQ(obj.prev, (void *)0);
  EXPECT_EQ(list.first(), &obj);
  EXPECT_EQ(list.size(), 1);

  list.insertFirst(&obj1);
  EXPECT_EQ(obj1.next, &obj);
  EXPECT_EQ(obj.prev, &obj1);
  EXPECT_EQ(obj1.prev, (void *)0);
  EXPECT_EQ(list.first(), &obj1);
  EXPECT_EQ(list.size(), 2);
}

TEST(insertLastTest, insertLastTestCase) {
  MiniList<Int> list;
  Int obj;
  Int obj1;

  list.insertLast(&obj);
  EXPECT_EQ(obj.prev, (void *)0); 
  EXPECT_EQ(list.first(), &obj);
  EXPECT_EQ(obj.next, (void *)0); 
  EXPECT_EQ(list.last(), &obj);
  EXPECT_EQ(list.size(), 1);

  list.insertLast(&obj1);
  EXPECT_EQ(obj1.prev, &obj); 
  EXPECT_EQ(obj.next, &obj1); 
  EXPECT_EQ(obj1.next, (void *)0); 
  EXPECT_EQ(list.last(), &obj1);
  EXPECT_EQ(list.size(), 2);
}

TEST(insertAfterTest, insertAfterTestCase) {
  MiniList<Int> list;
  Int obj;
  Int obj1;
  Int obj2;

  list.insertFirst(&obj);

  list.insertAfter(&obj, &obj1);
  EXPECT_EQ(obj1.prev, &obj);
  EXPECT_EQ(obj1.next, (void *)0);
  EXPECT_EQ(list.last(), &obj1);
  EXPECT_EQ(obj.next, &obj1);
  EXPECT_EQ(list.size(), 2);

  list.insertAfter(&obj, &obj2);
  EXPECT_EQ(obj2.prev, &obj);
  EXPECT_EQ(obj2.next, &obj1);
  EXPECT_EQ(obj2.prev, &obj);
  EXPECT_EQ(obj.next, &obj2);
  EXPECT_EQ(list.size(), 3);
}

TEST(insertBeforeTest, insertBeforeTestCase) {
  MiniList<Int> list;
  Int obj;
  Int obj1;
  Int obj2;

  list.insertFirst(&obj);

  list.insertBefore(&obj, &obj1);
  EXPECT_EQ(obj1.next, &obj);
  EXPECT_EQ(obj1.prev, (void *)0);
  EXPECT_EQ(list.first(), &obj1);
  EXPECT_EQ(obj.prev, &obj1);
  EXPECT_EQ(list.size(), 2);

  list.insertBefore(&obj, &obj2);
  EXPECT_EQ(obj2.next, &obj);
  EXPECT_EQ(obj2.prev, &obj1);
  EXPECT_EQ(obj1.next, &obj2);
  EXPECT_EQ(obj.prev, &obj2);
  EXPECT_EQ(list.size(), 3);
}

TEST(removeTest, removeTestCase) {
  MiniList<Int> list;
  Int obj;
  Int obj1;
  Int obj2;

  list.insertLast(&obj);
  list.insertLast(&obj1);
  list.insertLast(&obj2);

  list.remove(&obj);
  EXPECT_EQ(list.first(), &obj1);
  EXPECT_EQ(obj1.prev, (void *)0);
  EXPECT_EQ(list.size(), 2);

  list.remove(&obj2);
  EXPECT_EQ(obj1.next, (void *)0);
  EXPECT_EQ(list.last(), &obj1);
  EXPECT_EQ(list.size(), 1);
}

// To do: add more unit test
