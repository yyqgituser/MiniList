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

// To do: add more unit test
