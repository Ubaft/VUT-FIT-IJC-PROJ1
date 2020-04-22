// htab_begin.c
// Řešení IJC-DU2, příklad 2), 23.4.2020
// Autor: Filip Osvald, FIT
// Přeloženo: gcc 7.5.0
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
