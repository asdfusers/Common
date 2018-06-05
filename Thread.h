#pragma once

#include "stdafx.h"
class CThread
{
protected:
	virtual void threadMain() = 0;
	static unsigned WINAPI __threadMain(void* arg);

public:
	void begin();
	void join();



private:
	HANDLE hThread;

};
