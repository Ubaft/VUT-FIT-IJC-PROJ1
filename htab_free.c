// htab_free.c
// Řešení IJC-DU2, příklad 2), 23.4.2020
// Autor: Filip Osvald, FIT
// Přeloženo: gcc 7.5.0
#include "htab.h"
#include "htab_table.h"

void htab_free(htab_t * t){
    htab_clear(t);
    free(t);
}