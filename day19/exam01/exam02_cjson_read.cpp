// exam01.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

//cjson 읽어오기 예제
void exam1_cjson_read()
{
	char szBuf[1024] = { 0 };

	FILE *fp;
	fopen_s(&fp, "test.json", "rt");
	fread_s(szBuf, 1024, 1024, 1, fp);

	puts(szBuf);

	//목록별 불러오기
	cJSON *pRoot = cJSON_Parse(szBuf);

	cJSON *pName = cJSON_GetObjectItemCaseSensitive(pRoot, "name");
	cJSON *pDistance = cJSON_GetObjectItemCaseSensitive(pRoot, "distance");
	cJSON *pNCode = cJSON_GetObjectItemCaseSensitive(pRoot, "national_code");
	cJSON *pComm = cJSON_GetObjectItemCaseSensitive(pRoot, "comm");
	//목록안의 목록에서 불러오기
	cJSON *pItem = cJSON_GetObjectItemCaseSensitive(pRoot, "item");
	cJSON *pWepon = cJSON_GetObjectItemCaseSensitive(pItem, "wepon");
	//배열 불러오기.
	cJSON *pEtc = cJSON_GetObjectItemCaseSensitive(pRoot, "etc");
	cJSON *pEtc_0 = cJSON_GetArrayItem(pEtc, 0);
	cJSON *pEtc_1 = cJSON_GetArrayItem(pEtc, 1);

	printf_s("파싱결과 \n");
	printf_s("%s \n", pName->valuestring);
	printf_s("%lf \n", pDistance->valuedouble);
	printf_s("%d \n", pNCode->valueint);
	printf_s("%d \n", pComm->valueint);

	printf_s("wepon is %s \n", pWepon->valuestring);
	printf_s("공격력은 %d \n", cJSON_GetObjectItemCaseSensitive(pItem, "ap")->valueint);

	printf_s("%d %s \n", pEtc_0->valueint, pEtc_1->valuestring);


	fclose(fp);
}

