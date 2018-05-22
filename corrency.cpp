#include "corrency.h"

Corrency::Corrency()
{

}


Corrency::Corrency(coin euro, coin dolar)
{
    coins.push_back(euro);
    coins.push_back(dolar);
}

bool Corrency::add_coin(coin coin_new)
{
   if(coins.size()+1<=coins.max_size())
   {
       coins.push_back(coin_new);
       return true;
   }
   else return false;
}

bool Corrency::remove_coin(string name){
   list<coin>::iterator it = coins.begin();
    for(coin &x :coins)
    {

        if(x.name==name)
        {
            coins.erase(it);
            return true;
        }
        it++;
    }return false;


}

float Corrency::value_converter(coin from, coin to)
{
    return from.value_to_euro/to.value_to_euro;
}


float Corrency::value_converter(coin from)
{
    return from.value_to_euro;
}


bool update_corrency();
