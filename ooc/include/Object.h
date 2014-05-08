#ifndef __OBJECT_H__
#define __OBJECT_H__

extern const void *Object;      /* new(Object); */
extern const void *Class;       /* new(Class, "name", super, size, sel, meth, ...) */

void*   new (const void *_class, ...);
void    delete (void *self);

int     differ(const void *self, const void *a);
size_t  sizeOf(const void* self);
// int     puto(const void *self, FILE *fp);

#endif // __OBJECT_H__
