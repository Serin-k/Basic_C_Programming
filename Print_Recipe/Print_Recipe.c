#include<stdio.h>	
#include<string.h>
#include<ctype.h>	
#include <stdlib.h>														//������� ����

#include"SerinHeather.h"

//1711435 �輼��
//[2��] ���� ��� ��� ���α׷� 

/* Definition Of Global Variables */
int  c,people, count;
char rs, ch[50], Special, Food[10], Type[10], Ramen[7] = { "RAMEN" }, Pasta[7] = { "PASTA" }, Exit[5] = {"PLZ"};
char P_Tom[14] = { "TOMATO" }, P_Agl[10] = { "AGLIOOLIO" };

char *R_In[6] = { "Water", "Noodle", "SoupPowder" };
int R_Num[] = { 300, 1, 1, 99999 };
char *R_Unit[] = { "�� of"," ", " " };

char *Add[] = { "GreenOnion", "Egg", "BeanSprouts" };
int A_Num[] = { 2, 1, 1, 99999 };
char *A_Unit[] = { "pieces of", " ", "handful of" };

char *TP_In[] = { "Water", "Noodle", "TomatoSauce", "Salt" };
int TP_Num[] = { 1, 100, 300, 1, 99999 };
char *TP_Unit[] = { "�� of", "gram of", "ml of", "Table spoon of" };

char *AP_In[] = { "Water", "Noodle", "OliveOil", "Shrimp", "Garlic", "Peperoncino" };
int AP_Num[] = { 1, 100, 6, 5, 8, 1, 99999 };
char *AP_Unit[] = { "�� of", "gram of", "Table spoon of", " ", " ", "Table spoon of" };

/* Definition Of Global Functions */
int INGREDIENT(int PEO, int num[], char *str[], char *str2[]);

int main(void)
{
	printf("This progrmam shows the ingredients of certain foods\n");
	while (1)
	{	
		count = 0;												//while�� ���� �ʱ�ȭ �����ν� while���� �� ������ �ʱ�ȭ
		printf("\n>>You can exit with 'plz'<<\n");				
		printf("Available Foods[ Ramen / Pasta ]\n");
		printf("\nInsert Food Name: ");								//���� �̸� �Է�
		scanf("%s", Food);
		while (getchar() != '\n');
		strupr(Food);												//���ڹ迭 �빮�ڷ�

		if (strcmp(Food, Exit) == 0)								//���α׷� ����
			break;
		else if (strcmp(Food, Pasta) != 0 && strcmp(Food, Ramen) != 0)	//ramen�� pasta�� �ƴ� �ٸ� �Է�
		{
			printf("Wrong Input. You can only choose [ramen/pasta]\n");
			continue;
		}



		printf("How many people? (Insert only number): ");			//�ο��� �Է�
		scanf("%s", ch);
		while (getchar() != '\n');
	
		Checker(ch);												//�������� Ȯ��

		if (rs == 'F')												//people�� ���ڰ� �ƴ� ��	
		{
			printf("You can insert only number. You're input: [%s]\n", ch);
			continue;
		}
		people = atoi(ch);											//�ο��� ����� ���� char���ڿ��� int�� ��ȯ

		if (strcmp(Food, Ramen) == 0)								//����� ���
		{
				printf("****You selected RAMEN****\nDo you want special ramen? [ O / X ]\n");

				scanf("%c", &Special);								//����ȶ��� �⺻��� �� ����
				while (getchar() != '\n');
				Special = toupper(Special);

			if (Special == 'X')										//�⺻ ����� ���
			{
				Partition();
				printf("\nNormal Ramen\n");
				INGREDIENT(people, R_Num, R_Unit, R_In);			//��� ���
			}
			else if (Special == 'O')
			{
				Partition();
				printf("\nSpecial Ramen");							//����� ����� ���
				INGREDIENT(people, R_Num, R_Unit, R_In);			//��� ���
				INGREDIENT(people, A_Num, A_Unit, Add);
			}
			else													//o/x�� �ƴ� �ٸ� �Է�
			{
				printf("Wrong Input. You can only choose o/x.");
				continue;
			}
		}

		else if (strcmp(Food, Pasta) == 0)							//�Ľ�Ÿ�� ��� ����
		{
			printf("****You selected PASTA****\nYou can choose [ Tomato / AglioOlio ]");
			printf("\nWhich pasta?: ");								//�丶��� �˸����ø��� �� ����
			scanf("%s", Type);
			strupr(Type);

			if (strcmp(Type, P_Tom) == 0)							//�丶�� �Ľ�Ÿ�� ���
			{
				Partition();
				printf("\nTomato Pasta\n");
				INGREDIENT(people, TP_Num, TP_Unit, TP_In);			//��� ���
			}
			else if (strcmp(Type, P_Agl) == 0)						//�丶�� �Ľ�Ÿ�� ���
			{
				Partition();
				printf("\nAglio Olio Pasta\n");
				INGREDIENT(people, AP_Num, AP_Unit, AP_In);			//��� ���
			}
			else													//tomato�� aglioolio�� �ƴ� �ٸ� �Է�
			{
			printf("Wrong Input. You can only choose [tomato/aglioolio]");
			continue;
			}
		}

		Partition();
	}
	
	printf("\n\nThanks:D\n");
	return 0;
}


int INGREDIENT(int PEO, int num[], char *str[], char *str2[])		//��, ����, ���� ������ �Է¹޾� ��� ������ִ� �Լ�
{
	if (count == 0)													//�Լ� �ߺ� ȣ��� ��µ��� ���� ����
	{
		printf("\n*Ingredients*\n");
		printf("For %d people\n", PEO);
	}
	else;
	for (int i = 0; num[i]!=99999 ;i++)								//������
	{
		printf("\n");
		printf("%3d %s %s", PEO*(num[i]), str[i], str2[i]);
	}
	count++;
	return count;
}

