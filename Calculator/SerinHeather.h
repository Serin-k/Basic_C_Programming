#include<stdio.h>	
#include<string.h>
#include<ctype.h>	
#include <stdlib.h>		


void Partition()
{
	printf("\n======================================================\n");
}

int Checker(char *ch)													//���ڸ� ���, ���ڰ� �ƴϸ� rs��'F'�� ������ �����ִ� �Լ�
{
	int c=0;
	char rs;
	rs = NULL;															//���� �� �ʱ�ȭ
	while (ch[c] != NULL)
	{
		if (isdigit(ch[c]) != 0);
		else
			rs = 'F';
		c++;
	}
	return rs;
}





