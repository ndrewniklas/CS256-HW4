#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <string>

class PolyTester;

class Polynomial
{
    friend class PolyTester;

private:
    // add your instance variables here
	double* coeff;
	int size;
public:
    // add your function declarations here
	Polynomial();
	Polynomial(double arr[], int size);
	Polynomial(const Polynomial& other);
	Polynomial(int value);
	Polynomial(double value);
	~Polynomial();
	
	Polynomial& operator=(const Polynomial& right);
	
	int getSize() const;
	int degree() const;
	
	std::string str() const;
	
	double solve(double x) const;
	
};

#endif