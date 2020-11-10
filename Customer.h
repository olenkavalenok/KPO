#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Request.h"
#include "Provider.h"

using namespace std;

// ЗАКАЗЧИК
class Customer
{
private:
	string name; // имя
	string telephone; // телефон
	string login; // логин
	string password; // пароль
	string email; // адрес эл. почты
	string numcard; // номер карты
	string message; // входящие сообщения
public:
	Customer(string name, string telephone, string login, string password, string email, string numcard, string message); // конструктор
	Customer(); // конструктор по умолчанию

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
