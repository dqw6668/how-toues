#include <Windows.h>
#include <stdio.h>

int main()
{
	HWND hWnd = FindWindow(TEXT("地下城与勇士"),TEXT("地下城与勇士"));//定义DNF的窗口句柄和类名
	if (hWnd == NULL)//判断窗口句柄是否存在
	{
		printf("未找到窗口\n");
	}
	DWORD pid = 0;
	GetWindowThreadProcessId(hWnd,&pid);//获取DNF进程ID句柄
	if (pid == 0)//判断进程ID是否存在
	{
		printf("未找到进程\n");
	}
	HANDLE hProcss = OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);//打开DNF进程 提升权限
	if (hProcss == NULL)//判断DNF进程时候存在
	{
		printf("未找到进程\n");
	}
	DWORD renwujizhi = 0x03160DD0;//定义人物基址
	ReadProcessMemory(hProcss, (LPCVOID)renwujizhi, &renwujizhi, sizeof(renwujizhi), NULL);//读取人物基址
	DWORD Linshi1 = renwujizhi + 0x00002A98;//人物基址+武器基址
	ReadProcessMemory(hProcss, (LPCVOID)Linshi1, &Linshi1, sizeof(Linshi1), NULL);//读取人物基址+武器基址
	DWORD Linshi2 = Linshi1 + 0x0000114C;//人物基址+武器基址+无敌偏移
	//定义无敌偏移
	DWORD a = 100;//定义修改无敌的值
	//无敌
	WriteProcessMemory(hProcss, (LPVOID)Linshi2, &a, sizeof(a), NULL);//修改无敌的值为100
	printf("该地址修改后的数据为：%d\n", a);//输出修改后的数据
	printf("\n*******************************************\n");
	//==================================================================
	DWORD RenWuJiZhi = 0x03160DD0;//定义人物基址
	ReadProcessMemory(hProcss, (LPCVOID)RenWuJiZhi, &RenWuJiZhi, sizeof(RenWuJiZhi), NULL);//读取人物基址
	DWORD BaTi = RenWuJiZhi + 0x000008AC;//人物基址+霸体偏移
	//定义霸体偏移
	DWORD b = 1;//定义修改霸体的值
	//霸体
	WriteProcessMemory(hProcss, (LPVOID)BaTi, &b, sizeof(b), NULL);//修改霸体的值为1
	printf("该地址修改后的数据为：%d\n", b);//输出修改后的数据
	printf("\n*******************************************\n");
	//==================================================================
	CloseHandle(hProcss);//关闭DNF句柄防止线程占用
	system("pause");//暂停 （这个还没有理解= = ）
	return 0;//返回
}
