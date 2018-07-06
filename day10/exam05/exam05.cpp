// exam05.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

//8421
//0101 = > 0x5
//
/*
0 | 0 -> 0		//논리합 연산자
0 | 1 -> 1
1 | 0 -> 1
1 | 1 -> 1

0 & 0 => 0		//논리곱 연산자
0 & 1 => 0
1 & 0 => 0
1 & 1 => 1
*/

void outputDec2Bin(int ndec)		//10진수->2진수
{
	//e = 9; // 2진수 1001
	unsigned int a = 0x80000000;
	for (int i = 0;i < 32;i++)		//1001 & 0001 = 0 or 1
	{
		if (ndec&a)
		{
			printf_s("1");
		}
		else
		{
			printf_s("0");
		}
		a = a >> 1;
	}
	printf_s("\n");
}

int main()
{
	char a = 1;		//2진수 0000 0001
	char b = 2;		//
	char c = 4;
	char d = 8;

	char e = a | b | c | d;

	printf_s("%d %x \n", e, e);									// x 16진수

	e = 9; // 2진수 1001

	for (int i = 0;i < 4;i++)		//1001 & 0001 = 0 or 1
	{
		if (e&a)
		{
			printf_s("1");
		}
		else
		{
			printf_s("0");
		}
		a = a << 1;
	}
	printf_s("\n");
	// 0010 0100 => 0110
	char _e = b ^ c;
	printf_s("%d \n", _e);

	char k = 1;						//ex) 전광판
	for (int i = 0;i < 5;i++)
	{
		k = k ^ 1;
		printf_s("%d \n", k);
	}

	int num;
	printf_s("Input number : ");
	scanf_s("%d", &num);
	outputDec2Bin(num);


    return 0;
}

