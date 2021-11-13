#pragma once

#include "PopRushiaView.h"


class Core
{
private:
	Status status; //狀態
	unsigned long long click; //點擊次數

public:
	Core()
	{
		status = Status::close;
		click = 0ULL;
	}

	void press(CPopRushiaView* view)
	{
		if (status == Status::close)
		{
			this->status = Status::open;

			PlaySound( //播放音效
				MAKEINTRESOURCE(IDR_WAVE1),
				AfxGetResourceHandle(),
				SND_ASYNC | SND_RESOURCE); //不是很確定能不能成功

			++click;
			view->Invalidate();
			view->UpdateWindow(); //重畫視窗
		}
	}

	void release(CPopRushiaView* view)
	{
		if (status == Status::open)
		{
			this->status = Status::close;
			//PlaySound(NULL, NULL, NULL); //停止音效 刪除看會不會比較好
			view->Invalidate();
			view->UpdateWindow(); //重畫視窗
		}
	}

	Status getStatus()
	{
		return this->status;
	}

	unsigned long long getClick()
	{
		return this->click;
	}

	~Core()
	{}

}core;