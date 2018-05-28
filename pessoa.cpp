#include "pessoa.h"


pessoa::pessoa(string name, int number_cc, int born_date[2], string adress, int zip_code[2], int phone_number = 0, string e_mail = "false"):name(name)
{
	this->number_cc = number_cc;
	this->adress = adress;
	this->zip_code[0] = zip_code[0];
	this->zip_code[1] = zip_code[1];
	this->phone_number = phone_number;
	this->e_mail = e_mail;
	this->born_date[0] = born_date[0];
	this->born_date[1] = born_date[1];
}

bool pessoa::update_adress(string new_adress, int new_zip_code[2])
{
	if (new_zip_code[0] > 999 && new_zip_code[0] <= 9999)
		if (new_zip_code[1] > 99 && new_zip_code[1] <= 999)
		{
			adress = new_adress;
			this->zip_code[0] = new_zip_code[0];
			this->zip_code[1] = new_zip_code[1];
			return true;
		}
	return false;
}

bool pessoa::update_cc(int new_number_cc)
{
	if (new_number_cc > 9999999 && new_number_cc <= 99999999)
	{
		this->number_cc = new_number_cc;
		return true;
	}
	return false;
}

bool pessoa::update_phone_number(int new_phone_number)
{
	if (new_phone_number <= 999999999 && new_phone_number > 99999999)
	{
		this->phone_number = new_phone_number;
		return true;
	}
	return false;
}

bool pessoa::update_e_mail(string new_e_mail)
{
	if (new_e_mail.size()/sizeof(char) > new_e_mail.find('@'))
		if (new_e_mail.find('@') < new_e_mail.find_last_of('.'))
		return true;
	return false;
}

pessoa::~pessoa()
{
}
