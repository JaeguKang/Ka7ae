// exam05.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void foo()
{
	printf_s("i'm groot!\n");
}
void bar()
{
	printf_s("i'm grooooooot~\n");
}

int main()
{
	void (*fp)();							//함수포인터 선언
	fp = foo;
	fp();		//이건왜써줌

	fp = bar;
	fp();

    return 0;
}

