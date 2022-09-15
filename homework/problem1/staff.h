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

void list_init(staffList **);

int list_insert(staffList *, int pos, staff *);

int list_delete(staffList *, int pos);

int list_find_id(staffList *, char *);

void list_show(staffList *);

int list_destroy(staffList *);

void staff_create(staff **);

#endif