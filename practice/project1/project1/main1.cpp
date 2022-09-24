#define _CRT_SECURE_NO_WARNINGS
#include"main1.h"
#include<cstring>
#include<time.h>
#include<Windows.h>
bool main_::administrator()
{
	char ab[100];
	char b[100];
	cout << "请输入管理员姓名：" << endl;
	cin.getline(ab, 100);
	cout << "请输入密码：" << endl;
	cin.getline(b,100);
	if (strcmp(ab,"admin")==0&&strcmp(b,"123456")==0)
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
	char username[100], password[100], address[100],phonenumber[100];
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
A:cin.getline(username, 100);
	if (strlen(username) > 10)
	{
		cout << "超过十个字符，请重新输入" << endl;
		goto A;
	}
	strcpy(a.username, username);
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
B:cin.getline(password, 100);
	if (strlen(password) > 20)
	{
		cout << "超过20个字符，请重新输入" << endl;
		goto B;
	}
	strcpy(a.password, password);
	cout << "请输入电话号码，不超过20个字符" << endl;
C:cin.getline(phonenumber,100);
	if (strlen(password) > 20)
	{
		cout << "超过20个字符，请重新输入" << endl;
		goto C;
	}
	strcpy(a.phonenumber, phonenumber);
	cout << "请输入地址，不超过40个字符" << endl;
D:cin.getline(address, 100);
	if (strlen(address) > 40)
	{
		cout << "超过40个字符，请重新输入" << endl;
		goto D;
	}
	strcpy(a.address, address);
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
	char m[100];
	char n[100];
	cout << "请输入用户名" << endl;
	cin.getline(m, 100);
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
			cin.getline(n, 100);
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
void main_::check()
{
	//寻找同一商品的state预支付订单，是否到时间，放在数组中，排序，与此商品数量进行比较，两种情况，选出报价高的前数量者，改变订单状态
	//改变商品数量，-购买人数，改变商品状态
	//改变购买者的钱包数量金额
	FILE *fp1 = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\user.txt", "r");
	FILE *fp2 = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\order.txt", "r");
	fseek(fp1, 0, SEEK_END);
	int mm = ftell(fp1) / sizeof(User);
	fseek(fp1, 0, SEEK_SET);//将user，order全部取出
	User *u = new User[mm];
	for (int i = 0; i <= mm - 1; i++)
	{
		fread(&u[i], sizeof(User), 1, fp1);
	}
	fseek(fp2, 0, SEEK_END);
	int mmm = ftell(fp2) / sizeof(Order);
	fseek(fp2, 0, SEEK_SET);
	Order *o = new Order[mmm];
	for (int i = 0; i <= mmm - 1; i++)
	{
		fread(&o[i], sizeof(Order), 1, fp2);
	}
	time_t timep;
	time(&timep);
	char tmp[11];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d", localtime(&timep));
	//strcpy(a.addedDate, tmp);
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "r");
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(Commodity);
	fseek(fp, 0, SEEK_SET);
	Commodity *c = new Commodity[m];
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&c[i], sizeof(Commodity), 1, fp);
	}
	fclose(fp);
	fclose(fp1);
	fclose(fp2);
	for (int i = 0; i <= m - 1; i++)
	{
		Order *oo[1000];
		int j = 0,sum=0;
		if (c[i].state == 1 )//if (c[i].state == 1 && strcmp(c[i].addedDate, tmp) != 0)
		{
			for (int ii = 0; ii <= mmm - 1; ii++)
			{
				if (strcmp(o[ii].commodityID, c[i].commodityID) == 0&&o[ii].state==0)
				{
					oo[j] = &o[ii];
					j++;
					sum += o[ii].number;
				}
			}
			if (sum <= c[i].number)
			{
				c[i].number -= sum;
				c[i].state = 0;
				for (int ii = 0; ii <= mm - 1; ii++)
				{
					for (int jj = 0; jj <= j - 1; jj++)
					{
						oo[jj]->state = 1;
						if (strcmp(oo[jj]->buyerID, u[ii].userID) == 0)
						{
							u[ii].balance -= oo[jj]->number*(oo[jj]->unitPrice);//mm user,mmm oreder,m commodity
						}
					}
				}
			}
			else
			{
				//c[i].number = 0;
				//c[i].state = 0;
				int max;
				for (int jj = 0;jj<=j-1;jj++)
				{
					max = jj;
					Order *l = oo[jj];
					for (int p = jj + 1; p <= j - 1; p++)
					{
						if (oo[p]->unitPrice > l->unitPrice)
						{
							max = p;
							l = oo[p];
						}
					}
					l = oo[jj];
					oo[jj] = oo[max];
					oo[max] = l;
				}
				int sum = 0;
				for (int p = 0; p <= j - 1; p++)
				{
					oo[p]->state = 2;
				}
				for (int p = 0; p <= j - 1; p++)
				{
					sum += oo[p]->number;
					oo[p]->state = 1;
						
					if (sum < c[i].number)
					{
						for (int ii = 0; ii <= mm - 1; mm++)
						{
							if (strcmp(oo[p]->buyerID, u[ii].userID) == 0)
							{
								u[ii].balance -= oo[p]->number*(oo[p]->unitPrice);
								break;
							}
						}
					}
					else if (sum == c[i].number)
					{
						for (int ii = 0; ii <= mm - 1; mm++)
						{
							if (strcmp(oo[p]->buyerID, u[ii].userID) == 0)
							{
								u[ii].balance -= oo[p]->number*(oo[p]->unitPrice);
								break;
							}
						}
						break;
					}
					else
					{
						oo[p]->number = c[i].number - sum;
						for (int ii = 0; ii <= mm - 1; mm++)
						{
							if (strcmp(oo[p]->buyerID, u[ii].userID) == 0)
							{
								u[ii].balance -= oo[p]->number*(oo[p]->unitPrice);
								break;
							}
						}
						break;
					}
				}
				c[i].number = 0;
			}
			c[i].state = 0;
		}
	}//mm user, mmm oreder, m commodity
	FILE *fp3 = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\user.txt", "w");
	FILE *fp4 = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\order.txt", "w");
	FILE *fp5 = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "w");
	for (int i = 0; i <= mm - 1; i++)
	{
		fwrite(&u[i], sizeof(User), 1, fp3);
	}
	for (int ii = 0; ii <= mmm - 1; mmm++)
	{
		fwrite(&o[ii], sizeof(Order), 1, fp4);
	}
	for (int iii = 0; iii <= m - 1; iii++)
	{
		fwrite(&c[iii], sizeof(Commodity), 1, fp5);
	}
	fclose(fp3);
	fclose(fp4);
	fclose(fp5);
}