#include"administrator_module.h"
#include"calculator.h"
void administrator_module()
{
	char k[100];
A:
	administrator a;
	a.menu();
	int b;
	cout << "ÇëÊäÈë²Ù×÷" << endl;
	//cin >> b;
	while (scanf_s("%d", &b) == 0)
	{
		while (getchar() != '\n');
		cout << "ÊäÈë´íÎó,ÇëÖØÐÂÊäÈë" << endl;
	}
	cin.getline(k, 100);
	switch (b)
	{
	case 1:
		 a.all_commodity(); break;
	case 2: a.search_commodity(); break;
	case 3: a.delete_commodity(); break;
	case 4: a.all_order(); break;
	case 5: a.all_user(); break;
	case 6: a.delete_user(); break;
	case 7: return; break;
	case 8: calculator(); break;
	default:cout << "ÊäÈë´íÎó" << endl;
	}
	goto A;
}