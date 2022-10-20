#include"fibonacci.h"

/// @brief 循环队列初始化
/// @param sq 
void queue_init(sq_queue* sq)
{
    if(NULL == sq)
        return;
    sq->front = sq->rear = 0;
    sq->length = 0;
}

/// @brief 判断循环队列是否为空
/// @param sq 
/// @return int 队列为空返回1, 否则返回0
int queue_is_empty(sq_queue*sq)
{
    if(sq->length == 0)
        return 1;
    else
        return 0;
}

/// @brief 判断队列是否为满
/// @param sq 
/// @return int 队列满返回1, 否则返回0
int queue_is_full(sq_queue*sq)
{
    if(sq->length == MAXSIZE)
        return 1;
    else
        return 0;
}

/// @brief 入队
/// @param sq 
/// @param data 
void queue_push(sq_queue*sq,int data)
{
    if(NULL == sq)
        return;
    sq->rear = (sq->rear + 1) % MAXSIZE;
    sq->f[sq->rear] = data;
    sq->length++;
    if (queue_is_full(sq) == 1)
    {
        sq->front = (sq->front + 1) % MAXSIZE;
        sq->length--;
    }
}

/// @brief 出队
/// @param sq 
void queue_pop(sq_queue*sq)
{
    if(NULL == sq)
        return;
    if(queue_is_empty(sq) == 1)
    {
        printf("队列为空");
        return;
    }
    sq->rear = (sq->rear + MAXSIZE - 1) % MAXSIZE;
    sq->length--;
}

/// @brief 查询队首元素
/// @param sq 
/// @return 队列为空或不存在返回-1, 否则返回队首元素值
int queue_front(sq_queue *sq)
{
    if(NULL == sq)
        return -1;
    if (queue_is_empty(sq) == 1)
        return -1;
    else
        return sq->f[sq->front];
}