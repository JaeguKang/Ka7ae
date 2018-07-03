// exam7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ary[] = { 2,8,15,18,20,8,4,12,16,17,2,1,7,14,20,19,8,9,6,5,15,1,17,2,20,19,17 };
	int nFind;
	int nCount = 0;

	printf("찾기를 원하는 숫자를 입력하세요. :");
	scanf_s("%d", &nFind);
	
	int array_size = sizeof(ary) / sizeof(ary[0]); //=sizeof(int) int = 4바이트/ 배열의 갯수를 구하는것  / sizeof가 해당하는 것에 크기를 구해줌 
													// int 형은 4바이트 * 배열의 갯수 나누기 하나의 int = 4바이트 고로 배열의 갯수가 구해짐
	for (int i = 0; i < array_size; i++) {			// 배열을 한사이클 돌림 
		if (ary[i] == nFind) nCount++;
		}
	
	printf_s("%d 은 %d 개 있습니다.\n", nFind, nCount);
	

	

    return 0;
}

