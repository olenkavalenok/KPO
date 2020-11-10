#pragma once

#include <iostream>
#include <string>
#include <list>
#include "Product.h"
#include "Time.h"

using namespace std;
setlocale(LC_ALL, "Russian");

// ЗАКАЗ
class Request
{
private:
	int number; // номер заказа
	string shop_name; // название магазина, для которого закупается товар
	Time time; // время закупки
public:
	vector<Product> products; // список товаров в заказе

	Request(int number, string shop_name, vector<Product> products, Time time); //конструктор
	Request(); //конструктор

	int getNumber();
	void setNumber(int number);

	string getShopName();
	void setShopName(string shop_name);

	vector<Product> getProductRequest();
	void setProductRequest(vector<Product> products);

	Time getTime();
	void setTime(Time time);

	void info_products(); // вывод списка товаров в заказе на консоль
	void info_request(); // вывод заказа на консоль
	void fixDemand(); // установка к-ва товаров в зависимости от спроса
};
