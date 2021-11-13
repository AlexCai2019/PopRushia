﻿
// PopRushiaView.h: CPopRushiaView 類別的介面
//

#pragma once

#include "Show.h"

class CPopRushiaView : public CView
{
protected: // 僅從序列化建立
	CPopRushiaView() noexcept;
	DECLARE_DYNCREATE(CPopRushiaView)

// 屬性
public:
	CPopRushiaDoc* GetDocument() const;

// 作業
public:

// 覆寫
public:
	virtual void OnDraw(CDC* pDC);  // 覆寫以描繪此檢視
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 程式碼實作
public:
	virtual ~CPopRushiaView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 產生的訊息對應函式
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 對 PopRushiaView.cpp 中的版本進行偵錯
inline CPopRushiaDoc* CPopRushiaView::GetDocument() const
   { return reinterpret_cast<CPopRushiaDoc*>(m_pDocument); }
#endif

