// exam9.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	/*
	char word[32];
	scanf_s("%s", word, sizeof(word));
	printf_s("입력하신 문자열은 : %s \n",word);
	*/

	char word[50];
	scanf_s("%s", word, sizeof(word));
	printf_s("입력한 문자열은 : %s \n", word);
	
	
	int nCount = 0;
	int aCount = 0;

	int nArray_size = sizeof(word) / sizeof(word[0]);
	for (int i = 0; i < nArray_size;i++) {
		if (word[i] >= 65 && word[i] <= 90) {						//아스키 코드 65~90 대문자 A~Z / 97~122 소문자 a~z
			aCount++;
		}															//알파벳 갯수를 따로 추려내기
		if (word[i] >= 97 && word[i] <= 122) {
			aCount++;
		}
		if (word[i] == 0x00) {
			break;
		}
		nCount++;
	}

	printf_s("입력한 크기는 : %d . 알파벳의 갯수는 : %d 입니다. \n", nCount, aCount);

    return 0;
}

