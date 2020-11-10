#include <iostream>
#include <list>
#include <string>
#include "Request.h"
#include "Provider.h"
#include "Customer.h"
#include <iomanip>
#include <cstring>
#include <sstream>
#include "windows.h"
#include <conio.h>

using namespace std;

// СИСТЕМА

// МЕНЮ "ЗАКАЗ"
void menu_request(Request* request, Provider* provider)
{
	system("cls");
	int a;
	int j;
	bool flag = true;
	int input_count;
	Time new_time;
	bool aExit = false;
	while (!aExit)
	{
		cout << "\n" << setw(40) << "Изменить список товаров" << setw(35) << "Изменить время закупки.....4" << endl;
		cout << setw(40) << "Удалить товар.......................1" << endl;
		cout << setw(40) << "Добавить товар......................2" << endl;
		cout << setw(40) << "Изменить количество товара..........3" << setw(35) << "Назад......................0" << endl << endl;
		do {
			cout << "Введите номер функции: ";
			cin >> a;
		} while ((a < 0) || (a > 4));
		switch (a)
		{
			// УДАЛИТЬ ТОВАР
		case 1:
			system("cls");
			cout << endl;
			request->info_products(); // вывод товаров в заказе
			int i;
			do {
				cout << "Введите номер товара: ";
				cin >> i;
			} while ((i < 0) || (i > request->products.size()-1));
			request->products.erase(request->products.begin() + i); // удаление товара под номером i
			break;
			// ДОБАВИТЬ ТОВАР
		case 2:
			system("cls");
			cout << endl;
			provider->info_products_provider(); // вывод списка товаров, которые есть у поставщика
			do {
				cout << "Введите номер товара: ";
				cin >> i;
			} while ((i < 0) || (i > provider->products_provider.size() - 1));
			for (j = 0; j < request->products.size(); j++)
				if (request->products[j].getProduct_Name() == provider->getProductProvider()[i].getProduct_Name()) // проверяем, есть ли выбранный товар в заказе
					flag = false;
			if (flag == true)
				request->products.emplace_back(provider->getProductProvider()[i]); // добавление в заказ товара под номером i, если его до этого не было
			else
				cout << "\n" << "Товар уже добавлен" << endl;
			break;
			// ИЗМЕНИТЬ К-ВО ТОВАРА
		case 3:
			system("cls");
			cout << endl;
			request->info_products(); // вывод товаров в заказе 
			do {
				cout << "Введите номер товара: ";
				cin >> i;
			} while ((i < 0) || (i > request->products.size() - 1));
			cout << "Введите количество: ";
			cin >> input_count;
			request->products[i].setCount(input_count); // изменяем к-во товара под номером i
			break;
			// ИЗМЕНИТЬ ВРЕМЯ ЗАКУПКИ
		case 4:
			system("cls");
			cout << endl;
			int new_day, new_hour, new_minute, new_second; // новые параметры времени
			cout << "Введите время" << endl;
			do {
				cout << "День: ";
				cin >> new_day;
			} while ((new_day < 1) || (new_day > 28));
			do {
				cout << "Час: ";
				cin >> new_hour;
			} while ((new_hour < 0) || (new_hour > 23));
			do {
				cout << "Минута: ";
				cin >> new_minute;
			} while ((new_minute < 0) || (new_minute > 59));
			do {
				cout << "Секунда: ";
				cin >> new_second;
			} while ((new_second < 0) || (new_second > 59));
			// устанавливаем значения параметров
			new_time.setDay(new_day);
			new_time.setHour(new_hour);
			new_time.setMinute(new_minute);
			new_time.setSecond(new_second);
			request->setTime(new_time); // устанавливаем новое время
			break;
			// ВЫХОД ИЗ МЕНЮ
		case 0:
			aExit = true;
			system("cls");
			break;
		}
	}
}

