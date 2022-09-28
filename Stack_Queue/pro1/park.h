#ifndef PARK_H__
#define PARK_H__

#define PARK_SPACE 100
#define PRICE_PER_SECOND 1

#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

//每辆车的信息
typedef struct Car
{
    char plate_num[8]; //车牌号码
    time_t park_time;  //停车时间
} car;

//每个车位的信息
typedef struct Space
{
    car car_info;  //车位中停的车的信息
    int is_parked; //该车位是否有车(1:有车, 0:无车)
} space;

//停车场信息(固定车位100个)
typedef struct Lot
{
    space all_space[PARK_SPACE]; //所有车位
    int empty_space;             //剩余车位数
} lot;

//收费记录历史
typedef struct History_node
{
    car car_info;
    time_t leave_time;
    int price;
    struct  History_node *next;
} history;

//打印停车场信息
void lot_show(lot *);

//模拟车辆停入停车场
void car_come(lot *);

//模拟车辆驶出停车场并收费
void car_leave(lot *, history *);

//打印历史收费记录
void history_show(history *);

//销毁历史收费记录
void history_destroy(history *);

//按车牌号查找停车场中停放目标车的车位
int car_find(lot *, char *);

#endif