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

// �����������
Request::Request(int number, string shop_name, vector<Product> products, Time time)
{
	this->number = number; // ����� ������
	this->shop_name = shop_name; // �������� ��������, ��� �������� ���������� �����
	this->products = products; // ������ ������� � ������
	this->time = time; // ����� �������
}

//����������� �� ���������
Request::Request()
{
	this->shop_name = "������";
	this->products={Product("����", 31, 432, 518, 550),
					Product("������", 52, 205, 224, 300),
					Product("���", 65, 192, 235, 250),
					Product("��������", 54, 317, 302, 350),
					Product("����� ������������", 42, 123, 125, 150),
					Product("������� ����������", 215, 279, 214, 300),
					Product("���� �������", 35, 156, 122, 200),
					Product("�������� ��������", 25, 194, 228, 250) };
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

// ����� ������ ������� � ������ �� �������
void Request::info_products()
{
	cout << setw(3) << "�" << setw(30)
		<< "�������� ������" << setw(10)
		<< "����" << setw(30)
		<< "����� �� ������� �����" << setw(30)
		<< "����� �� ��������� �����" << setw(15)
		<< "����������" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < products.size(); i++)
		cout << setw(3) << i << products[i] << endl;
}

// ����� ������ �� �������
void Request::info_request()
{
	cout << "\n" << "-------------------------------------------------***�������: " << shop_name << "***------------------------------------------------" << endl;
	cout << "\n" << "-------------" << "����� �: " << number << "----------------------------------------------------------------------------------------------" << endl;
	cout << "\n" << setw(65) << "***�����������***" << endl << endl;
	info_products();
	cout << "-------------����� ������: " << time << "----------------------------------------------------------------------------------" << endl << endl;
}

// ��������� �-�� ������� � ����������� �� ������
void Request::fixDemand()
{
	for (int i = 0; i < products.size(); i++)
	{
		// ���� ����� ���� �� 20%, �� ��������� �-�� �� 20%
		if (products[i].getDemand() / products[i].getLastDemand() < 0.8)
		{
			int new_count = int(products[i].getCount() * 0.8);
			products[i].setCount(new_count);
		}
		// ���� ����� ��������� �� 20%, �� ����������� �-�� �� 20%
		else if (products[i].getDemand() / products[i].getLastDemand() > 1.2)
		{
			int new_count = int(products[i].getCount() * 1.2);
			products[i].setCount(new_count);
		}
	}
}