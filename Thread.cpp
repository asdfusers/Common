#include "stdafx.h"
#include "Thread.h"


unsigned CThread::__threadMain(void* arg)
{
	CThread* self = (CThread*)arg;
	self->threadMain();
	return 0;
}


void CThread::begin()
{
	hThread = (HANDLE)_beginthreadex(NULL, NULL, __threadMain, (void*)this, 0, 0);
}

void CThread::join()
{
	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);
}
