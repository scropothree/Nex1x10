#if !defined(_NVVODHELP_H_)
#define _NVVODHELP_H_
#include "osp.h"


/**----------------------------------------------------------------------
* GetVodVer
* 
* @brief   ��ȡ�汾��Ϣ
* 
* @return  s8*
* @see     
------------------------------------------------------------------------*/
extern s8* GetVodVer();

/**----------------------------------------------------------------------
* nvvodregcmd
* 
* @brief   ע��osp��������
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
extern void nvvodregcmd();

/**----------------------------------------------------------------------
* nvvodhelp
* 
* @brief   vodģ���������
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvvodhelp();
/**----------------------------------------------------------------------
* nvvodver
* 
* @brief   vod�汾����ʾ
* 
* @param   void
* @return  void
* @see     
------------------------------------------------------------------------*/
API void nvvodver();

#endif // _NVVODHELP_H_