#include "linklist.h"

int rand_num(int maxn)
{
    return rand() % maxn + 1;
}

linklist *linklist_init(int size)
{
    linklist *head = malloc(sizeof(*head));
    if (head == NULL)
        return NULL;
    //序号从1开始初始化单循环链表,每个人的密码从[1,3*n]中任意选取,其中n为游戏总人数
    head->serialNum = 1;
    head->password = rand_num(3 * size);
    head->next = head;
    linklist *cur = head;
    for (int i = 2; i <= size; i++)
    {
        linklist *temp = (linklist *)malloc(sizeof(linklist));
        temp->serialNum = i;
        temp->password = rand_num(3 * size);
        temp->next = head;  //虽然这一步没啥用,但是可以防止出现野指针
        cur->next = temp;
        cur = temp;
    }
    return head;
}

void linklist_destroy(linklist *list)
{
    linklist *cur = list->next;
    while (cur != list)
    {
        linklist *temp = cur;
        cur = cur->next;
        free(temp);         //遍历结点进行内存释放,以销毁链表
    }
    free(list);
}

int linklist_insert(linklist *list, int passwd)
{
    if (list == NULL)
        return -1;
    linklist *last = list->next;
    while (last != list)
        last = last->next;
    linklist *temp = (linklist *)malloc(sizeof(linklist));
    temp->password = passwd;
    temp->next = list;
    last->next = temp;
    return 0;
}

int linklist_delete(linklist *list)
{
    //由于是单循环链表,所以选择删除当前首元结点指向的下一结点比较方便快捷
    if (list == NULL)
        return -1;
    //注意判断只有一个结点时的情况
    if(list->next ==list)
    {
        printf("id:%d\tpasswd:%d\n", list->serialNum, list->password);
        printf("game over!\n");
        free(list);
        return 0;
    }
    linklist *temp = list->next;
    printf("id:%d\tpasswd:%d\n", temp->serialNum, temp->password);
    list->next = temp->next;
    free(temp);
    return 0;
}