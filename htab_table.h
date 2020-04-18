#ifndef __HTAB_TABLE_H__
#define __HTAB_TABLE_H__
#include "htab.h"
struct htab
{
    unsigned size;
    unsigned arr_size;
    struct htab_item *ptr[];
};
typedef struct htab_item
{
    htab_key_t key;
    htab_value_t data;
    struct htab_item *next;
} htab_item_t;
#endif