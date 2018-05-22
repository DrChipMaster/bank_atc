#include <vector>
#include <list>
#include <string>
#include "account.h"
using namespace std;
#pragma once
class banco
{
	list<Account> accounts;
	long int balance;
	long int lucro;
	float taxas_monthly_payment[3];
	float taxas_transaction[3];
    const int numero;
public:
    banco();
	const string name;
    banco(string name, float tax_month[3], float tax_transaction[3],int numero);
	void update_accout_type();
	float monthly_payment();
	void add_account(Account &account);
	float calculate_balance();
	bool close_account(Account& account);
	~banco();
};

