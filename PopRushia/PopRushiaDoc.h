﻿
// PopRushiaDoc.h: CPopRushiaDoc 類別的介面
//


#pragma once


class CPopRushiaDoc : public CDocument
{
protected: // 僅從序列化建立
	CPopRushiaDoc() noexcept;
	DECLARE_DYNCREATE(CPopRushiaDoc)

// 屬性
public:

// 作業
public:

// 覆寫
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 程式碼實作
public:
	virtual ~CPopRushiaDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 產生的訊息對應函式
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 為搜尋處理常式設定搜尋內容的 Helper 函式
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
