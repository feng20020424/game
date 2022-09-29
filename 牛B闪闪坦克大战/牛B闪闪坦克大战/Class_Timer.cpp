#include "Class_Timer.h"

//���������ϵĴ���
LARGE_INTEGER Class_Timer::m_clk = { 0 };
LONGLONG Class_Timer::m_oldclk = 0;
int Class_Timer::m_freq = 0;

//��������������
LONGLONG Class_Timer::sys_clk = 0;
LONGLONG Class_Timer::game_clk = 0;

//���������ϵĴ���
// ��ʱ
void Class_Timer::Sleep(int ms)
{
	if (m_oldclk == 0)
	{
		//QueryPerformanceFrequency(&m_clk);
		//m_freq = (int)m_clk.QuadPart / 1000;	// ��ü�������ʱ��Ƶ��

		// ��ʼ��ʱ
		QueryPerformanceCounter(&m_clk);
		m_oldclk = m_clk.QuadPart;				// ��ÿ�ʼʱ��
	}

	unsigned int c = ms * m_freq;

	m_oldclk += c;

	QueryPerformanceCounter(&m_clk);

	if (m_clk.QuadPart > m_oldclk)//����Ѿ����ӳٽ�����ʱ��
		m_oldclk = m_clk.QuadPart;
	else
		do
		{
			//��ʱ
			::Sleep(1);
			QueryPerformanceCounter(&m_clk);	// �����ֹʱ��
		} while (m_clk.QuadPart < m_oldclk);
}

//��������������
void Class_Timer::initGameTimer()
{
	QueryPerformanceFrequency(&m_clk);
	m_freq = (int)m_clk.QuadPart / 1000;	// ��ü�������ʱ��Ƶ��
	renewSysClk();
}

void Class_Timer::GameSleep(int ms)
{
	Sleep(ms);
	//ˢ��һ����Ϸʵ�ʾ�����������
	QueryPerformanceCounter(&m_clk);
	game_clk += m_clk.QuadPart - sys_clk;
	//��ʱ��ˢ��һ��ϵͳ��������������Ϸѭ��ִ�к����ʱ��ͳ��
	renewSysClk();
}

DWORD Class_Timer::GetGameTime()
{
	return (DWORD)game_clk / m_freq;
}

void Class_Timer::renewSysClk()
{
	//��ȡ��ǰϵͳ������������
	QueryPerformanceCounter(&m_clk);
	sys_clk = m_clk.QuadPart;
}
