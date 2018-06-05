#pragma once
#include "CriticalSections.h"
class CCriticalSectionLock
{
private:
	CS::CriticalSection& m_cs;
	bool lock;

public:
	CCriticalSectionLock(CS::CriticalSection& crit);
	~CCriticalSectionLock();
};

