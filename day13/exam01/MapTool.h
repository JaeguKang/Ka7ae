#pragma once


struct S_TGE_MAPTOOL
{
	COORD m_cdCurrentCursorPos;
	COORD m_cd_MCurrentCursorPos;
	WCHAR m_wcCurrentBrushCode;
	WORD m_wCurrentBrushAttr;


};

void initMapTool(S_TGE_MAPTOOL *pObj);
int parseCmd(S_TGE_MAPTOOL *pObj, char *szCmdBuf);
