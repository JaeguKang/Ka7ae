// exam1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

																					/*P.142*/
int main()
{
	int inch;
	double C;
	double km;

	printf("인치를 입력하세요. :");
	scanf_s("%d", &inch);
	printf("섭씨온도를 입력하세요. :");
	scanf_s("%lf", &C);
	printf("킬로미터를 입력하세요. : ");
	scanf_s("%lf", &km);

	printf("=============================================================\n");
	printf("|                         Value                             |\n");
	printf("=============================================================\n");
	
	printf("%d인치는 %lf센티입니다.\n", inch, inch*2.54); /*정수*실수=실수*/                /*printf("%d인치는 \t %lf센티입니다.\n", inch, inch*2.54);텝 한번 띄어쓰기*/
	
	printf("%lf섭씨온도는 %lf화씨온도입니다.\n", C, (C*1.8) + 32);

	printf("%lf km는 %lf mi이고 %lf m입니다.\n", km, km * 5 / 8, km * 1000);

	return 0;
}

