// exam05.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//																			마우스 키보드 입력받기

#include "stdafx.h"


int main()
{
	HANDLE hStdin;
	DWORD fdwSaveOldMode;
	DWORD cNumRead, fdwMode;
	INPUT_RECORD irInBuf[128];										//입력받은 키 값을 순차적으로 처리하기 위한 버퍼.(배열)

	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hStdin, &fdwSaveOldMode);						//에디터모드 저장.

	//마우스모드 설정
	fdwMode = ENABLE_EXTENDED_FLAGS;
	SetConsoleMode(hStdin, fdwMode);								//에디터모드 비활성화.

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;				//마우스모드 활성화
	SetConsoleMode(hStdin, fdwMode);

	bool bLoop = true;
	while (bLoop)
	{
		ReadConsoleInput(hStdin, irInBuf, sizeof(irInBuf)/sizeof(INPUT_RECORD), &cNumRead);

		for (DWORD i = 0;i < cNumRead;i++)
		{
			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT:
			{
				if (irInBuf->Event.KeyEvent.bKeyDown)
				{
					printf_s("key pressed : %d\n", irInBuf[i].Event.KeyEvent.wVirtualKeyCode);
				}
				else
				{
					if (irInBuf[i].Event.KeyEvent.wVirtualKeyCode == 81)						//81 = q 누르면 종료.
					{
						bLoop = false;
					}
					printf_s("key released : %d\n", irInBuf[i].Event.KeyEvent.wVirtualKeyCode);
				}
				
			}
			break;
			case MOUSE_EVENT:
			{
				if (irInBuf[i].Event.MouseEvent.dwButtonState == 1)
				{
					printf_s("%d %d \n", irInBuf[i].Event.MouseEvent.dwMousePosition.X, irInBuf[i].Event.MouseEvent.dwMousePosition.Y);
				}

				/*printf_s("%d %d\n", irInBuf[i].Event.MouseEvent.dwButtonState, irInBuf[i].Event.MouseEvent.dwEventFlags);		키에 해당하는 아스키코드 출력*/
			}
				break;
			default:
				break;
			}
		}

		//for (int i = 0;i < cNumRead;i++)
		//{
		//	printf_s("%d \n", irInBuf[i].EventType);			키에 해당하는 아스키코드 출력
		//}
	}

	SetConsoleMode(hStdin, fdwSaveOldMode);		//에디터 모드 활성화.

    return 0;
}

