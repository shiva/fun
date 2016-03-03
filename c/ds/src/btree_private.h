/*
 * rbtree.h
 *
 *  Created on: Feb 25, 2016
 *      Author: shiva
 */
#ifndef C_DS_INCLUDE_BTREE_PRIVATE_H
#define C_DS_INCLUDE_BTREE_PRIVATE_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

	typedef enum {
		NODE_LEFT = 0,
		NODE_RIGHT
	} node_orientation_t;

	struct btree_s {
		node_t root;
	};

	struct node_s {
		node_t children[2];
		int    data;
	};

#ifdef __cplusplus
}
#endif

#endif /* C_DS_INCLUDE_BTREE_PRIVATE_H */
