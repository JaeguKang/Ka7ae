// exam04.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


void count()
{
	int static a = 0;
	printf_s("%d \n", a++);
}

void decount()
{
	int static a = 100;
	printf_s("%d \n", a--);
}

int a = 0;

int main()
{
	printf_s("명령어를 입력하세요.\n");
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

		else
		{
			printf_s("%s 는 처리할 수 없는 명령어입니다.\n", szCmdBuf);
		}
	}
	printf_s("프로그램을 종료합니다.\n");
	
    return 0;
}

