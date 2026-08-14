#include <stdio.h>

#include "config.h"

void config_init(SortConfig *cfg)
{
    cfg->flags = 0;
}

int config_parse_command(int argc, char **argv, SortConfig *cfg)
{
    int i;
    char c;
    int file_start = 1;     // 记录文件参数开始位置

    printf("===== Project: %s ======\n", *argv++);

    for (i = 2; i <= argc && (*argv)[0] == '-'; i++, argv++) {
        while ((c = *++argv[0])) {
            switch (c) {
            case 'n':
                cfg->flags |= SORT_NUMERIC;
                break;
            case 'r':
                cfg->flags |= SORT_REVERSE;
                break;
            case 'f':
                cfg->flags |= SORT_FOLDCASE;
                break;

            default:
                printf("Unknown command\n");
                break;
            }
        }
    }
    // 这里可以判断是stdin，但是不知道后面是否有用，先留着
    // if (i == argc) {

    // }

    file_start = i;
    return file_start;
}