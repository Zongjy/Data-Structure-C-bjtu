#include "mystring.h"

/// @brief 以C字符串初始化新定义的字符串结构
/// @param dest 
/// @param src 
void str_init(mystring *dest, char *src)
{
    int len = 0;
    char *temp = src;
    // 获取src长度(不含'\0')
    while (*temp != '\0')
    {
        len++;
        temp++;
    }
    // 空串
    if (len == 0)
    {
        dest->pstr = NULL;
        dest->length = 0;
    }
    else
    {
        // 多分配一个char的空间放'\0'
        dest->pstr = (char *)malloc((len + 1) * sizeof(char));
        for (int i = 0; i < len; i++)
        {
            dest->pstr[i] = src[i];
        }
        dest->pstr[len] = '\0';
        dest->length = len;
    }
}

/// @brief 返回串长
/// @param str 
/// @return int 
int str_len(const mystring *str)
{
    return str->length;
}

/// @brief 拼接两个字符串
/// @param s1 
/// @param s2 
void str_concat(mystring *s1, mystring *s2)
{
    int len1 = str_len(s1), len2 = str_len(s2);
    int len = len1 + len2;
    // 重新分配内存
    s1->pstr = (char *)realloc(s1->pstr, sizeof(char) * (len + 1));
    for (int i = len1; i < len; i++)
    {
        // 将 s2 连在 s1 的后面
        s1->pstr[i] = s2->pstr[i - len1];
    }
    // 末尾赋'\0'
    s1->pstr[len] = '\0';
    s1->length = len;
}

/// @brief 求str的nextval数组
/// @param str 
/// @param nextval 
void str_nextval(mystring *str, int *nextval)
{
    // 由于这里定义的字符串是类似于C风格的字符串, 而非教材中的首位放串长
    // 所以next[0] == -1, next[1] == 0, i 和 j 也均减少1
    // 求模式串的最大相同前后缀, j需落后i, 相当于拿自己匹配自己(错开1位)
    int i = 0, j = -1;
    nextval[0] = -1;
    while (i < str->length-1)
    {
        if (j == -1 || str->pstr[i] == str->pstr[j])
        {
            i++;
            j++;
            if (str->pstr[i] != str->pstr[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j]; // 如果求next则不需要这一步
        }
        else
        {
            j = nextval[j]; // 回溯
        }
    }
}

/// @brief 利用KMP(改进)算法求子串下标
/// @param master 
/// @param pattern 
/// @return 第一次匹配成功的子串首位下标, 若无法找到则返回-1
int str_index(mystring *master, mystring *pattern)
{
    int nextval[pattern->length];
    str_nextval(pattern, nextval);
    // 这里 ij 均为 0 开始匹配
    int i = 0, j = 0;
    while (i < master->length && j < pattern->length)
    {
        if (j == -1 || master->pstr[i] == pattern->pstr[j])
        {
            i++;
            j++;
        }
        else
        {
            j = nextval[j];
        }
    }
    // 如果最后模式串全都匹配完了, 说明有子串匹配模式串
    if (j >= pattern->length)
        return i - pattern->length; // 返回匹配点下标(0~Len)
    else
        return -1;
}