// exam01.cpp: �ܼ� ���� ���α׷��� �������� �����մϴ�.
//

#include "stdafx.h"

//cjson �о���� ����
void exam1_cjson_read()
{
	char szBuf[1024] = { 0 };

	FILE *fp;
	fopen_s(&fp, "test.json", "rt");
	fread_s(szBuf, 1024, 1024, 1, fp);

	puts(szBuf);

	//��Ϻ� �ҷ�����
	cJSON *pRoot = cJSON_Parse(szBuf);

	cJSON *pName = cJSON_GetObjectItemCaseSensitive(pRoot, "name");
	cJSON *pDistance = cJSON_GetObjectItemCaseSensitive(pRoot, "distance");
	cJSON *pNCode = cJSON_GetObjectItemCaseSensitive(pRoot, "national_code");
	cJSON *pComm = cJSON_GetObjectItemCaseSensitive(pRoot, "comm");
	//��Ͼ��� ��Ͽ��� �ҷ�����
	cJSON *pItem = cJSON_GetObjectItemCaseSensitive(pRoot, "item");
	cJSON *pWepon = cJSON_GetObjectItemCaseSensitive(pItem, "wepon");
	//�迭 �ҷ�����.
	cJSON *pEtc = cJSON_GetObjectItemCaseSensitive(pRoot, "etc");
	cJSON *pEtc_0 = cJSON_GetArrayItem(pEtc, 0);
	cJSON *pEtc_1 = cJSON_GetArrayItem(pEtc, 1);

	printf_s("�Ľ̰�� \n");
	printf_s("%s \n", pName->valuestring);
	printf_s("%lf \n", pDistance->valuedouble);
	printf_s("%d \n", pNCode->valueint);
	printf_s("%d \n", pComm->valueint);

	printf_s("wepon is %s \n", pWepon->valuestring);
	printf_s("���ݷ��� %d \n", cJSON_GetObjectItemCaseSensitive(pItem, "ap")->valueint);

	printf_s("%d %s \n", pEtc_0->valueint, pEtc_1->valuestring);


	fclose(fp);
}

