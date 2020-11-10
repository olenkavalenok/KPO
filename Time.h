#pragma once

#include <iostream>
#include <list>
#include <string>

using namespace std;

// ¬–≈ћя
class Time
{
private:
	int day; // день закупки
	int hour; // час
	int minute; // минута
	int second; // секунда
public:
	Time(int day, int hour, int minute, int second); // конструктор
	Time(); // конструктор по умолчанию

	int getDay();
	void setDay(int day);

	int getHour();
	void setHour(int hour);

	int getMinute();
	void setMinute(int minute);

	int getSecond();
	void setSecond(int second);

	friend ostream& operator << (std::ostream& out, const Time& Time); // перегрузка оператора, вывод времени
};