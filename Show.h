#pragma once

#include "framework.h"
#include <mmsystem.h>

#define CLOSE 0
#define OPEN 1

#define WIDTH 800
#define HEIGHT 800

enum class Status
{
	close = CLOSE,
	open = OPEN
};

class Show
{
private:
	CBitmap texture;
	CBitmap* oldbmp;
	CDC memdc;

public:

	Show()
	{
		oldbmp = nullptr;
	}

	void initial(CDC* pDC)
	{
		memdc.CreateCompatibleDC(pDC);
		texture.LoadBitmap(IDB_BITMAP1);
		oldbmp = memdc.SelectObject(&texture);
	}

	void show(CDC* pDC, CRect* screen, Status status, unsigned long long click)
	{
		int left = 0;

		left = (status == Status::close) ? 0 : WIDTH;

		int img_coords[2] =
		{
			(screen->right >> 1) - (WIDTH >> 1), //顯示在中間
			0
		};

		pDC->BitBlt( //顯示
			img_coords[0], //圖片左上角在視窗的x
			img_coords[1], //圖片左上角在視窗的y
			WIDTH, HEIGHT, //顯示的長度
			&memdc,
			left, 0, //切割
			SRCCOPY);

		CString click_time;
		click_time.Format(L"Click: %I64d", click);
		pDC->DrawText(click_time, screen, DT_RIGHT);
	}

	~Show()
	{
		memdc.SelectObject(oldbmp);
		texture.DeleteObject();
		memdc.DeleteDC();
	}
};