// exam8.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

														//배열 문자배열 P.266
int main()
{
	//char word[] = { 'l','o','v','e','\x00' };		//null문자 = \x00
	char word[] = "love";						//큰따옴표로 묶으면 자동으로 null문자 생김

	int nSize = sizeof(word) / sizeof(word[0]);

	for (int i=0; i < 4; i++) {
		printf_s("%c", word[i]);
	}
	printf_s("\n");

	printf_s("%s\n", word);

    return 0;
}

