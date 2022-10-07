#define _CRT_SECURE_NO_WARNINGS
#include"information.h"
void information::menu()
{
	cout << "=================================================" << endl;
	cout << "1.查看个人信息 2.修改信息 3.充值 4.返回用户主界面" << endl;
	cout << "==================================================" << endl;

}
void information::self_info(User &a)
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\user.txt", "r");
	cout << "****************" << endl;
	cout << "用户名：" << a.username << endl;
	cout << "联系方式：" << a.phonenumber << endl;
	cout << "地址：" << a.address << endl;
	cout << "钱包余额：" << a.balance << endl;
	cout << "******************" << endl;
	fclose(fp);

}
void information::modify_info(User &aa)
{
	char k[100];
	char username[100], phonenumber[100], address[100];
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\user.txt", "r");
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(User);
	fseek(fp, 0, SEEK_SET);
	cout << "请输入修改的属性（1.用户名 2.联系方式 3.地址）" << endl;
	int n;
D://cin >> n; 
	while (scanf_s("%d", &n) == 0)
	{
		while (getchar() != '\n');
		cout << "输入错误,请重新输入" << endl;
	}
	cin.getline(k, 100);
	if (n == 1)
	{
		cout << "请输入修改后的用户名(不超过10个字符）" << endl;
	A:cin.getline(username, 100);
		if (strlen(username) > 10)
		{
			cout << "用户名超过10个字符，请重新输入" << endl;
			goto A;
		}
		strcpy(aa.username, username);
	}
	else if (n == 2)
	{
		cout << "请输入修改后的联系方式(不超过20个字符）" << endl;
	B:cin.getline(phonenumber,100);
		if (strlen(phonenumber) > 20)
		{
			cout << "联系方式超过20个字符，请重新输入" << endl;
			goto B;
		}
		strcpy(aa.phonenumber, phonenumber);
	}
	else if (n == 3)
	{
		cout << "请输入修改后的地址(不超过40个字符）" << endl;
	C:cin.getline(address,100);
		if (strlen(address) > 40)
		{
			cout << "地址超过40个字符，请重新输入" << endl;
			goto C;
		}
		strcpy(aa.address, address);
	}
	else
	{
		cout << "输入错误，请重新输入" << endl;
		goto D;
	}
	User aba;
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&aba, sizeof(User), 1, fp);
		if (strcmp(aba.username, aa.username) == 0 && strcmp(aba.userID, aa.userID) != 0)
		{
			cout << "此用户名已有人使用，请重新输入" << endl;
			goto A;
		}
	}
	fseek(fp, 0, SEEK_SET);
	User *a = new User[m];
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&a[i], sizeof(User), 1, fp);
	}
	for (int i = 0; i <= m - 1; i++)
	{
		if (strcmp(a[i].userID, aa.userID) == 0)
		{
			a[i] = aa;
		}
	}
	fclose(fp);
	FILE *fp1 = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\user.txt", "w");
	for (int i = 0; i <= m - 1; i++)
	{
		fwrite(&a[i], sizeof(User), 1, fp1);
	}
	fclose(fp1);
	delete[]a;
	cout << "修改成功" << endl;

}
void information::recharge(User &aa)
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\user.txt", "r");
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(User);
	fseek(fp, 0, SEEK_SET);
	cout << "请输入充值金额" << endl;
	double aaa;
	//cin >> aaa;
	while (scanf_s("%lf", &aaa) == 0)
	{
		while (getchar() != '\n');
		cout << "输入错误,请重新输入" << endl;
	}
	aa.balance += aaa;
	User *a = new User[m];
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&a[i], sizeof(User), 1, fp);
		if (strcmp(a[i].userID, aa.userID) == 0)
		{
			a[i] = aa;
		}
	}
	fclose(fp);
	FILE *fp1 = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\user.txt", "w");
	for (int i = 0; i <= m - 1; i++)
	{
		fwrite(&a[i], sizeof(User), 1, fp1);
	}
	fclose(fp1);
	delete[]a;
	cout << "充值成功" << endl;
}