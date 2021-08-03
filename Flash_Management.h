/*
 * @Author: xph
 * @Date: 2021-08-04 00:41:49
 * @LastEditTime: 2021-08-04 00:46:41
 * @LastEditors: Please set LastEditors
 * @Description: 非易失性存储器管理
 * @FilePath: \Flash_Management\Flash_Management.h
 */
#ifndef __FLASH_MANAGEMENT_H
#define __FLASH_MANAGEMENT_H

/*模块A中有这样一个结构体需要非易失存储*/
typedef struct _t_paras
{
    int tmpA; /*语言种类*/
} T_PARAS;

/*模块B中有这样一个结构体需要非易失存储*/
typedef struct _t_pid
{
    int tmpB; /*语言种类*/
} T_PID;

typedef struct _t_nv_layout
{
    void *pElement; /*参数地址*/
    int length;     /*参数长度*/
} T_NV_LAYOUT;

/*参数映射表记录条数*/
#define NV_RECORD_NUMBER(nvList) (sizeof(nvList) / sizeof(T_NV_LAYOUT))
void nv_load(T_NV_LAYOUT *pLayout, int nvAddr, int number);  //加载内存数据
void nv_store(T_NV_LAYOUT *pLayout, int nvAddr, int number); //存储内存数据

#endif
