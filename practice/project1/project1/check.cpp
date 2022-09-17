#include"check.h"
bool check(char a[])
{
	bool zifu(char a);
	bool shuzi_(char a);
	bool caozuofu(char a);
	int left(char a[]);
	int right(char a[]);
	int i;
	for (i = 0; i <= strlen(a) - 1; i++)
	{
		if (zifu(a[i]) == 0)
		{
			cout << "输入错误，您输入的第" << i << "个字符系统无法识别" << endl;
			return 0;
		}
	}
	for (i = 0; i <= strlen(a) - 1; i++)
	{
		if (a[i] == '.' && (shuzi_(a[i + 1]) == 0 || i == strlen(a) - 1))
		{
			cout << "小数点后没有数字" << endl;
			return 0;
		}
		if (a[i] == '.'&&i < strlen(a) - 2 && shuzi_(a[i + 2]) == 1)
		{
			cout << "本系统只支持小数点后一位" << endl;
			return 0;
		}
		if (caozuofu(a[i]) == 1 && (i == strlen(a) - 1 || caozuofu(a[i + 1]) == 1))
		{
			cout << "两个操作符不能相连" << endl;
			return 0;
		}
	}
	if (left(a) != right(a))
	{
		cout << "括号不匹配" << endl;
		return 0;
	}
	int aa = 0, bb = 0;
	for (int m = 0; m <= strlen(a) - 1; m++)
	{
		if (a[m] == '(')
		{
			aa++;
			if (caozuofu(a[m + 1]) == 1 || i == strlen(a) - 1)
			{
				cout << "左括号后需要有数字" << endl;
				return 0;
			}
		}
		if (a[m] == ')')
		{
			bb++;
			if (i < strlen(a) - 1 && shuzi_(a[m + 1]) == 1)
			{
				cout << "右括号后不能直接跟数字" << endl;
				return 0;
			}
		}
		if (aa < bb)
		{
			cout << "左括号与右括号不匹配" << endl;
			return 0;
		}
	}
	return 1;
}
bool zifu(char a)
{
	if (a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a == ')' || a == '.' || a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9')
		return 1;
	else
		return 0;
}
bool shuzi_(char a)
{
	if (a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9' || a == '0')
		return 1;
	else
		return 0;
}
bool caozuofu(char a)
{
	if (a == '+' || a == '-' || a == '*' || a == '/' || a == '.')
		return 1;
	else
		return 0;
}
int left(char a[])
{
	int i = 0;
	for (int j = 0; j <= strlen(a) - 1; j++)
	{
		if (a[j] == '(')
			i++;
	}
	return i;
}
int right(char a[])
{
	int i = 0;
	for (int j = 0; j <= strlen(a) - 1; j++)
	{
		if (a[j] == ')')
			i++;
	}
	return i;

}