#include "CppUTest/TestHarness.h"
#include "linkedlist.h"

TEST_GROUP(LinkedList)
{
};

TEST(LinkedList, create_list)
{
	node_t head = NULL;

	ll_push(&head, 1);
	CHECK(head != NULL);
}

TEST(LinkedList, insert_and_remove_items)
{
	node_t head = NULL;

	ll_push(&head, 1);
	ll_push(&head, 2);
	ll_push(&head, 3);

	CHECK(ll_pop(&head) == 3);
	CHECK(ll_pop(&head) == 2);
	CHECK(ll_pop(&head) == 1);
}

TEST(LinkedList, iterate_list)
{
	int i = 0;
	node_t head = NULL;
	node_t n = NULL;

	while(i < 10) {
		ll_push(&head, i);
		i++;
	}

	n = head;
	i--;

	while(n) {
		CHECK(ll_node_get_value(n) == i);
		n = ll_node_get_next(n);
		i--;
	}
}

TEST(LinkedList, remove_by_index)
{
	node_t head = NULL;

	ll_push(&head, 1);
	ll_push(&head, 2);
	ll_push(&head, 3);

	ll_remove_by_index(&head, 1);
	CHECK(ll_pop(&head) == 3);
	CHECK(ll_pop(&head) == 1);
}

TEST(LinkedList, ll_remove_by_value)
{
	node_t head = NULL;

	ll_push(&head, 1);
	ll_push(&head, 2);
	ll_push(&head, 3);
	ll_push(&head, 4);

	ll_remove_by_value(&head, 2);
	CHECK(ll_pop(&head) == 4);
	CHECK(ll_pop(&head) == 3);
	CHECK(ll_pop(&head) == 1);
}

TEST(LinkedList, ll_remove_tail)
{
	node_t head = NULL;

	ll_push(&head, 1);
	ll_push(&head, 2);
	ll_push(&head, 3);
	ll_push(&head, 4);

	ll_remove_tail(head);
	CHECK(ll_pop(&head) == 4);
	CHECK(ll_pop(&head) == 3);
	CHECK(ll_pop(&head) == 2);
}

TEST(LinkedList, ll_append)
{
	node_t head = NULL;

	ll_append(&head, 1);
	ll_append(&head, 2);
	ll_append(&head, 3);
	ll_append(&head, 4);

	CHECK(ll_pop(&head) == 1);
	CHECK(ll_pop(&head) == 2);
	CHECK(ll_pop(&head) == 3);
	CHECK(ll_pop(&head) == 4);
}

