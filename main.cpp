#include <QCoreApplication>
#include <banco.h>
#include <corrency.h>
#include "list_of_banks.h"
#include "pessoa.h"
#include "account.h"
#include <iostream>

using namespace std;
void init_new_world(banco *bank, string *name , float taxs[3],list_of_banks *Portugal);
void menu_geral();



int main()
{
    banco *bank;
    string name;
    float taxs[3];
     float transactions[]={0,0,0};
    list_of_banks Portugal("Portugal");
    init_new_world(bank, &name ,taxs, &Portugal);
    bool modo_geral=1, modo_banco=0,modo_conta=0;
    while(modo_geral)
    {
        cout<<endl<<"Criar banco -1 || Apagar banco -2 || Entrar em modo banco -3"<<endl;
        int resposta;
        cin>> resposta;
        switch (resposta) {
        case 1:
            cout<<"Bem-Vindo a criaçao do banco"<<endl;
            cout<<"Como ele se deverá chamar?"<<endl;
            cin>>name;
            cout<< "Muito Bem ... "<<endl;
            cout<<"Qual deverá ser a mensalidade Do tipo estudante?"<<endl<<"0-se nao tiver"<<endl;
            cin >> taxs[0];
            cout <<"Qual deverá ser a mensalidade do tipo reformado?"<<endl;
            cin >> taxs[1];
            //Portugal.add_bank(banco(name,taxs,transactions))
            if(Portugal.add_bank(banco(name,taxs,transactions,1000)))
            {
                cout<<"banco criado com sucesso"<<endl;
            }else cout<<"banco nao foi criado com sucesso"<<endl;
            break;
        case 2:
            cout<< "intruduza o nome do banco que pertende apagar!"<<endl;
            cin >> name;
            if(Portugal.remove_bank(name))
                cout<< "banco removido com sucesso!"<<endl;
            else cout << "nao foi possivel remover o banco"<<endl;
            break;
        case 3:
            cout<<"Qual o nome do banco que pertende entrar?"<<endl;
            cin >> name;
            bank=Portugal.get_bank(name);
            modo_banco=1;
            while(modo_banco)
            {
                cout<<"Adicionar conta-1 || Remover conta -2 || Fazer Mensalidades -3 ||"
                      " Calcular Desfazamentos- 4 || Entrar em modo Conta -5|| Sair de modo banco -0"<<endl;
                cin >> resposta;
                switch (resposta) {
                case 1:

                    break;
                default:
                    break;
                }

            }
            break;
        default:
            break;
        }

    }






}


void init_new_world(banco *bank, string *name , float taxs[3], list_of_banks *Portugal)
{
    cout<<"Bem-Vindo a criaçao do mundo bancario"<<endl<<"vamos criar o primeiro banco"<<endl<<endl;

    cout<<"Como ele se deverá chamar?"<<endl;
    cin>>*name;
    cout<< "Muito Bem ... "<<endl;

    cout<<"Qual deverá ser a mensalidade Do tipo estudante?"<<endl<<"0-se nao tiver"<<endl;
    cin >> taxs[0];
    cout <<"Qual deverá ser a mensalidade do tipo reformado?"<<endl;
    cin >> taxs[1];
    float transactions[]={0,0,0};
    if(Portugal->add_bank(banco(*name,taxs,transactions,1000)))
    {
        cout<<"banco criado com sucesso"<<endl;
    }

}
void menu_geral(){

}
