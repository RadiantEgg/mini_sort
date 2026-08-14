#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>

typedef struct {
    char **data;
    size_t size;
    size_t capacity;
} LineList;

LineList *linelist_create(void);

void linelist_destroy(LineList *lst);

void linelist_read_stdin(LineList *lst);

void linelist_read_file(LineList *lst, const char *filename);

// void linelist_add(LineList *lst, char *line);

// char *read_line_from_stdin(LineList *lst);

// char *read_line_from_file(LineList *lst);

// void resize



#endif

