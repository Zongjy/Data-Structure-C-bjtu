#include"fibonacci.h"

int main()
{
    // 记录每项的值
    int record[200];
    int cnt = 0;
    sq_queue fibo;
    queue_init(&fibo);
    // a1, a2初始化为0
    for (int i = 0; i < MAXSIZE-1; i++)
    {
        queue_push(&fibo, 0);
        record[cnt] = 0;
        cnt++;
    }
    // a3为1
    queue_push(&fibo, 1);
    record[cnt] = 1;
    cnt++;
    // 滚动向后计算, 直到队首超过200
    while (queue_front(&fibo) <= 200)
    {
        int tmp = 0;
        for (int i = 0; i < MAXSIZE;i++)
            tmp += fibo.f[i];
        queue_push(&fibo, tmp);
        record[cnt] = tmp;
        cnt++;
    }
    // 打印记录的所有答案值
    for (int i = 0; i < cnt; i++)
    {
        printf("%d\n", record[i]);
    }
    return 0;
}