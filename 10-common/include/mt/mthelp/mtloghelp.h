/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   mtLogģ���������
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
 * 
 */
/*---------------------------------------------------------------------------*/

#ifndef _MTLOG_HELP_H_
#define _MTLOG_HELP_H_


#include "osp.h"



/** ***********************************************************
* 
* @brief    ʱ�������
* @note     Ĭ��ֻ��ʾʱ/��/��/���� 
*
* @param	[in] bOn  �Ƿ���
* @return	��
*
**************************************************************/
API void mtlogts(BOOL32 bOn);


/** ***********************************************************
* 
* @brief    ��ϸʱ����Ϣ��ӡ����
* @note     Ĭ�ϲ���ʾ������ �˿��ؿ��������յ���ʾ
*
* @param	[in] bOn  �Ƿ���
* @return	��
*
**************************************************************/
API void mtlogtsdetail(BOOL32 bOn);



/** ***********************************************************
* 
* @brief    �߳�id��ӡ����
*
* @param	[in] bOn  �Ƿ���
* @return	��
*
**************************************************************/
API void mtlogtid(BOOL32 bOn);



/** ***********************************************************
* 
* @brief    ͨ��ģ��ID����ָ��ģ�� Err | Warn | Hint �ȼ���־��ӡ
*
* @param	[in] emModule        ��־ģ��ID
* @return	��
* @note     emModuleΪ0��������ģ��
*
**************************************************************/
API void mtlogon(EmMtLogModule emModule);



/** ***********************************************************
* 
* @brief    ͨ��ģ��������ָ��ģ�� Err | Warn | Hint �ȼ���־��ӡ
*
* @param	[in] pchMouduleName        ��־ģ����
* @return	��
* @note     ģ����Ϊ�տ�������ģ��
*
**************************************************************/
API void mtlogonn(const s8 *pchMouduleName);


/** ***********************************************************
* 
* @brief    ͨ��ģ��ID����ָ��ģ�� debug | trace �ȼ���־��ӡ
*
* @param	[in] emModule ��־ģ��ID
* @return	��
* @note     ģ����Ϊ�տ�������ģ��
*
**************************************************************/
API void mtlogdbgon(EmMtLogModule emModule);



/** ***********************************************************
* 
* @brief    ͨ��ģ��������ָ��ģ�� debug | trace �ȼ���־��ӡ
*
* @param	[in] pchMouduleName ��־ģ����
* @return	��
* @note     ģ����Ϊ�տ�������ģ��
*
**************************************************************/
API void mtlogdbgonn(const s8 *pchMouduleName);



/** ***********************************************************
* 
* @brief    ͨ��ģ��ID�ر�ָ��ģ�� Err | Warn | Hint �ȼ���־��ӡ
*
* @param	[in] emModule        ��־ģ��ID
* @return	��
* @note     emModuleΪ0�ر�����ģ��
*
**************************************************************/
API void mtlogoff(EmMtLogModule emModule);



/** ***********************************************************
* 
* @brief    ͨ��ģ�����ر�ָ��ģ�� Err | Warn | Hint �ȼ���־��ӡ
*
* @param	[in] pchMouduleName        ��־ģ����
* @return	��
* @note     ģ����Ϊ�չر�����ģ��
*
**************************************************************/
API void mtlogoffn(const s8 *pchMouduleName);



/** ***********************************************************
* 
* @brief    ͨ��ģ��ID�ر�ָ��ģ�� debug | trace �ȼ���־��ӡ
*
* @param	[in] emModule ��־ģ��ID
* @return	��
* @note     ģ����Ϊ�չر�����ģ��
*
**************************************************************/
API void mtlogdbgoff(EmMtLogModule emModule);



/** ***********************************************************
* 
* @brief    ͨ��ģ�����ر�ָ��ģ�� debug | trace �ȼ���־��ӡ
*
* @param	[in] pchMouduleName ��־ģ����
* @return	��
* @note     ģ����Ϊ�չر�����ģ��
*
**************************************************************/
API void mtlogdbgoffn(s8 * pchModuleName);



/** ***********************************************************
* 
* @brief    ͨ��ģ��ID�����ض�ģ���ض��ȼ���ӡ
*
* @param	[in] pchMouduleName ��־ģ����
* @return	��
* @note     ģ��IDΪ�տ�������ģ��
*
**************************************************************/
API void mtloglvon(EmMtLogType emType, EmMtLogModule emModule);



/** ***********************************************************
* 
* @brief    ͨ��ģ��ID�ر��ض�ģ���ض��ȼ���ӡ
*
* @param	[in] pchMouduleName ��־ģ����
* @return	��
* @note     ģ��IDΪ�չر�����ģ��
*
**************************************************************/
API void mtloglvoff(EmMtLogType emType, EmMtLogModule emModule);



/** ***********************************************************
* 
* @brief    ��־������Ϣ
*
* @param	��
* @return	��
* @note     ��
*
**************************************************************/
API void mtloghelp();



/** ***********************************************************
* 
* @brief    ��־ģ��״̬��Ϣ
*
* @param	��
* @return	��
* @note     ��
*
**************************************************************/
API void mtlogshow();



#endif  //_MTLOG_HELP_H_