// htab_end.c
// Řešení IJC-DU2, příklad 2), 23.4.2020
// Autor: Filip Osvald, FIT
// Přeloženo: gcc 7.5.0
#include "htab.h"
#include "htab_table.h"

htab_iterator_t htab_end(const htab_t * t){
    htab_iterator_t ret;
    ret.idx = t->arr_size;
    ret.ptr = NULL;
    ret.t = t;
    return ret;
}