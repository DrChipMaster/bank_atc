#ifndef LIST_OF_BANKS_H
#define LIST_OF_BANKS_H
#include "banco.h"

#include <list>


class list_of_banks
{
list<banco> banks;
string name;
public:
	banco create_banco_io();
    bool add_bank();
    bool remove_bank(string name);
    list_of_banks(string name);
    banco *get_bank(string name);
};

#endif // LIST_OF_BANKS_H
