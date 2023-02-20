#include "Fraction.hpp"

#include <iostream>
#include <numeric>
#include <stdexcept>

using namespace std;

Fraction::Fraction()
{
	numerator = 0;
	denominator = 1;
}

Fraction::Fraction(const int& numerator, const int& denominator)
{
	this->numerator = numerator;
	if (denominator != 0)
	{
		this->denominator = denominator;
	}
	else
	{
		throw runtime_error("denominator cannot be zero");
	}
}

Fraction::Fraction(const Fraction& other)
{
	numerator = other.numerator;
	denominator = other.denominator;
}

void Fraction::display()
{
	cout << numerator << " / " << denominator << "\n";
}

void Fraction::set_numerator(const int& numerator)
{
	this->numerator = numerator;
}

void Fraction::set_denominator(const int& denominator)
{
	if (denominator != 0)
	{
		this->denominator = denominator;
	}
	else
	{
		throw runtime_error("denominator cannot be zero");
	}
}

Fraction::operator int() const
{
	return numerator / denominator;
}

Fraction::operator double() const
{
	return (double)numerator / denominator;
}

Fraction& Fraction::operator=(const Fraction& other)
{
	numerator = other.numerator;
	denominator = other.denominator;
	return *this;
}

Fraction& Fraction::operator+=(const Fraction& other)
{
	int common_denominator = lcm(denominator, other.denominator);

	numerator = numerator * (common_denominator / denominator) +
		other.numerator * (common_denominator / other.denominator);
	denominator = common_denominator;
	return *this;
}

Fraction& Fraction::operator-=(const Fraction& other)
{
	int common_denominator = lcm(denominator, other.denominator);

	numerator = numerator * (common_denominator / denominator) -
		other.numerator * (common_denominator / other.denominator);
	denominator = common_denominator;
	return *this;
}

Fraction operator+(const Fraction& fraction_1, const Fraction& fraction_2)
{
	Fraction result;
	int common_denominator = lcm(fraction_1.denominator, fraction_2.denominator);

	result.numerator = fraction_1.numerator * (common_denominator / fraction_1.denominator) +
		fraction_2.numerator * (common_denominator / fraction_2.denominator);
	result.denominator = common_denominator;
	return result;
}

Fraction operator-(const Fraction& fraction_1, const Fraction& fraction_2)
{
	Fraction result;
	int common_denominator = lcm(fraction_1.denominator, fraction_2.denominator);

	result.numerator = fraction_1.numerator * (common_denominator / fraction_1.denominator) -
		fraction_2.numerator * (common_denominator / fraction_2.denominator);
	result.denominator = common_denominator;
	return result;
}

Fraction operator*(const Fraction& fraction_1, const Fraction& fraction_2)
{
	Fraction result;
	result.numerator = fraction_1.numerator * fraction_2.numerator;
	result.denominator = fraction_1.denominator * fraction_2.denominator;
	return result;
}

Fraction operator/(const Fraction& fraction_1, const Fraction& fraction_2)
{
	Fraction result;
	result.numerator = fraction_1.numerator * fraction_2.denominator;
	result.denominator = fraction_1.denominator * fraction_2.numerator;
	return result;
}

bool operator>(const Fraction& fraction_1, const Fraction& fraction_2)
{
	double f_1 = (double)fraction_1;
	double f_2 = (double)fraction_2;

	if (f_1 > f_2)
		return true;
	else
		return false;
}

bool operator>=(const Fraction& fraction_1, const Fraction& fraction_2)
{
	if (fraction_1.denominator == fraction_2.denominator)
	{
		if (fraction_1.numerator == fraction_2.numerator)
			return true;
	}

	double f_1 = (double)fraction_1;
	double f_2 = (double)fraction_2;

	if (f_1 > f_2)
		return true;
	else
		return false;
}

bool operator<(const Fraction& fraction_1, const Fraction& fraction_2)
{
	double f_1 = (double)fraction_1;
	double f_2 = (double)fraction_2;

	if (f_1 < f_2)
		return true;
	else
		return false;
}

bool operator<=(const Fraction& fraction_1, const Fraction& fraction_2)
{
	if (fraction_1.denominator == fraction_2.denominator)
	{
		if (fraction_1.numerator == fraction_2.numerator)
			return true;
	}

	double f_1 = (double)fraction_1;
	double f_2 = (double)fraction_2;

	if (f_1 < f_2)
		return true;
	else
		return false;
}

bool operator==(const Fraction& fraction_1, const Fraction& fraction_2)
{
	int common_denominator = lcm(fraction_1.denominator, fraction_2.denominator);

	int num_1 = fraction_1.numerator * (common_denominator / fraction_1.denominator);
	int num_2 = fraction_2.numerator * (common_denominator / fraction_2.denominator);

	if (num_1 == num_2)
		return true;
	else
		return false;
}

bool operator!=(const Fraction& fraction_1, const Fraction& fraction_2)
{
	int common_denominator = lcm(fraction_1.denominator, fraction_2.denominator);

	int num_1 = fraction_1.numerator * (common_denominator / fraction_1.denominator);
	int num_2 = fraction_2.numerator * (common_denominator / fraction_2.denominator);

	if (num_1 != num_2)
		return true;
	else
		return false;
}

Fraction& Fraction::operator++()
{
	numerator += denominator;
	return *this;
}

Fraction& Fraction::operator--()
{
	numerator -= denominator;
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction temp(*this);
	numerator += denominator;
	return temp;
}

Fraction Fraction::operator--(int)
{
	Fraction temp(*this);
	numerator -= denominator;
	return temp;
}
