#include <Windows.h>
#include <stdio.h>



DWORD 人物基址 = 0x039B4230;
DWORD 评分基址 = 0x038D1264;
DWORD 加密基址 = 0x039FE3D8;
DWORD 解密基址 = 0x039FE378;
DWORD 加密参数1 = 0x03490A80;
DWORD 加密参数2 = 0x03490C80;
DWORD 无敌call = 0x026569A0;
DWORD 技能栏 = 0x00005AA0;
DWORD 技能栏偏移 = 0x00000084;
DWORD 技能等级偏移 = 0x000006F0;
DWORD 技能冷却偏移 = 0x00000300;
DWORD 自动拾取 = 0x01849D8B;
DWORD 入包范围 = 0x01849D5D;
DWORD 商店基址 = 0x038D2F30;
DWORD 喇叭公告 = 0x0197E320;


DWORD pid = 0;

int 读内存整数(int Pid, int address)
{
	HANDLE hProcess;
	LPVOID 返回数据;
	SIZE_T length = 4;//长度
	if (Pid == -1)
	{
		hProcess = GetCurrentProcess(); //打开当前进程
	}
	else
	{
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, (DWORD)Pid);//PROCESS_VM_READ

	}
	int abb;
	abb = ReadProcessMemory(hProcess, (LPCVOID)address, &返回数据, length, FALSE);//内存读整数
	CloseHandle(hProcess);
	return (int)返回数据;
}

BOOL  写内存整数(int pid, int address, int data)
{
	HANDLE hProcess;
	if (pid == -1)
	{
		hProcess = GetCurrentProcess(); //打开当前进程
	}
	else
	{
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, (DWORD)pid);//PROCESS_VM_READ

	}

	BOOL a = WriteProcessMemory(hProcess, (LPVOID)address, (LPCVOID)&data, 4, 0);

	CloseHandle(hProcess);//关闭对象


	return a;




}

byte *p;
byte *读内存字节集(int Pid, int address, int length)
{
	HANDLE hProcess;
	//fhbyte = {};
	if (Pid == -1)
	{
		hProcess = GetCurrentProcess(); //打开当前进程
	}
	else
	{
		//hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, (DWORD)进程ID);//PROCESS_VM_READ
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, Pid);
	}

	p = new byte[length];//取空白字节集以做存储缓冲区 
	memset(p, 0, length);//清空申请的缓存区
	ReadProcessMemory(hProcess, (LPCVOID)address, p, length, NULL);

	CloseHandle(hProcess);//关闭对象

	return p;//这里返回读取到的字节集的首地址


}


BOOL 写内存字节集(int Pid, int address, byte data[], int length)
{
	HANDLE hProcess;
	if (Pid == -1)
	{
		hProcess = GetCurrentProcess(); //打开当前进程
	}
	else
	{
		hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, (DWORD)Pid);//PROCESS_VM_READ

	}

	BOOL a = WriteProcessMemory(hProcess, (LPVOID)address, (LPCVOID)data, length, 0);
	CloseHandle(hProcess);//关闭对象
	return a;
}


void 加密(int 地址, int 数值)
{
	int edi, ecx, eax, esi, edx, ss;
	ecx = 地址;
	eax = 读内存整数(pid, 加密基址);
	eax = eax + 1;
	写内存整数(pid, 0x39FE3D8, eax);
	edx = eax;
	edx >>= 8;
	edx <<= 24;
	edx >>= 24;
	edx = 读内存整数(pid, edx * 2 + 加密参数1);
	edx = WORD(edx);
	eax <<= 24;
	eax = eax = 24;
	ss = 读内存整数(pid, eax * 2 + 加密参数2);
	ss = WORD(ss);
	edx = edx^ ss;
	eax = edx;
	eax = WORD(eax);
	esi = 数值;
	edx = esi >> 16;
	Sleep(10);
	ss = WORD(esi);
	edx = edx + ss;
	edx = edx^ eax;
	edi = edx;
	edx = eax;
	eax <<= 16;
	eax = eax + edx;
	esi = 数值;
	eax = eax^esi;
	esi = 地址 + 4;
	写内存整数(pid, esi, eax);
	eax = 读内存整数(pid, 地址);
	esi = 读内存整数(pid, 解密基址);
	ecx = edi;
	ecx <<= 16;
	ecx = ecx + edx;
	edx = eax;
	edx >>= 16;
	edx = 读内存整数(pid, esi + edx * 4 + 36);
	eax = WORD(eax);
	写内存整数(pid, edx + eax * 4 + 8468, ecx);

}


int 解密(int 地址)
{
	int eax, esi, edx;
	eax = 读内存整数(pid, 地址);
	esi = 读内存整数(pid, 解密基址);
	edx = eax;
	edx >>= 16;
	edx = 读内存整数(pid, esi + edx * 4 + 36);
	eax = WORD(eax);
	eax = 读内存整数(pid, edx + eax * 4 + 8468);
	eax = WORD(eax);
	edx = eax;
	esi = edx;
	esi <<= 16;
	esi = esi + edx;
	edx = 读内存整数(pid, 地址 + 4);
	eax = esi^edx;
	return eax;

}

void 三速()
{
	加密(读内存整数(pid, 读内存整数(pid, 人物基址) + 0x2B0C) + 0x97C, 600);//移速
	//Sleep(500);
	加密(读内存整数(pid, 读内存整数(pid, 人物基址) + 0x2B0C) + 0x994, 500);//攻速
	//Sleep(500);
	加密(读内存整数(pid, 读内存整数(pid, 人物基址) + 0x2B0C) + 0x99C, 800);//施放
}

