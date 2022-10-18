#include"vague.h"
#include<cstring>
bool f(char *input, char *pre)
{
	for (int i = 0; i <= strlen(input) - 1; i++)
	{
		for (int j = 0; j <= strlen(pre) - 1; j++)
		{
			if (input[i] == pre[j])
				break;
			if (j == strlen(pre) - 1)
				return 0;
		}
	}
	return 1;
}