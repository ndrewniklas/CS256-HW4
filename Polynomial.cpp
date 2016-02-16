#include <sstream>
#include <cmath>

#include "Polynomial.h"

// provide your function implementations here

Polynomial::Polynomial()
	:coeff(new double[1]), size(1)
{ 
}

Polynomial::Polynomial(double arr[], int n)
	:coeff(new double[n]), size(n)
{
	for(int i = 0; i < size; ++i){
		coeff[i] = arr[i];
	}
}

Polynomial::Polynomial(const Polynomial& other)
	:coeff(new double[other.size]), size(other.size)
{
	for(int i = 0; i < size; ++i){
		coeff[i] = other.coeff[i];
	}
}

Polynomial::Polynomial(int value)
	:coeff(new double[1]), size(1)
{
	coeff[0] = value;
}

Polynomial::Polynomial(double value)
	:coeff(new double[1]), size(1)
{
	coeff[0] = value;
}

Polynomial::~Polynomial(){
	if(coeff != nullptr){
		delete [] coeff;
		coeff = nullptr;
	}
	size = 0;
}

Polynomial& Polynomial::operator=(const Polynomial& right){
	if(this == &right){
		return *this;
	}
	if(right.size > size){
		delete []coeff;
		coeff = new double[right.size];
	}
	size = right.size;
	for(int i = 0; i < size; ++i){
		coeff[i] = right.coeff[i];
	}
	
	return *this;
}




























