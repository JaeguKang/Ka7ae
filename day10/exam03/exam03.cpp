// exam03.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	const double pi = 3.14;
	int num;
	const int *pNumReadOnly = NULL;						//const를 앞뒤로 써도 문법적 차이는 없다.
	//int const *pNum = &num;							//그래도 보통 앞에다 씀.
	num = 5;
	pNumReadOnly = &num;

	//pi = 3.141592;
	printf_s("%.2lf %d \n", pi, *pNumReadOnly);

	//*pNumReadOnly = 7;
	//*pNum = 8;
	num = 7;
	
	printf_s("%d \n", num);
	printf_s("%d \n", *pNumReadOnly);

    return 0;
}

