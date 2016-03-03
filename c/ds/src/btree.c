#include <assert.h>
#include "mem.h"
#include "types.h"
#include "btree.h"
#include "btree_private.h"

btree btree_create(void)
{
    btree t = NULL;

    t = mem_alloc(sizeof(struct btree_s));
    if (t) {
        t->root = NULL;
    }

    return t;
}

node_t make_node(int data)
{
    node_t n = mem_alloc(sizeof(struct node_s));
    if (n) {
        n->children[NODE_LEFT] = NULL;
        n->children[NODE_RIGHT] = NULL;
        n->data = data;
    }

    return n;
}

bool node_has_child(node_t n, node_orientation_t orientation)
{
	return (n->children[orientation] != NULL);
}

node_t node_get_child(node_t n, node_orientation_t orientation)
{
	return n->children[orientation];
}

void node_add_child(node_t n, node_orientation_t o, node_t child)
{
	assert(n->children[o] == NULL);
	n->children[o] = child;
}

void btree_node_insert(node_t node, node_t newnode)
{
	node_t child = NULL;
	node_orientation_t orientation;

	orientation = (newnode->data < node->data) ? NODE_LEFT : NODE_RIGHT;
	child = node_get_child(node, orientation);
	if (child) {
		return btree_node_insert(child, newnode);
	} else {  // reached leaf, add newnode
		return node_add_child(node, orientation, newnode);
	}
}

size_t btree_node_size(node_t node)
{
	if (!node) {
		return 0;
	}

	return btree_node_size(node->children[NODE_LEFT]) +
		   btree_node_size(node->children[NODE_RIGHT]) + 1;
}

void btree_insert(btree tree, int data)
{
	node_t newnode = make_node(data);

	if (!tree) {
		return;
	}

	if (!tree->root) {	// no root => just use new node as root
		tree->root = newnode;
		return;
	}

	// root exists
	return btree_node_insert(tree->root, newnode);
}

void btree_delete(btree tree)
{
	return;
}

node_t btree_search(btree tree, int data)
{
	return NULL;
}

size_t  btree_size(btree tree)
{
	return btree_node_size(tree->root);
}

size_t  btree_max_depth(btree tree)
{
	return 0;
}
