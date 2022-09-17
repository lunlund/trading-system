#define _CRT_SECURE_NO_WARNINGS
#include"sellers.h"
#include<Windows.h>
#include<time.h>
void sellers::menu()
{
	cout << "===================================================================================" << endl;
	cout << "1.发布商品 2.查看发布商品 3.修改商品信息 4.下架商品 5.查看历史订单 6.返回用户主界面" << endl;
	cout << "===================================================================================" << endl;
}
void sellers::new_commodity(User &aa)
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "a+");
	Commodity a;
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(Commodity);
	fseek(fp, 0, SEEK_SET);
	int n = m;
	strcpy(a.commodityID, "M000");
	for (int i = 1; ; i++)
	{
		a.commodityID[4 - i] = (char)(m % 10 + '0');
		m = m / 10;
		if (m == 0)
			break;
	}
	cout << a.commodityID << endl;
	cout << "请输入商品名称(不超过20个字符)" << endl;
	A:cin >> a.commodityname;
	if (strlen(a.commodityname) > 20)
	{
		cout << "商品名称超过20个字符，请重新输入" << endl;
		goto A;
	}
	cout << "请输入商品价格（自动保存一位小数）" << endl;
	cin >> a.price;
	cout << "请输入商品数量" << endl;
	cin >> a.number;
	cout << "请输入商品描述(不超过200个字符）" << endl;
	B:cin >> a.description;
	if (strlen(a.description) > 200)
	{
		cout << "超过200个字符，请重新输入" << endl;
		goto B;
	}
	cout << "请确认发布的商品信息无误" << endl;
	cout << "*****************************" << endl;
	cout << "商品名称：" << a.commodityname << endl;
	cout << "商品价格：" << a.price << endl;
	cout << "商品数量：" << a.number << endl;
	cout << "商品描述：" << a.description << endl;
	cout << "*****************************" << endl;
	cout << "请确认要发布商品吗？（y/n）";
		char mm;
	C:cin >> mm;
	if (mm == 'y')
	{
		cout << "发布商品成功" << endl;
		a.state = 1;
		strcpy(a.sellerID, aa.userID);
		time_t timep;
		time(&timep);
		char tmp[11];
		strftime(tmp, sizeof(tmp), "%Y-%m-%d", localtime(&timep));
		strcpy(a.addedDate, tmp);
		fwrite(&a, sizeof(Commodity), 1, fp);
		fclose(fp);
	}
	else if (mm == 'n')
	{
		cout << "发布商品失败" << endl;
	}
	else
	{
		cout<<"输入错误请重新输入"<<endl;
		goto C;
	}
}
void sellers::all_commodity(User &aa)
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "r");
	cout << "********************************************************************" << endl;
	cout << "商品ID   名称   价格   上架时间   数量   商品状态" << endl;
	Commodity a;
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(Commodity);
	fseek(fp, 0, SEEK_SET);
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&a, sizeof(Commodity), 1, fp);
		if (strcmp(a.sellerID,aa.userID)==0)
		{
			cout << a.commodityID << a.commodityname << a.price << a.addedDate  << a.number;
			if (a.state == 1)
				cout << "销售中" << endl;
			else
				cout << "已下架" << endl;
		}
	}
	cout << "*************************************************************************" << endl;
	fclose(fp);
}
void sellers::modify_information(User &aa)
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\Commodity.txt", "r");
	char str[5];
	Commodity aaa;
	cout << "请输入被修改商品的ID" << endl;
	cin >> str;
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(Commodity);
	fseek(fp, 0, SEEK_SET);
	Commodity *a = new Commodity[m];
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&a[i], sizeof(Commodity), 1, fp);
		if (strcmp(a[i].commodityID, str) == 0)
		{
			cout << "请输入被修改商品的属性（1.价格 2.描述）" << endl;
			int p;
		A:cin >> p;
			if (p == 1)
			{
				cout << "请输入被修改商品的价格" << endl;
				cin >> aaa.price;
			}
			else if (p == 2)
			{
				cout << "请输入被修改商品的描述(200个字符以内）" << endl;
			B:cin >> aaa.description;
				if (strlen(aaa.description) > 200)
				{
					cout << "描述内容过多，字符超过200，请重新输入" << endl;
					goto B;
				}
			}
			else
			{
				cout << "输入错误，请重新输入" << endl;
				goto A;
			}
			if (p == 1)
			{
				a[i].price = aaa.price;
			}
			else
			{
				strcpy(a[i].description, aaa.description);
			}
			cout << "请确认修改的商品信息无误" << endl;
			cout << "*****************************" << endl;
			cout << "商品ID:" << str << endl;
			cout << "商品名称:"<<a[i].commodityname<<endl;
			cout << "商品价格:"<<a[i].price<<endl;
			cout << "商品描述:"<<a[i].description<<endl;
			cout << "******************************" << endl;
			cout << "确认修改？（y/n)" << endl;
			break;
		}
		if (i == m - 1)
		{
			cout << "没有此商品"<<endl;
			delete[]a;
			return;
		}
	}
	fclose(fp);
	FILE *fp1 = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\Commodity.txt", "w");
	char q;
C:cin >> q;
	if (q == 'y')
	{
		for (int i = 0; i <= m - 1; i++)
		{
			fwrite(&a[i], sizeof(Commodity), 1, fp1);
		}
		cout << "修改成功" << endl;
	}
	else if(q == 'n')
	{
		cout << "修改失败" << endl;
	}
	else
	{
		cout << "输入错误，请重新输入" << endl;
		goto C;
	}
	fclose(fp1);
	delete[]a;

}
void sellers::delete_commodity(User &aa)
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
		if (strcmp(a[i].commodityID, b) == 0 && a[i].state == 1&&strcmp(a[i].commodityID,aa.userID)==0)
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
void sellers::all_order(User &aa)
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\order.txt", "r");
	cout << "************************************************************************" << endl;
	cout << "订单ID   商品ID   交易单价   数量   交易时间  买家ID  订单状态" << endl;
	Order a;
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(Order);
	fseek(fp, 0, SEEK_SET);
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&a, sizeof(Order), 1, fp);
		if (strcmp(aa.userID,a.sellerID)==0)
		{
			cout << a.orderID << a.commodityID << a.unitPrice << a.number << a.date << a.buyerID;
			if (a.state == 1)
			{
				cout << "已成交" << endl;
			}
			else
			{
				cout << "预支付" << endl;
			}
		}
	}
	cout << "*************************************************************************" << endl;
	fclose(fp);
}