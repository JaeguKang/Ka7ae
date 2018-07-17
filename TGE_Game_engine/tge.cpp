#include"stdafx.h"
#include"tge.h"
//#include"../day15/exam04/gameObject.h"

//80x25


namespace TGE
{

	CHAR_INFO g_chiBuffer[SCREEN_BUF_SIZE];


	//Ŀ���̵��Լ�
	void setCursor(HANDLE handle, int x, int y)
	{
		COORD _pos;
		_pos.X = x;
		_pos.Y = y;
		SetConsoleCursorPosition(handle, _pos);
	}

	//ĳ���� ��� �Լ� 
	void setCharacter(CHAR_INFO *pBuf, int x, int y, WCHAR code, WORD attr)
	{
		//chiBuffer[(80 * 5) + 5].Char.UnicodeChar = TEXT('A');
		pBuf[(80 * y) + x].Char.UnicodeChar = code;
		pBuf[(80 * y) + x].Attributes = attr;
	}


	CHAR_INFO *getCharacter(CHAR_INFO *pBuf, int x, int y)
	{
		return &(pBuf[(80 * y) + x]);
	}

	//��ũ�� Ŭ���� ver2.
	void clearScreenBuffer(CHAR_INFO *pBuf, WCHAR _wCode, WORD _wAttr)
	{
		for (int i = 0;i < SCREEN_BUF_SIZE;i++)
		{
			pBuf[i].Char.UnicodeChar = _wCode;//0x20;//9673;//9678
			pBuf[i].Attributes = _wAttr;//0x009f;
		}
	}

	void CopyScreenBuffer( CHAR_INFO *pBufdest, CHAR_INFO *pBufsrc)
	{
		memcpy_s(pBufdest, SCREEN_BUF_SIZE * sizeof(CHAR_INFO),
			pBufsrc, SCREEN_BUF_SIZE * sizeof(CHAR_INFO));
	}

	//��ũ�� Ŭ���� �Լ�
	void clearScreenBuffer(WCHAR _wCode, WORD _wAttr)
	{
		CHAR_INFO *pBuf = g_chiBuffer;
		clearScreenBuffer(pBuf, _wCode, _wAttr);
	}

	//������Ʈ �Լ�
	void updateBuffer(HANDLE handle, CHAR_INFO *pBuf)
	{
		COORD coordBufSize;
		COORD coordBufferCoord;
		coordBufSize.X = 80;
		coordBufSize.Y = 25;
		coordBufferCoord.X = 0;
		coordBufferCoord.Y = 0;

		SMALL_RECT destRect;
		destRect.Top = 0;
		destRect.Left = 0;
		destRect.Bottom = destRect.Top + coordBufSize.Y - 1;
		destRect.Right = destRect.Left + coordBufSize.X - 1;

		WriteConsoleOutput(handle, pBuf, coordBufSize, coordBufferCoord, &destRect);
	}

	//���ϴ� ��ġ�� �����ϴ� �Լ�
	void drawBox(CHAR_INFO *pBuf, int _posx, int _posy, int _width, int _height)
	{

		int x, y;


		/*int _posx = 10;
		int _posy = 10;
		int _width = 5;
		int _height = 3;*/

		for (y = 0;y < _height;y++)
		{
			for (x = 0;x < _width;x++)
			{
				setCharacter(g_chiBuffer, _posx + x, _posy + y, 0x20, 0x000f);
			}
		}


	}

	//���� ���� �׸��� �Լ�
	void drawLineH(int _x, int _y, int _nLength, WCHAR code, WORD attr)
	{
		//int _x = 10;
		//int _y = 10;
		//WCHAR code = 0x20;
		//WORD attr = 0x00c0;	//8 + 4 + 2 + 1		IRGB
		//int _nLength = 10;

		int i = 0;
		for (i = 0;i < _nLength;i++)
		{
			TGE::setCharacter(TGE::g_chiBuffer, _x + i, _y, code, attr);
		}
	}
	//���� ���� �׸��� �Լ�
	void drawLineV(int _x, int _y, int _nLength, WCHAR code, WORD attr)
	{
		int i = 0;
		for (i = 0;i < _nLength;i++)
		{
			TGE::setCharacter(TGE::g_chiBuffer, _x, _y + i, code, attr);
		}
	}

	//��ū ����� �Լ�
	int doTokenize(char *szBuf, char szBufToken[8][MAX_TOKEN_SIZE])
	{
		char *szpTemp;
		char *pNextToken = NULL;
		const char *pszDelimiter = " ";
		szpTemp = strtok_s(szBuf, pszDelimiter, &pNextToken);		//ù��°
		int _nTokenIndex = 0;
		while (szpTemp != NULL)
		{
			strcpy_s(szBufToken[_nTokenIndex], sizeof(szBufToken[_nTokenIndex]), szpTemp);
			_nTokenIndex++;
			szpTemp = strtok_s(NULL, pszDelimiter, &pNextToken);	//�ι�° ȣ��
		}

		return _nTokenIndex;
	}

