// exam01.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int num;
	int *ptr;
	num = 3;
	ptr = &num;

	printf_s("%d %d \n", num, &num); // 주소값!
	printf_s("%d %d \n", *ptr, ptr); //주소값에 참조연산자를 붙이면 주소에 들어있는 값이 나온다.

	*ptr = 5;
	printf_s("%d %d \n", *ptr, ptr);
	printf_s("%d %d \n", num, &num); //주소는 변하지않고 주소에 있는 값만 변환시킴


	int address;
	scanf_s("%d", &address);							//주소입력
	printf_s("%d %d \n", address, *((int *)address));	//주소안의 값을출력

	/*
	int *address;
	scanf_s("%d", &address);
	printf_s("%d \n", *address);
	*/

	/*
	int a;
	int b;

	*&a = 100;
	b = 100;										//뭐가 다른지..

	printf_s("%d %d \n", a, b);
	*/


	return 0;
}

