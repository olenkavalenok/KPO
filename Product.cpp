#include <iostream>
#include <list>
#include <string>
#include "Product.h"
#include <iomanip>

using namespace std;

// �����������
Product::Product(string product_name, double price, int demand, int last_demand, int count)
{
	this->product_name = product_name; // �������� ������
	this->price = price; // ���� ������
	this->demand = demand; // ����� �� ����� �� ������� �����
	this->last_demand = last_demand; // ����� �� ����� �� ������� �����
	this->count = count; // �-�� ������
}

//����������� �� ���������
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

// ���������� ���������, ����� ���������� � ������
ostream& operator << (std::ostream& out, const Product& Product)
{
	return out << setw(30) << Product.product_name << setw(10)
		<< Product.price << setw(30)
		<< Product.demand << setw(30)
		<< Product.last_demand << setw(15)
		<< Product.count << endl;
}

