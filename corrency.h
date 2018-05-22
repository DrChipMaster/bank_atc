#ifndef CORRENCY_H
#define CORRENCY_H
#include <string>
#include <vector>
#include <list>
#include <string>

using namespace std;

struct coin
{
    string name;
    float value_to_euro;
};

class Corrency
{
    list<coin> coins;
public:
    Corrency();
    Corrency(coin euro, coin dolar);
    bool add_coin(coin coin_new);
    bool remove_coin(string name);
    float value_converter(coin from, coin to);
    float value_converter(coin from);
    bool update_corrency();
};

#endif // CORRENCY_H
