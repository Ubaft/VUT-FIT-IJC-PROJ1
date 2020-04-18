#include "htab.h"
#include "htab_table.h"
htab_iterator_t htab_begin(const htab_t * t){
    for(size_t i = 0; i < t->arr_size; i++)
    {
        if(t->ptr[i] != NULL)
        {
            htab_iterator_t ret;
            ret.idx = i;
            ret.ptr = t->ptr[i];
            ret.t = t;
            return ret;
        }
    }
    return htab_end(t);
}
