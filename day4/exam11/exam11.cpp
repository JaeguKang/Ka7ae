// exam11.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

																			//Exercise 9-3
int main()
{
	char word[50];
	scanf_s("%s", word, sizeof(word));
	printf_s("입력한 문자열은 : %s \n", word);

	int Array_size = sizeof(word) / sizeof(word[0]);
	int nLength = 0;

	for (int i = 0; i < Array_size; i++) {
		if (word[i] == 0x00) break;
		nLength++;
	}
	for (int j = nLength; j >= 0; j--) {
		printf_s("%c", word[j]);
	}
	printf_s("\n");

	for (int i = 0; i < nLength / 2; i++) {
		char _temp;
		_temp = word[i];
		word[i] = word[(nLength-1) - i];
		word[(nLength - 1) - i] = _temp;
	}
	printf_s("뒤바뀐 문자열은 : %s \n", word);
	
	
	
	
	
	
	
	
	/*
	char _temp;
	_temp = word[0];
	word[0] = word[1];
	word[1] = _temp;
	*/


	/*
	for (int i = 0; i < Array_size; i++) {
		
	}
	*/
    return 0;
}

