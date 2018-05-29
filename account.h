#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "pessoa.h"
 #include <list>

using namespace std;

struct iban{
    string nome;
    int num_bank;
    int num_account;
};

struct movement
{
   iban from;
   iban destynation;
   string transaction_type;
   float value;

};

class Account
   {
    iban iban_acount;
    float saldo;
    int type;

    list<movement> movements;

public:
    pessoa & Owner;
	bool blocked;
	Account(iban  newiban, pessoa &owner1, float saldo_ini = 0, int type = 0);
    bool deposit(float valor);
    bool deposit(float valor,movement mov);
    bool withdraw(float valor);
    bool block_account(bool block_type);
    bool transaction(Account &destination,float value);
    bool change_type(int type);
	int get_num_account() { return iban_acount.num_account; }
	int get_type() { return type; }
	bool fee(float valor);
	float get_saldo() { return saldo; }
    const int numero;
    iban get_iban();
    
};

#endif // ACCOUNT_H
