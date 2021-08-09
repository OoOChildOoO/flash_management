/*
 * @Author: xph
 * @Date: 2021-08-04 00:41:49
 * @LastEditTime: 2021-08-09 23:24:56
 * @LastEditors: Please set LastEditors
 * @Description: ����ʧ�Դ洢������
 * @FilePath: \Flash_Management\Flash_Management.h
 */
#ifndef __FLASH_MANAGEMENT_H
#define __FLASH_MANAGEMENT_H
#define ENABLE_NV_LAYOUT 0

typedef enum
{
    FLASH_IN = 0,
    FLASH_NOR,
    EEPROM,
    FLASH_OFF,
} NV_MEN_t;

#if ENABLE_NV_LAYOUT
typedef struct
{
    void *pElement;      /*�������ݵ�ַ*/
    NV_MEN_t memSel;     /*�洢��ѡ��*/
    unsigned int addr;   /*�����洢Ŀ���ַ*/
    unsigned int length; /*�������ݳ���*/
} NV_LAYOUT_t;

/*����ӳ����¼����*/
#define NV_RECORD_NUMBER(nvList) (sizeof(nvList) / sizeof(NV_LAYOUT_t))
void nv_load(NV_LAYOUT_t *pLayout, unsigned int number);  //�����ڴ�����
void nv_store(NV_LAYOUT_t *pLayout, unsigned int number); //�洢�ڴ�����
#else

void nv_load(void *pElement, NV_MEN_t memSel, unsigned int addr, unsigned int length);
void nv_store(void *pElement, NV_MEN_t memSel, unsigned int addr, unsigned int length);
#endif

#endif
