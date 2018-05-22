#include "list_of_banks.h"

list_of_banks::list_of_banks(string name)
{
this->name=name;
}

bool list_of_banks::add_bank(banco new_bank)
{
       if(banks.size()+1<=banks.max_size())
       {
           banks.push_back(new_bank);
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

}
