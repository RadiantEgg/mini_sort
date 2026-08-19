#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

void sort_lines(LineList *lst, Comparator cmp)
{
    qsort(lst->data, lst->size, sizeof(char *), cmp);
}