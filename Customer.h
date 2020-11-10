#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Request.h"
#include "Provider.h"

using namespace std;

// ��������
class Customer
{
private:
	string name; // ���
	string telephone; // �������
	string login; // �����
	string password; // ������
	string email; // ����� ��. �����
	string numcard; // ����� �����
	string message; // �������� ���������
public:
	Customer(string name, string telephone, string login, string password, string email, string numcard, string message); // �����������
	Customer(); // ����������� �� ���������

	string getName();
	void setName(string name);

	string getTelephone();
	void setTelephone(string telephone);

	string getLogin();
	void setLogin(string login);

	string getPassword();
	void setPassword(string password);

	string getEmail();
	void setEmail(string email);

	string getNumcard();
	void setNumcard(string numcard);

	string getMessage();
	void setMessage(string message);
};

