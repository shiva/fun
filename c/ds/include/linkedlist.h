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

	typedef struct node_s node_t;

	void push(node_t **head, int val);
	int  pop(node_t **head);

	bool append_last(node_t **head, int val);
	bool remove_last(node_t *head);

	bool remove_by_index(node_t **head, int idx);
	bool remove_by_value(node_t **head, int val);

	bool 	node_has_next(node_t *node);
	node_t* node_get_next(node_t *node);
	int 	node_get_value(node_t *node);


#ifdef __cplusplus
}
#endif

#endif /* C_DS_INCLUDE_LINKEDLIST_H_ */
