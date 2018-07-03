// exam06.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
//player (x:4,y:3)
char cTileMap[64] = {
	1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,1,
	1,0,0,2,0,0,0,1,
	1,0,0,0,9,0,0,1,
	1,1,1,1,0,0,0,1,
	1,0,0,0,0,0,0,3,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,
};												//move, get, use,

int main()
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			printf_s("%2d", cTileMap[x + y * 8]);
		}
		printf_s("\n");
	}
    return 0;
}

