// exam08.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

																			//Exercise 6-3 :1
int main()
{
	char cGender;
	printf("성별을입력하세요. (남자는m 여자는f)");
	scanf_s("%c", &cGender,sizeof(cGender));
	
	if (cGender == 'm') {
		printf("남자입니다\n");
	}
	else if (cGender == 'f') {
		printf("여자입니다\n");
	}
	else {
		printf("잘못입력하였습니다.\n");
	}
    return 0;
}

