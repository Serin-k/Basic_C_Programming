#include<stdio.h>	
#include<string.h>
#include<ctype.h>	
#include <stdlib.h>	

#include"1.HeatherFile.h"

//1711435 김세린
//[1번] BMI정상 출력 프로그램 

/* Definition Of Global Variables */
double height, weight, InputHeight, BMI;
char rs, IH[50], IW[50], Exit[10] = { "PLZ" };

int main()
{
	printf("This program shows your BMI\n");	
	while (1)
	{
		printf("If you want to exit program, input plz\n");
		printf("\nInput your height(cm): ");							//몸무게 입력
		scanf("%s", IH);
		while (getchar() != '\n');
		strupr(IH);

		if (strcmp(IH, Exit)==0)										//프로그램 종료
		{
			printf("\n\nExit Program\n");
			break;
		}

		Checker(IH);													//숫자인지 확인

		if (rs == 'F')													//입력이 숫자가 아닐 때	
		{
			printf("\nYou can insert only number. You're input: [%s]\n", IH);
			continue;													//while문 처음으로 돌아가 재입력
		}
		InputHeight = atof(IH);											//계산을 위해 char문자열을 int로 변환


		printf("\nInput your weight(kg): ");							//몸무게 입력
		scanf("%s", IW);
		while (getchar() != '\n');
		strupr(IW);

		if (strcmp(IW, Exit) == 0)										//프로그램 종료
		{
			printf("\n\nExit Program\n");
			break;
		}

		Checker(IW);													//숫자인지 확인

		if (rs == 'F')													//입력이 숫자가 아닐 때	
		{
			printf("\nYou can insert only number. You're input: [%s]\n", IW);
			continue;													//while문 처음으로 돌아가 재입력
		}
		weight = atof(IW);												//계산을 위해 char문자열을 int로 변환
		BMIprint(InputHeight, weight);									//결과 출력
	}

	return 0;
}

