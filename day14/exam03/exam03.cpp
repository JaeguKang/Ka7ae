//TGE skeleton 
#include "stdafx.h"
#include "../../engine/tge.h"
#include"../../engine/tge_sprite.h"

struct S_GAME_OBJECT
{
	COORD m_cdPosition;
	tge_sprite::S_SPRITE_OBJECT m_SpriteObject;
	int m_nFSM;
};

int MaxWidthValue = 76;
int MinWidthValue = 0;
int MaxHeightValue = 14;
int MinHeightValue = 1;

void Apply(S_GAME_OBJECT *pObj)
{
	//S_GAME_OBJECT *pObj = &crossObj;


	switch (pObj->m_nFSM)
	{
	case 0:
		pObj->m_nFSM = 10;
		break;
	case 10:
		if (pObj->m_cdPosition.X < MaxWidthValue)
		{
			pObj->m_cdPosition.X += 1;
		}
		else
		{
			MaxWidthValue -= 3;
			pObj->m_nFSM = 20;
		}
		break;
	case 30:
		if (pObj->m_cdPosition.X > MinWidthValue)
		{
			pObj->m_cdPosition.X -= 1;
		}
		else
		{
			MinWidthValue += 3;
			pObj->m_nFSM = 40;
		}
		break;
	case 20:
		if (pObj->m_cdPosition.Y < MaxHeightValue)
		{
			pObj->m_cdPosition.Y += 1;
		}
		else
		{
			MaxHeightValue--;
			pObj->m_nFSM = 30;
		}
		break;
	case 40:
		if (pObj->m_cdPosition.Y > MinHeightValue)
		{
			pObj->m_cdPosition.Y -= 1;
		}
		else
		{
			MinHeightValue++;
			pObj->m_nFSM = 10;
		}
		break;
	default:
		break;
	}

}

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	DWORD fdwOldMode;
	GetConsoleMode(hStdin, &fdwOldMode);
	SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	TGE::clearScreenBuffer(0x20, 0x0090);

	CHAR_INFO *pBackDataBuf = TGE::CreateScreenBuffer();
	TGE::loadBufferBinary(pBackDataBuf, "../../pub_res/1.map");

	CHAR_INFO *pBackBuff = TGE::CreateScreenBuffer();
	S_GAME_OBJECT crossObj = { 0 };

	tge_sprite::load(&(crossObj.m_SpriteObject), "../../pub_res/cross.spr");

	bool _bLoop = true;
	static int _nFSM = 0;
	while (_bLoop)
	{
		static char szCmdBuf[128];

		////입력 처리 
		//switch (_nFSM) 
		//{
		//case 0: //비동기 모드
		//	static DWORD cNumRead;
		//	static INPUT_RECORD irInputBuf[128];
		//	ReadConsoleInput(hStdin, irInputBuf, 128, &cNumRead);

		//	for (DWORD i = 0; i < cNumRead; i++)
		//	{
		//		if (irInputBuf[i].EventType == KEY_EVENT)
		//		{
		//			if (irInputBuf[i].Event.KeyEvent.bKeyDown) 
		//			{
		//				switch (irInputBuf[i].Event.KeyEvent.wVirtualKeyCode) 
		//				{
		//				case VK_RETURN: //커멘드 입력 모드 전환 
		//					_nFSM = 1;
		//					SetConsoleMode(hStdin, fdwOldMode);
		//					break;
		//				}
		//			}
		//		}
		//	}
		//	break;
		//case 1: //동기  모드
		//	TGE::setCursor(hStdout, 0, 0);
		//	TGE::setCursor(hStdout, 0, 26);
		//	printf_s("                                                 ]");
		//	TGE::setCursor(hStdout, 0, 26);
		//	printf_s("[cmd >");
		//	gets_s(szCmdBuf, sizeof(szCmdBuf));
		//	_nFSM = 0;
		//	SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
		//	break;
		//}
		////커멘드 처리..
		//{
		//	char szTokenBuf[8][64];
		//	if (TGE::doTokenize(szCmdBuf, szTokenBuf) > 0) 
		//	{
		//		if (!strcmp(szTokenBuf[0], "quit"))
		//		{
		//			_bLoop = false;
		//		}

		//	}
		//	szCmdBuf[0] = 0x00;
		//}

		//ai
		Sleep(10);

		Apply(&crossObj);


		memcpy_s(pBackBuff, SCREEN_BUF_SIZE * sizeof(CHAR_INFO), pBackDataBuf, SCREEN_BUF_SIZE * sizeof(CHAR_INFO));

		tge_sprite::put(&(crossObj.m_SpriteObject), crossObj.m_cdPosition.X, crossObj.m_cdPosition.Y, pBackBuff);
		memcpy_s(TGE::g_chiBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO), pBackBuff, SCREEN_BUF_SIZE * sizeof(CHAR_INFO)); //빽버퍼를 전면으로 카피


		//랜더 (화면 갱신)
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);
	}

	SetConsoleMode(hStdin, fdwOldMode);

	free(pBackBuff);

	return 0;
}