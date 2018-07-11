// exam02.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include"../../engine/tge.h"
#include"MapTool.h"

S_TGE_MAPTOOL g_MapToolObject;
enum { MODE_BRUSH_DRAW = 0, MODE_CMD_INPUT, MODE_BRUSH_MOVE, MODE_BRUSH_M_MODE };

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	DWORD fdwOldMode;

	GetConsoleMode(hStdin, &fdwOldMode);
	SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	initMapTool(&g_MapToolObject);
	int nFSM = MODE_BRUSH_DRAW;
	TGE::setCursor(hStdout, 0, 0);
	TGE::setCursor(hStdout, 0, 26);

	TGE::clearScreenBuffer(0x2e, 0x0007);

	while (1)
	{
		static char szCmdBuf[32];

		switch (nFSM)
		{
			//드로우모드
		case MODE_BRUSH_DRAW:
		{
			//비동기키입력
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
						TGE::setCursor(hStdout, 0, 0);
						TGE::setCursor(hStdout, 0, 26);
						printf_s("[                                                      ]");
						TGE::setCursor(hStdout, 0, 26);
						printf_s("%d", irInputBuf[i].Event.KeyEvent.wVirtualScanCode);

						//방향키를 입력하면 커맨드를 자동으로 함수에 넘겨줌
						switch (irInputBuf[i].Event.KeyEvent.wVirtualScanCode)
						{
						case 28:		//커맨드 입력모드전환
							nFSM = MODE_CMD_INPUT;
							SetConsoleMode(hStdin, fdwOldMode);
							break;
						case 72:		//up
							g_MapToolObject.m_cdCurrentCursorPos.Y -= 1;
							sprintf_s(szCmdBuf, 32, "set %d %d %4x %4x", g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y,
								g_MapToolObject.m_wcCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
							break;
						case 80:		//down
							g_MapToolObject.m_cdCurrentCursorPos.Y += 1;
							sprintf_s(szCmdBuf, 32, "set %d %d %4x %4x", g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y,
								g_MapToolObject.m_wcCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
							break;
						case 75:		//left
							g_MapToolObject.m_cdCurrentCursorPos.X -= 1;
							sprintf_s(szCmdBuf, 32, "set %d %d %4x %4x", g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y,
								g_MapToolObject.m_wcCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
							break;
						case 77:		//right
							g_MapToolObject.m_cdCurrentCursorPos.X += 1;
							sprintf_s(szCmdBuf, 32, "set %d %d %4x %4x", g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y,
								g_MapToolObject.m_wcCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
							break;
							//무브모드 전환 m
						case 50:
							nFSM = MODE_BRUSH_MOVE;
						default:
							break;
						}
					}
				}
				//마우스 이벤트
				else if (irInputBuf[i].EventType == MOUSE_EVENT)
				{
					TGE::setCursor(hStdout, 0, 0);
					TGE::setCursor(hStdout, 0, 26);
					printf_s("[                                                      ]");
					TGE::setCursor(hStdout, 0, 26);

					if (irInputBuf[i].Event.MouseEvent.dwButtonState == 1)
					{
						int _posx = irInputBuf[i].Event.MouseEvent.dwMousePosition.X;
						int _posy = irInputBuf[i].Event.MouseEvent.dwMousePosition.Y;
						sprintf_s(szCmdBuf, 32, "set %d %d %4x %4x", _posx, _posy,
							g_MapToolObject.m_wcCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
						//printf_s("%d %d \n", irInputBuf[i].Event.MouseEvent.dwMousePosition.X, irInputBuf[i].Event.MouseEvent.dwMousePosition.Y);
						g_MapToolObject.m_cdCurrentCursorPos.X = _posx;
						g_MapToolObject.m_cdCurrentCursorPos.Y = _posy;
					}
				}
			}
		}
		break;
		//스크립트입력모드
		case MODE_CMD_INPUT:
		{
			TGE::setCursor(hStdout, 0, 0);
			TGE::setCursor(hStdout, 0, 26);
			printf_s("[                                                      ]");
			TGE::setCursor(hStdout, 0, 26);
			printf_s("[Command : ");
			gets_s(szCmdBuf, sizeof(szCmdBuf));
			nFSM = 0;
			SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
		}
		break;
		//무브모드
		case MODE_BRUSH_MOVE:
		{
			static DWORD cNumRead;
			static INPUT_RECORD irInputBuf[128];
			ReadConsoleInput(hStdin, irInputBuf, 128, &cNumRead);

			for (DWORD i = 0;i < cNumRead; i++)
			{

				if (irInputBuf[i].EventType == KEY_EVENT)
				{

					if (irInputBuf[i].Event.KeyEvent.bKeyDown)
					{
						TGE::setCursor(hStdout, 0, 0);
						TGE::setCursor(hStdout, 0, 26);
						printf_s("[                                                      ]");
						TGE::setCursor(hStdout, 0, 26);
						printf_s("Move mode %d", irInputBuf[i].Event.KeyEvent.wVirtualScanCode);


						switch (irInputBuf[i].Event.KeyEvent.wVirtualScanCode)
						{
						case 28:		//커맨드 입력모드전환
							nFSM = MODE_CMD_INPUT;
							SetConsoleMode(hStdin, fdwOldMode);
						case 72:
						{
							g_MapToolObject.m_cdCurrentCursorPos.Y -= 1;
							sprintf_s(szCmdBuf, 32, "moveCursor %d %d %4x %4x", g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y,
								g_MapToolObject.m_wcCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
						}
						break;
						case 80:
						{
							g_MapToolObject.m_cdCurrentCursorPos.Y += 1;
							sprintf_s(szCmdBuf, 32, "moveCursor %d %d %4x %4x", g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y,
								g_MapToolObject.m_wcCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
						}
						break;
						case 75:
						{
							g_MapToolObject.m_cdCurrentCursorPos.X -= 1;
							sprintf_s(szCmdBuf, 32, "moveCursor %d %d %4x %4x", g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y,
								g_MapToolObject.m_wcCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
						}
						break;
						case 77:
						{
							g_MapToolObject.m_cdCurrentCursorPos.X += 1;
							sprintf_s(szCmdBuf, 32, "moveCursor %d %d %4x %4x", g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y,
								g_MapToolObject.m_wcCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
						}
						break;
						//드로우모드 전환 d
						case 32:
							nFSM = MODE_BRUSH_DRAW;
							strcpy_s(szCmdBuf, 32, "moveCursorEnd");
							break;
						default:
							break;
						}
					}
				}
			}
		}
		break;
		//마우스모드
		//case MODE_BRUSH_M_MODE:
		//{
		//	static DWORD cNumRead;
		//	static INPUT_RECORD irInputBuf[128];
		//	ReadConsoleInput(hStdin, irInputBuf, 128, &cNumRead);

		//	for (DWORD i = 0;i < cNumRead;i++)
		//	{
		//		if (irInputBuf[i].EventType == MOUSE_EVENT)
		//		{
		//			if (irInputBuf[i].Event.MouseEvent.dwButtonState == 1)
		//			{
		//				printf_s("%d %d \n", irInputBuf[i].Event.MouseEvent.dwMousePosition.X, irInputBuf[i].Event.MouseEvent.dwMousePosition.Y);
		//			}
		//		}
		//	}
		//}
		default:
			break;
		}




		//커맨드파싱
		if (!parseCmd(&g_MapToolObject, szCmdBuf)) break;

		//TGE::setCharacter(TGE::g_chiBuffer, g_cdCurrentCursorPos.X, g_cdCurrentCursorPos.Y, 0x20, 0x00e0);

		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);
	}



	return 0;
}

