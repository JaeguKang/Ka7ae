// exam11.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<conio.h>


//메인 코멘트
const char *strpWorldArea[32] =
{

	"커다란 방 한가운데 작은 탁자가 놓여있고 북, 동, 서쪽에는 문이있다.\n\n",										//0
	"북쪽에 출구가 보인다.\n\n그렇지만 무섭게 생긴 개가 지키고 있다.\n\n",											//1
	"작은 정원 같은 곳이다.\n\n누군가 파티를 했던 흔적이 있다.\n\n개가 좋아할 만한 뼈다귀들이 보인다.\n\n ",		//2

};



//이벤트 코멘트
const char *strEvent[32] =
{
	"개가 너무 무섭다.\n\n가까이 접근하는 것도 어렵다.\n\n",														//0
	"뼈다귀를 주울까?		(y,n)\n\n",																				//1
	"뼈다귀를 주웠다.\n\n",																							//2
	"에이 더러워..			(그냥지나친다)\n\n",																	//3
	"뼈다귀를 개한태 준다.		(y,n)\n\n",																			//4
	"뼈다귀로 개를 따돌리니 출구로 나갈 수 있게 됬다.\n\n",															//5
	"어우 무서워 근처도 못가겠다.		(뼈다귀를 주지 않는다.)\n\n",												//6	
	"ㅊㅋㅊㅋ 탈출성공 !! \n\n"
	
};



//플레이어의 위치 & 이동방향
int g_nCurrentPos = 0;
int g_wayTable[32][4] =
{
	{ -1,2,-1,1 },	//동 서 남 북 <순서
	{ -1,-1,0,-1 },
	{ 0,-1,-1,-1 }

};


//전역변수
char szCmdBuf[32];


//이벤트 요소
bool BoneCk = false;
bool BoneGv = false;
bool GameOv = false;

//이벤트 발생 함수
void EventA(int CPos)
{
	if (CPos == 1)
	{

		if (BoneCk)		
		{
			printf_s("%s", strEvent[4]);

			char _;
			_ = _getch();

			if (_ = 'y')
			{
				printf_s("%s", strEvent[5]);
				BoneGv = true;
			}

			else if (_ = 'n')
			{
				printf_s("%s", strEvent[6]);
			}

		}

		else
		{
			printf_s("%s", strEvent[0]);
		}


	}

	else if (CPos == 2)
	{
		printf_s("%s", strEvent[1]);


		char _;
		_ = _getch();


		if (_ = 'y')
		{
			printf_s("%s", strEvent[2]);
			BoneCk = true;
		}

		else if (_ = 'n')
		{
			printf_s("%s", strEvent[3]);
		}


	}


}


int main()
{
	while (1)
	{
		printf_s("Command : ");

		gets_s(szCmdBuf, sizeof(szCmdBuf));

		if (strcmp(szCmdBuf, "quit") == 0)
		{
			break;
		}

		//코멘트 보여주기
		else if (strcmp(szCmdBuf, "see") == 0)
		{
			printf_s("%s\n\n", strpWorldArea[g_nCurrentPos]);
		}

		//플레이어 이동
		else if (strcmp(szCmdBuf, "move") == 0)
		{
			int nDir;
			printf_s("방향을 입력하세요 동서남북=(0,1,2,3) ");
			scanf_s("%d", &nDir);

			int new_pos = g_wayTable[g_nCurrentPos][nDir];

			if (new_pos == -1)
			{
				printf_s("갈 수 없습니다.\n\n");
			}

			else
			{
				printf_s("이동합니다.\n\n");
				g_nCurrentPos = new_pos;
			}

		}

		//이벤트 발생 키
		else if (strcmp(szCmdBuf, "act") == 0)
		{
			EventA(g_nCurrentPos);
		}


	}


	return 0;

}