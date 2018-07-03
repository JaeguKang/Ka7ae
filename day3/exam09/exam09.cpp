// exam09.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

																		//P.190
int main()
{
	int a, b;
	char _op;
	int nSolve;

	scanf_s("%d %d\n", &a, &b);
	//scanf_s("%d", &b, sizeof(b));
	scanf_s("%c", &_op, sizeof(_op));

	switch (_op) {
	case'+':
		nSolve = a + b;
		break;
	case'-':
		nSolve = a - b;
		break;
	case'*':
		nSolve = a * b;
		break;
	case'%':
		nSolve = a % b;													//나머지를 구하는 연산
		break;
	case'/':
		nSolve = a / b;
		break;
	case'&':
		nSolve = a & b;													//&연산은 2진수 연산 and
		break;
	case'|':
		nSolve = a | b;													//|연산 or
		break;
	default:
		break;
	}

	printf("%d %c %d = %d \n", a, _op, b, nSolve);
    return 0;
}

