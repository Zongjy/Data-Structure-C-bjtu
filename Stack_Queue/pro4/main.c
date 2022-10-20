#include "bank.h"

int main()
{
    int serial = 0;
    int window[7];
    memset(window, 0, sizeof(window));
    queue gjj, yhk, lck;
    queue_init(&gjj);
    queue_init(&yhk);
    queue_init(&lck);
    int q = 0;
    // printf("%d", queue_isempty(&gjj));
    while (1)
    {
        printf("请输入操作序号:\n1. 客户办理业务;\n2. 客户办理完成;\n3. 查看柜台状态;\n4. 退出\n");
        scanf("%d", &q);
        if (q == 1)
        {
            serial++;
            entry_bank(&gjj, &yhk, &lck, serial, window);
        }
        else if (q == 2)
        {
            leave_bank(&gjj, &yhk, &lck, window);
        }
        else if (q == 3)
        {
            show_window(window);
        }
        else if (q == 4)
        {
            break;
        }
        else
        {
            printf("请输入正确的操作序号!\n");
        }
    }
    return 0;
}