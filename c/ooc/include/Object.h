#include <stdio.h>

#ifndef __OBJECT_H__
#define __OBJECT_H__

#ifdef __cplusplus
extern "C" {
#endif

    extern const void* Object;      /* create(Object); */
    extern const void* Class;       /* create(Class, "name", super, size, sel, meth, ... 0) */

    void * 	create(const void* _class, ...);
    void 	destroy(void* self);
    int 	differ(const void* self, const void* a);
    int 	puto(const void* self, FILE* fp);
    size_t 	sizeOf(const void* self);

#ifdef __cplusplus
}
#endif

#endif /* __OBJECT_H__ */
