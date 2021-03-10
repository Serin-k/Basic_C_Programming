#include<stdio.h>	
#include<string.h>
#include<ctype.h>	
#include <stdlib.h>		
#define NUM 10

FILE *fpi;
FILE *fpo;

int sum;
double avg;												//평균을 저장할 변수

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

void FPartition()																			//출력문 구분을 위한 출력문
{
	fprintf(fpo, "===============================================================================================================\n");
}



void KorAverage(void)																			//국어과목 평균 구하고, 출력
{
	avg = 0, sum = 0;																		//변수 초기화
	for (int i = 0;i < NUM;i++)																//구조체 배열0~9까지 돌며 국어멤버만 sum변수에 누적하여 저장
	{
		sum = sum + ps[i].Score.Kor;
	}
	avg = sum / NUM;																		//평균 계산
	fprintf(fpo, "		국어 평균: %0.2f\n", avg);											//파일 출력
}

void EngAverage(void)																			//영어과목 평균 구하고, 출력
{
	avg = 0, sum = 0;
	for (int i = 0;i < NUM;i++)
	{
		sum = sum + ps[i].Score.Eng;
	}
	avg = sum / NUM;
	fprintf(fpo, "		영어 평균: %0.2f\n", avg);
}


void MathAverage(void)																			//수학과목 평균 구하고, 출력
{
	avg = 0, sum = 0;
	for (int i = 0;i < NUM;i++)
	{
		sum = sum + ps[i].Score.Math;
	}
	avg = sum / NUM;
	fprintf(fpo, "		수학 평균: %0.2f\n", avg);
}

void SciAverage(void)																			//과학과목 평균 구하고, 출력
{
	avg = 0, sum = 0;
	for (int i = 0;i < NUM;i++)
	{
		sum = sum + ps[i].Score.Sci;
	}
	avg = sum / NUM;
	fprintf(fpo, "		과학 평균: %0.2f\n", avg);
}

void Average()																				//각 과목들의 평균 출력하는 함수
{
	KorAverage();
	EngAverage();
	MathAverage();
	SciAverage();
	FPartition();
}



void NameSort()																				//성명을 기준으로 정렬
{
	for (int i = 0; i < 9; i++)																//다음 포문은 9회 돌게 됨
	{
		for (int j = 0; j < 9 - i; j++)														//j가 0~9, 0~8, 0~7, 0~6 ...을 돌며 다음을 수행
		{
			if (strcmp(ps[j].Name, ps[j + 1].Name) > 0)										//구조체 배열 변수의 멤버인 문자열 이름의 크기를 strcmp로 앞 뒤간에 비교하며 앞이 크면 구조체 배열의 인덱스값으로 앞뒤의 자리를 바꿈.
			{
				ntmp = ps[j];
				ps[j] = ps[j + 1];
				ps[j + 1] = ntmp;
			}
		}
	}
	fprintf(fpo, "성명을 기준으로 정렬\n");
	for (int r = 0;r < NUM;r++) {															//for문을 돌며 결과값 파일에 출력
		fprintf(fpo, " 성명: %-6s 성별: %s 나이: %s 전화번호: %s 학교명: %-11s 국어: %-3d 영어: %-3d 수학: %-3d 과학: %-3d\n", ps[r].Name, ps[r].Gender, ps[r].Age, ps[r].Phone, ps[r].School, ps[r].Score.Kor, ps[r].Score.Eng, ps[r].Score.Math, ps[r].Score.Sci);
	}
}

void GenderSort()																			//성별을 기준으로 정렬
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
	fprintf(fpo, "성별을 기준으로 정렬\n");
	for (int r = 0;r < NUM;r++) {
		fprintf(fpo, "성별: %s, 성명: %-6s 나이: %s 전화번호: %s 학교명: %-11s 국어: %-3d 영어: %-3d 수학: %-3d 과학: %-3d\n", ps[r].Gender, ps[r].Name, ps[r].Age, ps[r].Phone, ps[r].School, ps[r].Score.Kor, ps[r].Score.Eng, ps[r].Score.Math, ps[r].Score.Sci);
	}
}


