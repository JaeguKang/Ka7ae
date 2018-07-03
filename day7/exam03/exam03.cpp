// exam03.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void count()
{
	int a = 0;
	a++;
	printf_s("%d\n", a);
}

void count2()
{
	static int a = 0;				//정적변수 P.382 다른메모리공간을 할당받음.
	a++;
	printf_s("%d\n", a);
}

void count3(int *a)		//포인터를 이용해 불러오기.
{
	(*a)++;
	printf_s("%d\n", *a);
}



int main()
{
	/*
	count();
	count();

	count2();
	count2();
	*/

	int a = 0;

	count3(&a);			//주소연산자를 써 불러올 수 있게 한다.
	count3(&a);

	// printf_s("a : %d\n", a);

    return 0;
}

/*
void count4(int *b)
{
	*b + *b + 10;
}
*/