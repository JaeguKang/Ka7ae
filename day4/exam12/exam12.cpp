// exam12.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char word[50];
	scanf_s("%s", word, sizeof(word));
	printf_s("입력한 문자열은 : %s \n", word);
	/*
	int index = 0;
	int _index = 0;
	*/
	int nLength = 0;
	int Array_size = sizeof(word) / sizeof(word[0]);

	for (int i = 0; i < Array_size; i++) {
		if (word[i] == 0x00) {
			break;
		}
		nLength++;
	}											//문자열의 크기를 찾는다
	printf_s("변환된 문자열은 : ");

	int nFSM = 0;								//true, fulse 를 구별해줄 변수를 만들고 ex)bool

	for (int i = 0; i < nLength; i++) {			
		if (nFSM == 0) {						//fulse일 때 @를 만나면 true로 바뀌게 설정하고 문자열은 그대로 출력
			if (word[i] == '@') nFSM = 1;
			printf_s("%c", word[i]);
		}
		else if (nFSM == 1) {					//true일 때 @를 만나면 fulse로 바뀌고
			if (word[i] == '@') nFSM = 0;

			if (nFSM == 1) {					//true상태에서는 문자열을 *로 치환
				printf_s("*");
			}
			else if (nFSM == 0) {				//fulse상태에서는 문자열을 그대로 출력하게 해서 @가 제대로 출력되게 함.변환된 문자열은 :
				printf_s("%c", word[i]);
			}
			

		}
		
	}
	printf_s("\n");
	



	/*
	for (int i = 0; i < Array_size; i++) {
		if (word[i] == '@') {
			break;
			
		}
		index++;
	}
	for (int i = index+1; i < Array_size; i++) {
		if (word[i] == '@') {
			break;
			
		}
		_index++;
	}

	for (int i = 0; i < Array_size; i++) {
		if (word[i] == 0x00) {
			break;
		}
		if (word[index] < word[i] < word[_index]) {
			word[i] = '*';
		}
	}
	
	printf_s("변환된 문자열은 : %s \n", word);
	*/

    return 0;
}

//@=64