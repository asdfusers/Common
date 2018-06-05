#include "CriticalSectionLock.h"

CCriticalSectionLock::CCriticalSectionLock(CS::CriticalSection& crit) : m_cs(crit)
{
	m_cs.enter();
	lock = true;
}


CCriticalSectionLock::~CCriticalSectionLock()
{
	if (lock)
		m_cs.leave();
}
