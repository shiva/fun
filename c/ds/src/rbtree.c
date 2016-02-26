#include "mem.h"
#include "types.h"
#include "rbtree.h"

struct rbtree_s {
    node_t* root;
}

struct node_s {
    bool    isred;
    node_t* left;
    node_t* right;

    int data;
}

rbtree create(void)
{
    rbtree t = NULL;

    t = mem_alloc(sizeof(struct rbtree_s));
    if (t) {
        t->root = NULL;
    }

    return t;
}

node_t* make_node(int data)
{
    node_t* n = mem_alloc(sizeof(struct node_s));
    if (n) {
        n->isred = false;
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
