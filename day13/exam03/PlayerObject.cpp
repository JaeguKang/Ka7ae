#include"stdafx.h"

#include"../../engine/tge.h"
#include"PlayerObject.h"

namespace playerobject
{
	void Init(S_PlayerObject *pObj, int _sx, int _sy)
	{
		pObj->m_Position.X = _sx;
		pObj->m_Position.Y = _sy;
		pObj->m_nKeyCount = 0;
	}
	//무브무브
	void move(S_PlayerObject *pObj, CHAR_INFO *pMapBuf, int _dx, int _dy)
	{
		int _check_x = pObj->m_Position.X + _dx;
		int _check_y = pObj->m_Position.Y + _dy;

		CHAR_INFO *pCi = TGE::getCharacter(pMapBuf, _check_x, _check_y);

		if (pCi->Attributes == 0x0007)
		{
			pObj->m_Position.X = _check_x;
			pObj->m_Position.Y = _check_y;
		}
	}
	//열쇠줍기
	int get(S_PlayerObject *pObj, CHAR_INFO *pMapBuf, int _dx, int _dy)
	{
		int _check_x = pObj->m_Position.X + _dx;
		int _check_y = pObj->m_Position.Y + _dy;

		CHAR_INFO *pCi = TGE::getCharacter(pMapBuf, _check_x, _check_y);
		//열쇠 구분
		if (pCi->Attributes == 0x00b0)
		{
			pObj->m_nKeyCount++;
			//pMapDataBuffer[_check_y*SCREEN_WIDTH + _check_x].Attributes = 0x0007;
			TGE::setCharacter(pMapBuf, _check_x, _check_y, 0x20, 0x0007);
			return 1;
		}
		return 0;
		
	}
	//문열기
	int use(S_PlayerObject *pObj, CHAR_INFO *pMapBuf, int _dx, int _dy)
	{
		int _check_x = pObj->m_Position.X + _dx;
		int _check_y = pObj->m_Position.Y + _dy;

		CHAR_INFO *pCi = TGE::getCharacter(pMapBuf, _check_x, _check_y);

		int _nRt = pCi->Attributes;

		//문 구분
		if (pCi->Attributes == 0x00c0 || pCi->Attributes == 0x00f0)			//일반문	||		탈출문
		{
			pObj->m_nKeyCount--;
			TGE::setCharacter(pMapBuf, _check_x, _check_y, 0x20, 0x0007);
		}

		return _nRt;
	}

	void DrawObject(S_PlayerObject *pObj, CHAR_INFO *pMapBuf)
	{
		TGE::setCharacter(pMapBuf, pObj->m_Position.X, pObj->m_Position.Y, 0x41, 0x000f);
	}
}
