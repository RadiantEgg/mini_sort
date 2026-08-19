#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "compare.h"

static int cmp_numeric(const void *a, const void *b)
{
    double x = atof(*(const char **)a);
    double y = atof(*(const char **)b);
    if (x == y)
        return 0;
    else if (x > y)
        return 1;
    else
        return -1;
}

static int cmp_numeric_reverse(const void *a, const void *b)
{
    double x = atof(*(const char **)a);
    double y = atof(*(const char **)b);
    if (x == y)
        return 0;
    else if (x > y)
        return -1;
    else
        return 1;
}

static int cmp_dictionary(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

static int cmp_dictionary_reverse(const void *a, const void *b)
{
    return -strcmp(*(const char **)a, *(const char **)b);
}

static int cmp_dictionary_foldcase(const void *a, const void *b)
{
    const char *s = *(const char **)a;
    const char *t = *(const char **)b;
    
    while (*s && *t && tolower(*s) == tolower(*t))
        s++, t++;
    
    if (*s == *t)
        return 0;
    
    if (tolower(*s) < tolower(*t))
        return -1;
    return 1;
}

static int cmp_dictionary_foldcase_reverse(const void *a, const void *b)
{
    const char *s = *(const char **)a;
    const char *t = *(const char **)b;
    
    while (*s && *t && tolower(*s) == tolower(*t))
        s++, t++;
    
    if (*s == *t)
        return 0;
    
    if (tolower(*s) < tolower(*t))
        return 1;
    return -1;
}

Comparator compare_create(const SortConfig *cfg)
{
    if (cfg->flags & SORT_NUMERIC) {
        if (cfg->flags & SORT_REVERSE)
            return cmp_numeric_reverse;
        else    
            return cmp_numeric;
    } else {
        if (cfg->flags & SORT_FOLDCASE) {
            if (cfg->flags & SORT_REVERSE)
                return cmp_dictionary_foldcase_reverse;
            else    
                return cmp_dictionary_foldcase;
        } 
        else if (cfg->flags & SORT_REVERSE)
            return cmp_dictionary_reverse;
        else
            return cmp_dictionary;
    }
}