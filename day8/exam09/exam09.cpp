// exam09.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<string.h>
#include<malloc.h>
#include<conio.h>
#include<stdlib.h>

void dump(char **buf)
{
	for (int i = 0;buf[i] != 0; i++)
	{
		printf_s("%s\n", buf[i]);
	}
}

int main()
{
	char szCmdBuf[32];
	char *strBuf[100] = { NULL };
	//*strBuf = (char *)malloc(100 * sizeof(char));
	//int str_num = 0;

	while (1)
	{
		printf_s("Command :");
		gets_s(szCmdBuf, sizeof(szCmdBuf));

		if (strcmp(szCmdBuf, "quit") == 0)
		{
			int i;
			for (i = 0;strBuf[i] != 0; i++)
			{
				free(strBuf[i]);								//동적할당된 공간을 초기화.
				strBuf[i] = NULL;
			}
			break;
		}

		else if (strcmp(szCmdBuf, "add") == 0)
		{
			printf_s("commend input : ");
			gets_s(szCmdBuf, 32);

			int i;
			for (i = 0; strBuf[i] != 0; i++) {}					//배열의 i번째에 값이 있는지 알아보기.
																//값이있으면 다음카운트로 값이없으면 루프를 끝냄.

			strBuf[i] = (char *)malloc(strlen(szCmdBuf)+1);							//메모리 공간 확보			strlen(szCmdBuf) : 문자열의 길이를 측정
			strcpy_s(strBuf[i], strlen(szCmdBuf) + 1, szCmdBuf);					//strBuf[i] = szCmdBuf;
			//str_num++;
		}

		else if (strcmp(szCmdBuf, "dump") == 0)
		{
			dump(strBuf);


		}

		else if (strcmp(szCmdBuf, "del") == 0)
		{

		}

	}

	return 0;
}

