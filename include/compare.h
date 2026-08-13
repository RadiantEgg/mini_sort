#ifndef COMPARE_H
#define COMPARE_H

#include "config.h"

// 后续：生成一个comparator

typedef int (*Comparator)(const void *, const void *);

Comparator compare_create(const SortConfig *cfg);


#endif