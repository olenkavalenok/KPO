#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
#include "Customer.h"
#include "Request.h"

using namespace std;

// ПОСТАВЩИК
class Provider
{
private:
	string name; // имя
	string telephone; // телефон
	string login; // логин
	string password; // пароль
	string email; // адрес эл. почты
	string numcard; // номер карты
	Request incoming_request; // входящие заказы
	string message; // входящие сообщения
public:
	vector<Product> products_provider; // список поставляемых товаров

	Provider(string name, string telephone, string login, string password, string email, string numcard, vector<Product> products_provider, Request incoming_request, string message); // конструктор
	Provider(); // конструктор по умолчанию

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

	void info_products_provider(); // вывод списка поставляемых товаров
};
