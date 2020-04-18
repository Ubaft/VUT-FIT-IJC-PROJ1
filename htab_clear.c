#include "htab.h"
#include "htab_table.h"

void htab_clear(htab_t * t){
    htab_iterator_t tmp = htab_begin(t);
    htab_iterator_t next = tmp;
    htab_iterator_t end = htab_end(t);
    while(!(htab_iterator_equal(tmp, end)))
    {
        next = htab_iterator_next(next);
        free((char*)tmp.ptr->key);
        free(tmp.ptr);
        t->ptr[tmp.idx] = NULL;
        tmp = next;
    }
    t->size = 0;
}