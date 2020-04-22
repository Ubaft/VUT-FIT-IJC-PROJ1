// htab_bucket_count.c
// Řešení IJC-DU2, příklad 2), 23.4.2020
// Autor: Filip Osvald, FIT
// Přeloženo: gcc 7.5.0
#include "htab.h"
#include "htab_table.h"
size_t htab_bucket_count(const htab_t * t){
    return t->arr_size;
}