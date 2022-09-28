#include "park.h"

void menu(lot *pParkLot, history *head)
{
    printf("请选择执行的操作(输入数字序号即可):\n");
    while (1)
    {
        printf("\n1.停入车辆 2.驶出车辆 3.查看停车场信息 4.查看收费信息 5.退出模拟\n");
        int sel;
        scanf("%d", &sel);
        switch (sel)
        {
        case 1:
            car_come(pParkLot);
            break;
        case 2:
            car_leave(pParkLot,head);
            break;
        case 3:
            lot_show(pParkLot);
            break;
        case 4:
            history_show(head);
            break;
        case 5:
            history_destroy(head);
            return;
        default:
            break;
        }
    }
}

int main()
{
    lot parkLot;
    parkLot.empty_space = PARK_SPACE;
    for (int i = 0; i < PARK_SPACE; i++)
    {
        parkLot.all_space[i].is_parked = 0;
    }
    history *head = (history *)malloc(sizeof(history));
    head->price = -1;
    head->next = NULL;
    menu(&parkLot, head);
    return 0;
}