// МЕНЮ ЗАКАЗЧИКА
void menu_customer(Customer* customer, Request* request, Provider* provider)
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a;
	bool aExit = false;
	string new_name; // новое имя
	string new_login; // новый логин
	string new_password; // новый пароль
	string new_telephone; // новый телефон
	string new_email; // новый адрес эл. почты
	string new_numcard; // новый номер карты
	string input_message;
	string input_email;

	// генерирует номер заказа
	setlocale(0, "");
	int random;
	srand(time(NULL));
	random = 0 + rand() % +100;
	(*request).setNumber(random); // устанавливаем номер заказа

	request->fixDemand(); // устанавливаем к-во товаров в зависимости от спроса
	while (!aExit)
	{
		cout << "\n" << setw(40) << "Изменить данные" << setw(30) << "Заказ" << endl;

		cout << setw(40) << "Изменить имя........................1" << setw(30) << "Посмотреть заказ......7" << setw(30) << "Входящие сообщения...10" << endl;
		cout << setw(40) << "Изменить логин......................2" << setw(30) << "Изменить заказ........8" << setw(30) << "Отправить сообщение..11" << endl;
		cout << setw(40) << "Изменить пароль.....................3" << setw(30) << "Отправить заказ.......9" << endl;
		cout << setw(40) << "Изменить телефон....................4" << endl;
		cout << setw(40) << "Изменение адреса эл. почты..........5" << endl;
		cout << setw(40) << "Изменение реквизитов зачисления.....6" << setw(60) << "Выход.................0" << endl << endl;

		do {
			cout << "Введите номер функции: ";
			cin >> a;
		} while ((a < 0) || (a > 11));
		switch (a)
		{
			// ИЗМЕНИТЬ ИМЯ
		case 1:
			system("cls");
			cout << endl;
			cout << "Введите новое имя: ";
			cin >> new_name;
			customer->setName(new_name);
			break;
			// ИЗМЕНИТЬ ЛОГИН
		case 2:
			system("cls");
			cout << endl;
			cout << "Введите новый логин: ";
			cin >> new_login;
			customer->setLogin(new_login);
			break;
			// ИЗМЕНИТЬ ПАРОЛЬ
		case 3:
			system("cls");
			cout << endl;
			cout << "Введите новый пароль: ";
			cin >> new_password;
			customer->setPassword(new_password);
			break;
			// ИЗМЕНИТЬ ТЕЛЕФОН
		case 4:
			system("cls");
			cout << endl;
			cout << "Введите новый телефон: ";
			cin >> new_telephone;
			customer->setTelephone(new_telephone);
			break;
			// ИЗМЕНИТЬ АДРЕС ЭЛ. ПОЧТЫ
		case 5:
			system("cls");
			cout << endl;
			cout << "Введите новый адрес эл. почты: ";
			cin >> new_email;
			customer->setEmail(new_email);
			break;
			// ИЗМЕНИТЬ НОМЕР КАРТЫ
		case 6:
			system("cls");
			cout << endl;
			cout << "Введите новый номер карты: ";
			cin >> new_numcard;
			customer->setNumcard(new_numcard);
			break;
			// ПОСМОТРЕТЬ ЗАКАЗ
		case 7:
			system("cls");
			cout << endl;
			request->info_request();
			break;
			// ИЗМЕНИТЬ ЗАКАЗ
		case 8:
			menu_request(&(*request), &(*provider)); // в меню "ЗАКАЗ"
			break;
			// ОТПРАВИТЬ ЗАКАЗ
		case 9:
			system("cls");
			cout << endl;
			provider->setIncomingRequest(*request); // добавляет заказ во "Входящие заказы" поставщика
			break;
			// ПОСМОТРЕТЬ ВХОДЯЩИЕ СООБЩЕНИЯ
		case 10:
			system("cls");
			cout << endl;
			cout << customer->getMessage();
			break;
			// ОТПРАВИТЬ СООБЩЕНИЕ
		case 11:
			system("cls");
			cout << endl;
			do {
				cout << "Введите адрес почты: ";
				cin >> input_email;
			} while (provider->getEmail() != input_email); // проверка правильности введённых данных
			cout << "Введите сообщение" << endl;
			cin.get();
			getline(cin, input_message); // сообщение
			provider->setMessage(input_message); // добавляем сообщение во "Входящие сообщения" поставщика
			break;
			// ВЫХОД ИЗ МЕНЮ
		case 0:
			aExit = true;
			break;
		}
	}
}

