// exam03.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<string.h>

int main()
{
	char szCmd[32];
	char cBufStack[256];
	int nstackPointer = 0;

	while (1)
	{
		scanf_s("%s", &szCmd, sizeof(szCmd));

		if (strcmp("quit", szCmd) == 0)
		{
			printf_s("프로그램을 종료합니다.\n");
			break;
		}
		else if (strcmp("push", szCmd) == 0)
		{
			printf_s("데이터를 입력하세요 : ");
			char _tmp;
			scanf_s("%c", &_tmp, 1);
			scanf_s("%c", &_tmp, 1);
			printf_s("입력값 : %c \n", _tmp);
			cBufStack[nstackPointer] = _tmp;
			nstackPointer++;
		}
		else if (strcmp("pop", szCmd) == 0)
		{
			nstackPointer--;
			printf_s("성공적으로 팝 했습니다. 스택포인터 위치는 (%d) 입니다.\n", nstackPointer);
		}
		else if (strcmp("dump", szCmd) == 0)
		{
			//cBufStack[nstackPointer] = 0x00;						//맨뒤에 널문자 넣어서 끊기
			//printf_s("%s\n",cBufStack);
			for (int i = 0; i < nstackPointer; i++ )				//for문으로
			{
				printf_s("%c", cBufStack[i]);
			}
			printf_s("\n");

		}
		else
		{
			printf_s("입력하신 커멘드는 : %s 입니다. \n", szCmd);
		}

	}

    return 0;
}

