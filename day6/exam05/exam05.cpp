// exam05.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

																				//포인터와 배열 P309~
int main()
{
	int ary[5] = { 10,20,30,40,50 };
	int *ap;
	ap = ary;
	for (int i = 0;i < 5;i++)
	{
		//printf_s("%d \n", ary[i]);
		//printf_s("%d \n", *(&ary[0] + i));			다 똑같은 값이나옴.
		//printf_s("%d \n", *(ary + i));
		printf_s("%d \n", *(ap + i));

	}

	ap = &ary[2];
	for (int i = 0; i < 3; i++)
	{
		printf_s("%d \n", *(ap + i));
	}

    return 0;
}



	/*
	char ch;
	int in;
	double db;
	printf_s("%d\n", sizeof(&ch));
	printf_s("%d\n", sizeof(&in));
	printf_s("%d\n", sizeof(&db));
	*/