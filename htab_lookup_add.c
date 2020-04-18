#include "htab.h"
#include "htab_table.h"
#include <stdbool.h>
#include <stdlib.h>

htab_iterator_t htab_lookup_add(htab_t * t, htab_key_t key){
    htab_iterator_t ret = htab_find(t, key);
    htab_iterator_t end = htab_end(t);
    if(htab_iterator_equal(ret, end) == false)
    {
        ret.ptr->data += 1;
        t->size += 1;
        return ret;
    }
    size_t index = htab_hash_fun(key) % t->arr_size;
    htab_item_t *tmp = t->ptr[index];
    htab_item_t *new = malloc(sizeof(htab_item_t));
    if(new == NULL)
        return end;
    new->data = 1;
    new->key = key;
    new->next = tmp->next;

    t->size += 1;
    tmp->next = new;
    
    ret.idx = index;
    ret.ptr = new;
    ret.t = t;
    return ret;
}