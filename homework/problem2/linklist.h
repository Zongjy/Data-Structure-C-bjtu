#ifndef LINKLIST_H__
#define LINKLIST_H__

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int password;   //密码
    struct Node *next;  
}linklist;              

//单循环链表的创建
void linklist_init(linklist **); 

//单循环链表的销毁
void linklist_destroy(linklist *);

//单循环链表的插入(在位于 pos 的结点后插入, pos 从 0 开始)
int linklist_insert(linklist *, int pos, int);

//单循环链表的删除(删除位于 pos 的结点)
int linklist_delete(linklist *, int pos);

//判断单循环链表是否为空
int linklist_is_empty(linklist *);

//遍历打印单循环链表内容
void linklist_show(linklist *);

#endif