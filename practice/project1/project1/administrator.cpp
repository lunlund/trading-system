#define _CRT_SECURE_NO_WARNINGS
#include"administrator.h"
void administrator::menu()
{
	cout << "====================================================================================" << endl;
	cout << "1.查看所有商品 2.搜索商品 3.下架商品 4.查看所有订单 5.查看所有用户 6.封禁用户 7.注销" << endl;
	cout << "====================================================================================" << endl;

}
void administrator::all_commodity()
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "r");
	cout << "********************************************************************" << endl;
	cout << "商品ID   名称   价格   上架时间   卖家ID  数量   商品状态" << endl;
	Commodity a;
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(Commodity);
	fseek(fp, 0, SEEK_SET);
	for (int i = 0;i<=m-1; i++)
	{
		fread(&a, sizeof(Commodity), 1, fp);
		cout << a.commodityID << a.commodityname << a.price << a.addedDate << a.sellerID << a.number;
		if (a.state == 1)
			cout << "销售中" << endl;
		else
			cout << "已下架" << endl;
	}
	cout << "*************************************************************************" << endl;
	fclose(fp);
}
void administrator::search_commodity()
{
	FILE *fp=fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt","r");
	cout << "请输入商品名称" << endl;
	bool aa = 0;
	char a[21];
	cin >> a;
	Commodity b;
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(Commodity);
	fseek(fp, 0, SEEK_SET);
	cout << "**********************************************************" << endl;
	cout << "商品ID   名称   价格   上架时间   卖家ID  数量   商品状态" << endl;
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&b, sizeof(Commodity), 1, fp);
		if (strcmp(a, b.commodityname) == 0)
		{
			aa = 1;
			cout << b.commodityID << b.commodityname << b.price << b.addedDate << b.sellerID << b.number;
			if (b.state == 1)
				cout << "销售中" << endl;
			else
				cout << "已下架" << endl;
		}
	}
	cout << "***********************************************************" << endl;
	if (aa == 0)
	{
		cout << "没有找到您想要的商品！返回初始界面" << endl;
	}
	fclose(fp);
	return;

}
void administrator::delete_commodity()
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "r");
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(Commodity);
	int i;
	fseek(fp, 0, SEEK_SET);
	Commodity *a = new Commodity[m];
	char b[5];
	cout << "请输入要下架的商品ID" << endl;
	cin >> b;
	for (i = 0; i <= m - 1; i++)
	{
		fread(&a[i], sizeof(Commodity), 1, fp);
		if (strcmp(a[i].commodityID, b) == 0&&a[i].state==1)
		{
			cout << "确定要下架该商品吗" << endl;
			cout << "**********************************************************" << endl;
			cout << "商品ID   名称   价格   上架时间   卖家ID  数量   商品状态" << endl;
			cout << a[i].commodityID << a[i].commodityname << a[i].price << a[i].addedDate << a[i].sellerID << a[i].number;
			if (a[i].state == 1)
				cout << "销售中" << endl;
			else
				cout << "已下架" << endl;
			cout << "**********************************************************" << endl;
		A:cout << "请选择（y/n)：";
			char j;
			cin >> j;
			if (j == 'y')
			{
				a[i].state = 0;
				cout << "下架成功" << endl;
			}
			if (j == 'n')
			{
				cout << "取消下架" << endl;
			}
			if (j != 'n'&&j != 'y')
			{
				cout << "输入错误，请重新输入" << endl;
				goto A;
			}
			break;
		}
	}
	fclose(fp);
	if (i == m)
	{
		cout << "在售商品中,未查到此ID" << endl;
		delete[]a;
		return;
	}
	else
	{
		FILE *fp1 = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "w");
		for (int j = 0; j <= m - 1; j++)
		{
			fwrite(&a[j], sizeof(Commodity), 1, fp1);
		}
		fclose(fp1);
		delete[]a;
	}

	
}
void administrator::all_order()
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\order.txt", "r");
	cout << "************************************************************************" << endl;
	cout << "订单ID   商品ID   交易单价   数量   交易时间  卖家ID   买家ID  订单状态" << endl;
	Order a;
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(Order);
	fseek(fp, 0, SEEK_SET);
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&a, sizeof(Order), 1, fp);
		cout << a.orderID << a.commodityID << a.unitPrice << a.number << a.date << a.sellerID << a.buyerID;
		if (a.state == 1)
		{
			cout << "已成交" << endl;
		}
		else
		{
			cout << "预支付" << endl;
		}
	}
	cout << "*************************************************************************" << endl;
	fclose(fp);
}
void administrator::all_user()
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\user.txt", "r");
	cout << "********************************************************************" << endl;
	cout << "用户ID   用户名   联系方式   地址   钱包余额  用户状态" << endl;
	User a;
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(User);
	fseek(fp, 0, SEEK_SET);
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&a, sizeof(User), 1, fp);
		cout << a.userID << a.username << a.phonenumber << a.address << a.balance;
		if (a.userstate == 1)
		{
			cout << "正常" << endl;
		}
		else
		{
			cout << "封禁" << endl;
		}
	}
	cout << "*************************************************************************" << endl;
	fclose(fp);
}
void administrator::delete_user()
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\user.txt", "r");
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(User);
	int i;
	fseek(fp, 0, SEEK_SET);
	User *a = new User[m];
	char b[5];
	cout << "请输入要封禁的用户ID" << endl;
	cin >> b;
	for (i = 0; i <= m - 1; i++)
	{
		fread(&a[i], sizeof(User), 1, fp);
		if (strcmp(a[i].userID, b) == 0 && a[i].userstate == 1)
		{
			cout << "确定要封禁该用户吗" << endl;
			cout << "**********************************************************" << endl;
			cout << "用户ID   用户名   联系方式  地址  钱包余额" << endl;
			cout << a[i].userID << a[i].username << a[i].phonenumber << a[i].address << a[i].balance << endl;
			cout << "**********************************************************" << endl;
		A:cout << "请选择（y/n)：";
			char j;
			cin >> j;
			if (j == 'y')
			{
				a[i].userstate = 0;
				cout << "封禁成功" << endl;
			}
			if (j == 'n')
			{
				cout << "封禁失败" << endl;
			}
			if (j != 'n'&&j != 'y')
			{
				cout << "输入错误，请重新输入" << endl;
				goto A;
			}
			break;
		}
	}
	fclose(fp);
	if (i == m)
	{
		cout << "在未封禁的用户中,未查到此ID" << endl;
		delete[]a;
		return;
	}
	else
	{
		FILE *fp1 = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\user.txt", "w");
		for (int j = 0; j <= m - 1; j++)
		{
			fwrite(&a[j], sizeof(User), 1, fp1);
		}
		fclose(fp1);
	}
	FILE *fp2 = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "r");
	fseek(fp2, 0, SEEK_END);
	int mm = ftell(fp2) / sizeof(Commodity);
	fseek(fp2, 0, SEEK_SET);
	Commodity *c = new Commodity[mm];
	for (int j = 0; j <= mm - 1; j++)
	{
		fread(&c[j], sizeof(Commodity), 1, fp2);
		if (strcmp(c[j].sellerID, a[i].userID) == 0)
		{
			c[j].state = 0;
		}
	}
	fclose(fp2);
	FILE *fp3 = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "w");
	for (int j = 0; j <= mm - 1; j++)
	{
		fwrite(&c[j], sizeof(Commodity), 1, fp3);
	}
	fclose(fp3);
	delete[]a;
	delete[]c;
}