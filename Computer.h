#pragma once
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"

using namespace std;

class Computer {
public:
	//Код компьютера
	int computerID;
	//Название марки компьютера
	string computername;
	//Тип процессора
	string typeofCPU;
	//Частота процессора
	double CPUfrequency;
	//Объем оперативной памяти
	int capacityRAM;
	//Объем жесткого диска
	int capacityHDD;
	//Объем памяти видеокарты
	int capacityGPU;
	//Стоимость компьютера
	double Cost;
	//Количество экземпляров
	int Count;


	int typesearch;
	//конструктор по умолчанию
	Computer()
	{
		int computerID = 0;
		string computername = "";
		string typeofCPU = "";
		double CPUfrequency = 0;
		int capacityRAM = 0;
		int capacityHDD = 0;
		int capacityGPU = 0;
		double Cost = 0;
		int Count = 0;
	}

	//Изменение структуры "Компьютер"
	Computer ChangeComputer(Computer &result)
	{
		int num = InputNumber(0, 9, "Что хотите изменить\n1 - ID\n2 - Name\n3 - Type Cpu\n4 - frequency\n5 - Ram\n6 - Hdd\n7 - Gpu\n8 - cost\n9 - count\n0 - exit\n");
		switch (num)
		{
		case 1:
			result.computerID = InputNumber(0, 999999, "Введите новый код компьютера (0-999.999): ");
			break;
		case 2:
			result.computername = InputInformation("Введите новое имя компьютера: ");
			break;
		case 3:
			result.typeofCPU = InputInformation("Введите новый тип процессора: ");
			break;
		case 4:
			result.CPUfrequency = InputDoubleNumber(0, 6, "Введите новую частоту процессора (0-6 ГГц): ");
			break;
		case 5:
			result.capacityRAM = InputNumber(0, 256, "Введите новый объем оперативной памяти (0-256 GB): ");
			break;
		case 6:
			result.capacityHDD = InputNumber(0, 8192, "Введите новый объем жесткого диска (0-8.192 GB): ");
			break;
		case 7:
			result.capacityGPU = InputNumber(0, 16, "Введите новый объем памяти видеокарты (0-16 GB): ");
			break;
		case 8:
			result.Cost = InputDoubleNumber(0, 1000000, "Введите новую стоимость компьютера (0-1.000.000 руб.): ");
			break;
		case 9:
			result.Count = InputNumber(0, 100, "Введите новое количество экземпляров (0-100 шт.): ");
			break;
		case 0:
			break;
		default:
			break;
		}
		return result;
	}

	//Перегруженный оператор равенства для структуры "Компьютер"
	Computer& operator = (Computer c)
	{
		computerID = c.computerID;
		computername = c.computername;
		typeofCPU = c.typeofCPU;
		CPUfrequency = c.CPUfrequency;
		capacityRAM = c.capacityRAM;
		capacityHDD = c.capacityHDD;
		capacityGPU = c.capacityGPU;
		Cost = c.Cost;
		Count = c.Count;

		return (*this);
	}

	//Поиск равного элемента по выбранному критерию
	bool SearchElement(Computer second)
	{
		switch (typesearch)
		{
		case 1:
			return ((*this).typeofCPU == second.typeofCPU);
		case 2:
			return ((*this).capacityRAM == second.capacityRAM);
		case 3:
			return ((*this).capacityGPU == second.capacityGPU);
		case 4:
			return ((*this).capacityHDD == second.capacityHDD);
		default:
			return false;
		}
	}
};

//Функция ввода структуры "Компьютер" с консоли
Computer InputScreenComputer()
{
	Computer c;
	c.computerID = InputNumber(0, 999999, "Введите код компьютера (0-999.999): ");
	c.computername = InputInformation("Введите имя компьютера: ");
	c.typeofCPU = InputInformation("Введите тип процессора: ");
	c.CPUfrequency = InputDoubleNumber(0, 6, "Введите частоту процессора (0-6 ГГц): ");
	c.capacityRAM = InputNumber(0, 256, "Введите объем оперативной памяти (0-256 GB): ");
	c.capacityHDD = InputNumber(0, 8192, "Введите объем жесткого диска (0-8.192 GB): ");
	c.capacityGPU = InputNumber(0, 16, "Введите объем памяти видеокарты (0-16 GB): ");
	c.Cost = InputDoubleNumber(0, 1000000, "Введите стоимость компьютера (0-1.000.000 руб.): ");
	c.Count = InputNumber(0, 100, "Введите количество экземпляров (0-100 шт.): ");

	return c;
}

