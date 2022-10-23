#include"vague.h"
#include<cstring>
bool f(char *input, char *pre)
{
	int j = 0;
	for (int i = 0; i <= strlen(input) - 1; i++)
	{
		for (; j <= strlen(pre) - 1; j++)
		{
			if (input[i] == pre[j])
			{				
				j++;
				break;
			}	
			if (j == strlen(pre) - 1)
				return 0;
		}
		if (j == strlen(pre)&&i!=strlen(input)-1)
			return 0;
	}
	return 1;
}