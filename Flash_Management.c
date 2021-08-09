/*
 * @Author: xph
 * @Date: 2021-08-04 00:02:34
 * @LastEditTime: 2021-08-09 22:52:14
 * @LastEditors: Please set LastEditors
 * @Description: ����ʧ�Դ洢������
 * @FilePath: \Flash_Management\Flash_Management.c
 */

/* standard lib */
#include <stdio.h>  // printf #include <stdbool.h> // bool for _Bool and true for 1
#include <conio.h>  // for clrscr, and getch()
#include "stdlib.h" // for rand()
#include "math.h"
#include "Flash_Management.h"

/**
 * @description: 
 * @param {NV_LAYOUT_t} *pLayout �洢��Ϣ
 * @param {unsigned int} number �洢��Ϣ������
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
 * @param {NV_LAYOUT_t} *pLayout ��ȡ��Ϣ
 * @param {unsigned int} number ��ȡ��Ϣ������
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

/*ģ��A��������һ���ṹ����Ҫ����ʧ�洢*/
typedef struct
{
    int tmpA; /*��������*/
} PARAS_t;

/*ģ��B��������һ���ṹ����Ҫ����ʧ�洢*/
typedef struct
{
    int tmpB; /*��������*/
} PID_t;

int main()
{
    PARAS_t sysParas = {
        .tmpA = 3};
    PID_t pidParas = {
        .tmpB = 4};
    unsigned int lengthA = 0;
    unsigned int lengthB = 0;
    /*����ӳ���*/
    NV_LAYOUT_t nvLayout[] = {
        [0] = {&sysParas, EEPROM, 1, sizeof(PARAS_t)}, /*����ӳ���¼*/
        [1] = {&pidParas, FLASH_IN, 1, sizeof(PID_t)}};

    getch();
    lengthA = NV_RECORD_NUMBER(nvLayout);
    lengthB = NV_RECORD_NUMBER(nvLayout);
    nv_load(nvLayout, lengthA);
    nv_store(nvLayout, lengthB);

    getch();
    return 0;
}