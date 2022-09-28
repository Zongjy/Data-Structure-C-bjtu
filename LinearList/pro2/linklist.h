#ifndef LINKLIST_H__
#define LINKLIST_H__

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int serialNum;  // 序号(从1开始)
    int password;   // 密码(正整数)
    struct Node *next;  
}linklist;

// 随机数生成(范围为[1,maxn])
int rand_num(int maxn);

// 单循环链表的创建(初始化表长为size)
linklist* linklist_init(int size); 

// 单循环链表的销毁
// 本题不需要销毁,因为表全部删完了
void linklist_destroy(linklist *);

// 单循环链表的插入(头插)
// 本题不需要插入
int linklist_insert(linklist *,int);

// 单循环链表的删除(删除首元结点指向的下一结点)
// 本题删除到表为空时游戏结束
int linklist_delete(linklist *);

// 遍历打印单循环链表内容
// 本题也不需要,因为每次删除时就打印了
// void linklist_show(linklist *);

#endif