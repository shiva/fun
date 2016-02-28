#include "mem.h"
#include "types.h"
#include "btree.h"

struct btree_s {
    node_t* root;
};

struct node_s {
    node_t* ;
    node_t* right;

    int data;
};

btree create_btree(void)
{
    rbtree t = NULL;

    t = mem_alloc(sizeof(struct btree_s));
    if (t) {
        t->root = NULL;
    }

    return t;
}

node_t* make_node(int data)
{
    node_t* n = mem_alloc(sizeof(struct node_s));
    if (n) {
        n->left = NULL;
        n->right = NULL;
        n->data = data;
    }
}

void insert(rbtree tree, int data)
{
    if (!tree) {
        return;
    }

    tree->root = insert_node(tree->root, data);
    if(tree->root == NULL) {
        tree->root =
    }
}

node_t* insert_node(node_t* root, int data)
{
    if (root == null) {
        root = make_node(data);
    } else if (data < root->data) {
        root->left = insert_node
    }
}

void 	delete(rbtree tree);
node_t* search(rbtree tree, int data);
