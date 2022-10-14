#define _CRT_SECURE_NO_WARNINGS
#include"sellers.h"
#include"output.h"
#include<Windows.h>
#include<time.h>
void sellers::menu()
{
	cout << "============================================================================================" << endl;
	cout << "1.发布商品 2.查看发布商品 3.修改商品信息 4.下架商品 5.查看历史订单 6.返回用户主界面 7.计算器" << endl;
	cout << "============================================================================================" << endl;
}
void sellers::new_commodity(User &aa)
{
	char k[100];
	char commodityname[100], description[1000];
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
A:cin.getline(commodityname, 100);
	if (strlen(commodityname) > 20)
	{
		cout << "商品名称超过20个字符，请重新输入" << endl;
		goto A;
	}
	strcpy(a.commodityname,commodityname);
	cout << "请输入商品价格（自动保存一位小数）" << endl;
	//cin >> a.price;
	while (scanf_s("%lf", &a.price) == 0)
	{
		while (getchar() != '\n');
		cout << "输入错误,请重新输入" << endl;
	}
	cout << "请输入商品数量" << endl;
	//cin >> a.number; 
	while (scanf_s("%d", &a.number) == 0)
	{
		while (getchar() != '\n');
		cout << "输入错误,请重新输入" << endl;
	}
	cin.getline(k, 100);
	cout << "请输入商品描述(不超过200个字符）" << endl;
B:cin.getline(description, 1000);
	if (strlen(description) > 200)
	{
		cout << "超过200个字符，请重新输入" << endl;
		goto B;
	}
	strcpy(a.description, description);
	cout << "请确认发布的商品信息无误" << endl;
	cout << "*****************************" << endl;
	cout << "商品名称：" << a.commodityname << endl;
	cout << "商品价格：" << a.price << endl;
	cout << "商品数量：" << a.number << endl;
	cout << "商品描述：" << a.description << endl;
	cout << "*****************************" << endl;
	cout << "请确认要发布商品吗？（y/n）";
		string mm;
	C://cin >> mm;
		getline(cin, mm);
	if (mm == "y")
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
	}
	else if (mm == "n")
	{
		cout << "发布商品失败" << endl;
	}
	else
	{
		cout<<"输入错误请重新输入"<<endl;
		goto C;
	}fclose(fp);
}
void sellers::all_commodity(User &aa)
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "r");
	cout << "********************************************************************" << endl;
	//cout << "商品ID   名称   价格   上架时间   数量   商品状态" << endl;
	cout << "商品ID 名称                 价格   上架时间   数量   商品状态" << endl;
	Commodity a;
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(Commodity);
	fseek(fp, 0, SEEK_SET);
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&a, sizeof(Commodity), 1, fp);
		if (strcmp(a.sellerID,aa.userID)==0)
		{
			/*cout << a.commodityID << a.commodityname << a.price << a.addedDate  << a.number;
			if (a.state == 1)
				cout << "销售中" << endl;
			else
				cout << "已下架" << endl;*/
			f(a.commodityID, 5);
			f(a.commodityname, 21);
			cout << a.price << "   ";
			f(a.addedDate, 11);
			cout << a.number << "     ";
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
	char k[100];
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "r");
	char str[100];
	char description[1000];
	Commodity aaa;
	cout << "请输入被修改商品的ID" << endl;
	cin.getline(str, 100);
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(Commodity);
	fseek(fp, 0, SEEK_SET);
	Commodity *a = new Commodity[m];
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&a[i], sizeof(Commodity), 1, fp);
	}
	for (int i = 0; i <= m - 1; i++)
	{
		if (strcmp(a[i].commodityID, str) == 0 && strcmp(a[i].sellerID, aa.userID) == 0)
		{
			cout << "请输入被修改商品的属性（1.价格 2.描述）" << endl;
			int p;
		A://cin >> p; 
			while (scanf_s("%d", &p) == 0)
			{
				while (getchar() != '\n');
				cout << "输入错误,请重新输入" << endl;
			}
			cin.getline(k, 100);
			if (p == 1)
			{
				cout << "请输入被修改商品的价格" << endl;
				//cin >> aaa.price;
				while (scanf_s("%lf", &aaa.price) == 0)
				{
					while (getchar() != '\n');
					cout << "输入错误,请重新输入" << endl;
				}
			}
			else if (p == 2)
			{
				cout << "请输入被修改商品的描述(200个字符以内）" << endl;
			B:cin.getline(description, 1000);
				if (strlen(description) > 200)
				{
					cout << "描述内容过多，字符超过200，请重新输入" << endl;
					goto B;
				}
				strcpy(aaa.description, description);
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
			cout << "商品名称:" << a[i].commodityname << endl;
			cout << "商品价格:" << a[i].price << endl;
			cout << "商品描述:" << a[i].description << endl;
			cout << "******************************" << endl;
			cout << "确认修改？（y/n)" << endl;
			break;
		}
		if (i == m - 1)
		{
			cout << "没有此商品" << endl;
			delete[]a;
			return;
		}
	}
	fclose(fp);
	FILE *fp1 = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "w");
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
	char b[100];
	cout << "请输入要下架的商品ID" << endl;
	cin.getline(b, 100);
	for (i = 0; i <= m - 1; i++)
	{
		fread(&a[i], sizeof(Commodity), 1, fp);
	}
	for (i = 0; i <= m - 1; i++)
	{
		if (strcmp(a[i].commodityID, b) == 0 && a[i].state == 1 && strcmp(a[i].sellerID, aa.userID) == 0)
		{
			cout << "确定要下架该商品吗" << endl;
			cout << "**********************************************************" << endl;
			//cout << "商品ID   名称   价格   上架时间   卖家ID  数量   商品状态" << endl;
			cout << "商品ID 名称                 价格   上架时间   卖家ID 数量   商品状态" << endl;
			/*cout << a[i].commodityID << a[i].commodityname << a[i].price << a[i].addedDate << a[i].sellerID << a[i].number;
			if (a[i].state == 1)
				cout << "销售中" << endl;
			else
				cout << "已下架" << endl;*/
			f(a[i].commodityID, 5);
			f(a[i].commodityname, 21);
			cout << a[i].price << "   ";
			f(a[i].addedDate, 11);
			f(a[i].sellerID, 5);
			cout << a[i].number << "     ";
			if (a[i].state == 1)
				cout << "销售中" << endl;
			else
				cout << "已下架" << endl;
			cout << "**********************************************************" << endl;
		A:cout << "请选择（y/n)：";
			string j;
			getline(cin, j);
			if (j == "y")
			{
				a[i].state = 0;
				cout << "下架成功" << endl;
			}
			if (j == "n")
			{
				cout << "取消下架" << endl;
			}
			if (j != "n"&&j != "y")
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
	//cout << "订单ID   商品ID   交易单价   数量   交易时间  买家ID  订单状态" << endl;
	cout << "订单ID 商品ID 交易单价  数量  交易时间  买家ID 订单状态" << endl;
	Order a;
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(Order);
	fseek(fp, 0, SEEK_SET);
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&a, sizeof(Order), 1, fp);
		if (strcmp(aa.userID,a.sellerID)==0)
		{
			/*cout << a.orderID << a.commodityID << a.unitPrice << a.number << a.date << a.buyerID;
			if (a.state == 1)
			{
				cout << "已成交" << endl;
			}
			else if(a.state==0)
			{
				cout << "预支付" << endl;
			}
			else
			{
				cout << "交易失败" << endl;
			}*/
			f(a.orderID, 5); cout << " ";
			f(a.commodityID, 5); cout << "  ";
			cout << a.unitPrice << "      ";
			cout << a.number << "    ";
			f(a.date, 11);
			//f(a.sellerID, 5);
			f(a.buyerID, 5);
			if (a.state == 1)
			{
				cout << "已成交" << endl;
			}
			else if (a.state == 0)
			{
				cout << "预支付" << endl;
			}
			else
			{
				cout << "交易失败" << endl;
			}
		}
	}
	cout << "*************************************************************************" << endl;
	fclose(fp);
}