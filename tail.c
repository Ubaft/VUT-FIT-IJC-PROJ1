// tail.c
// Řešení IJC-DU2, příklad 1), 23.4.2020
// Autor: Filip Osvald, FIT
// Přeloženo: gcc 7.5.0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define line_limit 1024
void print_lines(int tail, FILE *input);
void skip_print(int tail, FILE *input);
int main(int argc,char *argv[])
{
    long tail = 10;
    char *p;
    if(argc > 4) 
    {
        fprintf(stderr, "Too many arguments\n");
        return 1;
    }
    if (argc == 1)
    {
        print_lines( tail, stdin);
    }
    else if (argc == 2)
    {
        if(access(argv[1], F_OK) == -1)
        {
            fprintf(stderr, "File doesnt exist\n");
            return 1;
        }
        FILE *input = fopen(argv[1], "r");
        if (input == NULL)
        {
            fprintf(stderr, "File cant be opened\n");
            return 1;
        }
        print_lines(tail, input);
    }
    
    else if (argc == 3)
    {
        if(strcmp(argv[1], "-n") == 0)
        {
            tail = strtol(argv[2], &p, 10);
            if(strncmp(argv[2], "+", 1) == 0)
            {
                skip_print(tail, stdin);
            }
            else
            {
                print_lines(tail, stdin);
            }          
        }
    }
    else if(argc == 4)
    {
        if(strcmp(argv[1], "-n") == 0)
        {
            if(access(argv[3], F_OK) == -1)
            {
                fprintf(stderr, "File doesnt exist\n");
                return 1;
            }
            FILE *input = fopen(argv[3], "r");
            if (input == NULL)
            {
                fprintf(stderr, "File cant be open\n");
                return 1;
            }
            tail = strtol(argv[2], &p, 10);
            if(strncmp(argv[2], "+", 1) == 0)
            {
                skip_print(tail, input);
            }
            else
            {
                print_lines(tail, input);
            }
        }
    }
    return 0;
}
void print_lines(int tail, FILE *input)
{
    char p;
    char buffer[tail][line_limit];
    int i = 0;
    int full = 0;
    int toolong = 0;
    while (fgets(buffer[i], line_limit, input) != NULL)
    {
        if(buffer[i][strlen(buffer[i]) - 1] != '\n')
        {
            buffer[i][line_limit - 1] = '\n';
            if (toolong == 0)
            {
                fprintf(stderr, "Warning: Too long lines found and will be shortened\n");
            }
            while ((p = fgetc(input)) != '\n') {};
            toolong = 1;
        }
        i++;
        if (i == tail)
        {
            i = 0;
            full = 1;
        }
    }
    if (full == 0)
    {
        for (int index = 0; index < i; index++)
        {              
            printf("%s", buffer[index]);
        }
    }
    else
    {
        for(int j = 0; j < tail; j++)
        {
            printf("%s", buffer[i]);
            i++;
            if (i == tail)
            {
                i = 0;
            }
        }
    }
}
void skip_print(int tail, FILE *input)
{
    char p;
    char buffer[line_limit];
    int toolong = 0;
    while (fgets(buffer, line_limit, input) != NULL)
    {
        if(buffer[strlen(buffer) - 1] != '\n')
        {
            buffer[line_limit - 1] = '\n';
            if (toolong == 0)
            {
                fprintf(stderr, "Warning: Too long lines found and will be shortened\n");
            }
            while ((p = fgetc(input)) != '\n') {};
            toolong = 1;
        }
        if (tail <= 1)
        {
            printf("%s", buffer);
        }
        else
        {
            tail--;
        }
    }
}