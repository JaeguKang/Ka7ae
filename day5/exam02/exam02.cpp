// exam02.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<string.h>
//simple REPL 기본형

int main()
{
	char szCmd[32];

	while (1) 
	{
		scanf_s("%s", &szCmd, sizeof(szCmd));

		if (strcmp("quit", szCmd) == 0)
		{
			printf_s("프로그램을 종료합니다.\n");
			break;
		}

		else
		{
			printf_s("잘못입력했어 ㅡㅡ %s . \n", szCmd);
		}

	}
    return 0;
}

