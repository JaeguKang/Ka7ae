// exam02.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#define _PI 3.141592												//매크로 (간단한 함수도 이걸로 쓸 수 있음.)
const double __PI = 3.141592;
#define SUM(x,y) x+y

//#define _MY_TEST

int main()
{
	printf_s("%lf %d %lf \n", _PI, SUM(3, 4), SUM(3.4, 6.5));		//여러 형으로 쓸 수 있음. int ~ double

#ifdef _MY_TEST														//속성의 전처리기 정의> 편집
	printf_s("hellp define\n");
#elif _MY_TEST2														//or 명령줄 추가 옵션에 추가 -> /D"_MY_TEST2"
	printf_s("hello test2 define\n");
#else
	printf_s("hello not define\n");
#endif

	return 0;
}

