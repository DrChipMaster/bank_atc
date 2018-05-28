#include "list_of_banks.h"
#include <iostream>
using namespace std;

list_of_banks::list_of_banks(string name)
{
this->name=name;
this->num_last_bank = 0;
}

bool list_of_banks::add_bank()
{
       if(banks.size()+1<=banks.max_size())
       {
           banks.push_back(create_banco_io());
		   num_last_bank++;
           return true;
       }
       else return false;

}

bool list_of_banks::remove_bank(string name)
{
    list<banco>::iterator it = banks.begin();
    for (banco &a : banks)
    {
        if (a.name ==name)
        {
            banks.erase(it);
            return true;
        }
        it++;
    }
    return false;
}

banco* list_of_banks::get_bank(string name)
{
    for (banco &a : banks)
    {
        if (a.name ==name)
        {

            return &a;
        }
    }
	return nullptr;
}

banco list_of_banks::create_banco_io()
{
	string name;
	float tax_month[3];
	float tax_transaction[3];

	cout << "Qual o nome do banco" << endl;
	cin >> name;
	cout << "valor das mensalidades" << endl;
	cin >> tax_month[0] >> tax_month[1] >> tax_month[2];
	cout << " valor das transacoes" << endl;
	cin >> tax_transaction[0] >> tax_transaction[1] >> tax_transaction[2];
	return banco(name, tax_month, tax_transaction, num_last_bank+1);
}