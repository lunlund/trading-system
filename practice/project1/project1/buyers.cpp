#define _CRT_SECURE_NO_WARNINGS
#include"buyers.h"
#include"output.h"
#include<time.h>
#include<Windows.h>
void buyers::menu()
{
	cout << "================================================================================================" << endl;
	cout << "1.查看商品列表 2.购买商品 3.搜索商品 4.查看历史订单 5.查看商品详细信息 6.返回用户主界面 7.计算器" << endl;
	cout << "================================================================================================" << endl;
}
void buyers::all_commodity()
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "r");
	cout << "************************************************************************" << endl;
	//cout << "商品ID      名称      价格             上架时间         卖家ID " << endl;
	cout << "商品ID 名称                 价格   上架时间   卖家ID" << endl;
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp)/sizeof(Commodity);
	fseek(fp, 0, SEEK_SET);
	Commodity a;
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&a, sizeof(Commodity), 1, fp);
		if (a.state == 1)
		{
			//cout << a.commodityID << a.commodityname << a.price << a.addedDate << a.sellerID << endl;
			f(a.commodityID, 5);
			f(a.commodityname, 21);
			cout << a.price << "   ";
			f(a.addedDate, 11);
			f(a.sellerID, 5);
			cout << endl;
		}		
	}
	cout << "**************************************************************************" << endl;
	fclose(fp);
}
void buyers::buy_commodity(User &a)
{
	int num;
	double price;
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "r");
	cout << "请输入商品ID" << endl;
	char str[100];
	cin.getline(str, 100);
	Commodity b;
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(Commodity);
	fseek(fp, 0, SEEK_SET);
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&b, sizeof(Commodity), 1, fp);
		if (strcmp(b.commodityID, str) == 0&&b.state==1)
		{
			cout << "请输入数量（剩余" <<b.number<<"个）"<< endl;
		E://cin >> num;
			while (scanf_s("%d", &num) == 0)
			{
				while (getchar() != '\n');
				cout << "输入错误,请重新输入" << endl;
			}
			if (num > b.number)
			{
				cout << "购买数量过多，请重新输入" << endl;
				goto E;
			}
			cout << "请输入您的竞拍价(底价" <<b.price<<"元）" <<endl;
		F://cin >> price;
			while (scanf_s("%lf", &price) == 0)
			{
				while (getchar() != '\n');
				cout << "输入错误,请重新输入" << endl;
			}
			if (price < b.price)
			{
				cout << "竞拍价低于底价，请重新输入" << endl;
				goto F;
			}
			if (a.balance < price*num)
			{
				cout << "余额不足，交易失败" << endl;
				return;
			}
			break;
		}
		if (i == m - 1)
		{
			cout << "未找到此商品" << endl;
			return;
		}
	}
	fclose(fp);
	time_t timep;
	time(&timep);
	char tmp[11];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d", localtime(&timep));
	Order c;
	strcpy(c.buyerID, a.userID);
	strcpy(c.commodityID , b.commodityID);
	strcpy(c.date, tmp);
	c.number = num;
	strcpy(c.sellerID, b.sellerID);
	c.unitPrice = price;
	c.state = 0;
	FILE *fp1 = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\order.txt", "a+");
	fseek(fp1, 0, SEEK_END);
	int mm = ftell(fp1) / sizeof(Order);
	fseek(fp1, 0, SEEK_SET);
	strcpy(c.orderID, "T000");
	for (int i = 1; ; i++)
	{
		c.orderID[4 - i] = (char)(mm % 10 + '0');
		mm = mm / 10;
		if (mm == 0)
			break;
	}
	fwrite(&c, sizeof(Order), 1, fp1);
	fclose(fp1);
	cout << "*****************************************************************************" << endl;
	cout << "现在处于预拍阶段商品的发布时间为" << b.addedDate << ",拍卖结果请于其24h后查看" << endl;
	cout << "若拍卖成功，会自动扣款" << endl;
	cout << "*****************************************************************************" << endl;
}
void buyers::search_commodity()
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "r");
	cout << "请输入商品名称" << endl;
	bool aa = 0;
	char a[100];
	cin.getline(a, 100);
	Commodity b;
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(Commodity);
	fseek(fp, 0, SEEK_SET);
	cout << "****************************************" << endl;
	//cout << "商品ID   名称   价格   上架时间   卖家ID" << endl;
	cout << "商品ID 名称                 价格   上架时间   卖家ID" << endl;
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&b, sizeof(Commodity), 1, fp);
		if (strcmp(a, b.commodityname) == 0&&b.state==1)
		{
			aa = 1;
			//cout << b.commodityID << b.commodityname << b.price << b.addedDate << b.sellerID <<endl;
			f(b.commodityID, 5);
			f(b.commodityname, 21);
			cout << b.price << "   ";
			f(b.addedDate, 11);
			f(b.sellerID, 5);
			cout << endl;
		}
	}
	cout << "*****************************************" << endl;
	if (aa == 0)
	{
		cout << "没有找到您想要的商品！返回初始界面" << endl;
	}
	fclose(fp);
	return;
}
void buyers::all_order(User &b)
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\order.txt", "r");
	cout << "****************************************************************" << endl;
	//cout << "订单ID   商品ID   交易单价   数量   交易时间  卖家ID   订单状态" << endl;
	cout << "订单ID 商品ID 交易单价  数量  交易时间  卖家ID 买家ID 订单状态" << endl;
	Order a;
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(Order);
	fseek(fp, 0, SEEK_SET);
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&a, sizeof(Order), 1, fp);
		if (strcmp(a.buyerID, b.userID) == 0)
		{
			/*cout << a.orderID << a.commodityID << a.unitPrice << a.number << a.date << a.sellerID;
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
				cout << "交易失败" << endl;}*/
			f(a.orderID, 5); cout << " ";
			f(a.commodityID, 5); cout << "  ";
			cout << a.unitPrice << "      ";
			cout << a.number << "    ";
			f(a.date, 11);
			f(a.sellerID, 5);
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
	cout << "*****************************************************************" << endl;
	fclose(fp);
}
void buyers::commodity_information()
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "r");
	cout << "请输入商品ID" << endl;
	bool aa = 0;
	char a[100];
	cin.getline(a, 100);
	Commodity b;
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(Commodity);
	fseek(fp, 0, SEEK_SET);
	cout << "****************************************" << endl;
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&b, sizeof(Commodity), 1, fp);
		if (strcmp(a, b.commodityID) == 0 && b.state == 1)
		{
			aa = 1;
			cout << "商品ID" << b.commodityID << endl;
			cout << "商品名称" << b.commodityname << endl;
			cout << "商品价格" << b.price << endl;
			cout << "上架时间" << b.addedDate << endl;
			cout << "商品描述" << b.description << endl;
			cout << "商品卖家" << b.sellerID << endl;
			break;
		}
	}
	cout << "*****************************************" << endl;
	if (aa == 0)
	{
		cout << "没有找到您想要的商品！返回初始界面" << endl;
	}
	fclose(fp);
	return;
}