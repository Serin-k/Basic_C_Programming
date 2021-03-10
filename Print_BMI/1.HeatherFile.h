#include<stdio.h>	
#include<string.h>
#include<ctype.h>	
#include <stdlib.h>		

#include"SerinHeather.h"

void BMIprint(double H, double W)										//결과 출력 함수
{
	double height, BMI;
	height = H / 100;													//입력된 숫자의 단위는 cm이고, 계산에 쓰일 단위는 m이므로 변환 필요
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

