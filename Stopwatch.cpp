
#include "Stopwatch.h"
#include <windows.h>


__int64 ToInt64(LARGE_INTEGER* pI)
{
	return pI->QuadPart;
}




Stopwatch::Stopwatch()
{
	LARGE_INTEGER i;
	QueryPerformanceFrequency(&i);
	// get frequency in ticks per millisecond
	m_frequency = ToInt64(&i) / 1000;
	m_start = 0;
	m_stop = 0;
}

__int64 Stopwatch::Now()
{
	LARGE_INTEGER i;
	QueryPerformanceCounter(&i);
	__int64 now = ToInt64(&i);
	return now / m_frequency;
}



void Stopwatch::Start()
{
	m_start = Now();
}

void Stopwatch::Stop()
{
	m_stop = Now();
}
__int64 Stopwatch::ElapsedTicks()
{
	if(m_stop)
		return m_stop - m_start;
	else
		return Now() - m_start;
}

__int64 Stopwatch::ElapsedMilliseconds()
{
	return ElapsedTicks();
}