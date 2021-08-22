
// PopRushiaView.cpp: CPopRushiaView 類別的實作
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以定義在實作預覽、縮圖和搜尋篩選條件處理常式的
// ATL 專案中，並允許與該專案共用文件程式碼。
#ifndef SHARED_HANDLERS
#include "PopRushia.h"
#endif

#include "PopRushiaDoc.h"
#include "PopRushiaView.h"
#include "Rushia.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPopRushiaView

IMPLEMENT_DYNCREATE(CPopRushiaView, CView)

BEGIN_MESSAGE_MAP(CPopRushiaView, CView)
	// 標準列印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CPopRushiaView 建構/解構

CPopRushiaView::CPopRushiaView() noexcept
{
	// TODO: 在此加入建構程式碼

}

CPopRushiaView::~CPopRushiaView()
{
}

BOOL CPopRushiaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此經由修改 CREATESTRUCT cs 
	// 達到修改視窗類別或樣式的目的

	return CView::PreCreateWindow(cs);
}

// CPopRushiaView 繪圖

void CPopRushiaView::OnDraw(CDC* pDC)
{
	CPopRushiaDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此加入原生資料的描繪程式碼

	CRect screen; //螢幕大小
	GetClientRect(&screen); //獲取螢幕大小

	Show show;
	show.initial(pDC);
	show.show(pDC, &screen, core.getStatus(), core.getClick());
	pDC->DrawText(L"圖源: 奈兔工造", &screen, DT_BOTTOM);
}


// CPopRushiaView 列印

BOOL CPopRushiaView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 預設的準備列印程式碼
	return DoPreparePrinting(pInfo);
}

void CPopRushiaView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 加入列印前額外的初始設定
}

void CPopRushiaView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 加入列印後的清除程式碼
}


// CPopRushiaView 診斷

#ifdef _DEBUG
void CPopRushiaView::AssertValid() const
{
	CView::AssertValid();
}

void CPopRushiaView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPopRushiaDoc* CPopRushiaView::GetDocument() const // 內嵌非偵錯版本
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPopRushiaDoc)));
	return (CPopRushiaDoc*)m_pDocument;
}
#endif //_DEBUG


// CPopRushiaView 訊息處理常式


void CPopRushiaView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值

	CView::OnLButtonDown(nFlags, point);

	core.press(this);
}


void CPopRushiaView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值

	CView::OnLButtonUp(nFlags, point);

	core.release(this);
}
