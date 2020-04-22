// wordcount.c
// Řešení IJC-DU2, příklad 2), 23.4.2020
// Autor: Filip Osvald, FIT
// Přeloženo: gcc 7.5.0
#include "htab.h"
#include "io.h"
#define max_word_len 128
#define table_size 25357 //nejblizsi prvocislo k poctu unikatnich slov v dlouhe knize
#ifdef HASHTEST
size_t htab_hash_fun(htab_key_t str);
#endif
int main()
{
    htab_t *table = htab_init(table_size);
    char *s = malloc(max_word_len);
    int i;
    htab_iterator_t word;
    int long_words = 0;
    while ((i = get_word(s, max_word_len, stdin)) != EOF)
    {
        if(i >= max_word_len && (long_words == 0))
        {
            fprintf(stderr, "Warning: too long words appear in file\n");
            long_words++;
        }
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
size_t htab_hash_fun(htab_key_t str){
    size_t hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}