#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// “ќ¬ј–
class Product
{
private:
	string product_name; // название товара
	double price; // цена товара
	int demand; // спрос на товар за текущий мес€ц
	int last_demand; // спрос на товар за прошлый мес€ц
	int count; // к-во товара
public:
	Product(string product_name, double price, int demand, int last_demand, int count); //конструктор
	Product(); //конструктор по умолчанию

	string getProduct_Name();
	void setProduct_Name(string product_name);

	double getPrice();
	void setPrice(double price);

	int getDemand();
	void setDemand(int demand);

	int getLastDemand();
	void setLastDemand(int last_demand);

	int getCount();
	void setCount(int count);

	friend ostream& operator << (std::ostream& out, const Product& Product); // перегрузка оператора, вывод информации о товаре
};

