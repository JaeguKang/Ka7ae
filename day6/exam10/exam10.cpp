// exam10.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char *fruit = (char *)"strawberry";
	char fruit2[80] = "strawberry";
	//char *pStr = (char *)fruit;

	printf_s("%s \n", fruit);

	printf_s("%s \n", fruit + 2); //<<<<같은말
	printf_s("%s \n", &fruit[2]);

	fruit2[3] = 'o';
	printf_s("%s \n", fruit2);

	//pStr[3] = 'o';


    return 0;
}

