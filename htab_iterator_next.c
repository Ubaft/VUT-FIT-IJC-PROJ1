#include "htab.h"
#include "htab_table.h"
htab_iterator_t htab_iterator_next(htab_iterator_t it){
    htab_item_t *tmp = it.ptr->next;
    if(tmp != NULL)
    {
        htab_iterator_t ret;
        ret.idx = it.idx;
        ret.ptr = tmp;
        ret.t = it.t;
        return ret;
    }
    
    for(size_t i = it.idx + 1; i < it.t->arr_size; i++)
    {
        if(it.t->ptr[i] != NULL)
        {
            htab_iterator_t ret;
            ret.idx = i;
            ret.ptr = it.t->ptr[i];
            ret.t = it.t;
            return ret;
        }
    }
    return htab_end(it.t);
}
