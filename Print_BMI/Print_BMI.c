#include<stdio.h>	
#include<string.h>
#include<ctype.h>	
#include <stdlib.h>	

#include"1.HeatherFile.h"

//1711435 �輼��
//[1��] BMI���� ��� ���α׷� 

/* Definition Of Global Variables */
double height, weight, InputHeight, BMI;
char rs, IH[50], IW[50], Exit[10] = { "PLZ" };

int main()
{
	printf("This program shows your BMI\n");	
	while (1)
	{
		printf("If you want to exit program, input plz\n");
		printf("\nInput your height(cm): ");							//������ �Է�
		scanf("%s", IH);
		while (getchar() != '\n');
		strupr(IH);

		if (strcmp(IH, Exit)==0)										//���α׷� ����
		{
			printf("\n\nExit Program\n");
			break;
		}

		Checker(IH);													//�������� Ȯ��

		if (rs == 'F')													//�Է��� ���ڰ� �ƴ� ��	
		{
			printf("\nYou can insert only number. You're input: [%s]\n", IH);
			continue;													//while�� ó������ ���ư� ���Է�
		}
		InputHeight = atof(IH);											//����� ���� char���ڿ��� int�� ��ȯ


		printf("\nInput your weight(kg): ");							//������ �Է�
		scanf("%s", IW);
		while (getchar() != '\n');
		strupr(IW);

		if (strcmp(IW, Exit) == 0)										//���α׷� ����
		{
			printf("\n\nExit Program\n");
			break;
		}

		Checker(IW);													//�������� Ȯ��

		if (rs == 'F')													//�Է��� ���ڰ� �ƴ� ��	
		{
			printf("\nYou can insert only number. You're input: [%s]\n", IW);
			continue;													//while�� ó������ ���ư� ���Է�
		}
		weight = atof(IW);												//����� ���� char���ڿ��� int�� ��ȯ
		BMIprint(InputHeight, weight);									//��� ���
	}

	return 0;
}

