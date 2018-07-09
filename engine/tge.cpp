#include"stdafx.h"

//80x25
#define SCREEN_BUF_SIZE 2000
#define SCREEN_WIDTH 80

namespace TGE
{
	CHAR_INFO g_chiBuffer[SCREEN_BUF_SIZE];

	//커서이동함수
	void setCursor(HANDLE handle, int x, int y)
	{
		COORD _pos;
		_pos.X = x;
		_pos.Y = y;
		SetConsoleCursorPosition(handle, _pos);
	}

	//캐릭터 출력 함수 
	void setCharacter(CHAR_INFO *pBuf, int x, int y, WCHAR code, WORD attr)
	{
		//chiBuffer[(80 * 5) + 5].Char.UnicodeChar = TEXT('A');
		pBuf[(80 * y) + x].Char.UnicodeChar = code;
		pBuf[(80 * y) + x].Attributes = attr;
	}


	//스크린 클리어 함수
	void clearScreenBuffer(WCHAR _wCode, WORD _wAttr)
	{
		CHAR_INFO *pBuf = g_chiBuffer;

		for (int i = 0;i < SCREEN_BUF_SIZE;i++)
		{
			pBuf[i].Char.UnicodeChar = _wCode;//0x20;//9673;//9678
			pBuf[i].Attributes = _wAttr;//0x009f;
		}
	}

	//업데이트 함수
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

	//원하는 위치에 삽입하는 함수
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

	//가로 세로 직선 그리기 함수
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

	void drawLineV(int _x, int _y, int _nLength, WCHAR code, WORD attr)
	{
		int i = 0;
		for (i = 0;i < _nLength;i++)
		{
			TGE::setCharacter(TGE::g_chiBuffer, _x, _y + i, code, attr);
		}
	}

	//토큰 만들기 함수
	int doTokenize(char *szBuf, char szBufToken[8][16])
	{
		char *szpTemp;
		char *pNextToken = NULL;
		const char *pszDelimiter = " ";
		szpTemp = strtok_s(szBuf, pszDelimiter, &pNextToken);		//첫번째
		int _nTokenIndex = 0;
		while (szpTemp != NULL)
		{
			strcpy_s(szBufToken[_nTokenIndex], 16, szpTemp);
			_nTokenIndex++;
			szpTemp = strtok_s(NULL, pszDelimiter, &pNextToken);	//두번째 호출
		}

		return _nTokenIndex;
	}

	

}
