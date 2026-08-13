#ifndef CONFIG_H
#define CONFIG_H

// enum 常见于几选一的模式，而bit flag则更适用于模式组合

typedef enum {                // 默认字典序
    SORT_NUMERIC = 1 << 0,    // 数字排序
    SORT_REVERSE = 1 << 1,    // 反转排序结果
    SORT_FOLDCASE = 1 << 2,   // 忽略大小写
} SortFlag;

typedef struct {
    unsigned int flags;
} SortConfig;

// 初始化
void config_init(SortConfig *cfg);

// 解析命令行参数，返回‘文件’开始的位置
int config_parse_command(int argc, char **argv, SortConfig *cfg);


#endif