// htab_table.h
// Řešení IJC-DU2, příklad 2), 23.4.2020
// Autor: Filip Osvald, FIT
// Přeloženo: gcc 7.5.0
#ifndef __HTAB_TABLE_H__
#define __HTAB_TABLE_H__
#include "htab.h"
struct htab
{
    size_t size;
    size_t arr_size;
    struct htab_item *ptr[];
};
typedef struct htab_item
{
    htab_key_t key;
    htab_value_t data;
    struct htab_item *next;
} htab_item_t;
#endif