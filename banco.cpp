#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include <ctime>
#include "banco.h"

using namespace std;

banco::banco(string name, float tax_month[3], float tax_transaction[3], int num):name(name)
{
	num_last_account = 0;
	for (int i=0; i<3; i++)
	{ 
		this->taxas_monthly_payment[i] = tax_month[i];
		this->taxas_transaction[i] = tax_transaction[i];
		this->number = num;
	}
	
}
banco::banco(){

}

void banco::update_accout_type()
{
	time_t t = time(0); 
	tm* now = localtime(&t);
	int month = now->tm_mon + 1;
	int year = now->tm_year + 1900;
	for (Account &a : accounts)
	{
		two born_date = a.Owner.get_born_date();
		if (year - born_date.y > 65 || (year - born_date.y > 65 && month >= born_date.x))
			a.change_type(2);
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

void banco::add_account()
{
	accounts.push_back(creat_account_io());
	num_last_account++;
}

float banco::calculate_balance()
{
	float total_balance = 0;
	for (Account &a : accounts)
		total_balance += a.get_saldo();
	return total_balance;
}

bool banco::close_account(int num)
{
	list<Account>::iterator it = accounts.begin();
	for (Account &a : accounts)
	{
		if (a.get_num_account() == num)
		{
			accounts.erase(it);
			return true;
		}
	}
	return false;	
}

Account banco::creat_account_io()
{
	iban newiban;
	string nome;
	int numero_cc;
	int born_date[2];
	string address;
	int zip_code[2];
	int phone_number;
	int type;
	string e_mail;
	cout << "Qual e o nome do cliente" << endl;
	cin >> nome;
	cout << "Qual e a data de nascimento mes ano" << endl;
	cin >> born_date[0] >> born_date[1];
	cout << "Qual e a sua morada?" << endl;
	cin >> address;
	cout << "Qual e o seu codigo postal ?" << endl;
	cin >> zip_code[0] >> zip_code[1];
	cout << "Qual e o seu numero de telemovel?" << endl;
	cin >> phone_number;
	cout << "Qual é o seu e_mail" << endl;
	cin >> e_mail;
	cout << "Qual e o numero de CC" << endl;
	cin >> numero_cc;
	pessoa person(nome, numero_cc, born_date, address, zip_code, phone_number, e_mail);
	cout << "Qual o tipo de conta que deseja abrir" << endl;
	cin >> type;
	newiban.num_account = num_last_account + 1;
	newiban.num_bank = number;
	newiban.nome = "PT50";
	Account new_account(newiban, person, 0, type);
	return new_account;
}

float banco::fees()
{
	float total= 0;
	for (Account &a : accounts)
	{
		if (!a.fee(taxas_monthly_payment[a.get_type()]))
			a.block_account(true);
		total += taxas_monthly_payment[a.get_type()];
	}
	return total;
}


banco::~banco()
{
}

