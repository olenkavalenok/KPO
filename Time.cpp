#include <iostream>
#include <list>
#include <string>
#include "Time.h"

// конструктор
Time::Time(int day, int hour, int minute, int second) 
{
	this->day = day; // день закупки
	this->hour = hour; // час
	this->minute = minute; // минута
	this->second = second; // секунда
}

//конструктор по умолчанию
Time::Time() 
{
	this->day = 01;
	this->hour = 10;
	this->minute = 30;
	this->second = 00;
}

int Time::getDay()
{
	return this->day;
}
void Time::setDay(int day)
{
	this->day = day;
}

int Time::getHour()
{
	return this->hour;
}
void Time::setHour(int hour)
{
	this->hour = hour;
}

int Time::getMinute()
{
	return this->minute;
}
void Time::setMinute(int minute)
{
	this->minute = minute;
}

int Time::getSecond()
{
	return this->second;
}
void Time::setSecond(int second)
{
	this->second = second;
}

// перегрузка оператора, вывод времени
ostream& operator << (std::ostream& out, const Time& Time)
{
	return out << Time.day << "." << Time.hour << "." << Time.minute << "." << Time.second;
}