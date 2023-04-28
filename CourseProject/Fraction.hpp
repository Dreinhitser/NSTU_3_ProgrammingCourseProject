#ifndef FRACTION
#define FRACTION

class Fraction
{
private:
	int numerator;
	int denominator;

public:
	Fraction();
	Fraction(const int& numerator, const int& denominator);
	Fraction(const Fraction& other);

	void display();

	int get_numerator() { return numerator; }
	int get_denominator() { return denominator; }

	void set_numerator(const int& numerator);
	void set_denominator(const int& denominator);

	operator int() const;
	operator double() const;

	Fraction& operator=(const Fraction& other);
	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);
	
	// префикс
	Fraction& operator++();
	Fraction& operator--();

	// постфикс
	Fraction operator++(int);
	Fraction operator--(int);

	friend Fraction operator+(const Fraction& fraction_1, const Fraction& fraction_2);
	friend Fraction operator-(const Fraction& fraction_1, const Fraction& fraction_2);
	friend Fraction operator*(const Fraction& fraction_1, const Fraction& fraction_2);
	friend Fraction operator/(const Fraction& fraction_1, const Fraction& fraction_2);

	friend bool operator>(const Fraction& fraction_1, const Fraction& fraction_2);
	friend bool operator>=(const Fraction& fraction_1, const Fraction& fraction_2);
	friend bool operator<(const Fraction& fraction_1, const Fraction& fraction_2);
	friend bool operator<=(const Fraction& fraction_1, const Fraction& fraction_2);
	friend bool operator==(const Fraction& fraction_1, const Fraction& fraction_2);
	friend bool operator!=(const Fraction& fraction_1, const Fraction& fraction_2);
};

#endif // !FRACTION
