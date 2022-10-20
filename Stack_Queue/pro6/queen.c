#include "queen.h"

void queen_init(queen *qarr)
{
    if (qarr == NULL)
        return;
    qarr->top = 0;
    for (int i = 0; i < N; i++)
    {
        qarr->data[i] = 0;
    }
}

void queen_push(queen *qarr, int serial)
{
    if (qarr == NULL)
        return;
    if (queen_full(qarr) == 1)
        return;
    qarr->data[qarr->top] = serial;
    qarr->top++;
}

void queen_pop(queen *qarr)
{
    if (qarr == NULL)
        return;
    if (queen_empty(qarr) == 1)
        return;
    qarr->top--;
}

int queen_full(queen *qarr)
{
    if (qarr == NULL)
        return -1;
    if (qarr->top == N)
        return 1;
    return 0;
}

int queen_empty(queen *qarr)
{
    if (qarr == NULL)
        return -1;
    if (qarr->top == 0)
        return 1;
    return 0;
}

int queen_judge(queen *qarr)
{
    if (qarr == NULL)
        return -1;
    // 如果 flag == 1说明该放置方案可行, flag == 0 则不满足条件
    int flag = 1;
    int row = qarr->top;
    int col = qarr->data[row-1];
    for (int i = 1; i < row; i++)
    {
        // 条件: 不能位于同一列 and 不能位于同一对角线
        if (qarr->data[i-1] == col || abs(qarr->data[i-1] - col) == row - i)
            flag = 0;
    }
    return flag;
}