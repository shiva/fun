/*
 * linkedlist.h
 *
 *  Created on: Nov 11, 2015
 *      Author: shiva
 */
#ifndef C_DS_INCLUDE_LINKEDLIST_H_
#define C_DS_INCLUDE_LINKEDLIST_H_

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

	void ll_push(node_t *head, int val);
	int  ll_pop(node_t *head);

	/*!
	 * Add a node to the tail
	 *
	 */
	bool ll_append(node_t *head, int val);
	bool ll_remove_tail(node_t head);

	bool ll_remove_by_index(node_t *head, int idx);
	bool ll_remove_by_value(node_t *head, int val);

	bool   ll_node_has_next(node_t node);
	node_t ll_node_get_next(node_t node);
	int    ll_node_get_value(node_t node);


#ifdef __cplusplus
}
#endif

#endif /* C_DS_INCLUDE_LINKEDLIST_H_ */