// МЕНЮ ПОСТАВЩИКА
void menu_provider(Provider* provider, Customer* customer, Request* request)
{	
	system("cls");
	int c;
	int i, j;
	bool cExit = false;
	double new_price; // новая цена
	string new_name; // новое имя
	string new_login; // новый логин
	string new_password; // новый пароль
	string new_telephone; // новый телефон
	string new_email; // новый адрес эл. почты
	string new_numcard; // новый номер карты
	string input_email;
	string name_i;
	string s;
	ostringstream ost;

	string new_product_name; // название нового товара
	double new_product_price; // цена нового товара
	int new_product_count; // количество нового товара
	Product new_product;

	while (!cExit)
	{
		cout << "\n" << setw(40) << "Изменить данные" << setw(35) << "Заказ" << setw(25) << "Товары" << endl;

		cout << setw(40) << "Изменить имя........................1" << setw(35) << "Входящий заказ................7" << setw(25) << "Добавить продукт....10" << endl;
		cout << setw(40) << "Изменить логин......................2" << setw(35) << "Письмо о подтверждении........8" << setw(25) << "Удалить продукт.....11" << endl;
		cout << setw(40) << "Изменить пароль.....................3" << setw(60) << "Изменить цену.......12" << endl;
		cout << setw(40) << "Изменить телефон....................4" << endl;
		cout << setw(40) << "Изменение адреса эл. почты..........5" << endl;
		cout << setw(40) << "Изменение реквизитов зачисления.....6" << setw(35) << "Входящие сообщения............9" << setw(25) << "Выход................0" << endl << endl;
		do
		{
			cout << "Введите номер функции: ";
			cin >> c;
		} while (c < 0 || c > 12);
		switch (c)
		{
			// ИЗМЕНИТЬ ИМЯ
		case 1:
			system("cls");
			cout << endl;
			cout << "Введите новое имя: ";
			cin >> new_name;
			provider->setName(new_name);
			break;
			// ИЗМЕНИТЬ ЛОГИН
		case 2:
			system("cls");
			cout << endl;
			cout << "Введите новый логин: ";
			cin >> new_login;
			provider->setLogin(new_login);
			break;
			// ИЗМЕНИТЬ ПАРОЛЬ
		case 3:
			system("cls");
			cout << endl;
			cout << "Введите новый пароль: ";
			cin >> new_password;
			provider->setPassword(new_password);
			break;
			// ИЗМЕНИТЬ ТЕЛЕФОН
		case 4:
			system("cls");
			cout << endl;
			cout << "Введите новый телефон: ";
			cin >> new_telephone;
			provider->setTelephone(new_telephone);
			break;
			// ИЗМЕНИТЬ АДРЕС ЭЛ. ПОЧТЫ
		case 5:
			system("cls");
			cout << endl;
			cout << "Введите новый адрес эл. почты: ";
			cin >> new_email;
			provider->setEmail(new_email);
			break;
			// ИЗМЕНИТЬ НОМЕР КАРТЫ
		case 6:
			system("cls");
			cout << endl;
			cout << "Введите новый номер карты: ";
			cin >> new_numcard;
			provider->setNumcard(new_numcard);
			break;
			// ПОСМОТРЕТЬ ВХОДЯЩИЙ ЗАКАЗ
		case 7:
			system("cls");
			cout << endl;
			provider->getIncomingRequest().info_request();
			break;
			// ОТПРАВКА ПОДТВЕРЖДЕНИЯ
		case 8:
			system("cls");
			cout << endl;
			do {
				cout << "Введите адрес почты: ";
				cin >> input_email;
			} while (customer->getEmail() != input_email); // проверка правильности введённых данных
			ost << request->getNumber(); // номер заказа
			s = "Заказ № " + ost.str() + " получен"; // сообщение
			customer->setMessage(s); // добавляем сообщение во "Входящие сообщения" заказчика
			break;
			// ПОСМОТРЕТЬ ВХОДЯЩИЕ СООБЩЕНИЯ
		case 9:
			system("cls");
			cout << endl;
			cout << provider->getMessage();
			break;
			// ДОБАВИТЬ ТОВАР
		case 10:
			system("cls");
			cout << endl;
			provider->info_products_provider(); // вывод имеющихся товаров
			cout << "Введите название продукта: ";
			cin >> new_product_name;
			cout << "Введите название цену: ";
			cin >> new_product_price;
			cout << "Введите количество: ";
			cin >> new_product_count;
			new_product = Product(new_product_name, new_product_price, 0, 0, new_product_count); // создание нового товара 
			provider->products_provider.emplace_back(new_product); // добавление товара в список товаров
			break;
			// УДАЛЕНИЕ ТОВАРА
		case 11:
			system("cls");
			cout << endl;
			provider->info_products_provider(); // вывод имеющихся товаров
			int i;
			do {
				cout << "Введите номер товара: ";
				cin >> i;
			} while ((i < 0) || (i > provider->products_provider.size() - 1));
			provider->products_provider.erase(provider->products_provider.begin() + i); // удаление товара под номером i
			break;
			// ИЗМЕНИТЬ ЦЕНУ ТОВАРА
		case 12:
			system("cls");
			cout << endl;
			provider->info_products_provider(); // вывод имеющихся товаров
			do {
				cout << "Введите номер товара: ";
				cin >> i;
			} while ((i < 0) || (i > provider->products_provider.size() - 1));
			cout << "Введите цену: ";
			cin >> new_price;
			name_i = provider->getProductProvider()[i].getProduct_Name(); // название товара под номером i
			provider->getProductProvider()[i].setPrice(new_price); // изменение цены товара под номером i
			// ищем данный товар по названию в заказе и в заказе меняем его цену
			for (j = 0; j < (*request).products.size(); j++)
				if (request->products[j].getProduct_Name() == name_i)
					request->products[j].setPrice(new_price);
			break;
			// ВЫХОД ИЗ МЕНЮ
		case 0:
			cExit = true;;
			break;
		}
	}
}

