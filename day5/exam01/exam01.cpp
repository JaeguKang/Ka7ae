// exam01.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

/*

*/

int main()
{
	char word[50];
	scanf_s("%s", word, sizeof(word));
	printf_s("입력한 문자열은 : %s \n", word);


	int nLength = 0;
	int Array_size = sizeof(word) / sizeof(word[0]);

	for (int i = 0; i < Array_size; i++) {
		if (word[i] == 0x00) {
			break;
		}
		nLength++;
	}

	int nFSM = 0;




	for (int i = 1; i < nLength; i++) 
	{
		if (nFSM == 0) {
			if (word[i - 1] == '/' && word[i] == '*') nFSM = 1;
			printf_s("%c", word[i-1]);

		}
		else if (nFSM == 1)
		{
			printf_s(" ");

			if (word[i] == '*') nFSM = 2;
			printf_s("%c", word[i-1]);
		}
		else if (nFSM == 2) 
		{
			if (word[i] == '/')nFSM = 0;
			printf_s("%c", word[i-1]);


		}
		else if (nFSM == 0)
		{
		printf_s("%c", word[i-1]);
		}		




	}
		/*
		else if (nFSM == 1) {
			if (word[i - 1] == '*' && word[i] == '/')
				nFSM = 0;
		}
		else if (nFSM == 1) {

		*/





	
	printf_s("\n");
		return 0;
}

