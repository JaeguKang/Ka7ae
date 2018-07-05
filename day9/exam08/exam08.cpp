// exam08.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	FILE *fp;
	char ch;

	fopen_s(&fp, "b.txt", "w");
	if (fp == NULL)
	{
		printf_s("파일 오픈 실패.\n");
		return 1;
	}
	printf_s("input Data :");

	while (1)
	{
		ch = getchar();
		if (ch == EOF) break;
		fputc(ch, fp);
	}

	//fputc('a', fp);
	//putc(ch, stdout);

	fclose(fp);

    return 0;
}

