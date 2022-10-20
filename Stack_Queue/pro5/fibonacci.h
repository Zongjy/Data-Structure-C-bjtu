#ifndef FIBONACCI_H__
#define FIBONACCI_H__

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 4   // 循环队列容量

typedef struct queue
{
    int f[MAXSIZE]; // 数据域
    int front;      // 队首
    int rear;       // 队尾
    int length;     // 队列长度(辅助判断是否为空/满)
} sq_queue;

void queue_init(sq_queue*);

void queue_push(sq_queue *, int);

void queue_pop(sq_queue *);

int queue_is_empty(sq_queue *);

int queue_is_full(sq_queue *);

int queue_front(sq_queue *);

#endif