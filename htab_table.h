#ifndef __HTAB_TABLE_H
#define __HTAB_TABLE_H
#include "htab.h"
struct htab
{
    unsigned size;
    unsigned arr_size;
    struct htab_item *ptr[];
};
struct htab_item
{
    htab_key_t key;
    htab_value_t data;
    struct htab_item *next;
};
#endif