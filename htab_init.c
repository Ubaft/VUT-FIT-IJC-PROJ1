#include <stdlib.h>
#include "htab.h"
#include "htab_table.h"

htab_t *htab_init(size_t n){
    htab_t *ret = malloc(sizeof(htab_t) + (n * sizeof(htab_item_t)));
    if (ret == NULL)
        return NULL;
    ret->size = 0;
    ret->arr_size = n;
    for(size_t i = 0; i < n; i++)
        ret->ptr[i] = NULL;
    return ret;
}