// exam10.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int num;
	char name[20];

	fputs("input number : ", stdout);
	scanf_s("%d", &num);
	fputs("input spell : ", stdout);
	scanf_s("%s", name, sizeof(name));

	printf_s("input %d and %s .\n", num, name);

    return 0;
}

