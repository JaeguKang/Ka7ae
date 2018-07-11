// exam02.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include"../../engine/tge.h"

//주인공
COORD g_cdPlayerPos;


int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	DWORD fdwOldMode;
	GetConsoleMode(hStdin, &fdwOldMode);
	SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	TGE::loadBufferBinary(TGE::g_chiBuffer, "../../pub_res/1.map");
	g_cdPlayerPos.X = 15;
	g_cdPlayerPos.Y = 5;

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
						switch (irInputBuf[i].Event.KeyEvent.wVirtualScanCode)
						{
						//커맨드 입력모드전환
						case 28:		
							_nFSM = 1;
							SetConsoleMode(hStdin, fdwOldMode);
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
					g_cdPlayerPos.X += _dx;
					g_cdPlayerPos.Y += _dy;
				}

				szCmdBuf[0] = NULL;
			}

		}

		//오브젝트 처리
		TGE::setCharacter(TGE::g_chiBuffer, g_cdPlayerPos.X, g_cdPlayerPos.Y, 0x41, 0x000f);

		//랜더 (화면 갱신)
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);


	}
	return 0;
}
