#pragma once
#include<iostream>
#include"data.h"
#include"buyers.h"
#include"sellers.h"
#include"information.h"
using namespace std;
class users
{
public:
	void menu();
	void buyer_module(User &a);
	void seller_module(User &a);
	void self_information(User &a);


};
