#include"user_module.h"
#include"calculator.h"
void user_module(User &a)
{
A:
	users b;
	b.menu();
	int m;
	cout << "ÇëÊäÈë²Ù×÷" << endl;
	cin >> m;
	switch (m)
	{
	case 1:b.buyer_module(a); break;
	case 2:b.seller_module(a); break;
	case 3:b.self_information(a); break;
	case 4:return; break;
	case 5:calculator(); break;
	default:cout << "ÊäÈë´íÎó" << endl; break;
	}
	goto A;
}