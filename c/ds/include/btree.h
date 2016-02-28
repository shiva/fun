/*
 * rbtree.h
 *
 *  Created on: Feb 25, 2016
 *      Author: shiva
 */
#ifndef C_DS_INCLUDE_BTREE_H
#define C_DS_INCLUDE_BTREE_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct btree_s* btree;

	void 	btree_insert(btree tree, int data);
	void 	btree_delete(btree tree);
	node_t* btree_search(btree tree, int data);

#ifdef __cplusplus
}
#endif

#endif /* C_DS_INCLUDE_BTREE_H */
