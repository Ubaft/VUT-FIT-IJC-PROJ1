#include "htab.h"
#include "htab_table.h"

htab_iterator_t htab_end(const htab_t * t){
    htab_iterator_t ret;
    ret.idx = t->arr_size;
    ret.ptr = NULL;
    ret.t = t;
    return ret;
}