#define _CRT_SECURE_NO_WARNINGS
#include"buyers.h"
#include<time.h>
#include<Windows.h>
void buyers::menu()
{
	cout << "================================================================================================" << endl;
	cout << "1.�鿴��Ʒ�б� 2.������Ʒ 3.������Ʒ 4.�鿴��ʷ���� 5.�鿴��Ʒ��ϸ��Ϣ 6.�����û������� 7.������" << endl;
	cout << "================================================================================================" << endl;
}
void buyers::all_commodity()
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "r");
	cout << "************************************************************************" << endl;
	cout << "��ƷID      ����      �۸�             �ϼ�ʱ��         ����ID " << endl;
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp)/sizeof(Commodity);
	fseek(fp, 0, SEEK_SET);
	Commodity a;
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&a, sizeof(Commodity), 1, fp);
		if (a.state == 1)
		{
			cout << a.commodityID << a.commodityname << a.price << a.addedDate << a.sellerID << endl;
		}		
	}
	cout << "**************************************************************************" << endl;
	fclose(fp);
}
void buyers::buy_commodity(User &a)
{
	int num,price;
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "r");
	cout << "��������ƷID" << endl;
	char str[5];
	cin >> str;
	Commodity b;
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(Commodity);
	fseek(fp, 0, SEEK_SET);
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&b, sizeof(Commodity), 1, fp);
		if (strcmp(b.commodityID, str) == 0&&b.state==1)
		{
			cout << "������������ʣ��" <<b.number<<"����"<< endl;
			E:cin >> num;
			if (num > b.number)
			{
				cout << "�����������࣬����������" << endl;
				goto E;
			}
			cout << "���������ľ��ļ�(�׼�" <<b.price<<"Ԫ��" <<endl;
			F:cin >> price;
			if (price < b.price)
			{
				cout << "���ļ۵��ڵ׼ۣ�����������" << endl;
				goto F;
			}
			if (a.balance < price*num)
			{
				cout << "���㣬����ʧ��" << endl;
				return;
			}
			break;
		}
		if (i == m - 1)
		{
			cout << "δ�ҵ�����Ʒ" << endl;
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
	cout << "���ڴ���Ԥ�Ľ׶���Ʒ�ķ���ʱ��Ϊ" << b.addedDate << ",�������������24h��鿴" << endl;
	cout << "�������ɹ������Զ��ۿ�" << endl;
	cout << "*****************************************************************************" << endl;
}
void buyers::search_commodity()
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "r");
	cout << "��������Ʒ����" << endl;
	bool aa = 0;
	char a[21];
	cin >> a;
	Commodity b;
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(Commodity);
	fseek(fp, 0, SEEK_SET);
	cout << "****************************************" << endl;
	cout << "��ƷID   ����   �۸�   �ϼ�ʱ��   ����ID" << endl;
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&b, sizeof(Commodity), 1, fp);
		if (strcmp(a, b.commodityname) == 0&&b.state==1)
		{
			aa = 1;
			cout << b.commodityID << b.commodityname << b.price << b.addedDate << b.sellerID <<endl;
		}
	}
	cout << "*****************************************" << endl;
	if (aa == 0)
	{
		cout << "û���ҵ�����Ҫ����Ʒ�����س�ʼ����" << endl;
	}
	fclose(fp);
	return;
}
void buyers::all_order(User &b)
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\order.txt", "r");
	cout << "****************************************************************" << endl;
	cout << "����ID   ��ƷID   ���׵���   ����   ����ʱ��  ����ID   ����״̬" << endl;
	Order a;
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(Order);
	fseek(fp, 0, SEEK_SET);
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&a, sizeof(Order), 1, fp);
		if (strcmp(a.buyerID, b.userID) == 0)
		{
			cout << a.orderID << a.commodityID << a.unitPrice << a.number << a.date << a.sellerID;
			if (a.state == 1)
			{
				cout << "�ѳɽ�" << endl;
			}
			else
			{
				cout << "Ԥ֧��" << endl;
			}
		}
	}
	cout << "*****************************************************************" << endl;
	fclose(fp);
}
void buyers::commodity_information()
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "r");
	cout << "��������ƷID" << endl;
	bool aa = 0;
	char a[5];
	cin >> a;
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
			cout << "��ƷID" << b.commodityID << endl;
			cout << "��Ʒ����" << b.commodityname << endl;
			cout << "��Ʒ�۸�" << b.price << endl;
			cout << "�ϼ�ʱ��" << b.addedDate << endl;
			cout << "��Ʒ����" << b.description << endl;
			cout << "��Ʒ����" << b.sellerID << endl;
			break;
		}
	}
	cout << "*****************************************" << endl;
	if (aa == 0)
	{
		cout << "û���ҵ�����Ҫ����Ʒ�����س�ʼ����" << endl;
	}
	fclose(fp);
	return;
}