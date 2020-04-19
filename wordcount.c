#include "htab.h"
#include "io.h"
int main()
{
    htab_t *table = htab_init(1000);
    char *s = malloc(128);
    int i;
    htab_iterator_t word;

    while ((i = get_word(s, 128, stdin)) != EOF)
    {
        word = htab_lookup_add(table, (const char*)s);
    }
    
    word = htab_begin(table);
    htab_iterator_t end = htab_end(table);
    while((htab_iterator_equal(word, end)) == false)
    {
        printf("%s\t%d\n", htab_iterator_get_key(word), htab_iterator_get_value(word));
        word = htab_iterator_next(word);
    }
    htab_free(table);
    free(s);
    
}