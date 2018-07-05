// exam11.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
																						//저장시스템

struct _S_GAMEOBJECT
{
	char m_szName[32];
	int m_nHp;
	int m_nAttack;
	int m_nMp;
	int m_nDep;
};

//
void parsePlayerInfo(_S_GAMEOBJECT *pObj, char *szBuf)
{
	//edit 이름 100 50 6 3
	const char *deli = " ";
	char *_temp;
	char *pToken;
	pToken = strtok_s(szBuf, deli, &_temp);					//edit
	//puts(pToken);

	pToken = strtok_s(NULL, deli, &_temp);					//name
	strcpy_s(pObj->m_szName, sizeof(pObj->m_szName), pToken);
	//puts(pToken);

	pToken = strtok_s(NULL, deli, &_temp);					//hp
	pObj->m_nHp = atoi(pToken);
	//puts(pToken);

	pToken = strtok_s(NULL, deli, &_temp);					//mp
	pObj->m_nMp = atoi(pToken);
	//puts(pToken);

	pToken = strtok_s(NULL, deli, &_temp);					//atk
	pObj->m_nAttack = atoi(pToken);
	//puts(pToken);

	pToken = strtok_s(NULL, deli, &_temp);					//dep
	pObj->m_nDep = atoi(pToken);
	//puts(pToken);		

}



int main()
{
	char szBuf[128];
	_S_GAMEOBJECT player = { 0 };
	//_S_GAMEOBJECT _player = { 0 };

	while (1)
	{
		printf_s("Command : ");
		gets_s(szBuf, sizeof(szBuf));

		if (strcmp("quit", szBuf) == 0)
		{
			printf_s("End...");
			break;
		}

		else if (!strcmp("dump", szBuf))		//==0
		{
			printf_s("%12s%8d%8d%8d%8d\n", player.m_szName, player.m_nHp, player.m_nMp, player.m_nAttack, player.m_nDep);
		}

		else if (!strncmp("edit", szBuf, 4))
		{
			parsePlayerInfo(&player, szBuf);

		}

		else if (!strncmp("save", szBuf, 4))
		{
			FILE *fp = NULL;
			fopen_s(&fp, "save.txt", "w");		//w=write
			fprintf_s(fp, "edit %s %d %d %d %d\n", player.m_szName, player.m_nHp, player.m_nMp, player.m_nAttack, player.m_nDep);
			fclose(fp);
		}

		else if (!strncmp("load", szBuf, 4))
		{
			FILE *fp = NULL;
			fopen_s(&fp, "save.txt", "r");		//r=read

			fgets(szBuf, sizeof(szBuf), fp);
			parsePlayerInfo(&player, szBuf);

			fclose(fp);

		}

	}
	return 0;
}

