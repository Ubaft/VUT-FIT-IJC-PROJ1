#include "htab.h"
#include "htab_table.h"

void htab_free(htab_t * t){
    htab_clear(t);
    free(t);
}