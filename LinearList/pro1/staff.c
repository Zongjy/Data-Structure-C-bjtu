#include "staff.h"

void list_init(staffList **me)
{
    //注意传入二级指针进行分配内存,这里用**me和用staffList都可以
    (*me) = malloc(sizeof(**me));
    if (*me == NULL)
        return;
    //长度为-1表示空表(表的第一位为0)
    (*me)->length = -1;
    return;
}

int list_insert(staffList *me, int pos, staff *data)
{
    //超过静态顺序表的存储内存
    if (me->length == MAX_MEM_SIZE - 1)
        return -1;
    //插入位置为负数或者超过当前表长
    if (pos < 0 || pos > me->length + 1)
        return -2;
    //将pos后的结点向后移位
    for (int i = me->length; i >= pos; i--)
    {
        me->members[i + 1] = me->members[i];
    }
    //在pos处插入数据
    me->members[pos] = *data;
    me->length++;
    return 0;
}

int list_delete(staffList *me, int pos)
{
    //表为空时无法删除
    if (me->length < 0)
        return -1;
    //删除位置为负或者删除位置超过当前表长
    if (pos < 0 || pos > me->length)
        return -2;
    //将pos后的结点向前移位(直接赋值进行覆盖)
    for (int i = pos; i < me->length; i++)
    {
        me->members[i] = me->members[i + 1];
    }
    me->length--;
    return 0;
}

int list_find_id(staffList *me, char *target)
{
    if (me->length < 0)
        return -1;
    for (int i = 0; i <= me->length; i++)
    {
        //两字符串相等时返回0,返回当前结点下标
        if (strcmp(me->members[i].id, target) == 0)
            return i;
    }
    return -2;
}

void list_show(staffList *me)
{
    printf("现有职员如下:\n");
    if (me->length < 0)
        return;
    for (int i = 0; i <= me->length; i++)
    {
        printf("员工姓名: %s\n员工工号: %s\n员工职务: %d\n\n",
               me->members[i].name, me->members[i].id, me->members[i].job);
    }
    return;
}

int list_destroy(staffList *me)
{
    //malloc必free
    free(me);
    return 0;
}

void staff_create(staff **data)
{
    (*data) = malloc(sizeof(**data));
    if (*data == NULL)
        return;
    printf("\t员工姓名: ");
    scanf("%s", (*data)->name);
    fflush(stdin);
    printf("\n\t员工工号: ");
    scanf("%s", (*data)->id);
    fflush(stdin);
    printf("\n\t员工职务: ");
    scanf("%d", &(*data)->job);
    fflush(stdin);
    return;
}