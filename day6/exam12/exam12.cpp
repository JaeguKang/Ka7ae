// exam12.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include<string.h>

int main()
{
	const char *str1 = "apple";

	char buf[64];

	strcpy_s(buf, 64, str1);

	printf_s("%s \n", buf);								//							copy 함수

	printf_s("%d \n", strnlen_s(buf, 64));				//or sizeof(buf)			문자열 길이 계산 함수

	printf_s("같은 문자일 경우 :|%d \n", strcmp(buf, "apple"));					// 문자열 비교하는 함수. 0 or -1
	printf_s("다른 문자일 경우 :|%d \n", strcmp(buf, "opple"));

	printf_s("같은 문자일 경우 :|%d \n", strcmp("cat", "cat"));
	printf_s("다른 문자일 경우 :|%d \n", strcmp("cat", "bat"));					//첫 알파벳 비교후 2번째 알파벳 순이 빠르면 1 늦으면 -1
	printf_s("다른 문자일 경우 :|%d \n", strcmp("bat", "dog"));					//P.345에 설명.

	strcat_s(buf, sizeof(buf), "pie");											//두 개의 문자열을 붙이는 함수
	printf_s("%s \n", buf);														//buf <= buf + "pie"
	
	return 0;
}

