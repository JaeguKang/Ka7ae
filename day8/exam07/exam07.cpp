// exam07.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<malloc.h>

int main()
{
	int *ip = NULL;

	ip = (int *)malloc(sizeof(int));
	if (ip != NULL)
	{
		printf_s("메모리 할당 성공 \n");
	}
	else
	{
		printf_s("메모리 부족 \n");
	}

	*ip = 1;

	printf_s("%d \n", *ip);

	free(ip);
	ip = NULL;

    return 0;
}

