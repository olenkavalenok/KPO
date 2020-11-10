#include <iostream>
#include <list>
#include <string>
#include "Request.h"
#include "Product.h"
#include "Time.h"
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

// конструктор
Request::Request(int number, string shop_name, vector<Product> products, Time time)
{
	this->number = number; // номер заказа
	this->shop_name = shop_name; // название магазина, для которого закупается товар
	this->products = products; // список товаров в заказе
	this->time = time; // время закупки
}

//конструктор по умолчанию
Request::Request()
{
	this->shop_name = "Магнит";
	this->products={Product("Хлеб", 31, 432, 518, 550),
					Product("Гречка", 52, 205, 224, 300),
					Product("Рис", 65, 192, 235, 250),
					Product("Макароны", 54, 317, 302, 350),
					Product("Масло подсолнечное", 42, 123, 125, 150),
					Product("Колбаса докторская", 215, 279, 214, 300),
					Product("Мыло детское", 35, 156, 122, 200),
					Product("Салфетки бумажные", 25, 194, 228, 250) };
	this->time = Time();
}

int Request::getNumber()
{
	return this->number;
}
void Request::setNumber(int number)
{
	this->number = number;
}


string Request::getShopName()
{
	return this->shop_name;
}
void Request::setShopName(string shop_name)
{
	this->shop_name = shop_name;
}

vector<Product> Request::getProductRequest()
{
	return this->products;
}
void Request::setProductRequest(vector<Product> products)
{
	this->products = products;
}

Time Request::getTime()
{
	return this->time;
}
void Request::setTime(Time time)
{
	this->time = time;
}

// вывод списка товаров в заказе на консоль
void Request::info_products()
{
	cout << setw(3) << "№" << setw(30)
		<< "Название товара" << setw(10)
		<< "Цена" << setw(30)
		<< "Спрос за текущий месяц" << setw(30)
		<< "Спрос за прошедший месяц" << setw(15)
		<< "Количество" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < products.size(); i++)
		cout << setw(3) << i << products[i] << endl;
}

// вывод заказа на консоль
void Request::info_request()
{
	cout << "\n" << "-------------------------------------------------***Магазин: " << shop_name << "***------------------------------------------------" << endl;
	cout << "\n" << "-------------" << "Заказ №: " << number << "----------------------------------------------------------------------------------------------" << endl;
	cout << "\n" << setw(65) << "***Ассортимент***" << endl << endl;
	info_products();
	cout << "-------------Время заказа: " << time << "----------------------------------------------------------------------------------" << endl << endl;
}

// установка к-ва товаров в зависимости от спроса
void Request::fixDemand()
{
	for (int i = 0; i < products.size(); i++)
	{
		// если спрос упал на 20%, то уменьшаем к-во на 20%
		if (products[i].getDemand() / products[i].getLastDemand() < 0.8)
		{
			int new_count = int(products[i].getCount() * 0.8);
			products[i].setCount(new_count);
		}
		// если спрос повысился на 20%, то увеличиваем к-во на 20%
		else if (products[i].getDemand() / products[i].getLastDemand() > 1.2)
		{
			int new_count = int(products[i].getCount() * 1.2);
			products[i].setCount(new_count);
		}
	}
}