#include "banco.h"
#include "corrency.h"
#include "list_of_banks.h"
#include "pessoa.h"
#include "account.h"
#include <iostream>


using namespace std;

int choose_op();
void menu_list_banks(list_of_banks list, int op);
int choose_op_list();
void menu_bank(banco *bank, int op);
int choose_op_bank();
void menu_ATM();
int choose_op_ATM();

int main()
{
	string name;
	int op;
    banco *bank;
    list_of_banks Portugal("Portugal");
   while (1)
   {
	   switch (choose_op())
	   {
	   case 1:
	   { op = 0;
		   while (op != 4)
		   {
			   op = choose_op_list();
			   menu_list_banks(Portugal, op);
		   }
		}
	   case 2:
	   { op = 0;
	   do {
		   cout << " Nome do banco" << endl;
		   cin >> name;
		   bank = Portugal.get_bank(name);
	   } while (!bank);
	   while (op != 5)
	   {
		    op = choose_op_bank();
			menu_bank(bank, op);
	   }
	   }
	   default:
		   break;
	   }
   }
}


void menu_list_banks(list_of_banks list, int op)
{
	switch(op)
	{
	case 1:
	{ list.add_bank(); }
	case 2:
	{ list.remove_bank("pp"); }
	case 3:
	{ list.get_bank("pp"); }
	default:
		break;
	}
}
int choose_op_list()
{
	int op;
	cout << " 1 -> Criar um novo banco" << endl;
	cout << " 2 -> Remover um banco" << endl;
	cout << " 3 -> Procurar um banco" << endl;
	cout << " 4 -> Sair" << endl;
	cin >> op;
	return op;
}
void menu_bank(banco *bank, int op)
{
	switch (op)
	{
	case 1:
	{ bank->add_account(); }
	case 2:
	{int num;
	cout << "numero de conta" << endl;
	cin >> num;
	bank->close_account(num);
	}
	case 3:
	{ bank->update_accout_type(); }
	case 4:
	{bank->calculate_balance(); }
	default:
		break;
	}
}
int choose_op_bank()
{
	int op;
	cout << " 1 -> Criar uma nova conta" << endl;
	cout << " 2 -> Remover uma conta" << endl;
	cout << " 3 -> Atualiza tipo de contas" << endl;
	cout << " 4 -> Calcular balanco" << endl;
	cout << " 5 -> Sair" << endl;
	cin >> op;
	return op;
}

void menu_ATM(Account conta, int op)
{
	switch (op)
	{
	case 1:
	{float value;
	cout << "valor do deposito ?" << endl;
	cin >> value;
		conta.deposit(value); }
	case 2:
	{conta.get_saldo();	}
	case 3:
	{
		float value;
		cout << "valor do deposito ?" << endl;
		cin >> value; 
		conta.transaction(conta, value); }
	default:
		break;
	}
}
int choose_op_ATM()
{
	int op;
	cout << " 1 -> Fazer um deposito" << endl;
	cout << " 2 -> Saldo" << endl;
	cout << " 3 -> Transacao" << endl;
	cout << " 4 -> Sair" << endl;
	cin >> op;
	return op;
}
int choose_op()
{
	int op;
	cout << " 1 ->	menu Conjunto de bancos" << endl;
	cout << " 2 -> menu banco" << endl;
	cout << " 3 -> menu ATM" << endl;
	cout << " 4 -> Sair" << endl;
	cin >> op;
	return op;
}