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
	cout << "Введите числитель дроби: ";
	cin >> numerator;
	f1.set_numerator(numerator);

	int denominator;
	cout << "Введите знаменатель дроби: ";
	cin >> denominator;
	f1.set_denominator(denominator);

	cout << "Первая дробь: ";
	f1.display();
	cout << "Вторая дробь: ";
	f2.display();
	cout << "Третья дробь: ";
	f3.display();

	// преобразование к базовым типам
	// -----------------------------------
	cout << "\n\n";
	cout << "Перевод первой дроби в int: " << (int)f1 << "\n";
	cout << "Перевод первой дроби в double: " << (double)f1 << "\n";
	// -----------------------------------

	// арифметические операции
	// -----------------------------------
	cout << "\n\n";
	cout << "Операции с дробями:\n";
	cout << "1) ";
	f1.display();
	cout << "2) ";
	f2.display();

	Fraction res;

	res = f1 + f2;
	cout << "Сумма дробей = ";
	res.display();

	res = f1 - f2;
	cout << "Разность дробей = ";
	res.display();

	res = f1 / f2;
	cout << "Частное дробей = ";
	res.display();

	res = f1 * f2;
	cout << "Произведение дробей = ";
	res.display();
	// -----------------------------------

	// сравнение дробей
	// -----------------------------------
	cout << "\n\n";
	cout << "Сравнение дробей\nПоиск максимальной дроби\n";

	if (f1 > f2)
	{
		cout << "Наибольшая дробь среди первых двух = ";
		f1.display();
	}
	else if (f1 < f2)
	{
		cout << "Наибольшая дробь среди первых двух = ";
		f2.display();
	}
	else
	{
		cout << "Дроби равны\n";
	}
	// -----------------------------------

	return 0;
}