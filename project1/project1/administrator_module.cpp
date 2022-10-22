#include"administrator_module.h"
#include"calculator.h"
//#include <stdlib.h>
#include<windows.h>
void administrator_module()
{
	char k[100];
A:
	administrator a;
	a.menu();
	int b;
	cout << "请输入操作" << endl;
	//cin >> b;
	while (scanf_s("%d", &b) == 0)
	{
		while (getchar() != '\n');
		cout << "输入错误,请重新输入" << endl;
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
	case 7: cout << "正在跳转" << endl;Sleep(1000);  system("cls"); return; break;
	case 8: calculator(); break;
	default:cout << "输入错误" << endl;
	}
	goto A;
}