// exam5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void printArry(int nums[])
{
	for (int i = 0; i < 5; i++) {
		printf_s("%d", nums[i]);
	}
	printf("\n");

}

int main()
{
	int nums[5];
	//int _nums[5] = { 5,6,7,8,9 };
	int _nums[] = { 5,6,7,8,9 };

	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &nums[i]);
	}
	printArry(nums);
	printArry(_nums);		//반복되는것을 줄임 ..불러오기
	/*
	for (int i = 0; i < 5; i++) {
		printf_s("%d \n", nums[i]);
	}

	for (int i = 0; i < 5; i++) {
		printf_s("%d \n", _nums[i]);
	}*/
		return 0;
}

