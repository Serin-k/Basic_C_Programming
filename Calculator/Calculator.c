#include<stdio.h>	
#include<string.h>
#include<ctype.h>	
#include <stdlib.h>	

#include"3.HeatherFile.h"

/*1711435 �輼��
[3��] ��Ģ���� ���� ���α׷�*/

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
int Validity=TRUE;																//������� 0�� ������ ��, ������� 0�� ���� ������, �ٸ� �Է��� ���� ������ �Ǵ� ���� ����

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
		Initialize();																//�ʱ�ȭ

		printf("If you want to exit program, input 'plz'\n");
		printf("Only integer input numbers are allowed\n");							//�������� ���ڸ� �������� ���
		printf("Divisions are expressed with ROUNDING DOWN\n");						//�������� �������� ��µ��� ���
		printf("Available Operators: * / + - \n\nInput: ");
		scanf("%s", Input);															//�����Է�
		while (getchar() != '\n');
		strupr(Input);
		
		if (strcmp(Input, Exit) == 0)
		{																			//���α׷� ����
			printf("\n\nExit Program\n");
			break;
		}


		len = strlen(Input);
		while (i < len)
		{
			if (Input[i] >= '0'&&Input[i] <= '9')									//���� �� ��
			{
				num = Input[i] - '0';												//���� ��ȯ			
				NUMstack[Ntop++] = num;												//���ÿ� push

				int r = i-1;
				if (Input[r] >= '0'&&Input[r] <= '9')								//������ �Է��� ������ ���(���ڸ� �̻� ��)
				{
					LotNumPop();
					NUMstack[Ntop++]= d;
				}

				int v = i + 1;
				if (Input[v] >= '0'&&Input[v] <= '9');	
				else																//���� ������ ���ڰ� �ƴ϶��(�� �Է��� �����ڸ� �� �Է��� ���)
				{
					MDCalculator();													//�ռ� ���������ڰ� �־��ٸ� ��� ����		
					if (Count)														//Prior�� ���� ���� �޾Ҵٸ� ������ ����
						NUMstack[Ntop++] = Prior;
				}

			}

			else if (Input[i] == '+' || Input[i] == '-' || Input[i] == '*' || Input[i] == '/')
			{
				if (Input[i] == '*' || Input[i] == '/')								//����, �������� ���
				{
					Otmp[OTtop++] = Input[i];										//������tmp���ÿ� push
					Ntmp = NUMstack[--Ntop];										//���� ����->���� tmp�� push
				}

				else if (Input[i] == '+' || Input[i] == '-')						//���ϱ�, ������ ���
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
		if (Validity)																	//Validity�� ���� TURE���
		{
			for (x = 0;x < Otop;x++)												//������ ���-������ ������ ������
			{
				opr = OPRstack[x];
				num1 = NUMstack[x];
				num2 = NUMstack[x + 1];
				result=Calculate(num1, num2, opr);
				NUMstack[x + 1] = result;
			}
		}

	if (Validity)																	//Validity�� ���� TURE���
	printf("\nAnswer: %d\n", result);												//��� ���
	Partition();
	}

	return 0;
}




int MDCalculator(void)											//����, ������ ���
{
	if (OTtop != 0)												//������ tmp�� ���� ���� ���
	{
		num1 = Ntmp;											//�� �ǿ�����
		num2 = NUMstack[--Ntop];								//�� �ǿ�����
		opr = Otmp[--OTtop];									//������ pop
		result=Calculate(num1, num2, opr);						//���

		if (Ntop < 0)
			Ntop = 0;
		Prior = result;
		Count = TRUE;											//if���� ���� Prior�� ���� ���޹޾Ҵٸ� Count�� true�� ����
	}
	else
		Count = FALSE;

	return NUMstack, Ntop, OTtop, Prior, Count;
}

int LotNumPop(void)												//���ڸ� �̻� �� pop
{
	int count = 0;
	d = 0;
	int q = i;

	do {
		if (count == 0)											//1�� �ڸ�
			d = NUMstack[--Ntop];
		else if (count == 1)										//10�� �ڸ� �̻�
			d = NUMstack[--Ntop] * 10 + d;
		else
			break;
		count++;
		q--;
	} while (Input[q] >= '0'&& Input[q] <= '9');				//���� �Է��� ������ �Ϳ� ���� ���� ����

	if (Ntop < 0)
		Ntop = 0;

	return d, Ntop;
}

void Initialize(void)											//��� ���� �ʱ�ȭ
{
	Validity = TRUE;
	opr=NULL;
	Ntmp=0;
	i = 0, d = 0;
	Otop = 0, Ntop =0, OTtop = 0;
	num = 0, num1 = 0, num2 = 0;
	Count = 0, Prior = 0, len = 0, result = 0;
}
