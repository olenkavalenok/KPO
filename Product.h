#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// �����
class Product
{
private:
	string product_name; // �������� ������
	double price; // ���� ������
	int demand; // ����� �� ����� �� ������� �����
	int last_demand; // ����� �� ����� �� ������� �����
	int count; // �-�� ������
public:
	Product(string product_name, double price, int demand, int last_demand, int count); //�����������
	Product(); //����������� �� ���������

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

	friend ostream& operator << (std::ostream& out, const Product& Product); // ���������� ���������, ����� ���������� � ������
};

