#include"users.h"
void users::menu()
{
	cout << "==============================================================" << endl;
	cout << "1.������� 2.�������� 3.������Ϣ���� 4.ע����¼" << endl;
	cout << "==============================================================" << endl;

}
void users::buyer_module(User &a)
{
A:
	buyers b;
	b.menu();
	int m;
	cout << "���������" << endl;
	cin >> m;
	switch (m)
	{
	case 1:b.all_commodity(); break;
	case 2:b.buy_commodity(a); break;
	case 3:b.search_commodity(); break;
	case 4:b.all_order(a); break;
	case 5:b.commodity_information(); break;
	case 6:return; break;
	default:cout << "�������" << endl;
	}
	goto A;


}
void users::seller_module(User &a)
{
A:
	sellers b;
	b.menu();
	int m;
	cout << "���������" << endl;
	cin >> m;
	switch (m)
	{
	case 1:b.new_commodity(a); break;
	case 2:b.all_commodity(a); break;
	case 3:b.modify_information(); break;
	case 4:b.delete_commodity(a); break;
	case 5:b.all_order(a);
	case 6:return; break;
	default:cout << "�������" << endl;
	}
	goto A;

}
void users::self_information(User &a)
{
A:
	information b;
	b.menu();
	int m;
	cout << "���������" << endl;
	cin >> m;
	switch (m)
	{
	case 1:b.self_info(a);
	case 2:b.modify_info(a);
	case 3:b.recharge(a);
	case 4:return; break;
	default:cout << "�������" << endl; break;
	}


}