//Функция вывода структуры "Компьютер" на консоль
void OutputScreenComputer(Computer c)
{
	cout << "Код компьютера: " << c.computerID << endl;
	cout << "Имя марки компьютера: " << c.computername << endl;
	cout << "Тип процессора: " << c.typeofCPU << endl;
	cout << "Частота процессора: " << c.CPUfrequency << " ГГц" << endl;
	cout << "Объем оперативной памяти: " << c.capacityRAM << " GB" << endl;
	cout << "Объем жесткого диска: " << c.capacityHDD << " GB" << endl;
	cout << "Объем памяти видеокарты: " << c.capacityGPU << " GB" << endl;
	cout << "Стоимость компьютера: " << c.Cost << " руб." << endl;
	cout << "Количество экземпляров: " << c.Count << " шт." << endl;
}

//Перевод структуры "Компьютер" в строку
string ToString(Computer c, int i)
{
	string result = "Запись № " + to_string(i) + "\r\n" + "Код компьютера: " + to_string(c.computerID) + "\r\n" + "Имя компьютера: " + c.computername + "\r\n" + "Тип процессора: "
		+ c.typeofCPU + "\r\n" + "Частота процессора (В ГГц): " + to_string(c.CPUfrequency) + "\r\n"
		+ "Объем оперативной памяти (В GB): " + to_string(c.capacityRAM) + "\r\n" + "Объем жесткого диска (B GB): " +
		to_string(c.capacityHDD) + "\r\n" + "Объем памяти видеокарты (B DB): " + to_string(c.capacityGPU) + "\r\n" +
		"Стоимость компьютера (В руб.): " + to_string(c.Cost) + "\r\n" + "Количество экземпляров (В шт.): " + to_string(c.Count) + "\r\n";
	return result;
}

//Считывание структуры "Компьютер" из строки
Computer ReadFromString(ifstream& input)
{
	Computer result;
	string s;
	try
	{
		if (!input.eof())
		{
			getline(input, s);
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Код компьютера: ";
			result.computerID = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Имя компьютера: ";
			result.computername = s.substr(wrd.length(), s.length()).c_str();
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Тип процессора: ";
			result.typeofCPU = s.substr(wrd.length(), s.length()).c_str();
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Частота процессора (В ГГц): ";
			result.CPUfrequency = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Объем оперативной памяти (B GB): ";
			result.capacityRAM = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Объем жесткого диска (B GB): ";
			result.capacityHDD = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Объем памяти видеокарты (B GB): ";
			result.capacityGPU = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Стоимость компьютера (B руб.): ";
			result.Cost = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Количество экземпляров (В шт.): ";
			result.Count = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
	}
	catch (...)
	{
		cout << "Ошибка записи в файл!" << endl;
	}
	return result;
}

//Ввод критерия поиска в зависимости от выбранного типа
Computer InputChangeTypeSearch(int typesearch)
{
	Computer result;
	switch (typesearch)
	{
	case 1:
		result.typeofCPU = InputInformation("Введите тип процессора: ");
		return result;
	case 2:
		result.capacityRAM = InputNumber(0, 256, "Введите объем оперативной памяти (0-256 GB) :");
		return result;
	case 3:
		result.capacityGPU = InputNumber(0, 16, "Введите объем памяти видеокарты (0-16 GB): ");
		return result;
	case 4:
		result.capacityHDD = InputNumber(0, 8192, "Введите объем жесткого диска (0-8.192 GB): ");
		return result;
	default:
		return result;
	}
}

//Сравнение структур в зависимости от выбранного поля для сортировки
int Sort(Computer first, Computer second, int typesearch)
{
	switch (typesearch)
	{
	case 1:
		if (first.typeofCPU > second.typeofCPU) return 1;
		else if (first.typeofCPU < second.typeofCPU) return -1;
		else return 0;
	case 2:
		if (first.capacityRAM > second.capacityRAM) return 1;
		else if (first.capacityRAM < second.capacityRAM) return -1;
		else return 0;
	case 3:
		if (first.capacityGPU > second.capacityGPU) return 1;
		else if (first.capacityGPU < second.capacityGPU) return -1;
		else return 0;
	case 4:
		if (first.capacityHDD > second.capacityHDD) return 1;
		else if (first.capacityHDD < second.capacityHDD) return -1;
		else return 0;
	default:
		return -2;
	}
};