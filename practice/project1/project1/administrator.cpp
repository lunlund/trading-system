#define _CRT_SECURE_NO_WARNINGS
#include"administrator.h"
void administrator::menu()
{
	cout << "====================================================================================" << endl;
	cout << "1.�鿴������Ʒ 2.������Ʒ 3.�¼���Ʒ 4.�鿴���ж��� 5.�鿴�����û� 6.����û� 7.ע��" << endl;
	cout << "====================================================================================" << endl;

}
void administrator::all_commodity()
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt", "r");
	cout << "********************************************************************" << endl;
	cout << "��ƷID   ����   �۸�   �ϼ�ʱ��   ����ID  ����   ��Ʒ״̬" << endl;
	Commodity a;
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(Commodity);
	fseek(fp, 0, SEEK_SET);
	for (int i = 0;i<=m-1; i++)
	{
		fread(&a, sizeof(Commodity), 1, fp);
		cout << a.commodityID << a.commodityname << a.price << a.addedDate << a.sellerID << a.number;
		if (a.state == 1)
			cout << "������" << endl;
		else
			cout << "���¼�" << endl;
	}
	cout << "*************************************************************************" << endl;
	fclose(fp);
}
void administrator::search_commodity()
{
	FILE *fp=fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\commodity.txt","r");
	cout << "��������Ʒ����" << endl;
	bool aa = 0;
	char a[21];
	cin >> a;
	Commodity b;
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(Commodity);
	fseek(fp, 0, SEEK_SET);
	cout << "**********************************************************" << endl;
	cout << "��ƷID   ����   �۸�   �ϼ�ʱ��   ����ID  ����   ��Ʒ״̬" << endl;
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&b, sizeof(Commodity), 1, fp);
		if (strcmp(a, b.commodityname) == 0)
		{
			aa = 1;
			cout << b.commodityID << b.commodityname << b.price << b.addedDate << b.sellerID << b.number;
			if (b.state == 1)
				cout << "������" << endl;
			else
				cout << "���¼�" << endl;
		}
	}
	cout << "***********************************************************" << endl;
	if (aa == 0)
	{
		cout << "û���ҵ�����Ҫ����Ʒ�����س�ʼ����" << endl;
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
	cout << "������Ҫ�¼ܵ���ƷID" << endl;
	cin >> b;
	for (i = 0; i <= m - 1; i++)
	{
		fread(&a[i], sizeof(Commodity), 1, fp);
		if (strcmp(a[i].commodityID, b) == 0&&a[i].state==1)
		{
			cout << "ȷ��Ҫ�¼ܸ���Ʒ��" << endl;
			cout << "**********************************************************" << endl;
			cout << "��ƷID   ����   �۸�   �ϼ�ʱ��   ����ID  ����   ��Ʒ״̬" << endl;
			cout << a[i].commodityID << a[i].commodityname << a[i].price << a[i].addedDate << a[i].sellerID << a[i].number;
			if (a[i].state == 1)
				cout << "������" << endl;
			else
				cout << "���¼�" << endl;
			cout << "**********************************************************" << endl;
		A:cout << "��ѡ��y/n)��";
			char j;
			cin >> j;
			if (j == 'y')
			{
				a[i].state = 0;
				cout << "�¼ܳɹ�" << endl;
			}
			if (j == 'n')
			{
				cout << "ȡ���¼�" << endl;
			}
			if (j != 'n'&&j != 'y')
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
void administrator::all_order()
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\order.txt", "r");
	cout << "************************************************************************" << endl;
	cout << "����ID   ��ƷID   ���׵���   ����   ����ʱ��  ����ID   ���ID  ����״̬" << endl;
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
			cout << "�ѳɽ�" << endl;
		}
		else
		{
			cout << "Ԥ֧��" << endl;
		}
	}
	cout << "*************************************************************************" << endl;
	fclose(fp);
}
void administrator::all_user()
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\user.txt", "r");
	cout << "********************************************************************" << endl;
	cout << "�û�ID   �û���   ��ϵ��ʽ   ��ַ   Ǯ�����  �û�״̬" << endl;
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
			cout << "����" << endl;
		}
		else
		{
			cout << "���" << endl;
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
	cout << "������Ҫ������û�ID" << endl;
	cin >> b;
	for (i = 0; i <= m - 1; i++)
	{
		fread(&a[i], sizeof(User), 1, fp);
		if (strcmp(a[i].userID, b) == 0 && a[i].userstate == 1)
		{
			cout << "ȷ��Ҫ������û���" << endl;
			cout << "**********************************************************" << endl;
			cout << "�û�ID   �û���   ��ϵ��ʽ  ��ַ  Ǯ�����" << endl;
			cout << a[i].userID << a[i].username << a[i].phonenumber << a[i].address << a[i].balance << endl;
			cout << "**********************************************************" << endl;
		A:cout << "��ѡ��y/n)��";
			char j;
			cin >> j;
			if (j == 'y')
			{
				a[i].userstate = 0;
				cout << "����ɹ�" << endl;
			}
			if (j == 'n')
			{
				cout << "���ʧ��" << endl;
			}
			if (j != 'n'&&j != 'y')
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
		cout << "��δ������û���,δ�鵽��ID" << endl;
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