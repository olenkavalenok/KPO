#include <iostream>
#include <list>
#include "Provider.h"
#include <iomanip>
#include "Customer.h"

using namespace std;

// �����������
Provider::Provider(string name, string telephone, string login, string password, string email, string numcard, vector<Product> products_provider, Request incoming_request, string message){
	this->name = name; // ���
	this->telephone = telephone; // �������
	this->login = login; // �����
	this->password = password; // ������
	this->email = email; // ����� ��. �����
	this->numcard = numcard; // ����� �����
	this->products_provider = products_provider; // ������ ������������ �������
	this->incoming_request = incoming_request; // �������� ������
	this->message = message; // �������� ���������
}

//����������� �� ���������
Provider::Provider() 
{
	this->name = "��� ������ � �������������";
	this->telephone = "8(915)152-38-76";
	this->login = "c"; // allday1
	this->password = "d"; // 24.7.365
	this->email = "f"; // iphonemskopt@gmail.com
	this->numcard = "4000 1567 0000 0125";
	this->products_provider = { Product("����", 31, 432, 518, 550),
								Product("������", 52, 205, 224, 300),
								Product("���", 65, 192, 235, 250),
								Product("��������", 54, 317, 302, 350),
								Product("����� ������������", 42, 123, 125, 150),
								Product("������� ����������", 215, 279, 214, 300),
								Product("���� �������", 35, 156, 122, 200),
								Product("�������� ��������", 25, 194, 228, 250),
								Product("���", 60, 220, 206, 250),
								Product("�������", 300, 135, 151, 200),
								Product("������", 70, 357, 324, 400) };
	this->incoming_request = Request(0, "", {}, {0, 0, 0, 0});
	this->message = "����� ���� ��� ���������";
}

string Provider::getName()
{
	return this->name;
}
void Provider::setName(string name)
{
	this->name = name;
}

string Provider::getTelephone()
{
	return this->telephone;
}
void Provider::setTelephone(string telephone)
{
	this->telephone = telephone;
}

string Provider::getLogin()
{
	return this->login;
}
void Provider::setLogin(string login)
{
	this->login = login;
}

string Provider::getPassword()
{
	return this->password;
}
void Provider::setPassword(string password)
{
	this->password = password;
}

string Provider::getEmail()
{
	return this->email;
}
void Provider::setEmail(string email)
{
	this->email = email;
}

string Provider::getNumcard()
{
	return this->numcard;
}
void Provider::setNumcard(string numcard)
{
	this->numcard = numcard;
}

vector<Product> Provider::getProductProvider()
{
	return this->products_provider;
}
void Provider::setProductProvider(vector<Product> products_provider)
{
	this->products_provider = products_provider;
}

Request Provider::getIncomingRequest()
{
	return this->incoming_request;
}
void Provider::setIncomingRequest(Request incoming_request)
{
	this->incoming_request = incoming_request;
}

string Provider::getMessage()
{
	return this->message;
}
void Provider::setMessage(string message)
{
	this->message = message;
}

// ����� ������ ������������ �������
void Provider::info_products_provider()
{
	cout << setw(3) << "�" << setw(30) 
		<< "�������� ������" << setw(10)
		<< "����" << setw(30)
		<< "����� �� ������� �����" << setw(30)
		<< "����� �� ��������� �����" << setw(15)
		<< "����������" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl << endl;
	for (int i = 0; i < getProductProvider().size(); i++)
		cout << setw(3) << i << getProductProvider()[i] << endl;
}