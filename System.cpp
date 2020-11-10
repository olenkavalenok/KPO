#include <iostream>
#include <list>
#include <string>
#include "Request.h"
#include "Provider.h"
#include "Customer.h"
#include <iomanip>
#include <cstring>
#include <sstream>

using namespace std;

// �������

// ���� "�����"
void menu_request(Request* request, Provider* provider)
{
	int a;
	int j;
	bool flag = true;
	int input_count;
	Time new_time;
	bool aExit = false;
	while (!aExit)
	{
		cout << "\n" << setw(40) << "�������� ������ �������" << setw(35) << "�������� ����� �������.....4" << endl;
		cout << setw(40) << "������� �����.......................1" << endl;
		cout << setw(40) << "�������� �����......................2" << endl;
		cout << setw(40) << "�������� ���������� ������..........3" << setw(35) << "�����......................0" << endl << endl;
		do {
			cout << "������� ����� �������: ";
			cin >> a;
		} while ((a < 0) || (a > 4));
		switch (a)
		{
		// ������� �����
		case 1:
			request->info_products(); // ����� ������� � ������
			int i;
			cout << "������� ����� ������: ";
			cin >> i;
			request->products.erase(request->products.begin() + i); // �������� ������ ��� ������� i
			break;
		// �������� �����
		case 2:
			provider->info_products_provider(); // ����� ������ �������, ������� ���� � ����������
			cout << "������� ����� ������: ";
			cin >> i;
			for (j = 0; j < request->products.size(); j++)
				if (request->products[j].getProduct_Name() == provider->getProductProvider()[i].getProduct_Name()) // ���������, ���� �� ��������� ����� � ������
					flag = false;
			if (flag == true)
				request->products.emplace_back(provider->getProductProvider()[i]); // ���������� � ����� ������ ��� ������� i, ���� ��� �� ����� �� ����
			else
				cout << "����� ��� ��������" << endl;
			break;
		// �������� �-�� ������
		case 3:
			request->info_products(); // ����� ������� � ������ 
			cout << "������� ����� ��������: ";
			cin >> i;
			cout << "������� ����������: ";
			cin >> input_count;
			request->products[i].setCount(input_count); // �������� �-�� ������ ��� ������� i
			break;
		// �������� ����� �������
		case 4:
			int new_day, new_hour, new_minute, new_second; // ����� ��������� �������
			cout << "������� �����: ";
			cin >> new_day;
			cin >> new_hour;
			cin >> new_minute;
			cin >> new_second;
			// ������������� �������� ����������
			new_time.setDay(new_day);
			new_time.setHour(new_hour);
			new_time.setMinute(new_minute);
			new_time.setSecond(new_second);
			request->setTime(new_time); // ������������� ����� �����
			break;
		// ����� �� ����
		case 0:
			aExit = true;
			break;
		}
	}
}

