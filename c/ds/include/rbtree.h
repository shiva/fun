/*
 * rbtree.h
 *
 *  Created on: Feb 25, 2016
 *      Author: shiva
 */
#ifndef C_DS_INCLUDE_RBTREE_H
#define C_DS_INCLUDE_RBTREE_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct rbtree_s* rbtree;

	void 	rbtree_insert(rbtree tree, int data);
	void 	rbtree_delete(rbtree tree);
	node_t* rbtree_search(rbtree tree, int data);

#ifdef __cplusplus
}
#endif

#endif /* C_DS_INCLUDE_RBTREE_H */