void AgeSort()																				//나이을 기준으로 정렬
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
	fprintf(fpo, "나이를 기준으로 정렬\n");
	for (int r = 0;r < NUM;r++) {
		fprintf(fpo, "나이: %s, 성명: %-6s, 성별: %s 전화번호: %s 학교명: %-11s 국어: %-3d 영어: %-3d 수학: %-3d 과학: %-3d\n", ps[r].Age, ps[r].Name, ps[r].Gender, ps[r].Phone, ps[r].School, ps[r].Score.Kor, ps[r].Score.Eng, ps[r].Score.Math, ps[r].Score.Sci);
	}
}

void PhoneSort()																			//전화번호를 기준으로 정렬
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
	fprintf(fpo, "전화번호를 기준으로 정렬\n");
	for (int r = 0;r < NUM;r++) {
		fprintf(fpo, "전화번호: %s 성명: %-6s 성별: %s 나이: %s 학교명: %-11s 국어: %-3d 영어: %-3d 수학: %-3d 과학: %-3d\n", ps[r].Phone, ps[r].Name, ps[r].Gender, ps[r].Age, ps[r].School, ps[r].Score.Kor, ps[r].Score.Eng, ps[r].Score.Math, ps[r].Score.Sci);
	}
}

void SchoolSort()																			//학교 명을 기준으로 정렬
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
	fprintf(fpo, "학교명을 기준으로 정렬\n");
	for (int r = 0;r < NUM;r++) {
		fprintf(fpo, "학교명: %-11s 성명: %-6s 성별: %s 나이: %s 전화번호: %s 국어: %-3d 영어: %-3d 수학: %-3d 과학: %-3d\n", ps[r].School, ps[r].Name, ps[r].Gender, ps[r].Age, ps[r].Phone, ps[r].Score.Kor, ps[r].Score.Eng, ps[r].Score.Math, ps[r].Score.Sci);
	}
}

void KorSort()																				//국어 성적을 기준으로 정렬
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
	fprintf(fpo, "국어성적을 기준으로 정렬\n");
	for (int r = 0;r < NUM;r++) {
		fprintf(fpo, "국어: %-3d 성명: %-6s 성별: %s 나이: %s 전화번호: %s 학교명: %-11s 영어: %-3d 수학: %-3d 과학: %-3d\n", ps[r].Score.Kor, ps[r].Name, ps[r].Gender, ps[r].Age, ps[r].Phone, ps[r].School, ps[r].Score.Eng, ps[r].Score.Math, ps[r].Score.Sci);
	}
}

void EngSort()																				//영어 성적을 기준으로 정렬
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
	fprintf(fpo, "영어성적을 기준으로 정렬\n");
	for (int r = 0;r < NUM;r++) {
		fprintf(fpo, "영어: %-3d 성명: %-6s 성별: %s 나이: %s 전화번호: %s 학교명: %-11s 국어: %-3d  수학: %-3d 과학: %-3d\n", ps[r].Score.Eng, ps[r].Name, ps[r].Gender, ps[r].Age, ps[r].Phone, ps[r].School, ps[r].Score.Kor, ps[r].Score.Math, ps[r].Score.Sci);
	}
}

void MathSort()																				//수학 성적을 기준으로 정렬
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
	fprintf(fpo, "수학성적을 기준으로 정렬\n");
	for (int r = 0;r < NUM;r++) {
		fprintf(fpo, "수학: %-3d 성명: %-6s 성별: %s 나이: %s 전화번호: %s 학교명: %-11s 국어: %-3d 영어: %-3d  과학: %-3d\n", ps[r].Score.Math, ps[r].Name, ps[r].Gender, ps[r].Age, ps[r].Phone, ps[r].School, ps[r].Score.Kor, ps[r].Score.Eng, ps[r].Score.Sci);
	}
}

void SciSort()																				//과학 성적을 기준으로 정렬
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
	fprintf(fpo, "과학성적을 기준으로 정렬\n");
	for (int r = 0;r < NUM;r++) {
		fprintf(fpo, "과학: %-3d 성명: %-6s 성별: %s 나이: %s 전화번호: %s 학교명: %-11s 국어: %-3d 영어: %-3d 수학: %-3d \n", ps[r].Score.Sci, ps[r].Name, ps[r].Gender, ps[r].Age, ps[r].Phone, ps[r].School, ps[r].Score.Kor, ps[r].Score.Eng, ps[r].Score.Math);
	}
}
