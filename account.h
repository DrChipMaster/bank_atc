#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "pessoa.h"


struct iban{
    string nome;
    int num_bank;
    int num_account;
};

struct movements
{
   iban from;
   iban destynation;
   int transaction_type;
   int value;

};

class Account
   {
    float saldo;
    int type;
    pessoa & Owner;

public:

	bool blocked;
    Account(int numero,pessoa &owner1,float saldo_ini=0,int type=0);
    bool deposit(float valor);
    bool withdraw(float valor);
    bool block_account(bool block_type);
    bool transaction(Account &destination,float value);
    bool change_type(int type);
	int get_type() { return type; }
	bool fee(float valor);
	float get_saldo() { return saldo; }
    const int numero;
    
};

#endif // ACCOUNT_H