// ���� ���������
void menu_customer(Customer* customer, Request* request, Provider* provider)
{
	int a;
	bool aExit = false;
	string new_name; // ����� ���
	string new_login; // ����� �����
	string new_password; // ����� ������
	string new_telephone; // ����� �������
	string new_email; // ����� ����� ��. �����
	string new_numcard; // ����� ����� �����
	string input_message;
	string input_email;

	// ���������� ����� ������
	setlocale(0, "");
	int random;
	srand(time(NULL));
	random = 0 + rand() % +100;
	(*request).setNumber(random); // ������������� ����� ������

	request->fixDemand(); // ������������� �-�� ������� � ����������� �� ������
	while (!aExit)
	{
		cout << "\n" << setw(40) << "�������� ������" << setw(30) << "�����" << endl;

		cout << setw(40) << "�������� ���........................1" << setw(30) << "���������� �����......7" << setw(30) << "�������� ���������...10" << endl;
		cout << setw(40) << "�������� �����......................2" << setw(30) << "�������� �����........8" << setw(30) << "��������� ���������..11" << endl;
		cout << setw(40) << "�������� ������.....................3" << setw(30) << "��������� �����.......9" << endl;
		cout << setw(40) << "�������� �������....................4" << endl;
		cout << setw(40) << "��������� ������ ��. �����..........5" << endl;
		cout << setw(40) << "��������� ���������� ����������.....6" << setw(60) << "�����.................0" << endl << endl;

		do {
			cout << "������� ����� �������: ";
			cin >> a;
		} while ((a < 0) || (a > 11));
		switch (a)
		{
		// �������� ���
		case 1:
			cout << "������� ����� ���: ";
			cin >> new_name;
			customer->setName(new_name);
			break;
		// �������� �����
		case 2:
			cout << "������� ����� �����: ";
			cin >> new_login;
			customer->setLogin(new_login);
			break;
		// �������� ������
		case 3:
			cout << "������� ����� ������: ";
			cin >> new_password;
			customer->setPassword(new_password);
			break;
		// �������� �������
		case 4:
			cout << "������� ����� �������: ";
			cin >> new_telephone;
			customer->setTelephone(new_telephone);
			break;
		// �������� ����� ��. �����
		case 5:
			cout << "������� ����� ����� ��. �����: ";
			cin >> new_email;
			customer->setEmail(new_email);
			break;
		// �������� ����� �����
		case 6:
			cout << "������� ����� ����� �����: ";
			cin >> new_numcard;
			customer->setNumcard(new_numcard);
			break;
		// ���������� �����
		case 7:
			request->info_request();
			break;
		// �������� �����
		case 8:
			menu_request(&(*request), &(*provider)); // � ���� "�����"
			break;
		// ��������� �����
		case 9:
			provider->setIncomingRequest(*request); // ��������� ����� �� "�������� ������" ����������
			break;
		// ���������� �������� ���������
		case 10:
			cout << customer->getMessage();
			break;
		// ��������� ���������
		case 11:
			do {
				cout << "������� ����� �����: ";
				cin >> input_email;
			} while (provider->getEmail() != input_email); // �������� ������������ �������� ������
			cout << "������� ���������" << endl;
			cin >> input_message; // ���������
			provider->setMessage(input_message); // ��������� ��������� �� "�������� ���������" ����������
			break;
		// ����� �� ����
		case 0:
			aExit = true;
			break;
		}
	}
}

