#include "WinTimer.h"
#include <chrono>


WinTimer::WinTimer() :
	m_startTime(0),m_endTime(0),m_timeInMicro(0)
{

}

void WinTimer::startTimer()
{
	m_endTime = -1;
	m_timeInMicro = -1;
    // Get the current time point
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    // Get the duration in microseconds
    auto duration = now.time_since_epoch();
    double microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
    m_startTime= microseconds;
}

void WinTimer::stopTimer()
{
    // Get the current time point
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    // Get the duration in microseconds
    auto duration = now.time_since_epoch();
    double microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
    m_endTime = microseconds;

    m_timeInMicro = m_endTime - m_startTime;
}

double WinTimer::getTimeInMicroSec()
{
    return m_timeInMicro;
}

double WinTimer::getTimeInMilliSec()
{
    // Convert microseconds to milliseconds
    return m_timeInMicro / 1000.0;
}

double WinTimer::getTimeInSec()
{
    // Convert microseconds to seconds
    return m_timeInMicro / 1000000.0;
}