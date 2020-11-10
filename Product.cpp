#include <iostream>
#include <list>
#include <string>
#include "Product.h"
#include <iomanip>

using namespace std;

// конструктор
Product::Product(string product_name, double price, int demand, int last_demand, int count)
{
	this->product_name = product_name; // название товара
	this->price = price; // цена товара
	this->demand = demand; // спрос на товар за текущий месяц
	this->last_demand = last_demand; // спрос на товар за прошлый месяц
	this->count = count; // к-во товара
}

//конструктор по умолчанию
Product::Product() 
{
	this->product_name = "";
	this->price = 0;
	this->demand = 0;
	this->last_demand = 0;
	this->count = 0;
}

string Product::getProduct_Name()
{
	return this->product_name;
}
void Product::setProduct_Name(string product_name)
{
	this->product_name = product_name;
}

double Product::getPrice()
{
	return this->price;
}
void Product::setPrice(double price)
{
	this->price = price;
}

int Product::getDemand()
{
	return this->demand;
}
void Product::setDemand(int demand)
{
	this->demand = demand;
}

int Product::getLastDemand()
{
	return this->last_demand;
}
void Product::setLastDemand(int last_demand)
{
	this->last_demand = last_demand;
}

int Product::getCount()
{
	return this->count;
}
void Product::setCount(int count)
{
	this->count = count;
}

// перегрузка оператора, вывод информации о товаре
ostream& operator << (std::ostream& out, const Product& Product)
{
	return out << setw(30) << Product.product_name << setw(10)
		<< Product.price << setw(30)
		<< Product.demand << setw(30)
		<< Product.last_demand << setw(15)
		<< Product.count << endl;
}
