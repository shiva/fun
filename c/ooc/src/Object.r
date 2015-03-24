#ifndef __OBJECT_PRIVATE_H__
#define __OBJECT_PRIVATE_H__

struct Object {
    const struct Class *class;  /* Object's description */
};

typedef void * (* ctor_fn) (void* self, va_list* app);
typedef void * (* dtor_fn) (void* self);
typedef int    (* differ_fn) (const void* self, const void* b);
typedef int    (* puto_fn) (const void* self, FILE* fp);

struct Class {
    const struct        Object _;       /* class' description */
    const char*         name;           /* class' name */
    const struct Class* super;          /* class' super class */
    size_t              size;           /* class' object's size */
    
    ctor_fn             ctor;
    dtor_fn             dtor;
    differ_fn           differ;
    puto_fn             puto;
};

#endif // __OBJECT_PRIVATE_H__
