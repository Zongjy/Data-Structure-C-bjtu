#ifndef MYSTRING_H__
#define MYSTRING_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct mystring
{
    char *pstr;     // 不定长字符数组(最后一位为'\0')
    int length;     // 字符串长度(不含末尾'\0')
} mystring;

void str_init(mystring *, char *);

int str_len(const mystring *);

void str_concat(mystring *, mystring *);

int str_index(mystring *, mystring *);

// 计算串的next数组(KMP)
// void str_next(mystring *, int *);

void str_nextval(mystring *, int *);

#endif
