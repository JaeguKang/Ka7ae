// exam4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

//출력하기 p.63
int main()
{
	int num,num2; //변수
	printf("input ->");
	scanf_s("%d,%d", &num,&num2);//,로 구분짓지말고 왠만하면 엔터나 공백.
	printf("%result : %d, %d \n", num,num2);
	/*
	여러줄 표현가능한 주석. 개신기...
	*/
    return 0;
}

