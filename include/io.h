#ifndef IO_H
#define IO_H

#include <stdio.h>

#define MAX_CAPACITY 1000
#define MAX_LINE_LENGTH 1024

typedef struct {
    char **data;
    size_t size;
    size_t capacity;
} LineList;

LineList *linelist_create(void);

void linelist_destroy(LineList *lst);

void linelist_read_stdin(LineList *lst);

void linelist_read_file(LineList *lst, const char *filename);

void linelist_print_lines(LineList *lst);

// void resize



#endif

