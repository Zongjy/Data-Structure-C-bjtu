#include "queen.h"
#define M 100
int cnt = 0;

void show(queen *arr)
{
    printf("第 %d 组:", cnt);
    for (int i = 0; i < N; i++)
    {
        printf(" %d", arr->data[i]);
    }
    printf("\n");
}

void place(queen *arr, int row)
{
    // 已放满8行, 答案种类加1并输出
    if (row > N)
    {
        cnt++;
        show(arr);
        return;// unnecessary
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            // 该行每列都试一次
            queen_push(arr, i);
            // 如果符合条件则放置下一行
            if (queen_judge(arr) == 1)
                place(arr, row + 1);
            // 移走这一次的尝试
            queen_pop(arr);
        }
    }
    return;
}

int main()
{
    queen ans;
    queen_init(&ans);
    // 从第一行开始放
    place(&ans, 1);
    return 0;
}