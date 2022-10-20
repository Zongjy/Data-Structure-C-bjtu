#include "bank.h"

void queue_init(queue *pq)
{
    assert(pq);
    pq->head = pq->tail = NULL;
}

void queue_push(queue *pq, int data)
{
    assert(pq);
    node_q *newnode = (node_q *)malloc(sizeof(node_q));
    if (NULL == newnode)
    {
        perror("malloc error\n");
        exit(1);
    }
    newnode->serial_num = data;
    newnode->next = NULL;
    if (pq->head == NULL)
    {
        pq->head = pq->tail = newnode;
    }
    else
    {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
}

void queue_pop(queue *pq)
{
    assert(pq);
    //防止队列为空
    if (queue_isempty(pq))
    {
        printf("queue is empty\n");
        return;
    }
    //队列只有一个元素
    if (NULL == pq->head->next)
    {
        free(pq->head);
        pq->head = pq->tail = NULL;
    }
    else
    {
        node_q *cur = pq->head;
        pq->head = pq->tail;
        free(cur);
    }
}

void queue_destroy(queue *pq)
{
    assert(pq);
    node_q *cur = pq->head;
    while (cur)
    {
        node_q *temp = cur->next;
        free(cur);
        cur = temp;
    }
    pq->head = pq->tail = NULL;
}

int queue_front(queue *pq)
{
    assert(pq);
    if(pq->head == NULL)
        return 0;
    else
        return pq->head->serial_num;
}

void queue_show(queue *pq)
{
    assert(pq);
    node_q *cur = pq->head;
    while (cur)
    {
        printf("%d\t", cur->serial_num);
        cur = cur->next;
    }
}

int queue_isempty(queue *pq)
{
    assert(pq);
    if (pq->head == NULL)
        return 1;
    return 0;
}

void entry_bank(queue *gjj, queue *yhk, queue *lck, int serial, int *window)
{
    int choice;
    printf("\n请选择需要办理的业务:\n  1.公积金\n  2.银行卡\n  3.理财卡\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        if (window[1] == 0)
        {
            deal(serial, 1);
            window[1] = 1;
        }
        else
        {
            wait(serial, 1);
            queue_push(gjj, serial);
        }
    }
    else if (choice == 2)
    {
        int tmp = 0;
        for (int i = 2; i <= 4; i++)
        {
            if (window[i] == 0)
            {
                tmp = i;
                break;
            }
        }
        if (tmp == 0)
        {
            wait(serial, 2);
            queue_push(yhk, serial);
        }
        else
        {
            deal(serial, tmp);
            window[tmp] = 1;
        }
    }
    else if (choice == 3)
    {
        int tmp = 0;
        for (int i = 5; i <= 6; i++)
        {
            if (window[i] == 0)
            {
                tmp = i;
                break;
            }
        }
        if (tmp == 0)
        {
            for (int i = 2; i <= 4; i++)
            {
                if (window[i] == 0)
                {
                    tmp = i;
                    break;
                }
            }
            if (tmp == 0)
            {
                wait(serial, 2);
                queue_push(lck, serial);
            }
            else
            {
                deal(serial, tmp);
                window[tmp] = 1;
            }
        }
        else
        {
            deal(serial, tmp);
            window[tmp] = 1;
        }
    }
    else
    {
        printf("请输入正确的序号!\n");
        return;
    }
}

void leave_bank(queue *gjj, queue *yhk, queue *lck, int *window)
{
    int finish = 0;
    printf("请输入办理完成的柜台序号: ");
    scanf("%d", &finish);
    if (finish > 6 || finish < 1 || window[finish] == 0)
    {
        printf("请输入正确的柜台序号!\n");
        return;
    }
    else
    {
        window[finish] = 0;
        printf("%d 号柜台业务办理完成!\n", finish);
        if(finish == 1)
        {
            if(queue_isempty(gjj) == 0)
            {
                int tmp = queue_front(gjj);
                deal(tmp, finish);
                window[finish] = 1;
                queue_pop(gjj);
            }
        }
        else if (finish == 2||finish ==3)
        {
            if(queue_isempty(yhk) == 0)
            {
                int tmp = queue_front(yhk);
                deal(tmp, finish);
                window[finish] = 1;
                queue_pop(yhk);
            }
            else if(queue_isempty(yhk) == 1 && queue_isempty(lck) == 0)
            {
                int tmp = queue_front(lck);
                deal(tmp, finish);
                window[finish] = 1;
                queue_pop(lck);
            }
        }
        else
        {
            if(queue_isempty(lck) == 0)
            {
                int tmp = queue_front(lck);
                deal(tmp, finish);
                window[finish] = 1;
                queue_pop(lck);
            }
        }
    }
}

void show_window(int *window)
{
    for (int i = 1; i <= 6; i++)
    {
        if (window[i] == 0)
            printf("%d号柜台无人\n", i);
        else
            printf("%d号柜台有人\n", i);
    }
    return;
}