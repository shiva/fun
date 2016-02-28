/*
 * types_private.h
 *
 *  Created on: Nov 12, 2015
 *      Author: shiva
 */

#ifndef C_DS_INCLUDE_TYPES_PRIVATE_H_
#define C_DS_INCLUDE_TYPES_PRIVATE_H_

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct iterator_s* iterator_t;

	typedef bool (*has_next_fn)(iterator_t iter);
	typedef item_type (*get_next_fn)(iterator_t iter);

	typedef struct iterator_s {
		has_next_fn has_next;
		get_next_fn get_next;
	} iterator_base_t;

#ifdef __cplusplus
}
#endif

#endif /* C_DS_INCLUDE_TYPES_PRIVATE_H_ */
