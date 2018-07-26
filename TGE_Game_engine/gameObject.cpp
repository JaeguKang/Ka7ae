#include"stdafx.h"
#include"../engine/irrlicht/include/irrlicht.h"
#include"../engine/tge.h"
#include"../engine/tge_sprite.h"
#include"gameObject.h"

namespace cs2018prj
{
	//공통속성
	void _Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbSpeed, tge_sprite::S_SPRITE_OBJECT *pSpr)
	{
		pObj->m_vPos = _pos;
		pObj->m_dbSpeed = _dbSpeed;
		pObj->m_dbAngle = 0;
		pObj->m_dbWorkTick = 0;
		pObj->m_nFSM = 0;
		pObj->m_pSprite = pSpr;
		pObj->m_bActive = false;
		pObj->m_pWepon = NULL;
		pObj->pTargetBuf = NULL;
	}

	//플레이어 오브젝트
	namespace playerObject
	{
		//베이스
		void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbSpeed, tge_sprite::S_SPRITE_OBJECT *pSpr)
		{
			_Init(pObj, _pos, _dbSpeed, pSpr);

			pObj->m_fpApply = cs2018prj::playerObject::Apply;
			pObj->m_fpRender = cs2018prj::playerObject::Render;
			//pObj->m_Spr = _spr;
		}

		//동작
		void Apply(S_GAMEOBJECT *pObj, double _deltaTick)
		{
			//마우스로조종.
			switch (pObj->m_nFSM)
			{
			case 0:
				break;
			case 1:
				pObj->m_bActive = true;
				pObj->m_nFSM = 10;
				break;
			case 10:			//stop
				pObj->m_nFSM++;
				break;
			case 11:
				if (TGE::input::g_KeyTable[VK_SPACE])
				{
					pObj->m_nFSM = 20;
				}
			//방향키동작
				{
					if (TGE::input::g_KeyTable[VK_RIGHT])
					{
						pObj->m_vPos.X += (pObj->m_dbSpeed * _deltaTick);
					}

					if (TGE::input::g_KeyTable[VK_LEFT])
					{
						pObj->m_vPos.X -= (pObj->m_dbSpeed * _deltaTick);
					}

					if (TGE::input::g_KeyTable[VK_UP])
					{
						pObj->m_vPos.Y -= (pObj->m_dbSpeed * _deltaTick);
					}

					if (TGE::input::g_KeyTable[VK_DOWN])
					{
						pObj->m_vPos.Y += (pObj->m_dbSpeed * _deltaTick);
					}

					if (TGE::input::g_KeyTable['F'])
					{
						if (pObj->m_pWepon)
						{
							S_GAMEOBJECT *pWepon = (S_GAMEOBJECT *)pObj->m_pWepon;
							if (pWepon->m_nFSM == 0)						//슬립상태에서만 발사, 연사안됨.
							{
								pWepon->m_nFSM = 10;
								pWepon->m_vPos.X = pObj->m_vPos.X;
								pWepon->m_vPos.Y = pObj->m_vPos.Y - 2;
							}

						}
					}
				}
				break;
			case 20:		//move
			{
				irr::core::vector2df vTarget = irr::core::vector2df(TGE::input::g_cdMousePos.X, TGE::input::g_cdMousePos.Y);	//타켓포지션
				irr::core::vector2df vDir = vTarget - pObj->m_vPos;																//현포와 타포 사이의 벡터를구함.
				if (vDir.getLength() < 1)
				{
					pObj->m_nFSM = 0;
				}
				else
				{
					vDir.normalize();
					pObj->m_vPos += irr::core::vector2df(vDir.X * _deltaTick * pObj->m_dbSpeed, vDir.Y * _deltaTick*pObj->m_dbSpeed);
				}

			}
			break;
			case 100:
				pObj->m_bActive = false;
				pObj->m_nFSM = 101;
				break;
			case 101:
				break;
			default:
				break;
			}

		}

		//출력
		void Render(S_GAMEOBJECT *pObj, CHAR_INFO *pTargetBuf)
		{
			//TGE::setCharacter(pTargetBuf, pObj->m_posx, pObj->m_posy, pObj->m_Spr.Char.UnicodeChar, pObj->m_Spr.Attributes);
			if (pObj->m_bActive)
			{
				tge_sprite::put(pObj->m_pSprite,
					irr::core::round32(pObj->m_vPos.X + pObj->m_translation.X),
					irr::core::round32(pObj->m_vPos.Y + pObj->m_translation.Y), pTargetBuf);
			}

		}

		void Activate(S_GAMEOBJECT *pObj)
		{
			pObj->m_nFSM = 1;
		}
	}

	//적 오브젝트
	namespace alienObject
	{
		//베이스
		void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbSpeed, tge_sprite::S_SPRITE_OBJECT *pSpr)
		{
			_Init(pObj, _pos, _dbSpeed, pSpr);

			pObj->m_fpApply = cs2018prj::alienObject::Apply;
			pObj->m_fpRender = cs2018prj::playerObject::Render;
			//pObj->m_Spr = _spr;
		}

		//동작
		void Apply(S_GAMEOBJECT *pObj, double _deltaTick)
		{
			pObj->m_dbWorkTick += _deltaTick;
			switch (pObj->m_nFSM)
			{
				//sleep
			case 0:
				break;
				//감시
			case 10:
			{
				pObj->m_bActive = true;
				pObj->m_nFSM++;
				pObj->m_dbWorkTick = 0;
			}
			break;
			case 11:
			{
				irr::core::vector2df _vdir(1, 0);
				_vdir *= pObj->m_dbSpeed;
				_vdir *= _deltaTick;
				_vdir.rotateBy(pObj->m_dbAngle);
				pObj->m_vPos += _vdir;
				if (pObj->m_dbWorkTick > 3.5)
				{
					pObj->m_dbAngle += 180;
					pObj->m_dbWorkTick = 0;
				}
			}
			break;
			//추격
			case 20:
				break;
			case 100:
				pObj->m_bActive = false;
				pObj->m_nFSM = 0;
				break;
			case 101:
				break;
			default:
				break;
			}

		}

		void Activate(S_GAMEOBJECT *pObj)
		{
			pObj->m_nFSM = 10;
		}
	}

	//공격 오브젝트
	namespace attackObject
	{
		//적 공격
		namespace claw
		{

		}

		//플레이어공격
		namespace fire
		{
			void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbSpeed, tge_sprite::S_SPRITE_OBJECT *pSpr)
			{
				_Init(pObj, _pos, _dbSpeed, pSpr);
				pObj->m_fpApply = cs2018prj::attackObject::fire::Apply;
				pObj->m_fpRender = cs2018prj::playerObject::Render;
			}

			void Apply(S_GAMEOBJECT *pObj, double _deltaTick)
			{
				pObj->m_dbWorkTick += _deltaTick;
				switch (pObj->m_nFSM)
				{
				case 0:
					break;
				case 10:
					pObj->m_bActive = true;
					pObj->m_nFSM++;
					pObj->m_dbWorkTick = 0;
					break;
				case 11:
				{
					//10초간 투사체가 유지되면 100번으로
					if (pObj->m_dbWorkTick > 10)
					{
						pObj->m_nFSM = 100;
					}
					else
					{
						irr::core::vector2df _vdir(1, 0);
						_vdir *= pObj->m_dbSpeed;
						_vdir *= _deltaTick;
						pObj->m_vPos += _vdir;
					}
				}
				break;
				//투사체를 제거 후 0번으로 
				case 100:
					pObj->m_bActive = false;
					pObj->m_nFSM = 0;
					break;
				default:
					break;
				}
			}

			void Activate(S_GAMEOBJECT *pObj)
			{
				pObj->m_nFSM = 10;
			}
		}
	}

	namespace objMng
	{

		void add(S_OBJECT_MNG *pObj, S_GAMEOBJECT *pGameObj)
		{
			pObj->m_pListObject[pObj->m_nIndex++] = pGameObj;
		}
		void applyAll(S_OBJECT_MNG *pObj, double _deltaTick)
		{
			for (int i = 0;i < pObj->m_nIndex;i++)
			{
				pObj->m_pListObject[i]->m_fpApply(pObj->m_pListObject[i], _deltaTick);
			}
		}
		void renderAll(S_OBJECT_MNG *pObj, CHAR_INFO *pBuf)
		{
			for (int i = 0;i < pObj->m_nIndex;i++)
			{
				pObj->m_pListObject[i]->m_fpRender(pObj->m_pListObject[i], pBuf);
			}
		}

		void clearAll(S_OBJECT_MNG *pObj)
		{
			for (int i = 0;i < pObj->m_nIndex;i++)
			{
				if (pObj->m_pListObject[i] != NULL)
				{
					free(pObj->m_pListObject[i]);
				}
			}
		}
	}


}