// htab_iterator_get_key.c
// Řešení IJC-DU2, příklad 2), 23.4.2020
// Autor: Filip Osvald, FIT
// Přeloženo: gcc 7.5.0
#include "htab.h"
#include "htab_table.h"
htab_key_t htab_iterator_get_key(htab_iterator_t it){
    return it.ptr->key;
}