//НАЧАЛЬНОЕ МЕНЮ
int main()
{
	setlocale(0, "Rus");
	int a;
	string input_login; // введённый логин
	string input_password; // введённый пароль
	Provider PROVIDER; // создаём поставщика
	Customer CUSTOMER; // создаём заказчика
	Request REQUEST; // создаём заказ
	Time t;

	while (true)
	{
		system("cls");
		cout << "\n" << "1. Войти как заказчик" << endl;
		cout << "2. Войти как поставщик" << endl;
		cout << "3. Выход" << endl << endl;
		do {
			cout << "Введите номер функции: ";
			cin >> a;
		} while ((a < 1) || (a > 3));
		switch (a)
		{
			// ВОЙТИ КАК ЗАКАЗЧИК
		case 1:
			do {
				cout << "\n" << "Введите логин: ";
				cin >> input_login;
				cout << "Введите пароль: ";
				cin >> input_password;
			} while (CUSTOMER.getLogin() != input_login || CUSTOMER.getPassword() != input_password); // проверка правильности введённых данных
			// В МЕНЮ ЗАКАЗЧИКА
			menu_customer(&CUSTOMER, &REQUEST, &PROVIDER);
			break;
			// ВОЙТИ КАК ПОСТАВЩИКА
		case 2:
			do
			{
				cout << "\n" << "Введите логин: ";
				cin >> input_login;
				cout << "Введите пароль: ";
				cin >> input_password;
			} while (PROVIDER.getLogin() != input_login || PROVIDER.getPassword() != input_password); // проверка правильности введённых данных
			// В МЕНЮ ПОСТАВЩИКА
			menu_provider(&PROVIDER, &CUSTOMER, &REQUEST);
			break;
			// ВЫХОД
		case 3:
			exit(0);
			break;
		}
	}
}
