#pragma once

#include "PopRushiaView.h"


class Core
{
private:
	Status status; //���A
	unsigned long long click; //�I������

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

			PlaySound( //���񭵮�
				MAKEINTRESOURCE(IDR_WAVE1),
				AfxGetResourceHandle(),
				SND_ASYNC | SND_RESOURCE); //���O�ܽT�w�ण�ন�\

			++click;
			view->Invalidate();
			view->UpdateWindow(); //���e����
		}
	}

	void release(CPopRushiaView* view)
	{
		if (status == Status::open)
		{
			this->status = Status::close;
			//PlaySound(NULL, NULL, NULL); //����� �R���ݷ|���|����n
			view->Invalidate();
			view->UpdateWindow(); //���e����
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