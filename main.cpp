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
    bool program_on=1;
   while (program_on)
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
        }break;
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
       }break;
        case 3:


           break;
         case 4:
           program_on=0;
           break;

	   default:
           cout<<"Numero de operaçao invalida!"<<endl;
		   break;
	   }
   }
}


void menu_list_banks(list_of_banks list, int op)
{
 bool in_menu=1;
 while(in_menu)
    {
	switch(op)
	{
	case 1:
    { list.add_bank(); }
        break;
	case 2:
	{ list.remove_bank("pp"); }
        break;
	case 3:
	{ list.get_bank("pp"); }
        break;
    case 4:
        in_menu=0;
        break;
	default:
        in_menu=0;
        cout<<"Opção invalida, tente novamente"<<endl;
		break;
	}
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
    bool menu_bank1=1;
    while (menu_bank1)
    {
        switch (op)
         {
            case 1:
             bank->add_account();
            break;
            case 2:
                int num;
                cout << "numero de conta" << endl;
                cin >> num;
                bank->close_account(num);
            break;
            case 3:
                bank->update_accout_type();
             break;
            case 4:
                bank->calculate_balance();
             break;
            default:
                cout<<"Operaçao invalida, Tente novamente"<<endl;
                break;
        }
    }
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



int choose_op_bank()
{
    int op;
    cout << " 1 -> Criar uma nova conta  ||";
    cout << " 2 -> Remover uma conta  ||";
    cout << " 3 -> Atualiza tipo de contas  ||";
    cout << " 4 -> Calcular balanco ||";
    cout << " 5 -> Sair" << endl;
    cin >> op;
    return op;
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
    cout << " 1 ->	menu Conjunto de bancos ||";
    cout << " 2 -> menu banco ||";
    cout << " 3 -> menu ATM  ||";
    cout << " 4 -> Sair" << endl;
	cin >> op;
	return op;
}
