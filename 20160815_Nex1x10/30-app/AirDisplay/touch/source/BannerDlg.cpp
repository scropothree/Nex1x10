// MainDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "touch.h"
#include "BannerDlg.h"
#include "afxdialogex.h"
#include "touchDlg.h"
#include "language.h"

extern CtouchDlg * g_dlg;
// CBannerDlg 对话框

#define CM_ELAPSE   200 //检测鼠标是否离开窗口的时间间隔
#define HS_ELAPSE   5   //隐藏或显示过程每步的时间间隔
#define HS_STEPS    10  //隐藏或显示过程分成多少步

#define INTERVAL    20  //触发粘附时鼠标与屏幕边界的最小间隔,单位为象素
#define INFALTE     10  //触发收缩时鼠标与窗口边界的最小间隔,单位为象素
#define MINCX       200 //窗口最小宽度
#define MINCY       400 //窗口最小高度

//TimerId
#define HideTimerId 3
#define ShowTimerId 4
#define StatusBarTimerId 5

static bool LoadImageFromResource(IN CImage* pImage,
    IN INT nResID = 196, IN LPCWSTR lpTyp = L"RCPNG" )
{
    if ( pImage == NULL )
    {
        return false;
    }
    pImage->Destroy();

    //查找资源
    HRSRC hResource = FindResource(AfxGetResourceHandle(), MAKEINTRESOURCE(196), L"PNG");
    if ( hResource == NULL )
    {
        int res = GetLastError();
        PRINTMSG("FindResource Err:%d\r\n", res);
        return FALSE;
    }

    //加载资源
    HGLOBAL hImgData = ::LoadResource(AfxGetResourceHandle(), hResource);
    if ( hImgData == NULL )
    {
        int res = GetLastError();
        PRINTMSG("LoadResource Err:%d\r\n", res);
        ::FreeResource(hImgData);
        return false;
    }

    //锁定内存中的指定资源
    LPVOID lpVoid = ::LockResource(hImgData);

    LPSTREAM pStream = NULL;
    DWORD dwSize = ::SizeofResource(AfxGetResourceHandle(), hResource);
    HGLOBAL hNew = ::GlobalAlloc(GHND, dwSize);
    LPBYTE lpByte = (LPBYTE)::GlobalLock(hNew);
    ::memcpy(lpByte, lpVoid, dwSize);

    //解除内存中的指定资源
    ::GlobalUnlock(hNew);

    //从指定内存创建流对象
    HRESULT ht = ::CreateStreamOnHGlobal(hNew, TRUE, &pStream);
    if (ht = S_OK)
    {
        GlobalFree(hNew);
    }
    else
    {
        //加载图片
        pImage->Load(pStream);
        GlobalFree(hNew);
    }

    //释放资源
    ::FreeResource(hImgData);
    return true;
}

CBannerDlg::CBannerDlg(CWnd* pParent /*=NULL*/)
	: CBaseDlg(CBannerDlg::IDD, pParent)
{
	m_dwBkResourceID = IDB_BANNER_BK;
	//m_btnBannerClose.SetImage( IDB_BANNER_STOP, IDB_BANNER_STOP, IDB_BANNER_STOP, IDB_BANNER_STOP);
	
	m_staticBanner.SetFont(9, g_achDefaultFont);
	m_staticBanner.SetTextColor(Color(0,0,0));
	m_staticBanner.SetTextAlign(CTransparentStatic::emAlignmentCenter);
	m_staticBanner.SetOverShow(true, StringTrimmingEllipsisPath);

	/*m_btnBannerClose.SetFont(9, g_achDefaultFont);
	m_btnBannerClose.ShowText(TRUE);
	m_btnBannerClose.SetTextColor(Color(0,0,0), Color(30,148,218), Color(30,148,218), Color(0,0,0));
	m_btnBannerClose.SetTextPoint(CPoint(MULX(23), 0));*/

    //m_btnBannerStatusBar.SetImage(IDB_STATUS_BAR, IDB_STATUS_BAR, IDB_STATUS_BAR, IDB_STATUS_BAR);

	m_bIsSetTimer = FALSE;
	m_bIsFinished = TRUE;
	m_bIsHiding = FALSE;

	m_dwEdgeHeight = 0;
	m_dwEdgeWidth  =0;

    m_bShowStatusBar = FALSE;
}

void CBannerDlg::DoDataExchange(CDataExchange* pDX)
{
	//CDialogEx::DoDataExchange(pDX);
	CBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_BANNER, m_staticBanner);
    //DDX_Control(pDX, IDC_BTN_BANNER_CLOSE, m_btnBannerClose );
	DDX_Control(pDX, IDC_BTN_BANNER_CLOSE, m_btnBannerStatusBar );
	
}

