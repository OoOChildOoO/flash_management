/*
 * @Author: xph
 * @Date: 2021-08-04 00:02:34
 * @LastEditTime: 2021-08-09 23:25:40
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

#if ENABLE_NV_LAYOUT
/**
 * @description: 
 * @param {NV_LAYOUT_t} *pLayout 存储信息
 * @param {unsigned int} number 存储信息块数量
 * @return {*}
 */
void nv_load(NV_LAYOUT_t *pLayout, unsigned int number)
{
    unsigned int i;
    for (i = 0; i < number; i++)
    {
        switch (pLayout[i].memSel)
        {
        case FLASH_IN:
        case FLASH_NOR:
        case EEPROM:
        case FLASH_OFF:
            printf("memery select = %d\n", pLayout[i].memSel);
            printf("load addr = %d\n", pLayout[i].addr);
            printf("load length = %d\n", pLayout[i].length);
            printf("load data = %X\n", *(unsigned int *)pLayout[i].pElement);

            break;

        default:
            break;
        }
    }
    printf("\n");
}

/**
 * @description: 
 * @param {NV_LAYOUT_t} *pLayout 读取信息
 * @param {unsigned int} number 读取信息块数量
 * @return {*}
 */
void nv_store(NV_LAYOUT_t *pLayout, unsigned int number)
{
    unsigned int i;
    for (i = 0; i < number; i++)
    {
        switch (pLayout[i].memSel)
        {
        case FLASH_IN:
        case FLASH_NOR:
        case EEPROM:
        case FLASH_OFF:
            printf("memery select = %d\n", pLayout[i].memSel);
            printf("store addr = %d\n", pLayout[i].addr);
            printf("store length = %d\n", pLayout[i].length);
            printf("store data = %X\n", *(unsigned int *)pLayout[i].pElement);

            break;

        default:
            break;
        }
    }
    printf("\n");
}
#else
/**
 * @description: 加载数据
 * @param {void} *pElement 数据源地址
 * @param {NV_MEN_t} memSel 存储器选择 
 * @param {unsigned int} addr 目标存储地址
 * @param {unsigned int} length 数据长度
 * @return {*}
 */
void nv_load(void *pElement, NV_MEN_t memSel, unsigned int addr, unsigned int length)
{
    switch (memSel)
    {
    case FLASH_IN:
    case FLASH_NOR:
    case EEPROM:
    case FLASH_OFF:
        printf("memery select = %d\n", memSel);
        printf("load addr = %d\n", addr);
        printf("load length = %d\n", length);
        printf("load data = %X\n", *(unsigned int *)pElement);

        break;

    default:
        break;
    }
}
/**
 * @description: 存储数据
 * @param {void} *pElement 数据源地址
 * @param {NV_MEN_t} memSel 存储器选择 
 * @param {unsigned int} addr 目标存储地址
 * @param {unsigned int} length 数据长度
 * @return {*}
 */
void nv_store(void *pElement, NV_MEN_t memSel, unsigned int addr, unsigned int length)
{
    switch (memSel)
    {
    case FLASH_IN:
    case FLASH_NOR:
    case EEPROM:
    case FLASH_OFF:
        printf("memery select = %d\n", memSel);
        printf("store addr = %d\n", addr);
        printf("store length = %d\n", length);
        printf("store data = %X\n", *(unsigned int *)pElement);

        break;

    default:
        break;
    }
}
#endif

#if ENABLE_NV_LAYOUT
/*模块A中有这样一个结构体需要非易失存储*/
typedef struct
{
    int tmpA; /*语言种类*/
} PARAS_t;

/*模块B中有这样一个结构体需要非易失存储*/
typedef struct
{
    int tmpB; /*语言种类*/
} PID_t;

int main()
{
    PARAS_t sysParas = {
        .tmpA = 3};
    PID_t pidParas = {
        .tmpB = 4};
    unsigned int lengthA = 0;
    unsigned int lengthB = 0;
    /*参数映射表*/
    NV_LAYOUT_t nvLayout[] = {
        [0] = {&sysParas, EEPROM, 1, sizeof(PARAS_t)}, /*参数映射记录*/
        [1] = {&pidParas, FLASH_IN, 1, sizeof(PID_t)}};

    getch();
    lengthA = NV_RECORD_NUMBER(nvLayout);
    lengthB = NV_RECORD_NUMBER(nvLayout);
    nv_load(nvLayout, lengthA);
    nv_store(nvLayout, lengthB);

    getch();
    return 0;
}
#else
/*模块A中有这样一个结构体需要非易失存储*/
typedef struct
{
    int tmpA; /*语言种类*/
} PARAS_t;

/*模块B中有这样一个结构体需要非易失存储*/
typedef struct
{
    int tmpB; /*语言种类*/
} PID_t;

int main()
{
    PARAS_t sysParas = {
        .tmpA = 5};
    PID_t pidParas = {
        .tmpB = 6};

    nv_load(&sysParas, EEPROM, 0x55, sizeof(sysParas));
    nv_load(&pidParas, FLASH_IN, 0xAA, sizeof(pidParas));
    nv_store(&sysParas, EEPROM, 0x55, sizeof(sysParas));
    nv_store(&pidParas, FLASH_IN, 0xAA, sizeof(pidParas));

    getch();
    return 0;
}
#endif