#include "linkedlist.h"
#include "types.h"
#include "mem.h"

struct node_s {
	int val;
	struct node_s* next;
};

// push to head
void push(node_t **head, int val)
{
	node_t* new_node;
	new_node = mem_alloc(sizeof(node_t));

	new_node->val = val;
	new_node->next = *head;
	*head = new_node;
}

int pop(node_t **head)
{
	node_t* next = NULL;
	int ret;
	if (*head == NULL) {
		return -1;
	}

	next = (*head)->next;
	ret = (*head)->val;
	free(*head);
	*head = next;

	return ret;
}

node_t* get_tail(node_t *head)
{
	node_t* n = head;

	while(node_has_next(n)) {
		n = node_get_next(n);
	}

	return n;
}

bool append_last(node_t **head, int val)
{
	node_t* n = *head;
	node_t* new_node = NULL;

	if (!n) {
		push(head, val);
		return true;
	}

	n = get_tail(n);

	new_node = mem_alloc(sizeof(node_t));
	new_node->val = val;
	new_node->next = NULL;
	n->next = new_node;

	return true;
}

bool remove_last(node_t *head)
{
	if (!head) {
		return true;	// nothing to remove
	}

	if (!head->next) {
		// remove this item
		free(head);
		head = NULL;
		return true;
	}

	node_t* current = head;
	while(current->next != NULL) {
		current = current->next;
	}

	free(current);
	return true;
}

bool remove_by_index(node_t **head, int idx)
{
	int i = idx;
	node_t* n = *head;
	node_t* prev = NULL;

	if (idx == 0) {
		*head = n->next;
		free(n);
		return true;
	}

	while(n) {
		idx--;
		prev = n;
		n = node_get_next(n);

		if (idx == 0) {
			// found the correct node;
			prev->next = n->next;
			free(n);
			return true;
		}
	}

	return false;
}

bool remove_by_value(node_t **head, int val)
{
	node_t* n = *head;
	node_t* prev = NULL;

	if (n->val == val) {
		*head = n->next;
		free(n);
		return true;
	}

	prev = n;
	n = node_get_next(n);

	while(n) {
		prev = n;
		n = node_get_next(n);

		if (n->val == val) {
			prev->next = n->next;
			free(n);
			return true;
		}
	}

	return false;
}

bool node_has_next(node_t *node)
{
	if (node) {
		return (node->next != NULL);
	}

	return false;
}

node_t* node_get_next(node_t *node)
{
	if (node) {
		return node->next;
	}

	return NULL;
}

int node_get_value(node_t *node)
{
	if (node) {
		return node->val;
	}

	return -1;
}
