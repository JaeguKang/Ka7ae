// exam2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

																				//P.146
int main()
{
	printf("\x41 \n");
	//1 + 16 * 4 = 65
	printf("♭♩♪♬◆☆★◐◑○●◎⊙◈◇△▲▽▼□■◁◀▷▶◇◆♤♠♡♥♧♣\n"); //google 특수문자표 
	printf("부호 : %d , 부호없음 : %u \n", -1, -1); //부호 !
	printf("10 %d ,8 %o ,16 %x \n", 16, 16, 16);    //10진법 8진법 16진법
	printf("%x \n", '□'); // a1e0<<코드표 얻어올수있음.

	double _val = 0.0000001;
	printf("pi : %lf , %le \n", _val, _val);

	printf("pi : %lf , %le \n", 3.0000000001415926, 3.1415926); //뭔지모르겠음 ㅡ;

	printf("%c , %s \n", 'H', "Hello");

	/*unsignd int a; 부호를 인정하지 않는다는데 ㅡ뭔지
	  unsignd char b; 0~255
	  char c; -128~127*/
	printf("=============================================================\n");
	
	int A, B;
	printf("두 정수를 입력하세요 :");
	scanf_s("%d %d", &A, &B);
	printf("나눗셈 연산식은 %d / %d = %lf 입니다.\n", A, B, A * 1 / B); //exam3에 제대로 나눗셈
	return 0;
}

