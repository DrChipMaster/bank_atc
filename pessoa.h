#include <string>

using namespace std;

#pragma once

struct two { int x;
int y;
};
class pessoa
{
private:
	string e_mail;
	string adress;
	int number_cc;
	int zip_code[2];
	int phone_number;
	int born_date[2];

public:
	const string name;
	pessoa(string name, int number_cc, int born_date[2], string adress, int zip_code[2], int phone_number, string e_mail);
	bool update_adress(string new_adress, int zip_code[2]);
	bool update_cc(int new_number_cc);
	bool update_phone_number(int new_phone_number);
	bool update_e_mail(string new_e_mail);
	two get_born_date() { return { born_date[0], born_date[1] }; }
	~pessoa();
};

