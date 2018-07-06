#pragma once


void setCursor(HANDLE handle, int x, int y);
void setCharacter(CHAR_INFO *pBuf, int x, int y, WCHAR code, WCHAR attr);
void clearScreenBuffer(CHAR_INFO *pBuf);
void updateBuffer(HANDLE handle, CHAR_INFO *pBuf);

extern CHAR_INFO g_chiBuffer[];