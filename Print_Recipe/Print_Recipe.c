#include<stdio.h>	
#include<string.h>
#include<ctype.h>	
#include <stdlib.h>														//헤더파일 삽입

#include"SerinHeather.h"

//1711435 김세린
//[2번] 음식 재료 출력 프로그램 

/* Definition Of Global Variables */
int  c,people, count;
char rs, ch[50], Special, Food[10], Type[10], Ramen[7] = { "RAMEN" }, Pasta[7] = { "PASTA" }, Exit[5] = {"PLZ"};
char P_Tom[14] = { "TOMATO" }, P_Agl[10] = { "AGLIOOLIO" };

char *R_In[6] = { "Water", "Noodle", "SoupPowder" };
int R_Num[] = { 300, 1, 1, 99999 };
char *R_Unit[] = { "㎖ of"," ", " " };

char *Add[] = { "GreenOnion", "Egg", "BeanSprouts" };
int A_Num[] = { 2, 1, 1, 99999 };
char *A_Unit[] = { "pieces of", " ", "handful of" };

char *TP_In[] = { "Water", "Noodle", "TomatoSauce", "Salt" };
int TP_Num[] = { 1, 100, 300, 1, 99999 };
char *TP_Unit[] = { "ℓ of", "gram of", "ml of", "Table spoon of" };

char *AP_In[] = { "Water", "Noodle", "OliveOil", "Shrimp", "Garlic", "Peperoncino" };
int AP_Num[] = { 1, 100, 6, 5, 8, 1, 99999 };
char *AP_Unit[] = { "ℓ of", "gram of", "Table spoon of", " ", " ", "Table spoon of" };

/* Definition Of Global Functions */
int INGREDIENT(int PEO, int num[], char *str[], char *str2[]);

int main(void)
{
	printf("This progrmam shows the ingredients of certain foods\n");
	while (1)
	{	
		count = 0;												//while문 내에 초기화 함으로써 while문이 돌 때마다 초기화
		printf("\n>>You can exit with 'plz'<<\n");				
		printf("Available Foods[ Ramen / Pasta ]\n");
		printf("\nInsert Food Name: ");								//음식 이름 입력
		scanf("%s", Food);
		while (getchar() != '\n');
		strupr(Food);												//문자배열 대문자로

		if (strcmp(Food, Exit) == 0)								//프로그램 종료
			break;
		else if (strcmp(Food, Pasta) != 0 && strcmp(Food, Ramen) != 0)	//ramen과 pasta가 아닌 다른 입력
		{
			printf("Wrong Input. You can only choose [ramen/pasta]\n");
			continue;
		}



		printf("How many people? (Insert only number): ");			//인원수 입력
		scanf("%s", ch);
		while (getchar() != '\n');
	
		Checker(ch);												//숫자인지 확인

		if (rs == 'F')												//people이 숫자가 아닐 때	
		{
			printf("You can insert only number. You're input: [%s]\n", ch);
			continue;
		}
		people = atoi(ch);											//인원수 계산을 위해 char문자열을 int로 변환

		if (strcmp(Food, Ramen) == 0)								//라면일 경우
		{
				printf("****You selected RAMEN****\nDo you want special ramen? [ O / X ]\n");

				scanf("%c", &Special);								//스페셜라면과 기본라면 중 선택
				while (getchar() != '\n');
				Special = toupper(Special);

			if (Special == 'X')										//기본 라면일 경우
			{
				Partition();
				printf("\nNormal Ramen\n");
				INGREDIENT(people, R_Num, R_Unit, R_In);			//재료 출력
			}
			else if (Special == 'O')
			{
				Partition();
				printf("\nSpecial Ramen");							//스페셜 라면일 경우
				INGREDIENT(people, R_Num, R_Unit, R_In);			//재료 출력
				INGREDIENT(people, A_Num, A_Unit, Add);
			}
			else													//o/x가 아닌 다른 입력
			{
				printf("Wrong Input. You can only choose o/x.");
				continue;
			}
		}

		else if (strcmp(Food, Pasta) == 0)							//파스타일 경우 선택
		{
			printf("****You selected PASTA****\nYou can choose [ Tomato / AglioOlio ]");
			printf("\nWhich pasta?: ");								//토마토와 알리오올리오 중 선택
			scanf("%s", Type);
			strupr(Type);

			if (strcmp(Type, P_Tom) == 0)							//토마토 파스타일 경우
			{
				Partition();
				printf("\nTomato Pasta\n");
				INGREDIENT(people, TP_Num, TP_Unit, TP_In);			//재료 출력
			}
			else if (strcmp(Type, P_Agl) == 0)						//토마토 파스타일 경우
			{
				Partition();
				printf("\nAglio Olio Pasta\n");
				INGREDIENT(people, AP_Num, AP_Unit, AP_In);			//재료 출력
			}
			else													//tomato와 aglioolio가 아닌 다른 입력
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


int INGREDIENT(int PEO, int num[], char *str[], char *str2[])		//양, 단위, 재료명 순으로 입력받아 재료 출력해주는 함수
{
	if (count == 0)													//함수 중복 호출시 출력되지 않을 문구
	{
		printf("\n*Ingredients*\n");
		printf("For %d people\n", PEO);
	}
	else;
	for (int i = 0; num[i]!=99999 ;i++)								//재료출력
	{
		printf("\n");
		printf("%3d %s %s", PEO*(num[i]), str[i], str2[i]);
	}
	count++;
	return count;
}

