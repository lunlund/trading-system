#define _CRT_SECURE_NO_WARNINGS
#include"main1.h"
#include<cstring>
#include<time.h>
#include<Windows.h>
#include"vector.h"
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
	//cin >> a.balance;
	while (scanf_s("%lf", &a.balance) == 0)
	{
		while (getchar() != '\n');
		cout << "输入错误,请重新输入" << endl;
	}
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
	fseek(fp, 0, SEEK_END);
	int p = ftell(fp) / sizeof(User);
	fseek(fp, 0, SEEK_SET);
	//User *b = &a;
	for (int i = 0; i <= p - 1; i++)
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
	FILE *fpu = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\user.txt", "r");
	FILE *fpo = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\order.txt", "r");
	FILE *fpc = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "r");
	fseek(fpu, 0, SEEK_END);
	int num_u = ftell(fpu) / sizeof(User);
	fseek(fpu, 0, SEEK_SET);
	User *u = new User[num_u];
	for (int i = 0; i <= num_u - 1; i++)
	{
		fread(&u[i], sizeof(User), 1, fpu);
		//cout << u[i].username << endl;
	}
	fseek(fpo, 0, SEEK_END);
	int num_o = ftell(fpo) / sizeof(Order);
	fseek(fpo, 0, SEEK_SET);
	Order *o = new Order[num_o];
	for (int i = 0; i <= num_o - 1; i++)
	{
		fread(&o[i], sizeof(Order), 1, fpo);
	}
	fseek(fpc, 0, SEEK_END);
	int num_c = ftell(fpc) / sizeof(Commodity);
	fseek(fpc, 0, SEEK_SET);
	Commodity *c = new Commodity[num_c];
	for (int i = 0; i <= num_c - 1; i++)
	{
		fread(&c[i], sizeof(Commodity), 1, fpc);
	}
	fclose(fpo);
	fclose(fpc);
	fclose(fpu);
	time_t timep;
	time(&timep);
	char tmp[11];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d", localtime(&timep));
	for (int i = 0; i <= num_c - 1; i++)//商品数量，订单状态，订单购买数量，用户余额(买家减少，卖家增多），商品状态
	{
		if (c[i].state == 1)//找到在售商品,且过了一天  if (c[i].state == 1 && strcmp(tmp, c[i].addedDate) != 0)
		{
			c[i].state = 0;
			vector_<Order*> oo;
			for (int j = 0; j <= num_o - 1; j++)//将c[i]的订单领出来，排序
			{
				if ((strcmp(o[j].commodityID, c[i].commodityID) == 0) && (o[j].state == 0))
				{
					oo.push_back(&o[j]);
                }
			}
			if (oo.number == 0)
				continue;
			else
			{
				int sum = 0;
				for (int j = 0; j <= oo.number - 1; j++)
				{
					sum += oo[j]->number;
				}
				if (sum > c[i].number)
				{
					//c[i].number = 0;
					for (int j = 0; j < oo.number - 1; j++)//从小到大，冒泡排序
					{
						for (int p = 0; p < oo.number - 1 - j; p++)
						{
							if (oo[p]->unitPrice > oo[p + 1]->unitPrice)
							{
								Order *a = oo[p + 1];
								oo[p + 1] = oo[p];
								oo[p] = a;
							}
						}
					}
					int all = 0;
					int jj = 0;
					int stage = 0;
					for (jj = oo.number-1;jj >=0; jj--)
					{
						all += oo[jj]->number;
						if (all > c[i].number)
						{
							if (stage == 0)
							{
								oo[jj]->number = c[i].number - (all - oo[jj]->number);
								oo[jj]->state = 1;
								stage = 1;
							}
							else
							{
								oo[jj]->state = 2;
								continue;
							}
						}
						else if (all == c[i].number)
						{
							oo[jj]->state = 1;
							stage = 1;
						}
						else
						{
							oo[jj]->state = 1;
						}
						for (int p = 0; p <= num_u - 1; p++)//改变余额
						{
							if (strcmp(oo[jj]->buyerID, u[p].userID) == 0)
							{
								u[p].balance -= oo[jj]->unitPrice*oo[jj]->number;
							}
							if (strcmp(oo[jj]->sellerID, u[p].userID) == 0)
							{
								u[p].balance += oo[jj]->unitPrice*oo[jj]->number;
							}
						}
					}
					c[i].number = 0;
				}
				else//enough
				{
					c[i].number -= sum;
					for (int j = 0; j <= oo.number - 1; j++)
					{
						oo[j]->state = 1;
						for (int p = 0; p <= num_u - 1; p++)//改变余额
						{
							if (strcmp(oo[j]->buyerID, u[p].userID) == 0)
							{
								u[p].balance -= oo[j]->unitPrice*oo[j]->number;
							}
							if (strcmp(oo[j]->sellerID, u[p].userID) == 0)
							{
								u[p].balance += oo[j]->unitPrice*oo[j]->number;
							}
						}
					}
				}
			}
			oo.clear();
		}
	}
	//cout << num_u << endl;
	FILE *fpu_ = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\user.txt", "w");
	FILE *fpo_ = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\order.txt", "w");
	FILE *fpc_ = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "w");
	for (int i = 0; i <= num_u-1; i++)
	{
		fwrite(&u[i], sizeof(User), 1, fpu_);
		//cout << u[i].userID << endl;
	}
	for (int i = 0; i <= num_o-1; i++)
	{
		fwrite(&o[i], sizeof(Order), 1, fpo_);
	}
	for (int i = 0; i <= num_c - 1; i++)
	{
		fwrite(&c[i], sizeof(Commodity), 1, fpc_);
	}
	fclose(fpu_);
	fclose(fpo_);
	fclose(fpc_);
}