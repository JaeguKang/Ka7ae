// exam12.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<string.h>

int main()
{
	char strMsg[] = "move east and move north set 3,4";						//문자열 끊어주는 방법
	char *pTemp = NULL;
	const char *pszDelimitor = " ,";

	char *pToken = strtok_s((char *)strMsg, pszDelimitor, &pTemp);	//<<공백과 ','를 기준으로 끊어주는것

	printf_s("%s \n", pToken);

	while (pToken)													//두번째 부터는 반복문으로 돌리고 NULL을 만나면 스탑.
	{
		pToken = strtok_s(NULL, pszDelimitor, &pTemp);
		if (pToken == NULL)break;
		printf_s("%s \n", pToken);
	}

	return 0;
}

