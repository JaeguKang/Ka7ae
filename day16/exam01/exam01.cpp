//TGE skeleton 
#include "stdafx.h"
#include "../../engine/tge.h"
#include"../../engine/tge_sprite.h"
#include"../gameObject.h"
//#include "gameobject.h"


int main()
{

	HANDLE hStdout = NULL;
	TGE::startTGE(&hStdout);

	CHAR_INFO *pBakBuffer = TGE::CreateScreenBuffer();
	CHAR_INFO *pMapDataBuffer = TGE::CreateScreenBuffer();

	//리소스 로딩 
	//플레이어
	TGE::loadBufferBinary(pMapDataBuffer, "../../pub_res/lv1.map");

	tge_sprite::S_SPRITE_OBJECT sprMainInWhite;
	tge_sprite::Init(&sprMainInWhite);
	tge_sprite::load(&sprMainInWhite, "../../pub_res/miw.spr");

	//alien
	tge_sprite::S_SPRITE_OBJECT sprAlien;
	tge_sprite::Init(&sprAlien);
	tge_sprite::load(&sprAlien, "../../pub_res/alien.spr");

	//active
	tge_sprite::S_SPRITE_OBJECT sprClaw;
	tge_sprite::Init(&sprClaw);
	tge_sprite::load(&sprClaw, "../../pub_res/cross.spr");

	//fire
	tge_sprite::S_SPRITE_OBJECT sprFire;
	tge_sprite::Init(&sprFire);
	tge_sprite::load(&sprFire, "../../pub_res/fire.spr");

	//게임오브잭트 생성 
	cs2018prj::playerObject::S_GAMEOBJECT playerObj;							//플레이어
	cs2018prj::attackObject_claw::S_GAMEOBJECT alienClaw;						//에일리언공격
	cs2018prj::alienObject::S_GAMEOBJECT alienObj;								//에일리언
	cs2018prj::attackObject_frameBurster::S_GAMEOBJECT fireObj;					//플레이어공격

	//플레이어
	cs2018prj::playerObject::Init(&playerObj, 10, 10, 8, &sprMainInWhite);
	playerObj.m_translation = irr::core::vector2df(-1, -3);
	playerObj.m_pWepon = &fireObj;

	//에일리언
	cs2018prj::alienObject::Init(&alienObj, 50, 8, 5, &sprAlien);
	alienObj.m_translation = irr::core::vector2df(-1, -3);
	alienObj.m_pTargetObj = &playerObj;
	alienObj.m_pWepon = &alienClaw;

	//에일리언공격
	cs2018prj::attackObject_claw::Init(&alienClaw, 50, 8, 5, &sprClaw);
	alienClaw.m_translation = irr::core::vector2df(-1, -2);
	alienClaw.m_pTargetObj = &playerObj;

	//플레이어공격
	cs2018prj::attackObject_frameBurster::Init(&fireObj, 0, 0, 10, &sprFire);
	fireObj.m_translation = irr::core::vector2df(-1, -1);
	fireObj.m_pTargetObj = &alienObj;


	bool _bLoop = true;
	static int _nFSM = 0;
	UINT64 _oldTick = TGE::util::GetTimeMs64();

	while (_bLoop)
	{
		UINT64 _curTick = TGE::util::GetTimeMs64();
		UINT64 _deltaTick = _curTick - _oldTick;
		_oldTick = _curTick;

		double _dbDeltaTick = (double)(_deltaTick) / 1000.0;

		static char szCmdBuf[128];
		//입력 처리 
		switch (_nFSM) {
		case 0:
			if (TGE::input::g_KeyTable[VK_RETURN]) {
				_nFSM = 1;
				TGE::input::setEditMode();
			}
			break;
		case 1: //동기  모드
			TGE::setCursor(hStdout, 0, 0);
			TGE::setCursor(hStdout, 0, 26);
			printf_s("                                                 ]");
			TGE::setCursor(hStdout, 0, 26);
			printf_s("[cmd >");
			gets_s(szCmdBuf, sizeof(szCmdBuf));
			_nFSM = 0;
			TGE::input::setNormalMode();
			TGE::input::g_KeyTable[VK_RETURN] = 0;
			_oldTick = TGE::util::GetTimeMs64();
			break;
		}
		//커멘드 처리..
		{
			char szTokenBuf[8][64];
			if (TGE::doTokenize(szCmdBuf, szTokenBuf) > 0) {
				if (!strcmp(szTokenBuf[0], "quit")) {
					_bLoop = false;
				}
			}
			else if (!strcmp(szTokenBuf[0], "claw"))
			{
				alienClaw.m_nFSM = 10;
				//alienClaw.m_bActive = true;
				alienClaw.m_posx = atoi(szTokenBuf[1]);
				alienClaw.m_posy = atoi(szTokenBuf[2]);
			}
			else if (!strcmp(szTokenBuf[0], "fire"))
			{
				fireObj.m_nFSM = 10;
				fireObj.m_posx = playerObj.m_posx;
				fireObj.m_posy = playerObj.m_posy - 2;
				fireObj.m_pTargetObj = &alienObj;

			}
			szCmdBuf[0] = 0x00;
		}

		//ai
		cs2018prj::playerObject::Apply(&playerObj, _dbDeltaTick);
		cs2018prj::alienObject::Apply(&alienObj, _dbDeltaTick);
		cs2018prj::attackObject_claw::Apply(&alienClaw, _dbDeltaTick);
		cs2018prj::attackObject_frameBurster::Apply(&fireObj, _dbDeltaTick);


		//랜더링 전처리
		TGE::CopyScreenBuffer(pBakBuffer, pMapDataBuffer);
		cs2018prj::playerObject::Render(&playerObj, pBakBuffer);
		cs2018prj::alienObject::Render(&alienObj, pBakBuffer);
		cs2018prj::attackObject_claw::Render(&alienClaw, pBakBuffer);
		cs2018prj::attackObject_frameBurster::Render(&fireObj, pBakBuffer);

		//랜더 (화면 갱신)
		TGE::CopyScreenBuffer(TGE::g_chiBuffer, pBakBuffer);
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);
	}

	free(pBakBuffer);
	free(pMapDataBuffer);
	tge_sprite::Release(&sprMainInWhite);
	tge_sprite::Release(&sprAlien);
	tge_sprite::Release(&sprClaw);
	//free(sprAlien.m_pSpriteBuf);
	//free(sprMainInWhite.m_pSpriteBuf);
	//free(sprClaw.m_pSpriteBuf);
	TGE::endTGE();

	return 0;

}