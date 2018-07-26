#pragma once

																				//함수포인터 442
namespace cs2018prj
{
	struct S_GAMEOBJECT
	{
		irr::core::vector2df m_vPos;
		double m_dbSpeed;
		double m_dbAngle;
		double m_dbWorkTick;
		//double m_posx, m_posy;
		void *m_pWepon;
		//CHAR_INFO m_Spr;
		tge_sprite::S_SPRITE_OBJECT *m_pSprite;
		irr::core::vector2df m_translation;
		void *pTargetBuf;
		int m_nFSM;
		bool m_bActive;
		void(*m_fpClone)(S_GAMEOBJECT *pObj);
		void(*m_fpApply)(S_GAMEOBJECT *, double);
		void(*m_fpRender)(S_GAMEOBJECT *, CHAR_INFO *);
	};


	namespace playerObject
	{
		struct S_SUBOBJECT
		{

		};

		void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbSpeed, tge_sprite::S_SPRITE_OBJECT *pSpr);
		void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
		void Render(S_GAMEOBJECT *pObj, CHAR_INFO *pTargetBuf);
		void Activate(S_GAMEOBJECT *pObj);
	}

	namespace alienObject
	{
		struct S_SUBOBJECT {};


		void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbSpeed, tge_sprite::S_SPRITE_OBJECT *pSpr);
		void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
		void Activate(S_GAMEOBJECT *pObj);
		//void Render(S_GAMEOBJECT *pObj, CHAR_INFO *pTargetBuf);
	}

	namespace attackObject
	{
		namespace claw
		{
			struct S_SUBOBJECT
			{

			};


			void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbSpeed, tge_sprite::S_SPRITE_OBJECT *pSpr);
			void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
			void Render(S_GAMEOBJECT *pObj, CHAR_INFO *pTargetBuf);
		}

		namespace fire
		{
			struct S_SUBOBJECT
			{

			};

			void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbSpeed, tge_sprite::S_SPRITE_OBJECT *pSpr);
			void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
			void Activate(S_GAMEOBJECT *pObj);
		}
	}

	namespace objMng
	{
		struct S_OBJECT_MNG
		{
			S_GAMEOBJECT *m_pListObject[1024];
			int m_nIndex = 0;
		};
		void add(S_OBJECT_MNG *pObj, S_GAMEOBJECT *pGameObj);
		void applyAll(S_OBJECT_MNG *pObj, double _deltaTick);
		void renderAll(S_OBJECT_MNG *pObj, CHAR_INFO *pBuf);
		void clearAll(S_OBJECT_MNG *pObj);
	}



}