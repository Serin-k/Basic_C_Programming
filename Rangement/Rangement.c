#include<stdio.h>	
#include<string.h>
#include<ctype.h>	
#include <stdlib.h>	

#include"4.HeatherFile.h"

/*1711435 김세린
[4번]  프로그램*/

/* Definition Of Global Variables */
int sum, i, j, k = 0;
int IntKor, IntEng, IntMath, IntSci;					//문자열로 저장된 인수들을 정수형으로 변환해 저장하는 변수
char num;												//사용자의 입력을 받을 변수
char data[500];											//파일에서 읽어들인 데이터를 모아 저장할 문자 배열
char Blank[5] = " \n";									//strtok사용시 구분자로 사용될 배열
char*pDATA;												//단어 단위로 쪼개질 때 시작 주소를 전달해 줄 포인터
char*Add[100];											//단어 단위로 쪼개진 것의 시작 주소들을 가지고 있는 포인터 배열
char tmp[100];											//파일에서 한 문자열씩 읽어들일 임시적인 배열
int Normal=1;

void Select(void);

int main()
{
	if ((fpi = fopen("in.txt", "r")) == NULL)												//읽기 모드로 점수파일을 연다
	{																						//해당 파일이 없을 경우 다음 문구 출력
		printf("Cannot open File \n");
		exit(1);
	}

	while (fgets(tmp, 100 ,fpi))															//파일에서 문자열 읽어오기
	{																						//파일 문자열 입력함수로 점수txt의 문자열 한줄씩을 읽어와 tmp에 저장한다.
		strcat(data, tmp);																	//저장된 tmp를 data에 쌓는다.
		if (tmp == 0 || tmp == EOF)															//파일의 끝에 다다를 경우 파일입력 종료.
			break;
	}
			   
	pDATA = strtok(data, Blank);															//공백과 \n를 기준으로 단어를 구분하여 단어들의 첫 주소를 pDATA가 받는다.
	
	while (pDATA != NULL)																	//포인터 배열 Add에 반환받은 한 단어의 첫 주소 저장
	{
		Add[k++]=pDATA;																		//pDATA를 포인터배열Add에 하나씩 쌓는다
		pDATA = strtok(NULL, Blank);														//다음 단어로 넘어간다.
	}	

		/*Storaging*/					
	for (i = 0;i < NUM;i++)																	//구조체에 각 멤버 저장
	{
		j = i * 9;
		strcpy(ps[i].Name, Add[j++]);														//strcpy로 문자열 복사로 저장: 이름	
		strcpy(ps[i].Gender, Add[j++]);														//성별
		strcpy(ps[i].Age, Add[j++]);														//나이
		strcpy(ps[i].Phone, Add[j++]);														//전화번호
		strcpy(ps[i].School, Add[j++]);														//학교
		IntKor = atoi(Add[j++]);															//int형으로 변환하여 저장: 성적-국어
		ps[i].Score.Kor = IntKor;
		IntEng = atoi(Add[j++]);															//성적-영어
		ps[i].Score.Eng = IntEng;
		IntMath = atoi(Add[j++]);															//성적-수학
		ps[i].Score.Math = IntMath;
		IntSci = atoi(Add[j++]);															//성적-과학
		ps[i].Score.Sci = IntSci;
	}
	
	if ((fpo = fopen("out.txt", "wt")) == NULL)												//텍스트 쓰기 모드로 out파일을 연다
	{																						//해당 파일이 없을 경우 다음 문구 출력
		printf("Cannot open File \n");
		exit(1);
	}

	printf("This program shows the result of the sorted text by your input standard.\n");
	printf("\nWhich standard do you want to sort by?");
	printf("\n(1)Name (2)Gender (3)Age (4)Phone Number (5)School Name (6)Score of Korean (7)Score of English (8)Score of Math (9)Score of Science");
	printf("\nYour Input: ");
	scanf("%c", &num);																		//사용자의 입력을 받는다.
	Select();																				//입력에 따른 결과 출력 함수 호출
	if (Normal)																				//정상적인 입력이 되었다면
		Average();																			//각 과목들의 평균 출력하는 함수 호출

	fclose(fpi);																			//읽어들인 파일을 닫아준다.
	fclose(fpo);																			//써낸 파일을 닫아준다.
	printf("\n\n프로그램이 종료됩니다.결과는 out.txt파일로 출력됩니다.");


	return 0;
}





void Select(void)																			//사용자 입력에 따라 결과 출력 함수
{
	switch (num)
	{
	case '1':
		NameSort();																			//이름을 기준으로
		break;
	case '2':
		GenderSort();																		//성별을 기준으로
		break;
	case '3':
		AgeSort();																			//나이를 기준으로
		break;
	case '4':
		PhoneSort();																		//전화번호를 기준으로
		break;
	case '5':
		SchoolSort();																		//학교명을 기준으로
		break;
	case '6':
		KorSort();																			//국어 성적을 기준으로
		break;
	case '7':
		EngSort();																			//영어 성적을 기준으로
		break;
	case '8':
		MathSort();																			//수학 성적을 기준으로
		break;
	case '9':
		SciSort();																			//과학 성적을 기준으로
		break;
	default:
		Normal = 0;
		printf("\n잘못된 입력입니다.");														//다른 입력이 들어올 시 출력할 문구.
	}
	FPartition();
}

