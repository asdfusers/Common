#pragma once
#include "stdafx.h"

namespace CS
{
	class CriticalSection
	{
	private:
		CRITICAL_SECTION m_CS;

	public:
		CriticalSection() { InitializeCriticalSection(&m_CS); }
		virtual ~CriticalSection() { DeleteCriticalSection(&m_CS); }

		void enter() { EnterCriticalSection(&m_CS); }
		void leave() { LeaveCriticalSection(&m_CS); }

	};
}

