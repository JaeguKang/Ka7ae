// exam09.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char str[80] = "dream1";
	char str2[] = "dream2";
	const char *str3 = "dream3";
	char *str4;

	str4 = (char *)str3;

	//str3[0] = 'D';	안됨 ,,,, 주소값은됨
	printf_s("%s \n", str3);
	
	str2[0] = 'D';	//  배열값은 됨
	//str2 = str;		안됨 ,,,, 
	str3 = str2;
	str3 = str;
	printf_s("%s \n", str3);

	str4 = (char *)str3;		//=== str3[0] = 'D';
	str4[0] = 'D';
	printf_s("%s \n", str3);


    return 0;
}

