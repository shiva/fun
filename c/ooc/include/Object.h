#include <stdio.h>

#ifndef __OBJECT_H__
#define __OBJECT_H__


extern const void* Object;      /* new(Object); */
extern const void* Class;       /* new(Class, "name", super, size, sel, meth, ... 0) */

void * 	new (const void* _class, ...);
void 	delete (void* self);
int 	differ(const void* self, const void* a);
int 	puto(const void* self, FILE* fp);
size_t 	sizeOf(const void* self);

#endif /* __OBJECT_H__ */
