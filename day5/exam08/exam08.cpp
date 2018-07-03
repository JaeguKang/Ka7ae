// exam06.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<string.h>
//player (x:4,y:3)
char cTileMap[64] = {
	1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,1,
	1,0,0,2,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,0,0,0,1,
	1,0,0,0,0,0,0,3,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,
};												//move, get, use,  ▒ ♡ ☎ ▥

const char *TileSet[] = 
{
	"  ",//0
	"▒",//1
	"☎",//2
	"▥",//3
	"  ",//4
	"  ",//5
	"  ",//6
	"  ",//7
	"  ",//8
	"♤" //9
};

int g_PlayerPosX, g_PlayerPosY;

int main()
{
	g_PlayerPosX = 1;
	g_PlayerPosY = 6;
	int g_Player = 9;

	char szCmd[32];

	while (1)
	{
		printf_s("Command : ");
		scanf_s("%s", szCmd, sizeof(szCmd));
		

		if (strcmp("quit", szCmd) == 0)
		{
			printf_s("End. \n");
			break;
		}

		else if (strcmp("dump", szCmd) == 0)
		{

			char _TempBuf[64];

			for (int i = 0; i < 64; i++)
			{
				_TempBuf[i] = cTileMap[i];
			}
			
			_TempBuf[g_PlayerPosX + g_PlayerPosY * 8] = 9;

			for (int y = 0; y < 8; y++)
			{
				for (int x = 0; x < 8; x++)
				{
					printf_s("%2s", TileSet[_TempBuf[x + y * 8]]);
				}
				printf_s("\n");
			}


		}

		else if (strcmp("move", szCmd) == 0)
		{
			{char _; scanf_s("%c", &_, 1); } // clear console buffer

			printf_s("Move Command : ");
			
			char _;
			scanf_s("%c", &_, 1);

			if (_ == 'n')
			{
				g_PlayerPosY--;
			}

			if (_ == 'e')
			{
				g_PlayerPosX++;
			}

			if (_ == 'w')
			{
				g_PlayerPosX--;
			}

			if (_ == 's')
			{
				g_PlayerPosY++;
			}

			printf_s("The player moved %c . \n", _);

		}


		else if (g_Player == (int)1)
		{
			break;
		}

		else
		{
			printf_s("Retype Command. \n");
		}
	}


	
	return 0;
}
	/*
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			printf_s("%s", TileSet[cTileMap[x + y * 8]]);
		}
		printf_s("\n");
	}
	
	while (1);
	{

	}
	*/