#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
#include "Customer.h"
#include "Request.h"

using namespace std;

// ���������
class Provider
{
private:
	string name; // ���
	string telephone; // �������
	string login; // �����
	string password; // ������
	string email; // ����� ��. �����
	string numcard; // ����� �����
	Request incoming_request; // �������� ������
	string message; // �������� ���������
public:
	vector<Product> products_provider; // ������ ������������ �������

	Provider(string name, string telephone, string login, string password, string email, string numcard, vector<Product> products_provider, Request incoming_request, string message); // �����������
	Provider(); // ����������� �� ���������

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

	vector<Product> getProductProvider();
	void setProductProvider(vector<Product> products_provider);

	Request getIncomingRequest();
	void setIncomingRequest(Request incoming_request);

	string getMessage();
	void setMessage(string message);

	void info_products_provider(); // ����� ������ ������������ �������
};
