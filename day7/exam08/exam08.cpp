// exam04.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"



int main()
{
	char animal[5][16];
	int animal_num = 0;


	char szCmdBuf[32];

	while (1)
	{
		printf_s("명령어를 입력하세요.\n");

		gets_s(szCmdBuf, sizeof(szCmdBuf));
		if (strcmp(szCmdBuf, "quit") == 0)
		{
			break;
		}

		else if (strcmp(szCmdBuf, "add") == 0)
		{
			printf_s("어떤 동물 >");
			gets_s(animal[animal_num], 16);
			animal_num++;
		}

		else if (strcmp(szCmdBuf, "list") == 0)
		{
			printf_s("소유하신 동물들은..\n");
			for (int i = 0;i < animal_num;i++)
			{
				printf_s("%8s\n", animal[i]);
			}
		}

		else if (strcmp(szCmdBuf, "del") == 0)
		{
			animal_num--;
			printf_s("오늘은 %s 고기반찬입니다.\n", animal[animal_num]);
		}

		else
		{
			printf_s("%s 는 처리할 수 없는 명령어입니다.\n", szCmdBuf);
		}
	}
	printf_s("프로그램을 종료합니다.\n");

	return 0;
}