void 耐久()
{
	加密(读内存整数(pid, 读内存整数(pid, 人物基址) + 0x2B0C) + 0x5FC, 0);//上装 。。。耐久
	//Sleep(500);
	加密(读内存整数(pid, 读内存整数(pid, 人物基址) + 0x2B14) + 0x5FC, 0);//下装
	//Sleep(500);
	加密(读内存整数(pid, 读内存整数(pid, 人物基址) + 0x2B10) + 0x5FC, 0);//头肩
	//Sleep(500);
	加密(读内存整数(pid, 读内存整数(pid, 人物基址) + 0x2B18) + 0x5FC, 0);//鞋子
	//Sleep(500);
	加密(读内存整数(pid, 读内存整数(pid, 人物基址) + 0x2B1C) + 0x5FC, 0);//腰带
	//Sleep(500);
	加密(读内存整数(pid, 读内存整数(pid, 人物基址) + 0x2B04) + 0x5FC, 0);//武器
}

void 无敌Call(int 人物指针, int 开关)
{
	__asm{

		mov ecx, dword ptr ds : [人物指针]
			mov esi, dword ptr ss : [ecx]
			push - 1
			push 1
			push 开关
			push 1
			call 无敌call

	     }

}


void 无CD()
{
	int 技能a=0, 技能s=0, 技能d=0, 技能f=0, 技能g=0, 技能h=0, 技能q=0, 技能w=0, 技能e=0, 技能r=0, 技能t=0, 技能y=0;
    技能a = 解密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址)+ 技能栏) +技能栏偏移) + 0x00000000) + 技能等级偏移);
	技能s = 解密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x00000004) + 技能等级偏移);
	技能d = 解密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x00000008) + 技能等级偏移);
	技能f = 解密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x0000000C) + 技能等级偏移);
	技能g = 解密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x00000010) + 技能等级偏移);
	技能h = 解密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x00000014) + 技能等级偏移);
	技能q = 解密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x00000318) + 技能等级偏移);
	技能w = 解密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x0000031C) + 技能等级偏移);
	技能e = 解密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x00000320) + 技能等级偏移);
	技能r = 解密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x00000324) + 技能等级偏移);
	技能t = 解密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x00000328) + 技能等级偏移);
	技能y = 解密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x0000032C) + 技能等级偏移);
	
	加密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x00000000) + 技能冷却偏移) + (技能a - 1) * 8, 0);
	加密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x00000004) + 技能冷却偏移) + (技能s - 1) * 8, 0);
	加密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x00000008) + 技能冷却偏移) + (技能d - 1) * 8, 0);
	加密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x0000000C) + 技能冷却偏移) + (技能f - 1) * 8, 0);
	加密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x00000010) + 技能冷却偏移) + (技能g - 1) * 8, 0);
	加密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x00000014) + 技能冷却偏移) + (技能h - 1) * 8, 0);
	加密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x00000318) + 技能冷却偏移) + (技能q - 1) * 8, 0);
	加密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x0000031C) + 技能冷却偏移) + (技能w - 1) * 8, 0);
	加密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x00000320) + 技能冷却偏移) + (技能e - 1) * 8, 0);
	加密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x00000324) + 技能冷却偏移) + (技能r - 1) * 8, 0);
	加密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x00000328) + 技能冷却偏移) + (技能t - 1) * 8, 0);
	加密(读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 读内存整数(pid, 人物基址) + 技能栏) + 技能栏偏移) + 0x0000032C) + 技能冷却偏移) + (技能y - 1) * 8, 0);
}

void 无敌霸体()
{
	写内存整数(pid, 读内存整数(pid, 人物基址) + 0x838, 1);
	写内存整数(pid, 读内存整数(pid, 人物基址) + 0x924, 100);
}

void 属性微调()
{
	加密(读内存整数(pid, 读内存整数(pid, 人物基址) + 0x2B0C) + 0x7D4, 800);//四维
}












	int main()
	{   
		printf("        Aiko酱ing版权所有。\n");
		printf("\n");
		printf("本辅助完全免费，请不要用于商业途径。\n");
		printf("*****************************************\n");
		printf("*****************************************\n");
		HWND hWnd = FindWindow(TEXT("地下城与勇士"), TEXT("地下城与勇士"));//定义DNF的窗口句柄和类名
		if (hWnd == NULL)//判断窗口句柄是否存在
		{
			printf("未找到窗口\n");
		}

		GetWindowThreadProcessId(hWnd, &pid);//获取DNF进程句柄
		if (pid == 0)//判断进程是否存在
		{
			printf("未找到进程\n");
		}
		HANDLE hProcss = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);//打开DNF进程 提升权限
		if (hProcss == NULL)//判断DNF进程时候存在
		{
			printf("未找到进程\n");
		}
		else
		{
			printf("----------附加进程成功---------。\n");
			SYSTEMTIME sys;
			GetLocalTime(&sys);
			printf("\n");
			printf("当前时间为：%4d/%02d/%02d %02d:%02d:%02d.%03d 星期%1d\n", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds, sys.wDayOfWeek);
			printf("\n");
			//主线程();
			if (读内存整数(pid, 人物基址) >88888888)
			{
				printf("*****************************************\n");
				加密(读内存整数(pid, 评分基址) + 0x110, 6666666);
				无敌霸体();
				三速();
				无CD();
				printf("修改成功\n");
				printf("*****************************************\n");

			}
			else
			{
				printf("*****************************************\n");
				printf("游戏没有图标，读取内存失败！\n");
				printf("*****************************************\n");
			}

		}
			
		


		//b = 读内存整数(pid, BaTi);
		//printf("该地址修改后的数据为：%d\n", b);//输出修改后的数据
		//==================================================================
		CloseHandle(hProcss);//关闭DNF句柄防止线程占用
		system("pause");//暂停 （这个还没有理解= = ）
		return 0;//返回

	}
