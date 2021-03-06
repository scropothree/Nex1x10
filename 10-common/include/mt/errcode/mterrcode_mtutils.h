/**===========================================================================
 * @file    $Id$
 * @brief   负责终端公用函数组件错误码定义
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MTERRORCODE_MTUTILS_H_
#define _MTERRORCODE_MTUTILS_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief 错误码规则(10进制表示)
 *	 99                   99                    9             9999
 *	模块        +      子业务分类      +     错误等级    +   分配数量
 *(2位/100个)        （2位/100个）          （1位/10个）     (4位/10000个)
 */

/** mtutils错误码子模块ID定义, 新增子业务分类定义只能往后追加 */
enum EM_ERR_SUBMOD_UTILS
{
    emErrSubModUtils = 0,        ///< 终端错误码子模块
};


/** mtutils模块错误码定义 */
enum EmMtUtilsErrCode
{
	 ERR_MTUTILS_PATH_EXIST,    ///< 文件/文件夹不存在
	 ERR_MTUTILS_BUF_NOTENOUGH,	///< 缓冲区不够
	 ERR_MTUTILS_UNKOUWN_CHAR,	///< 未知字符  

	 ERR_MTUTILS_MALLOC_FAIL,   ///< malloc内存分配失败
	 ERR_MTUTILS_INVALID_IP,    ///< 非法IP地址
	 ERR_MTUTILS_FILE_NOT_EXIST, ///< 文件不存在

	 ERR_MTUTILS_INSTALL_EXCEPTION_FAIL, ///< 安装异常捕获失败
	 ERR_MTUTILS_INVALID_POINTER,        ///< 非法指针
	 ERR_MTUTILS_INVALID_PATH,           ///< 非法路径
	 ERR_MTUTILS_REG_EXPMODULE_FAIL,     ///< 模块注册失败
};


/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _MTERRORCODE_MTUTILS_H_