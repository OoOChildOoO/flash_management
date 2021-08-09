/*
 * @Author: xph
 * @Date: 2021-08-04 00:41:49
 * @LastEditTime: 2021-08-09 22:52:17
 * @LastEditors: Please set LastEditors
 * @Description: 非易失性存储器管理
 * @FilePath: \Flash_Management\Flash_Management.h
 */
#ifndef __FLASH_MANAGEMENT_H
#define __FLASH_MANAGEMENT_H

typedef enum
{
    FLASH_IN = 0,
    FLASH_NOR,
    EEPROM,
    FLASH_OFF,
} NV_MEN_t;

typedef struct
{
    void *pElement;      /*参数数据地址*/
    NV_MEN_t memSel;     /*存储器选择*/
    unsigned int addr;   /*参数存储目标地址*/
    unsigned int length; /*参数数据长度*/
} NV_LAYOUT_t;

/*参数映射表记录条数*/
#define NV_RECORD_NUMBER(nvList) (sizeof(nvList) / sizeof(NV_LAYOUT_t))
void nv_load(NV_LAYOUT_t *pLayout, unsigned int number);  //加载内存数据
void nv_store(NV_LAYOUT_t *pLayout, unsigned int number); //存储内存数据

#endif
