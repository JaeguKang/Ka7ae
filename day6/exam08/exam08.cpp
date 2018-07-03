// exam08.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

double getMinValue(double *ap, int nLength)
{
	double _min = 999999999;

	for (int i = 0;i < nLength; i++)
	{
		if (_min > ap[i])
		{
			_min = ap[i];
		}
	}
	return _min;
}

double getMaxValue(double *ap, int nLength)
{
	double _max = -99999999;

	for (int i = 0;i < nLength;i++)
	{
		if (_max < ap[i])
		{
			_max = ap[i];
		}
	}
	return _max;
}


int main()
{
	double ary[] = { 1.5,20.1,16.4,2.3,3.5, 0.7 };
	printf_s("배열의최소값은 : %lf 입니다. \n", getMinValue(ary, sizeof(ary) / sizeof(double))); // *ap = ary . nLength = sizeof~~~
	printf_s("배열의최대값은 : %lf 입니다. \n", getMaxValue(ary, sizeof(ary) / sizeof(double)));
    return 0;
}

