#pragma once

namespace TGE
{
	//Basic
	void setCursor(HANDLE handle, int x, int y);
	void setCharacter(CHAR_INFO *pBuf, int x, int y, WCHAR code, WORD attr);
	void clearScreenBuffer(WCHAR _wCode, WORD _wAttr);			//void clearScreenBuffer(CHAR_INFO *pBuf);
	void updateBuffer(HANDLE handle, CHAR_INFO *pBuf);

	//Draw
	void drawBox(int _posx, int _posy, int _width, int _height, WCHAR code, WORD attr);
	void drawLineH(int _x, int _y, int _nLength, WCHAR code, WORD attr);
	void drawLineV(int _x, int _y, int _nLength, WCHAR code, WORD attr);

	extern CHAR_INFO g_chiBuffer[];

	//��ƿ��Ƽ
	int doTokenize(char *szBuf, char szBufToken[8][16]);
}
