// exam07.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	FILE *fp;
	char ch;

	fopen_s(&fp, "a.txt","r");
	if (fp==NULL)
	{
		printf_s("파일읽기실패\n");
	}
	else
	{
		while (1)
		{
			ch = fgetc(fp);
			if (ch == EOF)
			{
				break;
			}
			printf_s("%c", ch);
		}
		printf_s("\n");


		//ch = fgetc(stdin);
		////ch = fgetc(fp);
		//printf_s("input keyword : %c \n", ch);
		//fclose(fp);	

		//ch = fgetc(stdin);
		//printf_s("input keyword : %c \n", ch);
		//fclose(fp);
	}
    return 0;
}

