// exam01.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

struct student
{
	int num;
	double grade;
	char level;

};

int main()
{
	int num;
	double grade;
	char level;

	num = 5;
	grade = 3.1;
	printf_s("%8d,%8.3lf\n", num, grade);		// .3은 소숫점 3째자리까지.

	struct student _student_1;		//인스턴스 = _student_1
	_student_1.num = 6;
	_student_1.grade = 5.1;
	printf_s("%8d,%8.3lf\n", _student_1.num, _student_1.grade);

	printf_s("%d,%d,%d\n", &(num), &(grade), &(level));

	printf_s("%d,%d,%d\n", &(_student_1.num), &(_student_1.grade),&(_student_1.level));		//8바이트씩 일정함

    return 0;
}

