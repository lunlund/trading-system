#include"user_module.h"
#include"calculator.h"
void user_module(User &a)
{
	char k[100];
A:
	users b;
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
	case 1: b.buyer_module(a); break;
	case 2: b.seller_module(a); break;
	case 3: b.self_information(a); break;
	case 4: system("cls"); return; break;
	case 5: calculator(); break;
	default:cout << "�������" << endl; break;
	}
	goto A;
}