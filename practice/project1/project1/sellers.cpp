#define _CRT_SECURE_NO_WARNINGS
#include"sellers.h"
#include"output.h"
#include<Windows.h>
#include<time.h>
void sellers::menu()
{
	cout << "============================================================================================" << endl;
	cout << "1.������Ʒ 2.�鿴������Ʒ 3.�޸���Ʒ��Ϣ 4.�¼���Ʒ 5.�鿴��ʷ���� 6.�����û������� 7.������" << endl;
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
	cout << "��������Ʒ����(������20���ַ�)" << endl;
A:cin.getline(commodityname, 100);
	if (strlen(commodityname) > 20)
	{
		cout << "��Ʒ���Ƴ���20���ַ�������������" << endl;
		goto A;
	}
	strcpy(a.commodityname,commodityname);
	cout << "��������Ʒ�۸��Զ�����һλС����" << endl;
	//cin >> a.price;
	while (scanf_s("%lf", &a.price) == 0)
	{
		while (getchar() != '\n');
		cout << "�������,����������" << endl;
	}
	cout << "��������Ʒ����" << endl;
	//cin >> a.number; 
	while (scanf_s("%d", &a.number) == 0)
	{
		while (getchar() != '\n');
		cout << "�������,����������" << endl;
	}
	cin.getline(k, 100);
	cout << "��������Ʒ����(������200���ַ���" << endl;
B:cin.getline(description, 1000);
	if (strlen(description) > 200)
	{
		cout << "����200���ַ�������������" << endl;
		goto B;
	}
	strcpy(a.description, description);
	cout << "��ȷ�Ϸ�������Ʒ��Ϣ����" << endl;
	cout << "*****************************" << endl;
	cout << "��Ʒ���ƣ�" << a.commodityname << endl;
	cout << "��Ʒ�۸�" << a.price << endl;
	cout << "��Ʒ������" << a.number << endl;
	cout << "��Ʒ������" << a.description << endl;
	cout << "*****************************" << endl;
	cout << "��ȷ��Ҫ������Ʒ�𣿣�y/n��";
		string mm;
	C://cin >> mm;
		getline(cin, mm);
	if (mm == "y")
	{
		cout << "������Ʒ�ɹ�" << endl;
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
		cout << "������Ʒʧ��" << endl;
	}
	else
	{
		cout<<"�����������������"<<endl;
		goto C;
	}fclose(fp);
}
void sellers::all_commodity(User &aa)
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "r");
	cout << "********************************************************************" << endl;
	//cout << "��ƷID   ����   �۸�   �ϼ�ʱ��   ����   ��Ʒ״̬" << endl;
	cout << "��ƷID ����                 �۸�   �ϼ�ʱ��   ����   ��Ʒ״̬" << endl;
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
				cout << "������" << endl;
			else
				cout << "���¼�" << endl;*/
			f(a.commodityID, 5);
			f(a.commodityname, 21);
			cout << a.price << "   ";
			f(a.addedDate, 11);
			cout << a.number << "     ";
			if (a.state == 1)
				cout << "������" << endl;
			else
				cout << "���¼�" << endl;
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
	cout << "�����뱻�޸���Ʒ��ID" << endl;
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
			cout << "�����뱻�޸���Ʒ�����ԣ�1.�۸� 2.������" << endl;
			int p;
		A://cin >> p; 
			while (scanf_s("%d", &p) == 0)
			{
				while (getchar() != '\n');
				cout << "�������,����������" << endl;
			}
			cin.getline(k, 100);
			if (p == 1)
			{
				cout << "�����뱻�޸���Ʒ�ļ۸�" << endl;
				//cin >> aaa.price;
				while (scanf_s("%lf", &aaa.price) == 0)
				{
					while (getchar() != '\n');
					cout << "�������,����������" << endl;
				}
			}
			else if (p == 2)
			{
				cout << "�����뱻�޸���Ʒ������(200���ַ����ڣ�" << endl;
			B:cin.getline(description, 1000);
				if (strlen(description) > 200)
				{
					cout << "�������ݹ��࣬�ַ�����200������������" << endl;
					goto B;
				}
				strcpy(aaa.description, description);
			}
			else
			{
				cout << "�����������������" << endl;
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
			cout << "��ȷ���޸ĵ���Ʒ��Ϣ����" << endl;
			cout << "*****************************" << endl;
			cout << "��ƷID:" << str << endl;
			cout << "��Ʒ����:" << a[i].commodityname << endl;
			cout << "��Ʒ�۸�:" << a[i].price << endl;
			cout << "��Ʒ����:" << a[i].description << endl;
			cout << "******************************" << endl;
			cout << "ȷ���޸ģ���y/n)" << endl;
			break;
		}
		if (i == m - 1)
		{
			cout << "û�д���Ʒ" << endl;
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
		cout << "�޸ĳɹ�" << endl;
	}
	else if(q == 'n')
	{
		cout << "�޸�ʧ��" << endl;
	}
	else
	{
		cout << "�����������������" << endl;
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
	cout << "������Ҫ�¼ܵ���ƷID" << endl;
	cin.getline(b, 100);
	for (i = 0; i <= m - 1; i++)
	{
		fread(&a[i], sizeof(Commodity), 1, fp);
	}
	for (i = 0; i <= m - 1; i++)
	{
		if (strcmp(a[i].commodityID, b) == 0 && a[i].state == 1 && strcmp(a[i].sellerID, aa.userID) == 0)
		{
			cout << "ȷ��Ҫ�¼ܸ���Ʒ��" << endl;
			cout << "**********************************************************" << endl;
			//cout << "��ƷID   ����   �۸�   �ϼ�ʱ��   ����ID  ����   ��Ʒ״̬" << endl;
			cout << "��ƷID ����                 �۸�   �ϼ�ʱ��   ����ID ����   ��Ʒ״̬" << endl;
			/*cout << a[i].commodityID << a[i].commodityname << a[i].price << a[i].addedDate << a[i].sellerID << a[i].number;
			if (a[i].state == 1)
				cout << "������" << endl;
			else
				cout << "���¼�" << endl;*/
			f(a[i].commodityID, 5);
			f(a[i].commodityname, 21);
			cout << a[i].price << "   ";
			f(a[i].addedDate, 11);
			f(a[i].sellerID, 5);
			cout << a[i].number << "     ";
			if (a[i].state == 1)
				cout << "������" << endl;
			else
				cout << "���¼�" << endl;
			cout << "**********************************************************" << endl;
		A:cout << "��ѡ��y/n)��";
			string j;
			getline(cin, j);
			if (j == "y")
			{
				a[i].state = 0;
				cout << "�¼ܳɹ�" << endl;
			}
			if (j == "n")
			{
				cout << "ȡ���¼�" << endl;
			}
			if (j != "n"&&j != "y")
			{
				cout << "�����������������" << endl;
				goto A;
			}
			break;
		}
	}
	fclose(fp);
	if (i == m)
	{
		cout << "������Ʒ��,δ�鵽��ID" << endl;
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
	//cout << "����ID   ��ƷID   ���׵���   ����   ����ʱ��  ���ID  ����״̬" << endl;
	cout << "����ID ��ƷID ���׵���  ����  ����ʱ��  ���ID ����״̬" << endl;
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
				cout << "�ѳɽ�" << endl;
			}
			else if(a.state==0)
			{
				cout << "Ԥ֧��" << endl;
			}
			else
			{
				cout << "����ʧ��" << endl;
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
				cout << "�ѳɽ�" << endl;
			}
			else if (a.state == 0)
			{
				cout << "Ԥ֧��" << endl;
			}
			else
			{
				cout << "����ʧ��" << endl;
			}
		}
	}
	cout << "*************************************************************************" << endl;
	fclose(fp);
}