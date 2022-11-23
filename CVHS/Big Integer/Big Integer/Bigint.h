// BigInt.h - header for big Integer class
// 2-18-20

#ifndef BIGINT_H
#define BIGINT_H
#pragma once
#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;

class BigInt
{
	friend ostream &operator<<(ostream &, const BigInt &);

public:
	static const int digits = 100;	// maximum number of digits in number

	BigInt(long = 0);				// converts an int or long to a BigInt
	BigInt(const string &);			// allows for number enter as string

	// BigInt num1("23423250348953405834685465462341");

	BigInt operator+(const BigInt &) const;		// allows you to add BigInt + BigInt
	BigInt operator+(int) const;				// allows you to add BigInt + int
	BigInt operator+(const string &) const;		// allows you to add BigInt + string of digits

	BigInt operator-(const BigInt &) const;		
	BigInt operator-(int) const;				
	BigInt operator-(const string &) const;		

private:
	short integer[digits];
};

BigInt::BigInt(long value)
{
	// set every location in the array to zero
	for (int x = 0; x < digits; x++)
	{
		integer[x] = 0;
	}

	// split the digits and store them in reverse in the array
	for (int x = digits - 1; value!=0 && x >= 0; x--)
	{
		integer[x] = value % 10;
		value /= 10;
	}
}

BigInt::BigInt(const string &number)
{
	for (int x = 0; x < digits; x++)
	{
		integer[x] = 0;
	}

	// get number of digits in string
	int length = number.size();

	for (int x = digits - length, y = 0; x < digits; x++, y++)
	{
		if (isdigit(number[y]))
		{
			integer[x] = number[y] - '0';
		}
	}
}

BigInt BigInt::operator+(const BigInt &right) const
{
	BigInt temp;

	int carry = 0;

	for (int x = digits - 1; x >= 0; x--)
	{
		temp.integer[x] = integer[x] + right.integer[x] + carry;

		if (temp.integer[x] > 9)
		{
			carry = 1;
			temp.integer[x] %= 10;
		}
		else
		{
			carry = 0;
		}
	}

	return temp;
}

BigInt BigInt::operator+(int right) const
{
	return *this + BigInt(right);
}

BigInt BigInt::operator+(const string &right) const
{
	return *this + BigInt(right);
}

BigInt BigInt::operator-(const BigInt &right) const
{
	BigInt temp;

	int carry = 0;

	for (int x = digits - 1; x >= 0; x--)
	{
		temp.integer[x] = integer[x] - carry - right.integer[x];

		if (temp.integer[x] < 0)
		{
			carry = 1;
			temp.integer[x] += 10;
		}
		else
		{
			carry = 0;
		}
	}

	return temp;
}

BigInt BigInt::operator-(int right) const
{
	return *this - BigInt(right);
}

BigInt BigInt::operator-(const string &right) const
{
	return *this - BigInt(right);
}

ostream& operator<<(ostream &output, const BigInt &num)
{
	int x;

	for (x = 0; (num.integer[x] == 0) && (x <= BigInt::digits); x++)
	{
		// DO NOTHING HERE - skip to the first non-zero digit
	}

	if (x == BigInt::digits)
	{
		output << 0;
	}
	else
	{
		for (; x < BigInt::digits; x++)
		{
			output << num.integer[x];
		}
	}

	return output;
}
#endif