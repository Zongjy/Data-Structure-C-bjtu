#include "staff.h"

int main()
{
    int n, err;
    staffList *list;
    list_init(&list);
    printf("请输入入职的员工个数:\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("请输入入职员工信息:\n");
        staff *worker;
        staff_create(&worker);
        err = list_insert(list, list->length + 1, worker);
        if (err == -1 || err == -2)
            exit(-1);
    }
    list_show(list);
    printf("请输入离职的员工个数:\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("请输入离职员工工号:\n");
        char tar[MAX_STR_LEN];
        scanf("%s", tar);
        fflush(stdin);
        err = list_delete(list, list_find_id(list, tar));
        if (err == -1 || err == -2)
            exit(-1);
    }
    list_show(list);
    return 0;
}