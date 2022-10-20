#ifndef QUEEN_H__
#define QUEEN_H__

#include<stdio.h>
#include<stdlib.h>
#define N 8         // 棋盘大小

typedef struct queen
{
    int data[N];    // 每一行放的棋子位处的列数(1 ~ N)
    int top;        // 第几列
} queen;

// 初始化栈
void queen_init(queen*);

// 入栈
void queen_push(queen *, int);

// 出栈
void queen_pop(queen *);

// 栈的销毁
// void queen_destroy(queen *);

// 栈满判断
int queen_full(queen *);

// 栈空判断
int queen_empty(queen *);

// 放置方案是否符合条件
int queen_judge(queen *);

#endif