#include <iostream>
#include <cmath>
#include <sstream>
#include <set>
#include <vector>
#include <map>
using namespace std;

int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}

class Rational {
public:
    Rational() {
    	numerator = 0;
    	denominator = 1;
    }

    Rational(int input_numerator, int input_denominator) {
    	int gcf = gcd(input_numerator, input_denominator);		//Greatest common factor
		numerator = input_numerator/gcf;
		denominator  = input_denominator/gcf;
		if (denominator < 0)
		{
			denominator = -denominator;
			numerator = -numerator;
		}
    }

    int Numerator() const {
    	return numerator;
    }

    int Denominator() const {
    	return denominator;
    }

private:
    int numerator;
    int denominator;
};

bool operator == (const Rational& lhs, const Rational& rhs)
{
	 return lhs.Numerator() == rhs.Numerator() &&
	      lhs.Denominator() == rhs.Denominator();
}

Rational operator + (const Rational& lhs, const Rational& rhs)
{
	return {
		lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator()
	};
}

Rational operator - (const Rational& lhs, const Rational& rhs)
{
	return {
		lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator()
	};
}

Rational operator * (const Rational& lhs, const Rational& rhs)
{
	return  {
		lhs.Numerator() * rhs.Numerator(),
		lhs.Denominator() * rhs.Denominator()
	};
}

Rational operator / (const Rational& lhs, const Rational& rhs)
{
	return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

ostream& operator << (ostream& stream, const Rational& number)
{
	return stream << number.Numerator() << "/" << number.Denominator();
}

istream& operator >> (istream& stream, Rational& number)
{
	int new_numerator, new_denominator;
	char c;
	if(stream)
	{
		stream >> new_numerator >> c >> new_denominator;
		if(stream  && c == '/')
			number = Rational(new_numerator, new_denominator);
	}
	return stream;
}

bool operator < (const Rational& lhs, const Rational& rhs)
{
	return (lhs - rhs).Numerator() < 0;
}

int main()  {
	return 0;
}
