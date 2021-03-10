#include<stdio.h>	
#include<string.h>
#include<ctype.h>	
#include <stdlib.h>		
#define NUM 10

FILE *fpi;
FILE *fpo;

int sum;
double avg;												//����� ������ ����

struct SCORE
{
	int Kor;
	int Eng;
	int Math;
	int Sci;
};
struct IDENTITY
{
	char Name[10];
	char Gender[2];
	char Age[5];
	char Phone[20];
	char School[20];
	struct SCORE Score;
};
typedef struct IDENTITY I;
I ps[NUM];
I ntmp;

void FPartition()																			//��¹� ������ ���� ��¹�
{
	fprintf(fpo, "===============================================================================================================\n");
}



void KorAverage(void)																			//������� ��� ���ϰ�, ���
{
	avg = 0, sum = 0;																		//���� �ʱ�ȭ
	for (int i = 0;i < NUM;i++)																//����ü �迭0~9���� ���� �������� sum������ �����Ͽ� ����
	{
		sum = sum + ps[i].Score.Kor;
	}
	avg = sum / NUM;																		//��� ���
	fprintf(fpo, "		���� ���: %0.2f\n", avg);											//���� ���
}

void EngAverage(void)																			//������� ��� ���ϰ�, ���
{
	avg = 0, sum = 0;
	for (int i = 0;i < NUM;i++)
	{
		sum = sum + ps[i].Score.Eng;
	}
	avg = sum / NUM;
	fprintf(fpo, "		���� ���: %0.2f\n", avg);
}


void MathAverage(void)																			//���а��� ��� ���ϰ�, ���
{
	avg = 0, sum = 0;
	for (int i = 0;i < NUM;i++)
	{
		sum = sum + ps[i].Score.Math;
	}
	avg = sum / NUM;
	fprintf(fpo, "		���� ���: %0.2f\n", avg);
}

void SciAverage(void)																			//���а��� ��� ���ϰ�, ���
{
	avg = 0, sum = 0;
	for (int i = 0;i < NUM;i++)
	{
		sum = sum + ps[i].Score.Sci;
	}
	avg = sum / NUM;
	fprintf(fpo, "		���� ���: %0.2f\n", avg);
}

void Average()																				//�� ������� ��� ����ϴ� �Լ�
{
	KorAverage();
	EngAverage();
	MathAverage();
	SciAverage();
	FPartition();
}



void NameSort()																				//������ �������� ����
{
	for (int i = 0; i < 9; i++)																//���� ������ 9ȸ ���� ��
	{
		for (int j = 0; j < 9 - i; j++)														//j�� 0~9, 0~8, 0~7, 0~6 ...�� ���� ������ ����
		{
			if (strcmp(ps[j].Name, ps[j + 1].Name) > 0)										//����ü �迭 ������ ����� ���ڿ� �̸��� ũ�⸦ strcmp�� �� �ڰ��� ���ϸ� ���� ũ�� ����ü �迭�� �ε��������� �յ��� �ڸ��� �ٲ�.
			{
				ntmp = ps[j];
				ps[j] = ps[j + 1];
				ps[j + 1] = ntmp;
			}
		}
	}
	fprintf(fpo, "������ �������� ����\n");
	for (int r = 0;r < NUM;r++) {															//for���� ���� ����� ���Ͽ� ���
		fprintf(fpo, " ����: %-6s ����: %s ����: %s ��ȭ��ȣ: %s �б���: %-11s ����: %-3d ����: %-3d ����: %-3d ����: %-3d\n", ps[r].Name, ps[r].Gender, ps[r].Age, ps[r].Phone, ps[r].School, ps[r].Score.Kor, ps[r].Score.Eng, ps[r].Score.Math, ps[r].Score.Sci);
	}
}

void GenderSort()																			//������ �������� ����
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (strcmp(ps[j].Gender, ps[j + 1].Gender) > 0)
			{
				ntmp = ps[j];
				ps[j] = ps[j + 1];
				ps[j + 1] = ntmp;
			}
		}
	}
	fprintf(fpo, "������ �������� ����\n");
	for (int r = 0;r < NUM;r++) {
		fprintf(fpo, "����: %s, ����: %-6s ����: %s ��ȭ��ȣ: %s �б���: %-11s ����: %-3d ����: %-3d ����: %-3d ����: %-3d\n", ps[r].Gender, ps[r].Name, ps[r].Age, ps[r].Phone, ps[r].School, ps[r].Score.Kor, ps[r].Score.Eng, ps[r].Score.Math, ps[r].Score.Sci);
	}
}


void AgeSort()																				//������ �������� ����
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (strcmp(ps[j].Age, ps[j + 1].Age) > 0)
			{
				ntmp = ps[j];
				ps[j] = ps[j + 1];
				ps[j + 1] = ntmp;
			}
		}
	}
	fprintf(fpo, "���̸� �������� ����\n");
	for (int r = 0;r < NUM;r++) {
		fprintf(fpo, "����: %s, ����: %-6s, ����: %s ��ȭ��ȣ: %s �б���: %-11s ����: %-3d ����: %-3d ����: %-3d ����: %-3d\n", ps[r].Age, ps[r].Name, ps[r].Gender, ps[r].Phone, ps[r].School, ps[r].Score.Kor, ps[r].Score.Eng, ps[r].Score.Math, ps[r].Score.Sci);
	}
}

