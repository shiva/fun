/*
 * rbtree.h
 *
 *  Created on: Feb 25, 2016
 *      Author: shiva
 */
#ifndef C_DS_INCLUDE_BTREE_H
#define C_DS_INCLUDE_BTREE_H

#include <stddef.h>
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct btree_s* btree;
	typedef enum {
		INORDER = 0,
		PREORDER,
		POSTORDER
	} traversal_t;

	typedef void (*callback)(node_t node);

	btree 	btree_create(void);
	void 	btree_insert(btree tree, int data);
	void 	btree_delete(btree tree);
	node_t  btree_search(btree tree, int data);

	/*!
	 * Visit each node in the tree
	 *
	 * @param type Type of Traversal [INORDER | PREORDER | POSTORDER]
	 */
	void    btree_walk(btree tree, traversal_t type, callback callback);

	/*!
	 * Get size of the tree
	 *
	 * @return number of nodes in the tree
	 */
	size_t  btree_size(btree tree);

	/*!
	 * Calculate max depth of a Binary Tree
	 *
	 * @experimental
	 */
	size_t  btree_max_depth(btree tree);

#ifdef __cplusplus
}
#endif

#endif /* C_DS_INCLUDE_BTREE_H */
