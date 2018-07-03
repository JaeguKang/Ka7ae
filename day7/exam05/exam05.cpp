// exam04.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<string.h>
#include<conio.h>

int g_nCounter = 0;

void count()
{
	printf_s("%d \n", g_nCounter++);
}

void decount()
{
	printf_s("%d \n", g_nCounter--);
}

void reSet()
{
	printf_s("%d \n", g_nCounter = 0);
}

int a = 0;

int main()
{
	printf_s("명령어를 입력하세요 (quit, count, decount, reset.).\n");
	char szCmdBuf[32];
	while (1)
	{
		gets_s(szCmdBuf, sizeof(szCmdBuf));
		if (strcmp(szCmdBuf, "quit") == 0)
		{
			break;
		}

		else if (strcmp(szCmdBuf, "count") == 0)
		{
			count();
		}

		else if (strcmp(szCmdBuf, "decount") == 0)
		{
			decount();
		}

		else if (strcmp(szCmdBuf, "reset") == 0)
		{
			reSet();
		}

		else
		{
			printf_s("%s 는 처리할 수 없는 명령어입니다.\n", szCmdBuf);
		}
	}
	printf_s("프로그램을 종료합니다.\n");

	return 0;
}

