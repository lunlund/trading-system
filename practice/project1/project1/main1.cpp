#define _CRT_SECURE_NO_WARNINGS
#include"main1.h"
#include<cstring>
#include<string>
bool main_::administrator()
{
	cout << "请输入管理员姓名：" << endl;
	string a, b;
	cin >> a;
	cout << "请输入密码：" << endl;
	cin >> b;
	if (a == "admin"&&b == "123456")
		return 1;
	else
		return 0;

}
void main_::menu()
{
	cout << "=============================================" << endl;
	cout << "1. 管理员登录 2.用户注册 3.用户登录 4.退出程序" << endl;
	cout << "=============================================" << endl;
}
bool main_::sign_up()
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\user.txt", "a+");
	fseek(fp,0, SEEK_END);
	int m = ftell(fp) / sizeof(User);
	fseek(fp, 0, SEEK_SET);
	int n = m;
	User a,aa;
	strcpy(a.userID, "U000");
	for (int i = 1; ; i++)
	{
		a.userID[4 - i] = (char)(m % 10 + '0');
		m = m / 10;
		if (m == 0)
			break;
	}
	cout << a.userID << endl;
	cout << "请输入用户名（不超过10个英文字符）" << endl;
A:cin >> a.username;
	if (strlen(a.username) > 10)
	{
		cout << "超过十个字符，请重新输入" << endl;
		goto A;
	}
	for (int i = 0; i <= n - 1; i++)
	{
		fread(&aa, sizeof(User), 1, fp);
		if (strcmp(aa.username, a.username) == 0)
		{
			cout << "此用户名已有人使用，请重新输入" << endl;
			goto A;
		}
	}


	cout << "请输入密码，不超过20个字符" << endl;
B:cin >> a.password;
	if (strlen(a.password) > 20)
	{
		cout << "超过20个字符，请重新输入" << endl;
		goto B;
	}
	cout << "请输入电话号码，不超过20个字符" << endl;
C:cin >> a.phonenumber;
	if (strlen(a.password) > 20)
	{
		cout << "超过20个字符，请重新输入" << endl;
		goto C;
	}
	cout << "请输入地址，不超过40个字符" << endl;
D:cin >> a.address;
	if (strlen(a.address) > 40)
	{
		cout << "超过40个字符，请重新输入" << endl;
		goto D;
	}
	cout << "请输入充值钱数（系统自动保留一位小数）" << endl;
	cin >> a.balance;
	a.userstate = 1;
	fwrite(&a, sizeof(User), 1, fp);
	fclose(fp);
	return 1;

}
User* main_::sign_in()
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\user.txt", "r");
	char m[11];
	char n[21];
	cout << "请输入用户名" << endl;
	cin >> m;
	User *a = new User;
	fseek(fp,0,SEEK_END);
	int p = ftell(fp) / sizeof(User);
	fseek(fp, 0,SEEK_SET);
	//User *b = &a;
	for (int i = 0;i<=p-1; i++)
	{
		fread(a, sizeof(User), 1, fp);
		if (strcmp(a->username, m) == 0)
		{
			cout << "请输入密码" << endl;
			cin >> n;
			if (strcmp(n, a->password) == 0)
			{
				if (a->userstate == 0)
				{
					cout << "您的账户被封禁" << endl;
					return NULL;
				}
				else
				{
					cout << "登录成功" << endl;
					return a;
				}
			}
			else
			{
				cout << "密码错误，登录失败" << endl;
				return NULL;
			}
			break;
		}
		if (i == p - 1)
		{
			cout << "没有此用户" << endl;
			return NULL;
		}
	}
	return NULL;


}