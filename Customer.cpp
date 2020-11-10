#include <iostream>
#include <list>
#include "Customer.h"
#include "Request.h"
#include <iomanip>

using namespace std;

// �����������
Customer::Customer(string name, string telephone, string login, string password, string email, string numcard, string message)
{
	this->name = name; // ���
	this->telephone = telephone; // �������
	this->login = login; // �����
	this->password = password; // ������
	this->email = email; // ����� ��. �����
	this->numcard = numcard; // ����� �����
	this->message = message; // �������� ���������
}

// ����������� �� ���������
Customer::Customer()
{
	this->name = "��� ������ �������";
	this->telephone = "8(800)200-90-02";
	this->login = "admin5&8";
	this->password = "27.10.2020";
	this->email = "Talvitie@magnit.ru";
	this->numcard = "4573 7800 0000 0156";
	this->message = "";
}

string Customer::getName()
{
	return this->name;
}
void Customer::setName(string name)
{
	this->name = name;
}

string Customer::getTelephone()
{
	return this->telephone;
}
void Customer::setTelephone(string telephone)
{
	this->telephone = telephone;
}

string Customer::getLogin()
{
	return this->login;
}
void Customer::setLogin(string login)
{
	this->login = login;
}

string Customer::getPassword()
{
	return this->password;
}
void Customer::setPassword(string password)
{
	this->password = password;
}

string Customer::getEmail()
{
	return this->email;
}
void Customer::setEmail(string email)
{
	this->email = email;
}

string Customer::getNumcard()
{
	return this->numcard;
}
void Customer::setNumcard(string numcard)
{
	this->numcard = numcard;
}

string Customer::getMessage()
{
	return this->message;
}
void Customer::setMessage(string message)
{
	this->message = message;
}