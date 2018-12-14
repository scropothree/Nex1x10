/*=============================================================================
ģ   ��   ��: touch
��   ��   ��: Language.h
�� ��  �� ��: ��
�ļ�ʵ�ֹ���: ˫��
��        ��: --
��        ��: --
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���              �޸�����
--
=============================================================================*/

#ifndef __LANGUAGE_HEADER_
#define __LANGUAGE_HEADER_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

extern EMLangID g_emLanType; //��������

#define TRANSLATE(text)     \
     CString( g_emLanType == enumLangIdCHN ? text##CHN : text##ENG )

    #define NET_STATUS_CONNECTING_CHN               "����������ʾ��"
    #define NET_STATUS_CONNECTING_ENG               "Connecting"
#define STRING_NET_STATUS_CONNECTING                TRANSLATE(NET_STATUS_CONNECTING_)

    #define NET_STATUS_CONNECTED_CHN                "��������ʾ��"
    #define NET_STATUS_CONNECTED_ENG                "Connected"
#define STRING_NET_STATUS_CONNECTED                 TRANSLATE(NET_STATUS_CONNECTED_)
    #define DES_NET_STATUS_CONNECTED_CHN            "��ѹ����Ͷ����������ʼͶ�����ٴΰ�ѹ����Ͷ��"
    #define DES_NET_STATUS_CONNECTED_ENG            "Press NT30 for Projecting��Press Again to Stop"
#define STRING_DES_NET_STATUS_CONNECTED             TRANSLATE(DES_NET_STATUS_CONNECTED_)

    #define NET_STATUS_DISCONNECTED_CHN             "�����ѶϿ�"
    #define NET_STATUS_DISCONNECTED_ENG             "Disconnected"
#define STRING_NET_STATUS_DISCONNECTED              TRANSLATE(NET_STATUS_DISCONNECTED_)
    #define DES_NET_STATUS_DISCONNECTED_CHN         "�뽫����Ͷ����������������ʾ��USB1��USB2�ӿڣ��������"
    #define DES_NET_STATUS_DISCONNECTED_ENG         "Please Plug NT30 to USB1/USB2 on the Display for Pairing"
#define STRING_DES_NET_STATUS_DISCONNECTED          TRANSLATE(DES_NET_STATUS_DISCONNECTED_)

    #define NET_STATUS_NO_NETWORK_CHN               "���������ȵ�"
    #define NET_STATUS_NO_NETWORK_ENG               "No Hotspot"
#define STRING_NET_STATUS_NO_NETWORK                TRANSLATE(NET_STATUS_NO_NETWORK_)
    #define DES_NET_STATUS_NO_NETWORK_CHN           "������������"
    #define DES_NET_STATUS_NO_NETWORK_ENG           "Please Check the Network"
#define STRING_DES_NET_STATUS_NO_NETWORK            TRANSLATE(DES_NET_STATUS_NO_NETWORK_)

    #define NET_STATUS_NO_MATCH_CHN                 "δ����ʾ�����"
    #define NET_STATUS_NO_MATCH_ENG                 "Nonpaired"
#define STRING_NET_STATUS_NO_MATCH                  TRANSLATE(NET_STATUS_NO_MATCH_)
    #define DES_NET_STATUS_NO_MATCH_CHN             "�뽫����Ͷ����������������ʾ��USB1����USB2�ӿڣ�������"
    #define DES_NET_STATUS_NO_MATCH_ENG             "Please Plug NT30 to USB1/USB2 on the Display for Pairing"
#define STRING_DES_NET_STATUS_NO_MATCH              TRANSLATE(DES_NET_STATUS_NO_MATCH_)

    #define NET_STATUS_ENOUGHNUM_CHN                "������������"
    #define NET_STATUS_ENOUGHNUM_ENG                "Connection Quantity Limited"
#define STRING_NET_STATUS_ENOUGHNUM                 TRANSLATE(NET_STATUS_ENOUGHNUM_)
    #define DES_NET_STATUS_ENOUGHNUM_CHN            "��ʾ�����֧������8������Ͷ��������"
    #define DES_NET_STATUS_ENOUGHNUM_ENG            "Maxmium Quantity is 8"
#define STRING_DES_NET_STATUS_ENOUGHNUM             TRANSLATE(DES_NET_STATUS_ENOUGHNUM_)

    #define NET_STATUS_RESETQUICKSHARE_CHN          "�޷�������ʾ��"
    #define NET_STATUS_RESETQUICKSHARE_ENG          "Cannot connect to the display"
#define STRING_NET_STATUS_RESETQUICKSHARE           TRANSLATE(NET_STATUS_RESETQUICKSHARE_)
    #define DES_NET_STATUS_RESETQUICKSHARE_CHN      "��ε�����Ͷ�������������½������"
    #define DES_NET_STATUS_RESETQUICKSHARE_ENG      "Please Remove NT30 and Replug it to your PC"
#define STRING_DES_NET_STATUS_RESETQUICKSHARE       TRANSLATE(DES_NET_STATUS_RESETQUICKSHARE_)

    #define NET_STATUS_RESETWIFI_CHN                "�����ѶϿ�"
    #define NET_STATUS_RESETWIFI_ENG                "Disconnected"
#define STRING_NET_STATUS_RESETWIFI                 TRANSLATE(NET_STATUS_RESETWIFI_)
    #define DES_NET_STATUS_RESETWIFI_CHN            "���������У����Ժ�..."
    #define DES_NET_STATUS_RESETWIFI_ENG            "Reconnecting to the Network..."
#define STRING_DES_NET_STATUS_RESETWIFI             TRANSLATE(DES_NET_STATUS_RESETWIFI_)

    #define SHOW_UPGRADE_CHN                        "�����°汾"
    #define SHOW_UPGRADE_ENG                        "New Version Released"
#define STRING_SHOW_UPGRADE                         TRANSLATE(SHOW_UPGRADE_)

    #define SHOW_UPGRADE_TIP1_CHN                   "�뽫����Ͷ����������������ʾ�˵�"
    #define SHOW_UPGRADE_TIP1_ENG                   "Please Plug NT30 to USB1/USB2"
#define STRING_SHOW_UPGRADE_TIP1                    TRANSLATE(SHOW_UPGRADE_TIP1_)

    #define SHOW_UPGRADE_TIP2_CHN                   "USB1��USB2�ӿڽ�������"
    #define SHOW_UPGRADE_TIP2_ENG                   "on the Display for Upgrading"
#define STRING_SHOW_UPGRADE_TIP2                    TRANSLATE(SHOW_UPGRADE_TIP2_)

    #define SHOW_LINK_IGNORE_CHN                    "<a href=\"�ݲ�����,����Ͷ��\">�ݲ�����,����Ͷ��</a>"
    #define SHOW_LINK_IGNORE_ENG                    "<a href=\"Optional: Decide later\">Optional: Decide later</a>"
#define STRING_SHOW_LINK_IGNORE                     TRANSLATE(SHOW_LINK_IGNORE_)

    #define CONNECT_BUSINESS_FAIL_CHN               "������ҵ������쳣"
    #define CONNECT_BUSINESS_FAIL_ENG               "������ҵ������쳣"
#define STRING_CONNECT_BUSINESS_FAIL                TRANSLATE(CONNECT_BUSINESS_FAIL_)
    #define DES_CONNECT_BUSINESS_FAIL_CHN           "��ε�����Ͷ�������������½������"
    #define DES_CONNECT_BUSINESS_FAIL_ENG           "Please Remove NT30 and Replug it to your PC"
#define STRING_DES_CONNECT_BUSINESS_FAIL            TRANSLATE(DES_CONNECT_BUSINESS_FAIL_)

    #define PROJECTING_CHN                          " ����Ͷ��"
    #define PROJECTING_ENG                          " Projecting"
#define STRING_PROJECTING                           TRANSLATE(PROJECTING_)

    #define STOP_PROJECTING_CHN                     "ֹͣͶ��"
    #define STOP_PROJECTING_ENG                     "Stop"
#define STRING_STOP_PROJECTING                      TRANSLATE(STOP_PROJECTING_)

#endif//__LANGUAGE_HEADER_