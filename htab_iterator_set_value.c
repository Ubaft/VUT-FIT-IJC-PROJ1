// htab_iterator_set_value.c
// Řešení IJC-DU2, příklad 2), 23.4.2020
// Autor: Filip Osvald, FIT
// Přeloženo: gcc 7.5.0
#include "htab.h"
#include "htab_table.h"
htab_value_t htab_iterator_set_value(htab_iterator_t it, htab_value_t val){
    it.ptr->data = val;
    return val;
}