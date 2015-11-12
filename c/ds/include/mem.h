/*
 * mem.h
 *
 *  Created on: Nov 11, 2015
 *      Author: shiva
 */

#include <stdlib.h>

#ifndef C_DS_INCLUDE_MEM_H_
#define C_DS_INCLUDE_MEM_H_

#ifdef __cplusplus
extern "C" {
#endif

	/* wrappers to allow for changing memory implementations */
	void* mem_alloc(size_t size);
	void  mem_free(void *ptr);
	void* mem_calloc(size_t nmemb, size_t size);
	void* mem_realloc(void *ptr, size_t size);

#ifdef __cplusplus
}
#endif

#endif /* C_DS_INCLUDE_MEM_H_ */

