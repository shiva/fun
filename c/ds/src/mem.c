/*
 * mem.c
 *
 *  Created on: Nov 11, 2015
 *      Author: shiva
 */
#include "mem.h"

void* mem_alloc(size_t size)
{
	return malloc(size);
}

void  mem_free(void *ptr)
{
	if (ptr) {
		return free(ptr);
	}
}

void* mem_calloc(size_t nmemb, size_t size)
{
	return calloc(nmemb, size);
}

void* mem_realloc(void *ptr, size_t size)
{
	return realloc(ptr, size);
}
