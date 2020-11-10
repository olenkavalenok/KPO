#pragma once

#include <iostream>
#include <string>
#include <list>
#include "Product.h"
#include "Time.h"

using namespace std;

// �����
class Request
{
private:
	int number; // ����� ������
	string shop_name; // �������� ��������, ��� �������� ���������� �����
	Time time; // ����� �������
public:
	vector<Product> products; // ������ ������� � ������

	Request(int number, string shop_name, vector<Product> products, Time time); //�����������
	Request(); //�����������

	int getNumber();
	void setNumber(int number);

	string getShopName();
	void setShopName(string shop_name);

	vector<Product> getProductRequest();
	void setProductRequest(vector<Product> products);

	Time getTime();
	void setTime(Time time);

	void info_products(); // ����� ������ ������� � ������ �� �������
	void info_request(); // ����� ������ �� �������
	void fixDemand(); // ��������� �-�� ������� � ����������� �� ������
};

