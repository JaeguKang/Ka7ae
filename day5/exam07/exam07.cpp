// exam02.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<string.h>
//simple REPL 기본형

//맵 8x8 size
char cTileMap[64] = {
	1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,0,0,0,0,1,
	1,0,0,0,1,1,1,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,
};

//플레이어 오브잭트
int g_nplayerPosX, g_nplayerPosY;

int main()
{
	g_nplayerPosX = 3;
	g_nplayerPosY = 3;

	char szCmd[32];

	while (1)
	{
		printf_s("명령어를 입력해 _");
		scanf_s("%s", &szCmd, sizeof(szCmd));

		if (strcmp("quit", szCmd) == 0)
		{
			printf_s("프로그램을 종료합니다.\n");
			break;
		}

		else if (strcmp("dump", szCmd) == 0)
		{
			//cTileMap[g_nplayerPosX + g_nplayerPosY * 8] = 9;

			char _tempBuf[64];

			for (int i = 0; i < 64; i++)
			{
				_tempBuf[i] = cTileMap[i];
			}

			_tempBuf[g_nplayerPosX + g_nplayerPosY * 8] = 9;		//플레이어 출력   ▒

			for (int y = 0; y < 8; y++)
			{
				for (int x = 0; x < 8; x++)
				{
					printf_s("%2d", _tempBuf[x + y * 8]);
				}
				printf_s("\n");
			}
		}

		else if (strcmp("move", szCmd) == 0)	//플레이어 이동
		{
			{char _; scanf_s("%c", &_, 1);} //clear console buffer
			
			printf_s("방항을 입력하세요 : ");
			
			char _;
			scanf_s("%c", &_, 1);
			if (_ == 'n')
			{
				g_nplayerPosY--;

			}
			else if (_ == 'e')
			{
				g_nplayerPosX++;
			}
			else if (_ == 'w')
			{
				g_nplayerPosX--;
			}
			else if (_ == 's')
			{
				g_nplayerPosY++;
			}

			printf_s("플레이어가 %c쪽으로 이동했다.\n",_);

		}




		else
		{
			printf_s("잘못입력했어 ㅡㅡ %s . \n", szCmd);
		}

	}
	return 0;
}

