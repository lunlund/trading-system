#include"main1.h"
#include"administrator_module.h"
#include"user_module.h"
#include<string>
int main()
{
	char k[100];
	main_ a;
	a.check();
	while (1)
	{
		a.menu();
		int m;
		cout << "请输入操作" << endl;
		cin >> m;
		cin.getline(k, 100);
		switch (m)
		{
		case 1: if (a.administrator() == 1)
		{
			administrator_module();
		}
			   else
		{
			cout << "密码错误，登录失败，返回主菜单" << endl;
		}break;
		case 2: if (a.sign_up() == 1)
		{
			cout << "注册成功" << endl;
		}
			   else
		{
			cout << "注册失败" << endl;
		}break;
		case 3: {
			User *aa = a.sign_in();
			if (aa != NULL)
			{
				user_module(*aa);
			}
			else
			{
				//cout << "密码错误，登录失败，返回主菜单" << endl;
			}break; }
		case 4: return 0; break;
		default:cout << "输入错误" << endl; break;
		}
	}


}