BEGIN_MESSAGE_MAP(CBannerDlg, CBaseDlg/*CDialogEx*/)
	ON_BN_CLICKED(IDC_BTN_BANNER_CLOSE, OnBannerClose)
	ON_WM_TIMER()
	ON_WM_NCHITTEST()
	ON_WM_CREATE()
END_MESSAGE_MAP()

BOOL CBannerDlg::OnInitDialog()
{
	CBaseDlg::OnInitDialog();
	InitUI();
	SetWindowText(_T(DEF_TELNET_NAME));

	return TRUE;
}

BOOL CBannerDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_KEYDOWN)
	{
		if ( VK_RETURN == pMsg->wParam
			|| VK_SPACE == pMsg->wParam
			|| VK_ESCAPE == pMsg->wParam)
		{
			return TRUE;
		}
	}
	return CBaseDlg::PreTranslateMessage(pMsg);
}

void CBannerDlg::InitUI()
{
	int nWidthTmp = MULX(346);
	int nHeighTmp = MULY(35);

	int width = (GetSystemMetrics ( SM_CXSCREEN )-nWidthTmp)/2; 
	int height= (GetSystemMetrics ( SM_CYSCREEN )-nHeighTmp)/2; 
	CDialog::SetWindowPos( &wndTopMost, width, -m_dwEdgeHeight, nWidthTmp, nHeighTmp, SWP_HIDEWINDOW );

	m_staticBanner.SetWindowPos( NULL, MULX(25), MULY(10), MULX(296), MULY(16), SWP_SHOWWINDOW/*SWP_NOSIZE*/ );
	//m_btnBannerClose.SetWindowPos( NULL, MULX(251), MULY(10), MULX(74), MULY(16), SWP_SHOWWINDOW/*SWP_NOSIZE*/ );
    //m_btnBannerStatusBar.SetWindowPos( NULL, MULX(2), MULY(27), MULX(342), MULY(6), SWP_HIDEWINDOW/*SWP_NOSIZE*/ );

	CString strName;
	if ( g_dlg != NULL )
	{
		strName = g_dlg->m_strSysUserName;
	}
	

	CString strDes = strName + STRING_PROJECTING;
	m_staticBanner.SetWindowText(strDes);

	//m_btnBannerClose.SetWindowText(STRING_STOP_PROJECTING);
	
}

void CBannerDlg::OnBannerClose()
{
	PRINTMSG_TIME("\r\n点击停止投屏按钮\r\n");
	g_dlg->StopProjectScreen(true);
}

int CBannerDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO: Add your specialized creation code here

	//获得边缘高度和宽度
	m_dwEdgeHeight = GetSystemMetrics(SM_CYEDGE);
	m_dwEdgeWidth  = 10/* GetSystemMetrics(SM_CXFRAME)*/;

	//可以在这里读取上次关闭后保存的大小

	return 0;
}

LRESULT CBannerDlg::OnNcHitTest(CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(!m_bIsSetTimer &&
		//防止鼠标超出屏幕右边时向右边收缩造成闪烁
		point.x < GetSystemMetrics(SM_CXSCREEN) + INFALTE)
	{   //鼠标进入时,如果是从收缩状态到显示状态则开启Timer
		//SetTimer(HideTimerId,CM_ELAPSE,NULL);
		m_bIsSetTimer = TRUE;

		m_bIsFinished = FALSE;
		m_bIsHiding = FALSE;
		SetTimer(ShowTimerId,HS_ELAPSE,NULL); //开启显示过程
	}
	return CDialog::OnNcHitTest(point);
}

void CBannerDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent == HideTimerId )
	{
		POINT curPos;
		GetCursorPos(&curPos);

		CRect tRect;
		//获取此时窗口大小
		GetWindowRect(tRect);
		//膨胀tRect,以达到鼠标离开窗口边沿一定距离才触发事件
		tRect.InflateRect(INFALTE,INFALTE); 

		if(!tRect.PtInRect(curPos)) //如果鼠标离开了这个区域
		{
			KillTimer(HideTimerId); //关闭检测鼠标Timer
			m_bIsSetTimer = FALSE;

			m_bIsFinished = FALSE;			
			m_bIsHiding = TRUE;
			SetTimer(ShowTimerId,HS_ELAPSE,NULL); //开启收缩过程
		}
	}

	if(nIDEvent == ShowTimerId)
	{
		if(m_bIsFinished) //如果收缩或显示过程完毕则关闭Timer	  
		{
			KillTimer(ShowTimerId);
			//展开状态才开启5s自动隐藏
			if (!m_bIsHiding)
			{
				g_dlg->SetBannerAutoHide(); //5s自动隐藏
			}
		}
		else
		{	
			m_bIsHiding ? Hide() : Show();
		}
	}

    if (nIDEvent == StatusBarTimerId)
    {
        //KillTimer(StatusBarTimerId);
        HDC hDc = ::GetDC( this->GetSafeHwnd() );
        HDC hDcMem =  CreateCompatibleDC( hDc);

        //CPaintDC dc(this);
        //CDC dcMem;
        //dcMem.CreateCompatibleDC(&dc);  //创建兼容DC


        CDC *pDC = CDC::FromHandle(hDcMem);
        //CBitmap cbmp;
        //cbmp.LoadBitmap(IDB_STATUS_BAR);  //载入位图

        //BITMAP bitmap;
        //cbmp.GetBitmap(&bitmap);  //获取位图信息
        //CRect rect;
        //PRINTMSG("bitmap: %ld, %ld", bitmap.bmWidth, bitmap.bmHeight);

        CImage ImageBg;
        if ( LoadImageFromResource(&ImageBg, IDB_STATUS_BAR, _T("RCPNG")) )
        {
            //Draw
            if (pDC != NULL)
            {
                //PRINTMSG("Res width:%d, height:%d\r\n", ImageBg.GetWidth(), ImageBg.GetHeight());
                ImageBg.Draw(pDC->m_hDC, 0, 30, 346, 4, 0, 0, 346,4);
                ImageBg.Destroy();
                ReleaseDC(pDC);
            }
        }


        //CBitmap *pbitold=dcMem.SelectObject(&cbmp);  //将位图选入DC中
        //BitBlt(hDcMem, 1, 30, 344, 4,
        //    dcMem.GetSafeHdc(), 0, 0, SRCCOPY);  //以stretchBlt的方式添加位图到相应区域

        //cbmp.DeleteObject();
        //dcMem.SelectObject(pbitold);
        //dcMem.DeleteDC();
    }

	CDialog::OnTimer(nIDEvent);
}

void CBannerDlg::DoHide()
{
	SetTimer(HideTimerId,CM_ELAPSE,NULL);//SetTimer(HideTimerId, CM_ELAPSE, NULL);
}

void CBannerDlg::StopAutoHide()
{
	KillTimer(ShowTimerId);
	KillTimer(HideTimerId);
}

BOOL CBannerDlg::SetWindowPos(const CWnd* pWndInsertAfter, LPCRECT pCRect, UINT nFlags)
{
    if (m_bShowStatusBar)
    {
        m_btnBannerStatusBar.ShowWindow(SW_SHOW);
        SetTimer(StatusBarTimerId,30,NULL);
    }

	return CDialog::SetWindowPos(pWndInsertAfter,pCRect->left, pCRect->top,
		pCRect->right - pCRect->left, pCRect->bottom - pCRect->top, nFlags);
}

void CBannerDlg::Hide()
{
	CRect tRect;
	GetWindowRect(tRect);

	INT height = tRect.Height();
	INT width  = tRect.Width();

	INT steps = 0;

	steps = height/HS_STEPS;
	tRect.bottom -= steps;
	if(tRect.bottom <= m_dwEdgeWidth)
	{   //你可以把下面一句替换上面的 ...+=|-=steps 达到取消抽屉效果
		//更好的办法是添加个BOOL值来控制,其他case同样.
		tRect.bottom = m_dwEdgeWidth;
		m_bIsFinished = TRUE;  //完成隐藏过程
        m_bShowStatusBar = TRUE;
	}
	tRect.top = tRect.bottom - height; 

	SetWindowPos(&wndTopMost,tRect);
}

void CBannerDlg::Show()
{
    m_btnBannerStatusBar.ShowWindow(SW_HIDE);
    m_bShowStatusBar = FALSE;

	CRect tRect;
	GetWindowRect(tRect);
	INT height = tRect.Height();
	INT width  = tRect.Width();

	INT steps = 0;
	steps = height/HS_STEPS;
	tRect.top += steps;
	if(tRect.top >= -m_dwEdgeHeight)
	{   //你可以把下面一句替换上面的 ...+=|-=steps 达到取消抽屉效果
		//更好的办法是添加个BOOL值来控制,其他case同样.
		tRect.top = -m_dwEdgeHeight;
		m_bIsFinished = TRUE;  //完成显示过程
	}
	tRect.bottom = tRect.top + height;

	SetWindowPos(&wndTopMost,tRect);
}
