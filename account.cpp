#include "account.h"

Account::Account(int numero,pessoa &owner1,float saldo_ini,int type):numero(numero), Owner(owner1)
{
    this->saldo=saldo_ini;
    this->type=type;


}

bool Account::deposit(float valor)
{
    if(valor * !blocked >= 1)
    {
        saldo += valor;
        return true;
    }
    else
    {
        return false;
    }
}
bool Account::withdraw(float valor)
{
    if(valor>=1 && valor <= saldo && !blocked)
    {
        saldo-=valor;
        return true;

    }
    else return false;
}
bool Account::block_account(bool Block_type)
{
 if(blocked!=Block_type)
 {
     blocked=Block_type;
     return true;
 }
 else
     return false;
}

 bool Account::transaction(Account &destination,float value)
 {
if(!destination.blocked && !blocked && value>1 && value <= saldo)
{
    saldo-=value;
    if(destination.deposit(value))return true;
    return false;
}
else return false;
 }
 bool Account::change_type(int type)
{
if (this->type!= type)
{
    this->type=type;
    return true;

}
else return false;

 }
 bool Account::fee(float value)
 {
	 saldo -= value;
	 if (saldo < 0)
		 return false;
	 return true;
 }


