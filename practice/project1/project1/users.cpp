#include"users.h"
#include"calculator.h"
void users::menu()
{
	cout << "==============================================================" << endl;
	cout << "1.������� 2.�������� 3.������Ϣ���� 4.ע����¼ 5.������" << endl;
	cout << "==============================================================" << endl;

}
void users::buyer_module(User &a)
{
A:
	char k[100];
	buyers b;
	b.menu();
	int m;
	cout << "���������" << endl;
	//cin >> m;
	while (scanf_s("%d", &m) == 0)
	{
		while (getchar() != '\n');
		cout << "�������,����������" << endl;
	}
	cin.getline(k, 100);
	switch (m)
	{
	case 1: b.all_commodity(); break;
	case 2: b.buy_commodity(a); break;
	case 3: b.search_commodity(); break;
	case 4: b.all_order(a); break;
	case 5: b.commodity_information(); break;
	case 6: system("cls"); return; break;
	case 7: calculator(); break;
	default:cout << "�������" << endl;
	}
	goto A;


}
void users::seller_module(User &a)
{
A:
	char k[100];
	sellers b;
	b.menu();
	int m;
	cout << "���������" << endl;
	//cin >> m;
	while (scanf_s("%d", &m) == 0)
	{
		while (getchar() != '\n');
		cout << "�������,����������" << endl;
	}
	cin.getline(k, 100);
	switch (m)
	{
	case 1: b.new_commodity(a); break;
	case 2: b.all_commodity(a); break;
	case 3: b.modify_information(a); break;
	case 4: b.delete_commodity(a); break;
	case 5: b.all_order(a); break;
	case 6: system("cls"); return; break;
	case 7: calculator(); break;
	default:cout << "�������" << endl;
	}
	goto A;

}
void users::self_information(User &a)
{
A:char k[100];
	information b;
	b.menu();
	int m;
	cout << "���������" << endl;
	//cin >> m;
	while (scanf_s("%d", &m) == 0)
	{
		while (getchar() != '\n');
		cout << "�������,����������" << endl;
	}
	cin.getline(k, 100);
	switch (m)
	{
	case 1: b.self_info(a); break;
	case 2: b.modify_info(a); break;
	case 3: b.recharge(a); break;
	case 4: system("cls"); return; break;
	default:cout << "�������" << endl; break;
	}
	goto A;

}