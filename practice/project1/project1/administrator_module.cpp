#include"administrator_module.h"
void administrator_module()
{
A:
	administrator a;
	a.menu();
	int b;
	cout << "ÇëÊäÈë²Ù×÷" << endl;
	cin >> b;
	switch (b)
	{
	case 1:a.all_commodity(); break;
	case 2:a.search_commodity(); break;
	case 3:a.delete_commodity(); break;
	case 4:a.all_order(); break;
	case 5:a.all_user(); break;
	case 6:a.delete_user(); break;
	case 7:return; break;
	default:cout << "ÊäÈë´íÎó" << endl;
	}
	goto A;
}