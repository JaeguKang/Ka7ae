#include"stdafx.h"

#include"../../engine/tge.h"
#include"maptool.h"


void initMapTool(S_TGE_MAPTOOL *pObj)
{
	pObj->m_cdCurrentCursorPos.X = 40;
	pObj->m_cdCurrentCursorPos.Y = 12;
	pObj->m_wcCurrentBrushCode = 0x20;
	pObj->m_wCurrentBrushAttr = 0x00e0;
	
	pObj->m_cd_MCurrentCursorPos.X;
	pObj->m_cd_MCurrentCursorPos.Y;
}

//토큰처리
int parseCmd(S_TGE_MAPTOOL *pObj, char *szCmdBuf)
{
	static char szTokenBuf[8][MAX_TOKEN_SIZE];

	TGE::doTokenize(szCmdBuf, szTokenBuf);

	if (!strcmp(szTokenBuf[0], "quit"))
	{
		return 0;
	}
	//set
	else if (!strcmp(szTokenBuf[0], "set"))
	{
		int _xpos = atoi(szTokenBuf[1]);
		int _ypos = atoi(szTokenBuf[2]);
		WCHAR _code = (WCHAR)strtol(szTokenBuf[3], NULL, 16);
		WORD _attr = (WORD)strtol(szTokenBuf[4], NULL, 16);

		TGE::setCharacter(TGE::g_chiBuffer, _xpos, _ypos, _code, _attr);
	}

	//moveCursor on/off
	else if (!strcmp(szTokenBuf[0], "moveCursor") || !strcmp(szTokenBuf[0], "moveCursorEnd"))
	{

		static COORD _oldPos = { -1,-1 };
		static WCHAR _oldCode = -1;
		static WORD _oldAttr = -1;

		if (!strcmp(szTokenBuf[0], "moveCursorEnd"))
		{
			_oldPos.X = -1;
		}
		else
		{
			if (_oldPos.X >= 0)
			{
				TGE::setCharacter(TGE::g_chiBuffer, _oldPos.X, _oldPos.Y, _oldCode, _oldAttr);
			}
			//이동 전 값은 대피시킴
			_oldPos.X = pObj->m_cdCurrentCursorPos.X;
			_oldPos.Y = pObj->m_cdCurrentCursorPos.Y;
			CHAR_INFO *oldInfo = TGE::getCharacter(TGE::g_chiBuffer, _oldPos.X, _oldPos.Y);
			_oldCode = oldInfo->Char.UnicodeChar;
			_oldAttr = oldInfo->Attributes;


			pObj->m_cdCurrentCursorPos.X = atoi(szTokenBuf[1]);
			pObj->m_cdCurrentCursorPos.Y = atoi(szTokenBuf[2]);
			WCHAR _code = (WCHAR)strtol(szTokenBuf[3], NULL, 16);
			WORD _attr = (WORD)strtol(szTokenBuf[4], NULL, 16);

			TGE::setCharacter(TGE::g_chiBuffer, pObj->m_cdCurrentCursorPos.X, pObj->m_cdCurrentCursorPos.Y, _code, _attr);
		}

	}

	//clear
	else if (!strcmp(szTokenBuf[0], "clear"))
	{
		TGE::clearScreenBuffer(0x20, 0x0007);
	}

	//브러쉬상태 변화 (문자, 컬러)
	else if (!strcmp(szTokenBuf[0], "changeBrush"))
	{
		WCHAR _code = (WCHAR)strtol(szTokenBuf[1], NULL, 16);
		WORD _attr = (WORD)strtol(szTokenBuf[2], NULL, 16);

		pObj->m_wcCurrentBrushCode = _code;
		pObj->m_wCurrentBrushAttr = _attr;
	}

	//save
	else if (!strcmp(szTokenBuf[0], "save"))
	{
		TGE::saveBufferBinary(TGE::g_chiBuffer, szTokenBuf[1]);
	}
	
	//load
	else if (!strcmp(szTokenBuf[0], "load"))
	{
		TGE::loadBufferBinary(TGE::g_chiBuffer, szTokenBuf[1]);
	}

	else if (!strcmp(szTokenBuf[0], "HaveMouseControl"))
	{

	}
	return 1;
}
