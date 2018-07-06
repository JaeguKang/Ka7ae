#include"stdafx.h"

//80x25
#define SCREEN_BUF_SIZE 2000
#define SCREEN_WIDTH 80

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
void setCharacter(CHAR_INFO *pBuf, int x, int y, WCHAR code, WCHAR attr)
{
	//chiBuffer[(80 * 5) + 5].Char.UnicodeChar = TEXT('A');
	pBuf[(80 * y) + x].Char.UnicodeChar = code;
	pBuf[(80 * y) + x].Attributes = attr;
}


//Ŭ���� �Լ�
void clearScreenBuffer(CHAR_INFO *pBuf)
{
	for (int i = 0;i < SCREEN_BUF_SIZE;i++)
	{
		pBuf[i].Char.UnicodeChar = 9673;//9678
		pBuf[i].Attributes = 0x009f;
	}
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