#include<stdio.h>	
#include<string.h>
#include<ctype.h>	
#include <stdlib.h>		


void Partition()
{
	printf("\n======================================================\n");
}

int Checker(char *ch)													//숫자면 통과, 숫자가 아니면 rs에'F'를 대입해 돌려주는 함수
{
	int c=0;
	char rs;
	rs = NULL;															//리턴 값 초기화
	while (ch[c] != NULL)
	{
		if (isdigit(ch[c]) != 0);
		else
			rs = 'F';
		c++;
	}
	return rs;
}





