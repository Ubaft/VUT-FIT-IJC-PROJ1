#include "htab.h"
#include "htab_table.h"
htab_key_t htab_iterator_get_key(htab_iterator_t it){
    return it.ptr->key;
}