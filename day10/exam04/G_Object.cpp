#include"stdafx.h"

double g_dbPi = 3.14;

struct _S_GAMEOBJECT
{
	char m_szName[16];
	int m_nHP;
};


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