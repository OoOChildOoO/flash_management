/*
 * @Author: xph
 * @Date: 2021-08-04 00:02:34
 * @LastEditTime: 2021-08-04 00:47:34
 * @LastEditors: Please set LastEditors
 * @Description: 非易失性存储器管理
 * @FilePath: \Flash_Management\Flash_Management.c
 */

/* standard lib */
#include <stdio.h>  // printf #include <stdbool.h> // bool for _Bool and true for 1
#include <conio.h>  // for clrscr, and getch()
#include "stdlib.h" // for rand()
#include "math.h"
#include "Flash_Management.h"

void nv_load(T_NV_LAYOUT *pLayout, int nvAddr, int number)
{
    int i;
    for (i = 0, nvAddr = 0; i < number; ++i, ++nvAddr)
    {
        if (nvAddr)
        {
        }
        printf("data = %X\n", *(unsigned int *)pLayout[i].pElement);
    }
}

void nv_store(T_NV_LAYOUT *pLayout, int nvAddr, int number)
{
    int i;
    for (i = 0, nvAddr = 0; i < number; ++i, ++nvAddr)
    {
        if (nvAddr)
        {
        }
        printf("data2 = %X\n", *(unsigned int *)pLayout[i].pElement);
    }
}

int main()
{
    T_PARAS sysParas = {
        .tmpA = 1};
    T_PID pidParas = {
        .tmpB = 2};
    int lengthA = 0;
    int lengthB = 0;
    /*参数映射表*/
    T_NV_LAYOUT nvLayout[] = {
        [0] = {&sysParas, sizeof(T_PARAS)}, /*参数映射记录*/
        [1] = {&pidParas, sizeof(T_PID)}};

    getch();
    lengthA = NV_RECORD_NUMBER(nvLayout);
    lengthB = NV_RECORD_NUMBER(nvLayout);
    nv_load(nvLayout, 1, lengthA);
    nv_store(nvLayout, 1, lengthB);

    getch();
    return 0;
}