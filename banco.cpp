#include "banco.h"


banco::banco(string name, float tax_month[3], float tax_transaction[3], int numero):name(name),numero(numero)
{
	for (int i=0; i<3; i++)
	{ 
		this->taxas_monthly_payment[i] = tax_month[i];
		this->taxas_transaction[i] = tax_transaction[i];
	}
	
}
banco::banco():numero(1000){

}

void banco::update_accout_type()
{
	for (Account &a : accounts)
	{
		;
	}
}

float banco::monthly_payment()
{
	float total = 0;
	for (Account &a : accounts)
	{
		total += taxas_monthly_payment[a.get_type()];
		a.fee(taxas_monthly_payment[a.get_type()]);
	}
	return total;
}

void banco::add_account(Account &acount)
{
		accounts.push_back(acount);
}

float banco::calculate_balance()
{
	float total_balance = 0;
	for (Account &a : accounts)
		total_balance += a.get_saldo();
	return total_balance;
}

bool banco::close_account(Account& account)
{
	list<Account>::iterator it = accounts.begin();
	for (Account &a : accounts)
	{
		if (a.numero == account.numero)
		{
			accounts.erase(it);
			return true;
		}
		it++;
	}
	return false;	
}
banco::~banco()
{
}
