// exam10.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char word[50];
	scanf_s("%s", word, sizeof(word));
	printf_s("입력한 문자열은 : %s \n", word);

	int Array_size = sizeof(word) / sizeof(word[0]);
	
	for (int i = 0; i < Array_size; i++) {
		if (word[i] == 0x00) break;

		if (word[i] >= 65 && word[i] <= 90) {
			word[i] = '*';
		}
		if (word[i] >= 97 && word[i] <= 122) {
			word[i] = '*';
		}
	}
	printf_s("변환된 문자열은 : %s \n", word);
    return 0;
}

