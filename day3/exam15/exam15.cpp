// exam15.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

															//Exercise7-5
int main()
{
	/*
	int i;
	int j;  //구구단
	for (j = 1; j <= 9; j++) {
		for (i = 0; i <= 9; i++) {
			printf("%d * %d = %d \n", j, i, j * i);
		}
	}
	*/
	int i, j;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			printf("%d * %d = %2d\n", i, j, j*i);
		}
		printf("\n");

	}
	
    return 0;
}

