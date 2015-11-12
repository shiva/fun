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
extern "C" {  // only need to export C interface if
              // used by C++ source code
#endif

	typedef void* item_type;
	typedef bool (*item_type_is_eq_fn)(item_type x, item_type y);

	typedef struct list_node_s list_node;
	typedef struct list_s list;

	list_node* search_list(list *l, item_type x);

#ifdef __cplusplus
}
#endif

#endif /* C_DS_INCLUDE_LINKEDLIST_H_ */
