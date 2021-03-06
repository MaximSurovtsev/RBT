#include <rbt.hpp>
#include <catch.hpp>

SCENARIO ("init", "[init]")
{
  RedBlackTree<int> test;
  REQUIRE(test._root() == test._NIL());
}

SCENARIO("insert", "[init]")
{
  RedBlackTree<int> test;
  test.insert(4);
  REQUIRE(test.search(4) != 0);
}

SCENARIO("insert2", "[init]")
{
  RedBlackTree<int> tree;
  tree.insert(1);
  tree.insert(2);
  tree.insert(3);
  REQUIRE(tree._root() == tree.search(2));
  REQUIRE(tree._color(2) == 1);
  REQUIRE(tree._color(1) == 0);
  REQUIRE(tree._color(3) == 0);
  REQUIRE(tree.search(1) != 0);
  REQUIRE(tree.search(2) != 0);
  REQUIRE(tree.search(3) != 0);
}

SCENARIO("insert3", "[init]")
{
  RedBlackTree<int> tree;
  tree.insert(1);
  tree.insert(2);
  tree.insert(3);
  tree.insert(4);
  tree.insert(5);
  REQUIRE(tree._root() == tree.search(2));
  REQUIRE(tree._color(2) == 1);
  REQUIRE(tree._color(1) == 1);
  REQUIRE(tree._color(4) == 1);
  REQUIRE(tree._color(3) == 0);
  REQUIRE(tree._color(5) == 0);
  REQUIRE(tree.search(1) != 0);
  REQUIRE(tree.search(2) != 0);
  REQUIRE(tree.search(3) != 0);
  REQUIRE(tree.search(4) != 0);
  REQUIRE(tree.search(5) != 0);
}

SCENARIO ("insert4", "[init]")
{
  RedBlackTree<int> tree;
  tree.insert(3);
  tree.insert(1);
  tree.insert(2);
  REQUIRE(tree._root() == tree.search(2));
  REQUIRE(tree._color(2) == 1);
  REQUIRE(tree._color(1) == 0);
  REQUIRE(tree._color(3) == 0);
  REQUIRE(tree.search(1) != 0);
  REQUIRE(tree.search(2) != 0);
  REQUIRE(tree.search(3) != 0);
}

SCENARIO("insert5", "[init]")
{
  RedBlackTree<int> tree;
  tree.insert(3);
  tree.insert(2);
  tree.insert(1);
  REQUIRE(tree._root() == tree.search(2));
  REQUIRE(tree._color(2) == 1);
  REQUIRE(tree._color(1) == 0);
  REQUIRE(tree._color(3) == 0);
  REQUIRE(tree.search(1) != 0);
  REQUIRE(tree.search(2) != 0);
  REQUIRE(tree.search(3) != 0);
}

SCENARIO("insert6", "[init]")
{
  RedBlackTree<int> tree;
  tree.insert(5);
  tree.insert(7);
  tree.insert(6);
  REQUIRE(tree._root() == tree.search(6));
  REQUIRE(tree._color(6) == 1);
  REQUIRE(tree._color(5) == 0);
  REQUIRE(tree._color(7) == 0);
  REQUIRE(tree.search(5) != 0);
  REQUIRE(tree.search(6) != 0);
  REQUIRE(tree.search(7) != 0);
}