// ���� ����������
void menu_provider(Provider* provider, Customer* customer, Request* request)
{
	int c;
	int i, j;
	bool cExit = false;
	double new_price; // ����� ����
	string new_name; // ����� ���
	string new_login; // ����� �����
	string new_password; // ����� ������
	string new_telephone; // ����� �������
	string new_email; // ����� ����� ��. �����
	string new_numcard; // ����� ����� �����
	string input_email;
	string name_i;
	string s;
	ostringstream ost;

	string new_product_name; // �������� ������ ������
	double new_product_price; // ���� ������ ������
	int new_product_count; // ���������� ������ ������
	Product new_product;

	while (!cExit)
	{
		cout << "\n" << setw(40) << "�������� ������" << setw(35) << "�����" << setw(25) << "��������" << endl;

		cout << setw(40) << "�������� ���........................1" << setw(35) << "�������� �����................7" << setw(25) << "�������� �������....10" << endl;
		cout << setw(40) << "�������� �����......................2" << setw(35) << "������ � �������������........8" << setw(25) << "������� �������.....11" << endl;
		cout << setw(40) << "�������� ������.....................3" << setw(60) <<                                                  "�������� ����.......12" << endl;
		cout << setw(40) << "�������� �������....................4" << endl;
		cout << setw(40) << "��������� ������ ��. �����..........5" << endl;
		cout << setw(40) << "��������� ���������� ����������.....6" << setw(35) << "�������� ���������............9" << setw(25) << "�����................0" << endl << endl;
		do
		{
			cout << "������� ����� �������: ";
			cin >> c;
		} while (c < 0 || c > 12);
		switch (c)
		{
		// �������� ���
		case 1:
			cout << "������� ����� ���: ";
			cin >> new_name;
			provider->setName(new_name);
			break;
		// �������� �����
		case 2:
			cout << "������� ����� �����: ";
			cin >> new_login;
			provider->setLogin(new_login);
			break;
		// �������� ������
		case 3:
			cout << "������� ����� ������: ";
			cin >> new_password;
			provider->setPassword(new_password);
			break;
		// �������� �������
		case 4:
			cout << "������� ����� �������: ";
			cin >> new_telephone;
			provider->setTelephone(new_telephone);
			break;
		// �������� ����� ��. �����
		case 5:
			cout << "������� ����� ����� ��. �����: ";
			cin >> new_email;
			provider->setEmail(new_email);
			break;
		// �������� ����� �����
		case 6:
			cout << "������� ����� ����� �����: ";
			cin >> new_numcard;
			provider->setNumcard(new_numcard);
			break;
		// ���������� �������� �����
		case 7:
			provider->getIncomingRequest().info_request();
			break;
		// �������� �������������
		case 8:
			do {
				cout << "������� ����� �����: ";
				cin >> input_email;
			} while (customer->getEmail() != input_email); // �������� ������������ �������� ������
			ost << request->getNumber(); // ����� ������
			s = "����� � " + ost.str() + " �������"; // ���������
			customer->setMessage(s); // ��������� ��������� �� "�������� ���������" ���������
			break;
		// ���������� �������� ���������
		case 9:
			cout << provider->getMessage();
			break;
		// �������� �����
		case 10:
			provider->info_products_provider(); // ����� ��������� �������
			cout << "������� �������� ��������: ";
			cin >> new_product_name;
			cout << "������� �������� ����: ";
			cin >> new_product_price;
			cout << "������� ����������: ";
			cin >> new_product_count;
			new_product = Product(new_product_name, new_product_price, 0, 0, new_product_count); // �������� ������ ������ 
			provider->products_provider.emplace_back(new_product); // ���������� ������ � ������ �������
			break;
		// �������� ������
		case 11:
			provider->info_products_provider(); // ����� ��������� �������
			int i;
			cout << "������� ����� ������: ";
			cin >> i;
			provider->products_provider.erase(provider->products_provider.begin() + i); // �������� ������ ��� ������� i
			break;
		// �������� ���� ������
		case 12:
			provider->info_products_provider(); // ����� ��������� �������
			cout << "������� ����� ��������: ";
			cin >> i;
			cout << "������� ����: ";
			cin >> new_price;
			name_i = provider->getProductProvider()[i].getProduct_Name(); // �������� ������ ��� ������� i
			provider->getProductProvider()[i].setPrice(new_price); // ��������� ���� ������ ��� ������� i
			// ���� ������ ����� �� �������� � ������ � � ������ ������ ��� ����
			for (j = 0; j < (*request).products.size(); j++)
				if (request->products[j].getProduct_Name() == name_i)
					request->products[j].setPrice(new_price);
			break;
		// ����� �� ����
		case 0:
			cExit = true;;
			break;
		}
	}
}

//��������� ����
int main()
{
	setlocale(0, "Rus");
	int a;
	string input_login; // �������� �����
	string input_password; // �������� ������
	Provider PROVIDER; // ������ ����������
	Customer CUSTOMER; // ������ ���������
	Request REQUEST; // ������ �����
	Time t;

	while (true)
	{
		cout << "1. ����� ��� ��������" << endl;
		cout << "2. ����� ��� ���������" << endl;
		cout << "3. �����" << endl << endl;
		do {
			cout << "������� ����� �������: ";
			cin >> a;
		} while ((a < 1) || (a > 3));
		switch (a)
		{
		// ����� ��� ��������
		case 1:
			do {
				cout << "������� �����: ";
				cin >> input_login;
				cout << "������� ������: ";
				cin >> input_password;
			} while (CUSTOMER.getLogin() != input_login || CUSTOMER.getPassword() != input_password); // �������� ������������ �������� ������
			// � ���� ���������
			menu_customer(&CUSTOMER, &REQUEST, &PROVIDER);
			break;
		// ����� ��� ����������
		case 2:
			do
			{
				cout << "������� �����: ";
				cin >> input_login;
				cout << "������� ������: ";
				cin >> input_password;
			} while (PROVIDER.getLogin() != input_login || PROVIDER.getPassword() != input_password); // �������� ������������ �������� ������
			// � ���� ����������
			menu_provider(&PROVIDER, &CUSTOMER, &REQUEST);
			break;
		// �����
		case 3:
			exit(0);
			break;
		}
	}
}