	//���̺��Լ�
	int saveBufferBinary(CHAR_INFO *pBuf, const char *szFileName)
	{
		FILE *fp;
		fopen_s(&fp, szFileName, "w");
		fwrite(pBuf, SCREEN_BUF_SIZE * sizeof(CHAR_INFO), 1, fp);
		fclose(fp);

		return 0;
	}

	//�ε��Լ�
	int loadBufferBinary(CHAR_INFO *pBuf, const char *szFileName)
	{
		FILE *fp;
		fopen_s(&fp, szFileName, "r");
		fread_s(pBuf, SCREEN_BUF_SIZE * sizeof(CHAR_INFO), sizeof(CHAR_INFO), 2000, fp);
		fclose(fp);

		return 0;
	}

	CHAR_INFO *CreateScreenBuffer()
	{
		return (CHAR_INFO*)malloc(sizeof(CHAR_INFO)*SCREEN_BUF_SIZE);
	}

	//��������Ʈ
	void putSprite(int posx, int posy, int destw, int desth, int srcw, int srch, CHAR_INFO *pDest, CHAR_INFO *pSrc)		//��ǥ(x, y), ������� ũ��(dest), ������ ũ��(src), ���������, ��������
	{

		int _x;
		int _y;
		_x = posx;	//�����ġ
		_y = posy;
		int src_buf_size = srcw * srch;
		int nStep = 0;
		int _i = 0;
		for (int i = 0;i < src_buf_size;i++)
		{
			nStep = i / srcw;

			pDest[_i + (nStep * SCREEN_WIDTH) + (_y * SCREEN_WIDTH + _x)] = pSrc[i];
			_i++;
			_i %= srcw;
		}

	}

	void putSprite(int posx, int posy, int srcw, int srch, CHAR_INFO *pDest, CHAR_INFO *pSrc)		//��ǥ(x, y), ������ ũ��(src), ���������, ��������
	{
		putSprite(posx, posy, SCREEN_WIDTH, 25, srcw, srch, pDest, pSrc);
	}

	//
	namespace input
	{
		char g_KeyTable[1024];
		DWORD _oldInputMode;
		HANDLE hStdin;
		COORD g_cdMousePos;

		DWORD WINAPI MyThreadFunction(LPVOID IpParam)
		{
			hStdin = GetStdHandle(STD_INPUT_HANDLE);
			DWORD _NumRead;
			INPUT_RECORD irInBuf[128];

			GetConsoleMode(hStdin, &_oldInputMode);
			SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

			

			while (1)
			{
				ReadConsoleInput(hStdin, irInBuf, 128, &_NumRead);

				for (DWORD i = 0;i < _NumRead;i++)
				{
					if (irInBuf[i].EventType == KEY_EVENT)
					{
						if (irInBuf[i].Event.KeyEvent.bKeyDown)
						{
							g_KeyTable[irInBuf[i].Event.KeyEvent.wVirtualKeyCode] = 1;

						}
						else
						{
							g_KeyTable[irInBuf[i].Event.KeyEvent.wVirtualKeyCode] = 0;
						}
					}

					else if (irInBuf[i].EventType == MOUSE_EVENT)
					{
						g_cdMousePos =
						{
							irInBuf[i].Event.MouseEvent.dwMousePosition.X,
							irInBuf[i].Event.MouseEvent.dwMousePosition.Y
						};
					}
				}

				Sleep(1);
			}

			SetConsoleMode(hStdin, _oldInputMode);

			return 0;
		}

		void setEditMode()
		{
			SetConsoleMode(hStdin, _oldInputMode);

		}

		void setNormalMode()
		{
			SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
		}

	}

	DWORD dwThreadId_ReadInput;
	HANDLE hThread_ReadInput;

	void startTGE(HANDLE *phStdout)
	{
		*phStdout = GetStdHandle(STD_OUTPUT_HANDLE);

		TGE::clearScreenBuffer(0x20, 0x0090);

		hThread_ReadInput = CreateThread(NULL, 0, input::MyThreadFunction, NULL, 0, &dwThreadId_ReadInput);
	} 

	void endTGE()
	{

	}

	namespace util
	{
		UINT64 GetTimeMs64()
		{
			FILETIME ft;
			LARGE_INTEGER li;

			GetSystemTimeAsFileTime(&ft);
			li.LowPart = ft.dwLowDateTime;
			li.HighPart = ft.dwHighDateTime;

			UINT64 ret_value = li.QuadPart;
			ret_value -= 116444736000000000LL;
			ret_value /= 10000;

			return ret_value;
		}

	}
}