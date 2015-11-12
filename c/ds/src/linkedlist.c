#include <stdio.h>
#include "linkedlist.h"

/* recursive list implementation */

typedef void* item_type;
typedef bool (*item_type_is_eq_fn)(item_type x, item_type y);

struct list_node_s {
    item_type           item;
    struct list_node_s* next;
};

struct list_s {
    item_type_is_eq_fn   is_equal;
    struct list_node_s*  head;
};

list_node* find_node(list_node* n, item_type x, item_type_is_eq_fn comparator)
{
    if (!n || !x || !comparator) {
        return NULL;
    }

    if (comparator(n->item, x)) {
        return n->item;
    } else {
        return find_node(n->next, x, comparator);
    }
}

list_node* search_list(list *l, item_type x)
{
	return find_node(l->head, x, l->is_equal);
}
