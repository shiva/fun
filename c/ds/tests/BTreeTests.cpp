#include "CppUTest/TestHarness.h"
#include "btree.h"

TEST_GROUP(BTree)
{
};

TEST(BTree, btree_insert)
{
	btree b = btree_create();
	btree_insert(b, 10);
	btree_insert(b, 2);
	btree_insert(b, 12);
	btree_insert(b, 1);
	btree_insert(b, 3);
}


