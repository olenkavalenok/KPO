#include <iostream>
#include <list>
#include <string>
#include "Time.h"

// �����������
Time::Time(int day, int hour, int minute, int second) 
{
	this->day = day; // ���� �������
	this->hour = hour; // ���
	this->minute = minute; // ������
	this->second = second; // �������
}

//����������� �� ���������
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

// ���������� ���������, ����� �������
ostream& operator << (std::ostream& out, const Time& Time)
{
	return out << Time.day << "." << Time.hour << "." << Time.minute << "." << Time.second;
}