#include<stdio.h>	
#include<string.h>
#include<ctype.h>	
#include <stdlib.h>	

#include"4.HeatherFile.h"

/*1711435 �輼��
[4��]  ���α׷�*/

/* Definition Of Global Variables */
int sum, i, j, k = 0;
int IntKor, IntEng, IntMath, IntSci;					//���ڿ��� ����� �μ����� ���������� ��ȯ�� �����ϴ� ����
char num;												//������� �Է��� ���� ����
char data[500];											//���Ͽ��� �о���� �����͸� ��� ������ ���� �迭
char Blank[5] = " \n";									//strtok���� �����ڷ� ���� �迭
char*pDATA;												//�ܾ� ������ �ɰ��� �� ���� �ּҸ� ������ �� ������
char*Add[100];											//�ܾ� ������ �ɰ��� ���� ���� �ּҵ��� ������ �ִ� ������ �迭
char tmp[100];											//���Ͽ��� �� ���ڿ��� �о���� �ӽ����� �迭
int Normal=1;

void Select(void);

int main()
{
	if ((fpi = fopen("in.txt", "r")) == NULL)												//�б� ���� ���������� ����
	{																						//�ش� ������ ���� ��� ���� ���� ���
		printf("Cannot open File \n");
		exit(1);
	}

	while (fgets(tmp, 100 ,fpi))															//���Ͽ��� ���ڿ� �о����
	{																						//���� ���ڿ� �Է��Լ��� ����txt�� ���ڿ� ���پ��� �о�� tmp�� �����Ѵ�.
		strcat(data, tmp);																	//����� tmp�� data�� �״´�.
		if (tmp == 0 || tmp == EOF)															//������ ���� �ٴٸ� ��� �����Է� ����.
			break;
	}
			   
	pDATA = strtok(data, Blank);															//����� \n�� �������� �ܾ �����Ͽ� �ܾ���� ù �ּҸ� pDATA�� �޴´�.
	
	while (pDATA != NULL)																	//������ �迭 Add�� ��ȯ���� �� �ܾ��� ù �ּ� ����
	{
		Add[k++]=pDATA;																		//pDATA�� �����͹迭Add�� �ϳ��� �״´�
		pDATA = strtok(NULL, Blank);														//���� �ܾ�� �Ѿ��.
	}	

		/*Storaging*/					
	for (i = 0;i < NUM;i++)																	//����ü�� �� ��� ����
	{
		j = i * 9;
		strcpy(ps[i].Name, Add[j++]);														//strcpy�� ���ڿ� ����� ����: �̸�	
		strcpy(ps[i].Gender, Add[j++]);														//����
		strcpy(ps[i].Age, Add[j++]);														//����
		strcpy(ps[i].Phone, Add[j++]);														//��ȭ��ȣ
		strcpy(ps[i].School, Add[j++]);														//�б�
		IntKor = atoi(Add[j++]);															//int������ ��ȯ�Ͽ� ����: ����-����
		ps[i].Score.Kor = IntKor;
		IntEng = atoi(Add[j++]);															//����-����
		ps[i].Score.Eng = IntEng;
		IntMath = atoi(Add[j++]);															//����-����
		ps[i].Score.Math = IntMath;
		IntSci = atoi(Add[j++]);															//����-����
		ps[i].Score.Sci = IntSci;
	}
	
	if ((fpo = fopen("out.txt", "wt")) == NULL)												//�ؽ�Ʈ ���� ���� out������ ����
	{																						//�ش� ������ ���� ��� ���� ���� ���
		printf("Cannot open File \n");
		exit(1);
	}

	printf("This program shows the result of the sorted text by your input standard.\n");
	printf("\nWhich standard do you want to sort by?");
	printf("\n(1)Name (2)Gender (3)Age (4)Phone Number (5)School Name (6)Score of Korean (7)Score of English (8)Score of Math (9)Score of Science");
	printf("\nYour Input: ");
	scanf("%c", &num);																		//������� �Է��� �޴´�.
	Select();																				//�Է¿� ���� ��� ��� �Լ� ȣ��
	if (Normal)																				//�������� �Է��� �Ǿ��ٸ�
		Average();																			//�� ������� ��� ����ϴ� �Լ� ȣ��

	fclose(fpi);																			//�о���� ������ �ݾ��ش�.
	fclose(fpo);																			//�᳽ ������ �ݾ��ش�.
	printf("\n\n���α׷��� ����˴ϴ�.����� out.txt���Ϸ� ��µ˴ϴ�.");


	return 0;
}





void Select(void)																			//����� �Է¿� ���� ��� ��� �Լ�
{
	switch (num)
	{
	case '1':
		NameSort();																			//�̸��� ��������
		break;
	case '2':
		GenderSort();																		//������ ��������
		break;
	case '3':
		AgeSort();																			//���̸� ��������
		break;
	case '4':
		PhoneSort();																		//��ȭ��ȣ�� ��������
		break;
	case '5':
		SchoolSort();																		//�б����� ��������
		break;
	case '6':
		KorSort();																			//���� ������ ��������
		break;
	case '7':
		EngSort();																			//���� ������ ��������
		break;
	case '8':
		MathSort();																			//���� ������ ��������
		break;
	case '9':
		SciSort();																			//���� ������ ��������
		break;
	default:
		Normal = 0;
		printf("\n�߸��� �Է��Դϴ�.");														//�ٸ� �Է��� ���� �� ����� ����.
	}
	FPartition();
}

