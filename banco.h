#ifndef BANCO_H
#define BANCO_H
#include <vector>
#include <list>
#include <string>
#include "account.h"
using namespace std;
#pragma once
class banco
{
	list<Account> accounts;
	int number;
	long int balance;
	long int lucro;
	float taxas_monthly_payment[3];
	float taxas_transaction[3];
public:
    banco();
	const string name;
	banco(string name, float tax_month[3], float tax_transaction[3]);
	void update_accout_type();
	float monthly_payment();
	void add_account();
	Account creat_account_io();
	float calculate_balance();
	Account get_account_cc(int cc);
	bool close_account(int num);
	float fees();
	~banco();
};

#endif