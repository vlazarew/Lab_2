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
	//��� ����������
	int computerID;
	//�������� ����� ����������
	string computername;
	//��� ����������
	string typeofCPU;
	//������� ����������
	double CPUfrequency;
	//����� ����������� ������
	int capacityRAM;
	//����� �������� �����
	int capacityHDD;
	//����� ������ ����������
	int capacityGPU;
	//��������� ����������
	double Cost;
	//���������� �����������
	int Count;


	int typesearch;
	//����������� �� ���������
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

	//��������� ��������� "���������"
	Computer ChangeComputer(Computer &result)
	{
		int num = InputNumber(0, 9, "��� ������ ��������\n1 - ID\n2 - Name\n3 - Type Cpu\n4 - frequency\n5 - Ram\n6 - Hdd\n7 - Gpu\n8 - cost\n9 - count\n0 - exit\n");
		switch (num)
		{
		case 1:
			result.computerID = InputNumber(0, 999999, "������� ����� ��� ���������� (0-999.999): ");
			break;
		case 2:
			result.computername = InputInformation("������� ����� ��� ����������: ");
			break;
		case 3:
			result.typeofCPU = InputInformation("������� ����� ��� ����������: ");
			break;
		case 4:
			result.CPUfrequency = InputDoubleNumber(0, 6, "������� ����� ������� ���������� (0-6 ���): ");
			break;
		case 5:
			result.capacityRAM = InputNumber(0, 256, "������� ����� ����� ����������� ������ (0-256 GB): ");
			break;
		case 6:
			result.capacityHDD = InputNumber(0, 8192, "������� ����� ����� �������� ����� (0-8.192 GB): ");
			break;
		case 7:
			result.capacityGPU = InputNumber(0, 16, "������� ����� ����� ������ ���������� (0-16 GB): ");
			break;
		case 8:
			result.Cost = InputDoubleNumber(0, 1000000, "������� ����� ��������� ���������� (0-1.000.000 ���.): ");
			break;
		case 9:
			result.Count = InputNumber(0, 100, "������� ����� ���������� ����������� (0-100 ��.): ");
			break;
		case 0:
			break;
		default:
			break;
		}
		return result;
	}

	//������������� �������� ��������� ��� ��������� "���������"
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

	//����� ������� �������� �� ���������� ��������
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

//������� ����� ��������� "���������" � �������
Computer InputScreenComputer()
{
	Computer c;
	c.computerID = InputNumber(0, 999999, "������� ��� ���������� (0-999.999): ");
	c.computername = InputInformation("������� ��� ����������: ");
	c.typeofCPU = InputInformation("������� ��� ����������: ");
	c.CPUfrequency = InputDoubleNumber(0, 6, "������� ������� ���������� (0-6 ���): ");
	c.capacityRAM = InputNumber(0, 256, "������� ����� ����������� ������ (0-256 GB): ");
	c.capacityHDD = InputNumber(0, 8192, "������� ����� �������� ����� (0-8.192 GB): ");
	c.capacityGPU = InputNumber(0, 16, "������� ����� ������ ���������� (0-16 GB): ");
	c.Cost = InputDoubleNumber(0, 1000000, "������� ��������� ���������� (0-1.000.000 ���.): ");
	c.Count = InputNumber(0, 100, "������� ���������� ����������� (0-100 ��.): ");

	return c;
}

//������� ������ ��������� "���������" �� �������
void OutputScreenComputer(Computer c)
{
	cout << "��� ����������: " << c.computerID << endl;
	cout << "��� ����� ����������: " << c.computername << endl;
	cout << "��� ����������: " << c.typeofCPU << endl;
	cout << "������� ����������: " << c.CPUfrequency << " ���" << endl;
	cout << "����� ����������� ������: " << c.capacityRAM << " GB" << endl;
	cout << "����� �������� �����: " << c.capacityHDD << " GB" << endl;
	cout << "����� ������ ����������: " << c.capacityGPU << " GB" << endl;
	cout << "��������� ����������: " << c.Cost << " ���." << endl;
	cout << "���������� �����������: " << c.Count << " ��." << endl;
}

//������� ��������� "���������" � ������
string ToString(Computer c, int i)
{
	string result = "������ � " + to_string(i) + "\r\n" + "��� ����������: " + to_string(c.computerID) + "\r\n" + "��� ����������: " + c.computername + "\r\n" + "��� ����������: "
		+ c.typeofCPU + "\r\n" + "������� ���������� (� ���): " + to_string(c.CPUfrequency) + "\r\n"
		+ "����� ����������� ������ (� GB): " + to_string(c.capacityRAM) + "\r\n" + "����� �������� ����� (B GB): " +
		to_string(c.capacityHDD) + "\r\n" + "����� ������ ���������� (B DB): " + to_string(c.capacityGPU) + "\r\n" +
		"��������� ���������� (� ���.): " + to_string(c.Cost) + "\r\n" + "���������� ����������� (� ��.): " + to_string(c.Count) + "\r\n";
	return result;
}

//���������� ��������� "���������" �� ������
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
			string wrd = "��� ����������: ";
			result.computerID = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "��� ����������: ";
			result.computername = s.substr(wrd.length(), s.length()).c_str();
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "��� ����������: ";
			result.typeofCPU = s.substr(wrd.length(), s.length()).c_str();
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "������� ���������� (� ���): ";
			result.CPUfrequency = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����� ����������� ������ (B GB): ";
			result.capacityRAM = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����� �������� ����� (B GB): ";
			result.capacityHDD = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "����� ������ ���������� (B GB): ";
			result.capacityGPU = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "��������� ���������� (B ���.): ";
			result.Cost = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "���������� ����������� (� ��.): ";
			result.Count = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
	}
	catch (...)
	{
		cout << "������ ������ � ����!" << endl;
	}
	return result;
}

//���� �������� ������ � ����������� �� ���������� ����
Computer InputChangeTypeSearch(int typesearch)
{
	Computer result;
	switch (typesearch)
	{
	case 1:
		result.typeofCPU = InputInformation("������� ��� ����������: ");
		return result;
	case 2:
		result.capacityRAM = InputNumber(0, 256, "������� ����� ����������� ������ (0-256 GB) :");
		return result;
	case 3:
		result.capacityGPU = InputNumber(0, 16, "������� ����� ������ ���������� (0-16 GB): ");
		return result;
	case 4:
		result.capacityHDD = InputNumber(0, 8192, "������� ����� �������� ����� (0-8.192 GB): ");
		return result;
	default:
		return result;
	}
}

//��������� �������� � ����������� �� ���������� ���� ��� ����������
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