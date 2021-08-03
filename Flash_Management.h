/*
 * @Author: xph
 * @Date: 2021-08-04 00:41:49
 * @LastEditTime: 2021-08-04 00:46:41
 * @LastEditors: Please set LastEditors
 * @Description: ����ʧ�Դ洢������
 * @FilePath: \Flash_Management\Flash_Management.h
 */
#ifndef __FLASH_MANAGEMENT_H
#define __FLASH_MANAGEMENT_H

/*ģ��A��������һ���ṹ����Ҫ����ʧ�洢*/
typedef struct _t_paras
{
    int tmpA; /*��������*/
} T_PARAS;

/*ģ��B��������һ���ṹ����Ҫ����ʧ�洢*/
typedef struct _t_pid
{
    int tmpB; /*��������*/
} T_PID;

typedef struct _t_nv_layout
{
    void *pElement; /*������ַ*/
    int length;     /*��������*/
} T_NV_LAYOUT;

/*����ӳ����¼����*/
#define NV_RECORD_NUMBER(nvList) (sizeof(nvList) / sizeof(T_NV_LAYOUT))
void nv_load(T_NV_LAYOUT *pLayout, int nvAddr, int number);  //�����ڴ�����
void nv_store(T_NV_LAYOUT *pLayout, int nvAddr, int number); //�洢�ڴ�����

#endif
