#ifndef STAFF_H__
#define STAFF_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEM_SIZE 40 //员工数量最大值
#define MAX_STR_LEN 50  //字符串长度最大值

typedef struct Staff
{
    char name[MAX_STR_LEN]; //员工姓名
    char id[MAX_STR_LEN];   //员工工号
    int job;                //员工职务
} staff;

typedef struct StaffList
{
    staff members[MAX_MEM_SIZE];
    int length; //表长
} staffList;

//初始化顺序表
void list_init(staffList **);

//在位于顺序表pos处的结点后插入新结点
int list_insert(staffList *, int pos, staff *);

//删除位于顺序表pos处的结点
int list_delete(staffList *, int pos);

//根据工号寻找员工位于顺序表的位置(从0开始计算)
int list_find_id(staffList *, char *);

//遍历打印顺序表的所有内容
void list_show(staffList *);

//顺序表的销毁
int list_destroy(staffList *);

//结点(员工结构体)的创建
void staff_create(staff **);

#endif