// exam01.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//																					게임 오브젝트.

#include "stdafx.h"

#include"gameoveject.h"								//헤더파일에 따로 구조체 입력한거 불러오기.

void CreateObject(_S_GAMEOBJECT **ppObj, const char *pName, int nHp)
{
	*ppObj = (_S_GAMEOBJECT *)malloc(sizeof(_S_GAMEOBJECT));
	(*ppObj)->m_nHP = nHp;
	strcpy_s((*ppObj)->m_szName, sizeof((*ppObj)->m_szName), pName);

}

void dumpObject(_S_GAMEOBJECT *pObj)				//출력만 할거면 단일포인터..?
{
	printf_s("%16s %4d\n", pObj->m_szName, pObj->m_nHP);
}

int main()
{
	_S_GAMEOBJECT *pPlayerObj = NULL;
	CreateObject(&pPlayerObj, "noname", 100);
	dumpObject(pPlayerObj);
	free(pPlayerObj);								//메모리관리를 프로그래머가 해줘야함

    return 0;
}

