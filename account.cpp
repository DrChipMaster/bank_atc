#include "account.h"

Account::Account(iban newiban ,pessoa &owner1,float saldo_ini,int type):numero(numero), Owner(owner1)
{
    this->saldo=saldo_ini;
    this->type=type;
	iban_acount = newiban;

}

bool Account::deposit(float valor)
{
    if(valor * !blocked >= 1)
    {
        movements.push_back(movement{iban_acount,iban_acount,"deposit",valor});
        saldo += valor;
        return true;
    }
    else
    {
        return false;
    }
}

bool Account::deposit(float valor,movement mov)
{
    if(valor * !blocked >= 1)
    {
        movements.push_back(mov);
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
        movements.push_back(movement{iban_acount,iban_acount,"withaw",valor});
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
    movement mov={iban_acount,destination.get_iban(),"withaw",value};
    movements.push_back(mov);
    saldo-=value;
    if(destination.deposit(value,mov))return true;
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
 iban Account::get_iban()
 {
     return iban_acount;
 }




