#pragma once
#include <Windows.h>

class Class_Timer
{
private:
	//���ϴ����Ѿ��е����ݳ�Ա��
	static LARGE_INTEGER m_clk;			// ����ʱ����Ϣ
	static LONGLONG m_oldclk;			// ���濪ʼʱ�Ӻͽ���ʱ��
	static int m_freq;					// ʱ��Ƶ��(ʱ��ʱ�任����)��ʱ���

	//������Ϸ����������
	static LONGLONG sys_clk;//��Ϸѭ��һ��ʼʱ��Ҫˢ���������
	static LONGLONG game_clk;//ʵ����Ϸ����������������ͣʱ�䲻���м�¼��

public:
	//���ϴ����Ѿ��еĳ�Ա������
	static void Sleep(int ms);

	/****************
	������Ϸ����������
	****************/
	//��ʼ����ʱ���������0
	static void initGameTimer();
	//��Ϸר���ӳ٣�����������Ϸ�Ƿ�����ͣ״̬��false��ʾû��ͣ��
	static void GameSleep(int ms);
	//��ȡ��Ϸʵ�ʾ����ĺ�����
	static DWORD GetGameTime();
	//ˢ����Ϸѭ����ʼǰ��ϵͳ������
	static void renewSysClk();
};

