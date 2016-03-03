#include "CppUTest/TestHarness.h"
#include "btree.h"
#include "btree_private.h"

TEST_GROUP(BTree)
{
};

TEST(BTree, btree_insert)
{
	btree b = btree_create();
	btree_insert(b, 10);
	CHECK_EQUAL(b->root->data, 10);

	btree_insert(b, 2);
	CHECK_EQUAL(b->root->data, 10);
	CHECK_EQUAL(b->root->children[0]->data, 2);

	btree_insert(b, 12);
	CHECK_EQUAL(b->root->data, 10);
	CHECK_EQUAL(b->root->children[0]->data, 2);
	CHECK_EQUAL(b->root->children[1]->data, 12);

	btree_insert(b, 1);
	CHECK_EQUAL(b->root->data, 10);
	CHECK_EQUAL(b->root->children[0]->data, 2);
	CHECK_EQUAL(b->root->children[0]->children[0]->data, 1);
	CHECK_EQUAL(b->root->children[1]->data, 12);

	btree_insert(b, 3);
	CHECK_EQUAL(b->root->data, 10);
	CHECK_EQUAL(b->root->children[0]->data, 2);
	CHECK_EQUAL(b->root->children[0]->children[0]->data, 1);
	CHECK_EQUAL(b->root->children[0]->children[1]->data, 3);
	CHECK_EQUAL(b->root->children[1]->data, 12);
}

TEST(BTree, btree_size)
{
	btree b = btree_create();
	CHECK_EQUAL(btree_size(b), 0);
	btree_insert(b, 10);
	CHECK_EQUAL(btree_size(b), 1);
	btree_insert(b, 2);
	CHECK_EQUAL(btree_size(b), 2);
	btree_insert(b, 2);
	CHECK_EQUAL(btree_size(b), 3);
}

