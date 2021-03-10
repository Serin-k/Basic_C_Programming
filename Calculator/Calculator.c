#include<stdio.h>	
#include<string.h>
#include<ctype.h>	
#include <stdlib.h>	

#include"3.HeatherFile.h"

/*1711435 김세린
[3번] 사칙연산 계산기 프로그램*/

#define TRUE 1
#define FALSE 0

/* Definition Of Global Variables */
char b, c, opr;
char Input[80];
char OPRstack[30], Otmp[20];
char Exit[10] = { "PLZ" };
int NUMstack[30];
int Ntmp;
int i,x, d;
int num, num1, num2;
int Otop, Ntop, OTtop;
int Count, Prior, result, len;
int Validity=TRUE;																//결과값이 0이 나왔을 때, 계산으로 0이 나온 것인지, 다른 입력이 들어온 것인지 판단 위한 변수

/* Definition Of Global Functions */
int MDCalculator(void);
int LotNumPop(void);
void Initialize(void);

int main()
{
	Partition();
	printf("<<Calculator Program>>\n");	

	while (1)
	{
		Initialize();																//초기화

		printf("If you want to exit program, input 'plz'\n");
		printf("Only integer input numbers are allowed\n");							//정수형의 숫자만 가능함을 출력
		printf("Divisions are expressed with ROUNDING DOWN\n");						//나눗셈은 버림으로 출력됨을 출력
		printf("Available Operators: * / + - \n\nInput: ");
		scanf("%s", Input);															//수식입력
		while (getchar() != '\n');
		strupr(Input);
		
		if (strcmp(Input, Exit) == 0)
		{																			//프로그램 종료
			printf("\n\nExit Program\n");
			break;
		}


		len = strlen(Input);
		while (i < len)
		{
			if (Input[i] >= '0'&&Input[i] <= '9')									//숫자 일 때
			{
				num = Input[i] - '0';												//정수 변환			
				NUMstack[Ntop++] = num;												//스택에 push

				int r = i-1;
				if (Input[r] >= '0'&&Input[r] <= '9')								//이전에 입력이 숫자일 경우(두자리 이상 수)
				{
					LotNumPop();
					NUMstack[Ntop++]= d;
				}

				int v = i + 1;
				if (Input[v] >= '0'&&Input[v] <= '9');	
				else																//다음 루프가 숫자가 아니라면(현 입력이 일의자리 수 입력일 경우)
				{
					MDCalculator();													//앞서 곱셈연산자가 있었다면 계산 수행		
					if (Count)														//Prior의 값을 전달 받았다면 다음을 수행
						NUMstack[Ntop++] = Prior;
				}

			}

			else if (Input[i] == '+' || Input[i] == '-' || Input[i] == '*' || Input[i] == '/')
			{
				if (Input[i] == '*' || Input[i] == '/')								//곱셈, 나눗셈인 경우
				{
					Otmp[OTtop++] = Input[i];										//연산자tmp스택에 push
					Ntmp = NUMstack[--Ntop];										//숫자 스택->숫자 tmp로 push
				}

				else if (Input[i] == '+' || Input[i] == '-')						//더하기, 빼기인 경우
				{
					OPRstack[Otop++] = Input[i];
				}
			}

			else if (Input[i] == ' ');

			else
			{
				Partition();
				printf("		Error!\n");
				printf("   Plz Check Your Fuction and Try Again:(\n");
				Validity = FALSE;
				break;
			}
			i++;
		}
		if (Validity)																	//Validity의 값이 TURE라면
		{
			for (x = 0;x < Otop;x++)												//나머지 계산-연산자 스택의 끝까지
			{
				opr = OPRstack[x];
				num1 = NUMstack[x];
				num2 = NUMstack[x + 1];
				result=Calculate(num1, num2, opr);
				NUMstack[x + 1] = result;
			}
		}

	if (Validity)																	//Validity의 값이 TURE라면
	printf("\nAnswer: %d\n", result);												//결과 출력
	Partition();
	}

	return 0;
}




int MDCalculator(void)											//곱셈, 나눗셈 계산
{
	if (OTtop != 0)												//연산자 tmp에 값이 있을 경우
	{
		num1 = Ntmp;											//앞 피연산자
		num2 = NUMstack[--Ntop];								//뒤 피연산자
		opr = Otmp[--OTtop];									//연산자 pop
		result=Calculate(num1, num2, opr);						//계산

		if (Ntop < 0)
			Ntop = 0;
		Prior = result;
		Count = TRUE;											//if문을 거쳐 Prior의 값을 전달받았다면 Count에 true값 전달
	}
	else
		Count = FALSE;

	return NUMstack, Ntop, OTtop, Prior, Count;
}

int LotNumPop(void)												//두자리 이상 수 pop
{
	int count = 0;
	d = 0;
	int q = i;

	do {
		if (count == 0)											//1의 자리
			d = NUMstack[--Ntop];
		else if (count == 1)										//10의 자리 이상
			d = NUMstack[--Ntop] * 10 + d;
		else
			break;
		count++;
		q--;
	} while (Input[q] >= '0'&& Input[q] <= '9');				//이전 입력이 숫자인 것에 한해 루프 수행

	if (Ntop < 0)
		Ntop = 0;

	return d, Ntop;
}

void Initialize(void)											//모든 변수 초기화
{
	Validity = TRUE;
	opr=NULL;
	Ntmp=0;
	i = 0, d = 0;
	Otop = 0, Ntop =0, OTtop = 0;
	num = 0, num1 = 0, num2 = 0;
	Count = 0, Prior = 0, len = 0, result = 0;
}
