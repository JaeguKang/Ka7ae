// exam03.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<string.h>
#include<conio.h>

void _get(char (*str)[80])
{
	for (int i = 0;i < 5;i++)
	{
		gets_s((str[i]),80);
	}
}

void _ptr(char(*str)[80])
{
	for (int i = 0;i < 5;i++)
	{
		printf_s("%s\n", (str[i]));
	}
}

int main()
{
	char szaBuf[5][80];
	int count = (sizeof(szaBuf) / sizeof(szaBuf[0]));

	_get(szaBuf);

	_ptr(szaBuf);


	

    return 0;
}

	/*
	int ary[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	printf_s("%d \n", ary);
	printf_s("%d \n", &ary);
	printf_s("%d \n", ary+1);
	printf_s("%d \n", &ary+1);

	int *ptr = NULL;
	printf_s("%d \n", ptr);
	printf_s("%d \n", &ptr);
	printf_s("%d \n", ptr+1);
	printf_s("%d \n", &ptr+1);
	*/