#include<stdio.h>	
#include<string.h>
#include<ctype.h>	
#include <stdlib.h>		

#include"SerinHeather.h"

void BMIprint(double H, double W)										//��� ��� �Լ�
{
	double height, BMI;
	height = H / 100;													//�Էµ� ������ ������ cm�̰�, ��꿡 ���� ������ m�̹Ƿ� ��ȯ �ʿ�
	BMI = W / (height * height);

	if (BMI < 18.5)
	{
		printf("\nUnderweight\n");
	}
	else if (BMI >= 18.5 && BMI < 25)
	{
		printf("\nNormal\n");
	}
	else if (BMI >= 25 && BMI < 30)
	{
		printf("\nOverweight\n");
	}
	else if (BMI >= 30)
	{
		printf("\nObese\n");
	}
	Partition();
}

