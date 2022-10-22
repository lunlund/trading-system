#include<iostream>
#include<cstring>
#include"output.h"
using namespace std;
void f(char a[], int m)
{
	cout << a;
	for (int i = 0; i <= m - strlen(a); i++)
	{
		cout << " ";
	}
}