#include"user_module.h"
void user_module(User &a)
{
A:
	users b;
	b.menu();
	int m;
	cout << "���������" << endl;
	cin >> m;
	switch (m)
	{
	case 1:b.buyer_module(a); break;
	case 2:b.seller_module(a); break;
	case 3:b.self_information(a); break;
	case 4:return; break;
	default:cout << "�������" << endl; break;
	}
	goto A;
}