void PhoneSort()																			//��ȭ��ȣ�� �������� ����
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (strcmp(ps[j].Phone, ps[j + 1].Phone) > 0)
			{
				ntmp = ps[j];
				ps[j] = ps[j + 1];
				ps[j + 1] = ntmp;
			}
		}
	}
	fprintf(fpo, "��ȭ��ȣ�� �������� ����\n");
	for (int r = 0;r < NUM;r++) {
		fprintf(fpo, "��ȭ��ȣ: %s ����: %-6s ����: %s ����: %s �б���: %-11s ����: %-3d ����: %-3d ����: %-3d ����: %-3d\n", ps[r].Phone, ps[r].Name, ps[r].Gender, ps[r].Age, ps[r].School, ps[r].Score.Kor, ps[r].Score.Eng, ps[r].Score.Math, ps[r].Score.Sci);
	}
}

void SchoolSort()																			//�б� ���� �������� ����
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (strcmp(ps[j].School, ps[j + 1].School) > 0)
			{
				ntmp = ps[j];
				ps[j] = ps[j + 1];
				ps[j + 1] = ntmp;
			}
		}
	}
	fprintf(fpo, "�б����� �������� ����\n");
	for (int r = 0;r < NUM;r++) {
		fprintf(fpo, "�б���: %-11s ����: %-6s ����: %s ����: %s ��ȭ��ȣ: %s ����: %-3d ����: %-3d ����: %-3d ����: %-3d\n", ps[r].School, ps[r].Name, ps[r].Gender, ps[r].Age, ps[r].Phone, ps[r].Score.Kor, ps[r].Score.Eng, ps[r].Score.Math, ps[r].Score.Sci);
	}
}

void KorSort()																				//���� ������ �������� ����
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (ps[j].Score.Kor > ps[j + 1].Score.Kor)
			{
				ntmp = ps[j];
				ps[j] = ps[j + 1];
				ps[j + 1] = ntmp;
			}
		}
	}
	fprintf(fpo, "������� �������� ����\n");
	for (int r = 0;r < NUM;r++) {
		fprintf(fpo, "����: %-3d ����: %-6s ����: %s ����: %s ��ȭ��ȣ: %s �б���: %-11s ����: %-3d ����: %-3d ����: %-3d\n", ps[r].Score.Kor, ps[r].Name, ps[r].Gender, ps[r].Age, ps[r].Phone, ps[r].School, ps[r].Score.Eng, ps[r].Score.Math, ps[r].Score.Sci);
	}
}

void EngSort()																				//���� ������ �������� ����
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (ps[j].Score.Eng > ps[j + 1].Score.Eng)
			{
				ntmp = ps[j];
				ps[j] = ps[j + 1];
				ps[j + 1] = ntmp;
			}
		}
	}
	fprintf(fpo, "������� �������� ����\n");
	for (int r = 0;r < NUM;r++) {
		fprintf(fpo, "����: %-3d ����: %-6s ����: %s ����: %s ��ȭ��ȣ: %s �б���: %-11s ����: %-3d  ����: %-3d ����: %-3d\n", ps[r].Score.Eng, ps[r].Name, ps[r].Gender, ps[r].Age, ps[r].Phone, ps[r].School, ps[r].Score.Kor, ps[r].Score.Math, ps[r].Score.Sci);
	}
}

void MathSort()																				//���� ������ �������� ����
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (ps[j].Score.Math > ps[j + 1].Score.Math)
			{
				ntmp = ps[j];
				ps[j] = ps[j + 1];
				ps[j + 1] = ntmp;
			}
		}
	}
	fprintf(fpo, "���м����� �������� ����\n");
	for (int r = 0;r < NUM;r++) {
		fprintf(fpo, "����: %-3d ����: %-6s ����: %s ����: %s ��ȭ��ȣ: %s �б���: %-11s ����: %-3d ����: %-3d  ����: %-3d\n", ps[r].Score.Math, ps[r].Name, ps[r].Gender, ps[r].Age, ps[r].Phone, ps[r].School, ps[r].Score.Kor, ps[r].Score.Eng, ps[r].Score.Sci);
	}
}

void SciSort()																				//���� ������ �������� ����
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (ps[j].Score.Sci > ps[j + 1].Score.Sci)
			{
				ntmp = ps[j];
				ps[j] = ps[j + 1];
				ps[j + 1] = ntmp;
			}
		}
	}
	fprintf(fpo, "���м����� �������� ����\n");
	for (int r = 0;r < NUM;r++) {
		fprintf(fpo, "����: %-3d ����: %-6s ����: %s ����: %s ��ȭ��ȣ: %s �б���: %-11s ����: %-3d ����: %-3d ����: %-3d \n", ps[r].Score.Sci, ps[r].Name, ps[r].Gender, ps[r].Age, ps[r].Phone, ps[r].School, ps[r].Score.Kor, ps[r].Score.Eng, ps[r].Score.Math);
	}
}
