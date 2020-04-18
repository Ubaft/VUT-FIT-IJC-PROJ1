#include "htab.h"
#include "htab_table.h"

void htab_erase(htab_t * t, htab_iterator_t it){
    htab_item_t *tmp = t->ptr[it.idx];
    htab_item_t *prev = tmp;
    while (tmp != NULL)
    {
        if(tmp == it.ptr)
        {
            t->size -= 1;
            if(tmp->data > 1)
            {    
                tmp->data -= 1;
                return;
            }
            prev->next = tmp->next;
            free(tmp);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}
