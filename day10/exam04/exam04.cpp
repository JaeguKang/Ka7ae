// exam04.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include"G_object.h"


 

int main()
{
	_S_GAMEOBJECT *pPlayerObj = NULL;
	CreateObject(&pPlayerObj, "angel", 100);
	dumpObject(pPlayerObj);
	free(pPlayerObj);

	printf_s("%lf \n", g_dbPi);

    return 0;
}

