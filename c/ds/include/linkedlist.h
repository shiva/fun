/*
 * linkedlist.h
 *
 *  Created on: Nov 11, 2015
 *      Author: shiva
 */

#include "types.h"

#ifndef C_DS_INCLUDE_LINKEDLIST_H_
#define C_DS_INCLUDE_LINKEDLIST_H_

typedef void* item_type;
typedef bool (*item_type_is_eq_fn)(item_type x, item_type y);

typedef struct list_node_s list_node;
typedef struct list_s list;

#endif /* C_DS_INCLUDE_LINKEDLIST_H_ */
