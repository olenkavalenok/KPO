#include <iostream>
#include <list>
#include "Provider.h"
#include <iomanip>
#include "Customer.h"

using namespace std;

// конструктор
Provider::Provider(string name, string telephone, string login, string password, string email, string numcard, vector<Product> products_provider, Request incoming_request, string message){
	this->name = name; // имя
	this->telephone = telephone; // телефон
	this->login = login; // логин
	this->password = password; // пароль
	this->email = email; // адрес эл. почты
	this->numcard = numcard; // номер карты
	this->products_provider = products_provider; // список поставляемых товаров
	this->incoming_request = incoming_request; // входящие заказы
	this->message = message; // входящие сообщения
}

//конструктор по умолчанию
Provider::Provider() 
{
	this->name = "ООО Быстро и круглосуточно";
	this->telephone = "8(915)152-38-76";
	this->login = "c"; // allday1
	this->password = "d"; // 24.7.365
	this->email = "f"; // iphonemskopt@gmail.com
	this->numcard = "4000 1567 0000 0125";
	this->products_provider = { Product("Хлеб", 31, 432, 518, 550),
								Product("Гречка", 52, 205, 224, 300),
								Product("Рис", 65, 192, 235, 250),
								Product("Макароны", 54, 317, 302, 350),
								Product("Масло подсолнечное", 42, 123, 125, 150),
								Product("Колбаса докторская", 215, 279, 214, 300),
								Product("Мыло детское", 35, 156, 122, 200),
								Product("Салфетки бумажные", 25, 194, 228, 250),
								Product("Сок", 60, 220, 206, 250),
								Product("Шоколад", 300, 135, 151, 200),
								Product("Молоко", 70, 357, 324, 400) };
	this->incoming_request = Request(0, "", {}, {0, 0, 0, 0});
	this->message = "Здесь пока нет сообщений";
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

// вывод списка поставляемых товаров
void Provider::info_products_provider()
{
	cout << setw(3) << "№" << setw(30) 
		<< "Название товара" << setw(10)
		<< "Цена" << setw(30)
		<< "Спрос за текущий месяц" << setw(30)
		<< "Спрос за прошедший месяц" << setw(15)
		<< "Количество" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl << endl;
	for (int i = 0; i < getProductProvider().size(); i++)
		cout << setw(3) << i << getProductProvider()[i] << endl;
}
