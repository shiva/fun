#include "CppUTest/TestHarness.h"
#include "linkedlist.h"

TEST_GROUP(LinkedList)
{
};

TEST(LinkedList, create_list)
{
	node_t *head = NULL;

	push(&head, 1);
	CHECK(head != NULL);
}

TEST(LinkedList, insert_and_remove_items)
{
	node_t *head = NULL;

	push(&head, 1);
	push(&head, 2);
	push(&head, 3);

	CHECK(pop(&head) == 3);
	CHECK(pop(&head) == 2);
	CHECK(pop(&head) == 1);
}

TEST(LinkedList, iterate_list)
{
	int i = 0;
	node_t *head = NULL;
	node_t *n = NULL;

	while(i < 10) {
		push(&head, i);
		i++;
	}

	n = head;
	i--;

	while(n) {
		CHECK(node_get_value(n) == i);
		n = node_get_next(n);
		i--;
	}
}

TEST(LinkedList, remove_by_index)
{
	node_t *head = NULL;

	push(&head, 1);
	push(&head, 2);
	push(&head, 3);

	remove_by_index(&head, 1);
	CHECK(pop(&head) == 3);
	CHECK(pop(&head) == 1);
}

TEST(LinkedList, remove_by_value)
{
	node_t *head = NULL;

	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);

	remove_by_value(&head, 2);
	CHECK(pop(&head) == 4);
	CHECK(pop(&head) == 3);
	CHECK(pop(&head) == 1);
}

TEST(LinkedList, remove_last)
{
	node_t *head = NULL;

	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);

	remove_last(head);
	CHECK(pop(&head) == 4);
	CHECK(pop(&head) == 3);
	CHECK(pop(&head) == 2);
}

TEST(LinkedList, append_last)
{
	node_t *head = NULL;

	append_last(&head, 1);
	append_last(&head, 2);
	append_last(&head, 3);
	append_last(&head, 4);

	CHECK(pop(&head) == 1);
	CHECK(pop(&head) == 2);
	CHECK(pop(&head) == 3);
	CHECK(pop(&head) == 4);
}

