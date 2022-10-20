#ifndef BANK_H__
#define BANK_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define wait(a, b) printf("请 %d 号顾客前往 %d 号队列等待\n", a, b)
#define deal(a, b) printf("请 %d 号顾客前往 %d 号柜台办理\n", a, b)

typedef struct node_queue
{
    int serial_num;
    struct node_queue *next;
} node_q;

typedef struct link_queue
{
    node_q *head;
    node_q *tail;
} queue;

void queue_init(queue *);

void queue_push(queue *, int);

void queue_pop(queue *);

void queue_show(queue *);

void queue_destroy(queue *);

int queue_isempty(queue *);

int queue_front(queue *);

void entry_bank(queue *, queue *, queue *, int, int *);

void leave_bank(queue *, queue *, queue *, int *);

void show_window(int *);

// void take_num(queue *, queue *, queue *,int);

#endif