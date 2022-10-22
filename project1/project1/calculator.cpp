#include"calculator.h"
void calculator()
{
	cout << "请输入一个计算表达式" << endl;
	bool shuzi(char a);
	bool yanshu(char a);
	int dayu(char a, char b);
	char a[1000];
	float b[26];
	memset(b, 0, 26);
	M:cin.getline(a, 1000);
	for (int i = 0; i <= strlen(a) - 1; i++)
	{
		if (a[i] == ' ')
		{
			cout << "输入中有空格，不合法，请重新输入" << endl;
			goto M;
		}
	}
	if (check(a) == 0)
	{
		return ;
	}
	vector <char> change(a, a + strlen(a));
	int index;
	for (index = 0; index <= 25; index++)
	{
		int aa, bb;
		for (aa = 0; aa <= change.size() - 1; aa++)
		{
			if (yanshu(change[aa]) == 1)
				break;
		}
		if (aa == change.size())
			break;
		for (bb = aa + 1; bb <= change.size() - 1; bb++)
		{
			if (yanshu(change[bb]) == 0)
				break;
		}
		bb--;
		int i;
		float sum = 0;
		for (i = aa; i <= bb; i++)
		{
			if (change[i] == '.')
				break;
		}
		if (i == bb + 1)
		{
			for (int j = aa; j <= bb; j++)
			{
				sum = sum + (change[j] - '0')*pow(10, bb - j);
			}
		}
		else
		{
			for (int j = aa; j <= bb - 2; j++)
			{
				sum = sum + (change[j] - '0')*pow(10, bb - 2 - j);
			}
			sum = sum + (change[bb] - '0')*0.1;
		}
		change[bb] = (char)('a' + index);
		change.erase(change.begin() + aa, change.begin() + bb);
		b[index] = sum;
	}
	// for(int i=0;i<=change.size()-1;i++)
	// cout<<change[i];
	// cout<<endl<<b[0]<<" "<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<b[4];

	vector<char> shuchu(0);
	vector<char> caozuofu(0);
	for (int i = 0; i <= change.size() - 1; i++)
	{
		if (shuzi(change[i]) == 1)
		{
			shuchu.push_back(change[i]);
			continue;
		}
		if (change[i] == '(')
		{
			caozuofu.push_back(change[i]);
			continue;
		}
		if (change[i] == ')')
		{
			while (caozuofu.back() != '(')
			{
				shuchu.push_back(caozuofu.back());
				caozuofu.pop_back();
			}
			caozuofu.pop_back();
		}
		else
		{
		A:if (caozuofu.size() == 0 || caozuofu.back() == '(')
		{
			caozuofu.push_back(change[i]);
		}
		  else if (dayu(change[i], caozuofu.back()) == 1)
		{
			caozuofu.push_back(change[i]);
		}
		  else
		{
			shuchu.push_back(caozuofu.back());
			caozuofu.pop_back();
			goto A;
		}
		}
	}
	while (caozuofu.size() != 0)
	{
		shuchu.push_back(caozuofu.back());
		caozuofu.pop_back();

	}
	// for(int p=0;p<=shuchu.size()-1;p++)
	// {
	//     cout<<shuchu[p];
	// }
	//cout<<endl;
	//cout<<(char)(shuchu[0]-'0'+shuchu[1]);
	while (shuchu.size() != 1)
	{
		int p = 0;
		while (shuzi(shuchu[p]) == 1)
			p++;
		if (shuchu[p] == '+')
			b[shuchu[p - 2] - 'a'] = b[shuchu[p - 2] - 'a'] + b[shuchu[p - 1] - 'a'];
		if (shuchu[p] == '-')
			b[shuchu[p - 2] - 'a'] = b[shuchu[p - 2] - 'a'] - b[shuchu[p - 1] - 'a'];
		if (shuchu[p] == '*')
			b[shuchu[p - 2] - 'a'] = b[shuchu[p - 2] - 'a'] * b[shuchu[p - 1] - 'a'];
		if (shuchu[p] == '/')
			b[shuchu[p - 2] - 'a'] = b[shuchu[p - 2] - 'a'] / b[shuchu[p - 1] - 'a'];
		shuchu.erase(shuchu.begin() + p - 1, shuchu.begin() + p + 1);
	}
	cout << b[0];
	cout << endl;

}
bool shuzi(char a)
{
	if (a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a == ')')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int dayu(char a, char b)
{
	if ((a == '+' || a == '-') && (b == '+' || b == '-'))
		return 0;
	if ((a == '*' || a == '/') && (b == '*' || b == '/'))
		return 0;
	if ((a == '+' || a == '-') && (b == '*' || b == '/'))
		return -1;
	else
		return 1;
}
bool yunsuanfu(char a)
{
	if (a == '+' || a == '-' || a == '*' || a == '/')
		return 1;
	else return 0;
}
bool yanshu(char a)
{
	if (a == '0' || a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9' || a == '.')
		return 1;
	else
		return 0;

}