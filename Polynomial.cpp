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

int Polynomial::getSize() const{
	return size;
}

int Polynomial::degree() const{
	for(int i = size; i > 0; --i){
		if(rint(coeff[i]) != 0){
			return i;
		}
	}
	return -1;
}

std::string Polynomial::str() const{
	std::stringstream s;
	bool first = true;
	for(int i = size-1; i >= 0; --i){
		if(std::islessequal(coeff[i], 0.0) && std::isgreaterequal(coeff[i], 0.0)){
			//coeff[i] == 0
			
		}else if(std::isless(coeff[i], -1.0)){
			//coeff[i] < -1
			first ? s <<  "" : s <<  " - ";
			s <<  fabs(coeff[i]);
			if(i > 1){
				s <<  "x^";
				s <<  i;
			}else if(i == 1){
				s << "x";
			}
			
		}else if(std::isgreater(coeff[i], 1.0)){
			//coeff[i] > 1
			first ? s <<  "" : s <<  " + ";
			s <<  fabs(coeff[i]);
			if(i > 1){
				s <<  "x^";
				s <<  i;
			}else if(i == 1){
				s << "x";
			}
			
		}else if(std::islessequal(coeff[i], 1.0) && std::isgreaterequal(coeff[i], 1.0)){
			//coeff[i] == 1
			first ? s <<  "" : s <<  " + ";
			if(i > 1){
				s <<  "x^";
				s <<  i;
			}else if(i == 1){
				s << "x";
			}
			
		}else if(std::islessequal(coeff[i], -1.0) && std::isgreaterequal(coeff[i], -1.0)){
			//coeff[i] == -1
			first ? s <<  "" : s <<  " - ";
			if(i > 1){
				s <<  "x^";
				s <<  i;
			}else if(i == 1){
				s << "x";
			}	
		}
		first = false;
	}
	
	return s.str();
}


























