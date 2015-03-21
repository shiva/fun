#ifndef __OBJECT_PRIVATE_H__
#define __OBJECT_PRIVATE_H__

struct Object {
    const struct Class *class;  /* Object's description */
};

struct Class {
    const struct 		Object _; 				/* class' description */
    const char*         name;					/* class' name */
    const struct Class* super;					/* class' super class */
    size_t              size;					/* class' object's size */
    
    void * (* ctor) (void* self, va_list* app);
    void * (* dtor) (void* self);
    int    (* differ) (const void* self, const void* b);
    int    (* puto) (const void* self, FILE* fp);
};

#endif // __OBJECT_PRIVATE_H__
