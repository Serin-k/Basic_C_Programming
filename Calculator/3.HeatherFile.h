#include<stdio.h>	
#include<string.h>
#include<ctype.h>	
#include <stdlib.h>	

#include "SerinHeather.h"

int Calculate(int opn1, int opn2, char opr)						//계산해주는 함수
{
	int result;
	switch (opr)
	{
	case '+':
		result = opn1 + opn2;
		break;
	case '-':
		result = opn1 - opn2;
		break;
	case '*':
		result = opn1 * opn2;
		break;
	case '/':
		result = opn1 / opn2;
		break;
	}
	return result;
}
