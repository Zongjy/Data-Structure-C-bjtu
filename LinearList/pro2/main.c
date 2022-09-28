#include<time.h>
#include"linklist.h"

int main()
{
    int n,err;
    printf("请输入参与游戏的人数:\n");
    scanf("%d", &n);
    srand((unsigned)time(NULL));
    linklist *head = linklist_init(n);
    if(head == NULL)
        exit(1);
    int cnt = rand_num(3 * n);
    while (head->next != head)
    {
        while(cnt>1)
        {
            head = head->next;
            cnt--;
        }
        //将要出列的人的密码作为下一次报数的上限值
        cnt = head->next->password;
        err = linklist_delete(head);
        if(err == -1)
            exit(1);
    }
    //最后一人出列
    err = linklist_delete(head);
    return 0;
}
