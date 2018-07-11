// exam02.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include"../../engine/tge.h"
#include"PlayerObject.h"

////주인공
//COORD g_cdPlayerPos;
//int g_nInven_keyCount;
playerobject::S_PlayerObject g_gamePlayer;


int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	DWORD fdwOldMode;
	GetConsoleMode(hStdin, &fdwOldMode);
	SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	CHAR_INFO *pBackScreenBuffer = TGE::CreateScreenBuffer();
	CHAR_INFO *pMapDataBuffer = TGE::CreateScreenBuffer();
	TGE::loadBufferBinary(pMapDataBuffer, "../../pub_res/1.map");
/*	g_cdPlayerPos.X = 15;
	g_cdPlayerPos.Y = 5;
	g_nInven_keyCount = 0;*/
	playerobject::Init(&g_gamePlayer, 15, 5);

	bool _bLoop = true;
	static int _nFSM = 0;
	while (_bLoop)
	{
		static char szCmdBuf[128];

		//입력처리
		switch (_nFSM)
		{

			//비동기모드
		case 0:
		{
			static DWORD cNumRead;
			static INPUT_RECORD irInputBuf[128];
			ReadConsoleInput(hStdin, irInputBuf, 128, &cNumRead);

			for (DWORD i = 0;i < cNumRead; i++)
			{
				//키보드 이벤트
				if (irInputBuf[i].EventType == KEY_EVENT)
				{

					if (irInputBuf[i].Event.KeyEvent.bKeyDown)
					{
						switch (irInputBuf[i].Event.KeyEvent.wVirtualKeyCode)
						{
							//커맨드 입력모드전환
						case VK_RETURN:
							_nFSM = 1;
							SetConsoleMode(hStdin, fdwOldMode);
							break;
						case VK_UP:
							sprintf_s(szCmdBuf, sizeof(szCmdBuf), "move 0 -1");
							break;
						case VK_DOWN:
							sprintf_s(szCmdBuf, sizeof(szCmdBuf), "move 0 1");
							break;
						case VK_LEFT:
							sprintf_s(szCmdBuf, sizeof(szCmdBuf), "move -1 0");
							break;
						case VK_RIGHT:
							sprintf_s(szCmdBuf, sizeof(szCmdBuf), "move 1 0");
							break;
						}
					}
				}
			}
		}
		break;

		//동기모드
		case 1:
		{
			TGE::setCursor(hStdout, 0, 0);
			TGE::setCursor(hStdout, 0, 26);
			printf_s("[                                                      ]");
			TGE::setCursor(hStdout, 0, 26);
			printf_s("[Command : ");
			gets_s(szCmdBuf, sizeof(szCmdBuf));
			_nFSM = 0;
			SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
		}
		break;

		default:
			break;

		}

		//커맨드 처리
		{
			char szTokenBuf[8][64];
			if (TGE::doTokenize(szCmdBuf, szTokenBuf) > 0)
			{
				if (!strcmp(szTokenBuf[0], "quit"))
				{
					_bLoop = false;
				}
				else if (!strcmp(szTokenBuf[0], "move"))
				{
					int _dx = atoi(szTokenBuf[1]);
					int _dy = atoi(szTokenBuf[2]);

					playerobject::move(&g_gamePlayer, pMapDataBuffer, _dx, _dy);
					
				}
				else if (!strcmp(szTokenBuf[0], "use"))
				{
					int _dx = atoi(szTokenBuf[1]);
					int _dy = atoi(szTokenBuf[2]);

					switch (playerobject::use(&g_gamePlayer, pMapDataBuffer, _dx, _dy))
					{
					case 0x00c0:
						printf_s("Open the door !");
							break;
					case 0x00f0:
						printf_s("탈출 성공 ! [GameOver]..");
						_bLoop = false;
						break;
					default:
						printf_s("Not door ..");
						break;
					}
				}
				else if (!strcmp(szTokenBuf[0], "get"))
				{
					int _dx = atoi(szTokenBuf[1]);
					int _dy = atoi(szTokenBuf[2]);

					if (playerobject::get(&g_gamePlayer, pMapDataBuffer, _dx, _dy) == 1)
					{
						printf_s("Find key !");
					}
					else
					{
						printf_s("Not find anything...");
					}
						
				}
				else if (!strcmp(szTokenBuf[0], "drop"))
				{

				}
				else if (!strcmp(szTokenBuf[0], "teleport"))			//35 16
				{
					int _x = atoi(szTokenBuf[1]);
					int _y = atoi(szTokenBuf[2]);

					g_gamePlayer.m_Position.X = _x;
					g_gamePlayer.m_Position.Y = _y;
				}

				szCmdBuf[0] = NULL;
			}

		}

		//배경다시그리기 처리
		memcpy_s(pBackScreenBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO), pMapDataBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO));

		//오브젝트 처리
		playerobject::DrawObject(&g_gamePlayer, pBackScreenBuffer);

		//랜더 (화면 갱신)
		memcpy_s(TGE::g_chiBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO), pBackScreenBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO));
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);

	}

	free(pBackScreenBuffer);
	free(pMapDataBuffer);

	return 0;
}