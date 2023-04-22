#include "Fraction.hpp"
#include <iostream>
#include <locale>

int main()
{
	using namespace std;

	setlocale(LC_ALL, "rus");

	Fraction f1;
	Fraction f2(3, 7);
	Fraction f3(f2);

	int numerator;
	cout << "������� ��������� �����: ";
	cin >> numerator;
	f1.set_numerator(numerator);

	int denominator;
	cout << "������� ����������� �����: ";
	cin >> denominator;
	f1.set_denominator(denominator);

	cout << "������ �����: ";
	f1.display();
	cout << "������ �����: ";
	f2.display();
	cout << "������ �����: ";
	f3.display();

	// �������������� � ������� �����
	// -----------------------------------
	cout << "\n\n";
	cout << "������� ������ ����� � int: " << (int)f1 << "\n";
	cout << "������� ������ ����� � double: " << (double)f1 << "\n";
	// -----------------------------------

	// �������������� ��������
	// -----------------------------------
	cout << "\n\n";
	cout << "�������� � �������:\n";
	cout << "1) ";
	f1.display();
	cout << "2) ";
	f2.display();

	Fraction res;

	res = f1 + f2;
	cout << "����� ������ = ";
	res.display();

	res = f1 - f2;
	cout << "�������� ������ = ";
	res.display();

	res = f1 / f2;
	cout << "������� ������ = ";
	res.display();

	res = f1 * f2;
	cout << "������������ ������ = ";
	res.display();
	// -----------------------------------

	// ��������� ������
	// -----------------------------------
	cout << "\n\n";
	cout << "��������� ������\n����� ������������ �����\n";

	if (f1 > f2)
	{
		cout << "���������� ����� ����� ������ ���� = ";
		f1.display();
	}
	else if (f1 < f2)
	{
		cout << "���������� ����� ����� ������ ���� = ";
		f2.display();
	}
	else
	{
		cout << "����� �����\n";
	}
	// -----------------------------------

	return 0;
}