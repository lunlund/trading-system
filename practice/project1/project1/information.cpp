#define _CRT_SECURE_NO_WARNINGS
#include"information.h"
void information::menu()
{
	cout << "=================================================" << endl;
	cout << "1.�鿴������Ϣ 2.�޸���Ϣ 3.��ֵ 4.�����û�������" << endl;
	cout << "==================================================" << endl;

}
void information::self_info(User &a)
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\user.txt", "r");
	cout << "****************" << endl;
	cout << "�û�����" << a.username << endl;
	cout << "��ϵ��ʽ��" << a.phonenumber << endl;
	cout << "��ַ��" << a.address << endl;
	cout << "Ǯ����" << a.balance << endl;
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
	cout << "�������޸ĵ����ԣ�1.�û��� 2.��ϵ��ʽ 3.��ַ��" << endl;
	int n;
D://cin >> n; 
	while (scanf_s("%d", &n) == 0)
	{
		while (getchar() != '\n');
		cout << "�������,����������" << endl;
	}
	cin.getline(k, 100);
	if (n == 1)
	{
		cout << "�������޸ĺ���û���(������10���ַ���" << endl;
	A:cin.getline(username, 100);
		if (strlen(username) > 10)
		{
			cout << "�û�������10���ַ�������������" << endl;
			goto A;
		}
		strcpy(aa.username, username);
	}
	else if (n == 2)
	{
		cout << "�������޸ĺ����ϵ��ʽ(������20���ַ���" << endl;
	B:cin.getline(phonenumber,100);
		if (strlen(phonenumber) > 20)
		{
			cout << "��ϵ��ʽ����20���ַ�������������" << endl;
			goto B;
		}
		strcpy(aa.phonenumber, phonenumber);
	}
	else if (n == 3)
	{
		cout << "�������޸ĺ�ĵ�ַ(������40���ַ���" << endl;
	C:cin.getline(address,100);
		if (strlen(address) > 40)
		{
			cout << "��ַ����40���ַ�������������" << endl;
			goto C;
		}
		strcpy(aa.address, address);
	}
	else
	{
		cout << "�����������������" << endl;
		goto D;
	}
	User aba;
	for (int i = 0; i <= m - 1; i++)
	{
		fread(&aba, sizeof(User), 1, fp);
		if (strcmp(aba.username, aa.username) == 0 && strcmp(aba.userID, aa.userID) != 0)
		{
			cout << "���û���������ʹ�ã�����������" << endl;
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
	cout << "�޸ĳɹ�" << endl;

}
void information::recharge(User &aa)
{
	FILE *fp = fopen("C:\\Users\\Administrator\\Desktop\\project1\\project1\\user.txt", "r");
	fseek(fp, 0, SEEK_END);
	int m = ftell(fp) / sizeof(User);
	fseek(fp, 0, SEEK_SET);
	cout << "�������ֵ���" << endl;
	double aaa;
	//cin >> aaa;
	while (scanf_s("%lf", &aaa) == 0)
	{
		while (getchar() != '\n');
		cout << "�������,����������" << endl;
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
	cout << "��ֵ�ɹ�" << endl;
}