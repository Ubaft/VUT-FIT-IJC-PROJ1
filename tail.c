#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int linecount(FILE *tocount);
void printlines(int lines_to_print, FILE *fp);

int main(int argc,char *argv[])
{
    long tail = 10;
    char *p;
    const char * filename;
    int filearg = 1;
    printf("argc :%d\n", argc);
    if(argc > 4) //maybe add for 3 args
    {
        fprintf(stderr, "Presahnut maximalni pocet argumentu\n");\
        return 1;
    }
    if(argc == 4)
    {
        if(strcmp(argv[1], "-n") == 0)
        {
            //printf("it is\n");
            if((strncmp(argv[2], "+-", 2) == 0) || (strncmp(argv[2], "-+", 2) == 0))
            {
                //odstranit prvni znak a parsovat
            }
            else if(strncmp(argv[2], "-", 1) == 0)
            {
                //odstranit prvni znak a parsovat
            }
            else if(strncmp(argv[2], "+", 1) == 0)
            {
                //odstranit prvni znak a parsovat
                printf("here +\n");
            }
            else
            {
                tail = strtol(argv[2], &p, 10);
                //nastavit pocetr radku normalne
            }
        }
        filearg = 3;
    }
    printf("checkpoint 1\n");
    filename = argv[filearg];
    FILE *input;
     // argv[1];
    if(access(filename, F_OK) == -1)
    {
        //fprintf(stderr, "Soubor neexistuje\n");
        //return 1;
        input = stdin;
        char c;
        while((c=fgetc(input))!=EOF)
        {
            fseek(input, 0, SEEK_SET);
        }
        
    }
    else
    {
       input = fopen(filename, "rb");
    }   
    
    if(input == NULL)
    {
        fprintf(stderr, "Otevreni souboru se nezdarilo\n");
        fclose(input);        
        return 1;
    }
    printf("checkpoint 2\n");
    printlines(tail, input);
    return 0;

}
int linecount(FILE *fp)
{
    fseek(fp, 0, SEEK_END);
    int lines = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    printf("checkpoint 3\n");
   
    if(lines == 0)
        return 0;
    lines = 1;
    char c;
    printf("checkpoint 5\n");
    while((c=fgetc(fp))!=EOF) 
    {
        printf("checkpoint 6\n");
        if(c=='\n')
        {
            lines++;
        }
        
   }
   printf("checkpoint 4 lines: %d\n", lines);
   fseek(fp, 0, SEEK_SET);
   return lines;
}

void printlines(int lines_to_print, FILE *fp)
{
    int line_count = linecount(fp);
    //printf("pocet radku je: %d\n", line_count);
    int lineskip = line_count - lines_to_print; //osetrit minus
    int skip = 0;
    if(lines_to_print > line_count)
        skip = 1;
    int lines = 0;
    printf("checkpoint 7\n");
    char c;
    if (line_count > 1 && skip != 1)
    {
        while((c=fgetc(fp))!=EOF) 
        {
            if(c=='\n')
            {
                lines++;
            }
            if(lines == lineskip)
                break;
        }
    }
   while((c=fgetc(fp))!=EOF) 
   {
       putc(c, stdout);
   }
}