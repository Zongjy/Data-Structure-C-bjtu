#include "park.h"

void lot_show(lot *pParkLot)
{
    if(pParkLot->empty_space == PARK_SPACE)
    {
        printf("停车场为空!\n");
        return;
    }
    printf("停车场信息如下:\n");
    for (int i = 0; i < PARK_SPACE; i++)
    {
        if (pParkLot->all_space[i].is_parked == 1)
        {
            printf("  车牌号码: %s\n  停入时间: %ld\n", pParkLot->all_space[i].car_info.plate_num,
                   pParkLot->all_space[i].car_info.park_time);
        }
    }
}

void history_show(history *head)
{
    history *cur = head;    //历史收费记录是一个含头结点的单向链表
    if (cur->next ==NULL)
    {
        printf("收费历史记录为空!\n");
        return;
    }
    int serial = 0;         //历史收费记录的序号
    while (cur->next != NULL)
    {
        cur = cur->next;
        serial++;
        printf("收费历史记录:\n  序号: %d\n  车牌号码: %s\n  收费: %d元\n",
               serial, cur->car_info.plate_num, cur->price);
    }
}

int car_find(lot *pParkLot, char *dest_car)
{
    for (int i = 0; i < PARK_SPACE; i++)
    {
        if (pParkLot->all_space[i].is_parked == 1 && strcmp(pParkLot->all_space[i].car_info.plate_num, dest_car) == 0)
            return i;       //找到返回车位序号(0~99)
    }
    return -1;              //没找到则返回-1
}

void car_come(lot *pParkLot)
{
    if (pParkLot->empty_space == 0)
    {
        printf("车位已满!\n");
        return;
    }
    printf("请输入停入车辆信息:\n请输入7位车牌号: ");
    char target[8];
    scanf("%s", target);
    if (car_find(pParkLot,target)!=-1)
    {
        printf("该车已停入, 请重新选择!\n");
        return;
    }
    for (int i = 0; i < PARK_SPACE; i++)
    {
        if (pParkLot->all_space[i].is_parked == 0)
        {
            strcpy(pParkLot->all_space[i].car_info.plate_num,target);
            pParkLot->all_space[i].is_parked = 1;
            pParkLot->empty_space--;
            pParkLot->all_space[i].car_info.park_time = time(NULL);
            printf("%s 已于 %ld 停入停车场!\n", pParkLot->all_space[i].car_info.plate_num,
                   pParkLot->all_space[i].car_info.park_time);
            return;
        }
    }
}

void car_leave(lot *pParkLot, history *head)
{
    if (pParkLot->empty_space == PARK_SPACE)
    {
        printf("停车场为空!\n");
        return;
    }
    char target[8];
    printf("请输入驶出车辆信息:\n请输入7位车牌号: ");
    scanf("%s", target);
    int pos = car_find(pParkLot, target);
    if(pos == -1)
    {
        printf("未找到该车!\n");
        return;
    }
    pParkLot->all_space[pos].is_parked = 0;
    pParkLot->empty_space++;
    //记录当前驶出停车场时间
    time_t now = time(NULL);
    //计算停车费
    int fee = (now - pParkLot->all_space[pos].car_info.park_time) * PRICE_PER_SECOND;
    //寻找收费历史记录末尾
    history *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = (history *)malloc(sizeof(history));
    cur = cur->next;
    strcpy(cur->car_info.plate_num, pParkLot->all_space[pos].car_info.plate_num);
    cur->car_info.park_time = pParkLot->all_space[pos].car_info.park_time;
    cur->next = NULL;
    cur->leave_time = now;
    cur->price = fee;
    printf("%s 已于 %ld 驶出停车场, 收费%d元\n", cur->car_info.plate_num,
            now, cur->price);
    return;
}

void history_destroy(history* head)
{
    history *cur = head->next;
    while (cur!=NULL)
    {
        history *temp = head;
        head = cur;
        cur = cur->next;
        free(temp);
    }
}