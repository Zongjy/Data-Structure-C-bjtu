#include "mystring.h"

int main()
{
    // 测试
    mystring S, T;
    str_init(&S, "aaababbcbaaba");
    str_init(&T, "aab");
    printf("%d\n", str_index(&S, &T));
    str_concat(&S, &T);
    printf("%s", S);
    return 0;
}