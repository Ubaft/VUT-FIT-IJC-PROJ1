#include "htab.h"
#include "htab_table.h"
#include <string.h>
#include <stdlib.h>

htab_iterator_t htab_find(htab_t * t, htab_key_t key){
    size_t index = htab_hash_fun(key) % t->arr_size;
    htab_item_t *tmp = t->ptr[index];
    while(tmp != NULL)
    {
        if(!(strcmp(tmp->key, key)))
        {
            htab_iterator_t ret;
            ret.idx = index;
            ret.ptr = tmp;
            ret.t = t;
            return ret;
        }
        tmp = tmp->next;
    }
    return htab_end(t);
}