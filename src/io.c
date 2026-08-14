#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "config.h"
#include "io.h"

LineList *linelist_create(void)
{
    LineList *lst = malloc(sizeof(LineList));

    lst->size = 0;
    lst->capacity = MAX_CAPACITY;
    lst->data = malloc(MAX_CAPACITY * sizeof(char *));

    return lst;
}


void linelist_destroy(LineList *lst)
{
    free(lst->data);
    free(lst);
}


static char *read_line_from_stdin(LineList *lst)
{
    char temp_line[MAX_LINE_LENGTH];
    int c;
    int index = 0;
    while ((c = getchar()) != EOF && c != '\n') 
        temp_line[index++] = c;
    if (c == EOF && index == 0)
        return NULL;

    temp_line[index] = '\0';

    char *line = malloc(index + 1);

    strcpy(line, temp_line);
    return line;
}

static char *read_line_from_file(FILE *fp)
{
    char temp_line[MAX_LINE_LENGTH];

    if (fgets(temp_line, sizeof(temp_line), fp) == NULL)
        return NULL;
        
    size_t len = strlen(temp_line);
    if (temp_line[len - 1] == '\n')
        temp_line[len - 1] = '\0';

    char *line = malloc(len + 1);
    strcpy(line, temp_line);

    return line;
}

// 先不考虑扩容
static void linelist_add(LineList *lst, char *line)
{
    lst->data[lst->size] = line;
    lst->size++;
}


void linelist_read_stdin(LineList *lst)
{
    while (1) {
        char *line = read_line_from_stdin(lst);
        if (line == NULL)
            break;
        else    
            linelist_add(lst, line);
    }
}

void linelist_read_file(LineList *lst, const char *filename)
{
    FILE *fp = fopen(filename, "r");

    while (1) {
        char *line = read_line_from_file(fp);
        if (line == NULL)
            break;
        else    
            linelist_add(lst, line);
    }
    fclose(fp);
}

void linelist_print_lines(LineList *lst)
{
    for (int i = 0; i < lst->size; i++) 
        printf("%s\n", lst->data[i]);
}