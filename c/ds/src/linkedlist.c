#include "linkedlist.h"
#include "types.h"
#include "mem.h"

struct node_s {
	int 			val;
	struct node_s* 	next;
};

// push to head
void ll_push(node_t *head, int val)
{
	node_t new_node;
	new_node = mem_alloc(sizeof(struct node_s));

	new_node->val = val;
	new_node->next = *head;
	*head = new_node;
}

int ll_pop(node_t *head)
{
	node_t next = NULL;
	int ret;
	if (head == NULL) {
		return -1;
	}

	next = (*head)->next;
	ret = (*head)->val;
	free(*head);
	*head = next;

	return ret;
}

node_t get_tail(node_t head)
{
	node_t n = head;

	while(ll_node_has_next(n)) {
		n = ll_node_get_next(n);
	}

	return n;
}

bool ll_append(node_t *head, int val)
{
	node_t n = *head;
	node_t new_node = NULL;

	if (!n) {
		ll_push(head, val);
		return true;
	}

	n = get_tail(n);

	new_node = mem_alloc(sizeof(struct node_s));
	new_node->val = val;
	new_node->next = NULL;
	n->next = new_node;

	return true;
}

bool ll_remove_tail(node_t head)
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

	node_t current = head;
	while(current->next != NULL) {
		current = current->next;
	}

	free(current);
	return true;
}

bool ll_remove_by_index(node_t *head, int idx)
{
	int i = idx;
	node_t n = *head;
	node_t prev = NULL;

	if (idx == 0) {
		*head = n->next;
		free(n);
		return true;
	}

	while(n) {
		idx--;
		prev = n;
		n = ll_node_get_next(n);

		if (idx == 0) {
			// found the correct node;
			prev->next = n->next;
			free(n);
			return true;
		}
	}

	return false;
}

bool ll_remove_by_value(node_t *head, int val)
{
	node_t n = *head;
	node_t prev = NULL;

	if (n->val == val) {
		*head = n->next;
		free(n);
		return true;
	}

	prev = n;
	n = ll_node_get_next(n);

	while(n) {
		prev = n;
		n = ll_node_get_next(n);

		if (n->val == val) {
			prev->next = n->next;
			free(n);
			return true;
		}
	}

	return false;
}

bool ll_node_has_next(node_t node)
{
	if (node) {
		return (node->next != NULL);
	}

	return false;
}

node_t ll_node_get_next(node_t node)
{
	if (node) {
		return node->next;
	}

	return NULL;
}

int ll_node_get_value(node_t node)
{
	if (node) {
		return node->val;
	}

	return -1;
}
