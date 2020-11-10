#pragma once

#include <iostream>
#include <list>
#include <string>

using namespace std;

// �����
class Time
{
private:
	int day; // ���� �������
	int hour; // ���
	int minute; // ������
	int second; // �������
public:
	Time(int day, int hour, int minute, int second); // �����������
	Time(); // ����������� �� ���������

	int getDay();
	void setDay(int day);

	int getHour();
	void setHour(int hour);

	int getMinute();
	void setMinute(int minute);

	int getSecond();
	void setSecond(int second);

	friend ostream& operator << (std::ostream& out, const Time& Time); // ���������� ���������, ����� �������
};