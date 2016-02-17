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
	void grow(int n);
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
	
	double& operator[](int n);
	
	Polynomial operator+(const Polynomial& right) const;
	Polynomial operator-(const Polynomial& right) const;
	Polynomial operator*(const Polynomial& right) const;
	Polynomial operator*(double n) const;
	
	Polynomial& operator+=(const Polynomial& right);
	Polynomial& operator-=(const Polynomial& right);
	Polynomial& operator*=(const Polynomial& right);
	
};

std::ostream& operator<<(std::ostream& os, const Polynomial& p);

#endif
