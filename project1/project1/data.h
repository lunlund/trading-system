#pragma once
#include<string>
#include<iostream>
using namespace std;
struct User
{
	char userID[5];
	char username[11];
	char password[21];
	char phonenumber[21];
	char address[41];
	double balance;
	bool userstate;
};
struct Commodity
{
	char commodityID[5];
	char commodityname[21];
	double price;
	int number;
	char description[201];
	char sellerID[5];
	char addedDate[11];
	bool state;

};
struct Order
{
	char orderID[5];
	char commodityID[5];
	double unitPrice;
	int number;
	char date[11];
	char sellerID[5];
	char buyerID[5];
	int state;
};