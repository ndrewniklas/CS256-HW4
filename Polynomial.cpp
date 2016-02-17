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
	if(size == 1){
		return 0;
	}else{
		for(int i = size - 1; i >= 0; --i){
			if(!(std::islessequal(coeff[i], 0.0) && std::isgreaterequal(coeff[i], 0.0))){
				return i;
			}else if(i == 0){
				return i;
			}
		}
	}
	return -2;
}

std::string Polynomial::str() const{
	std::stringstream s;
	bool first = true;
	for(int i = size - 1; i >= 0; --i){
		if(std::islessequal(coeff[i], 0.0) && std::isgreaterequal(coeff[i], 0.0)){
			//coeff[i] == 0
			
		}else if(std::isless(coeff[i], -1.0)){
			//coeff[i] < -1
			first ? s <<  "-" : s <<  " - ";
			s <<  fabs(coeff[i]);
			if(i > 1){
				s <<  "x^";
				s <<  i;
			}else if(i == 1){
				s << "x";
			}
			
		}else if(std::isgreater(coeff[i], 1.0)){
			//coeff[i] > 1
			first ? s <<  "" : s <<	 " + ";
			s <<  fabs(coeff[i]);
			if(i > 1){
				s <<  "x^";
				s <<  i;
			}else if(i == 1){
				s << "x";
			}
			
		}else if(std::islessequal(coeff[i], 1.0) && std::isgreaterequal(coeff[i], 1.0)){
			//coeff[i] == 1
			first ? s <<  "" : s <<	 " + ";
			if(i > 1){
				s <<  "x^";
				s <<  i;
			}else if(i == 1){
				s << "x";
			}
			
		}else if(std::islessequal(coeff[i], -1.0) && std::isgreaterequal(coeff[i], -1.0)){
			//coeff[i] == -1
			first ? s <<  "-" : s <<  " - ";
			if(i > 1){
				s <<  "x^";
				s <<  i;
			}else if(i == 1){
				s << "x";
			}	
		}
		if(s.tellp() != 0){
			first = false;
		}
	}
	
	return s.str();
}

double Polynomial::solve(double x) const{
	double total = 0.0;
	double subTtl = 0.0;
	for(int i = size - 1; i >= 0; --i){
		subTtl = 0.0;
		//x^i
		subTtl = pow(x, i);
		//coeff * x^i
		subTtl *= coeff[i];
		
		total += subTtl;
	}
	
	return total;
}

void Polynomial::grow(int n){
	double* temp = new double[n];
	for(int i = 0; i < size; ++i){
		temp[i] = coeff[i];
	}
	for(int j = size; j < n; ++j){
		temp[j] = 0;
	}
	size = n;
	delete [] coeff;
	coeff = temp;
}

double& Polynomial::operator[](int n){
	// std::cout << "\nsize: " << size << std::endl;
	// std::cout << "n: " << n << std::endl;
	if(size <= n){
		grow(n + 1);
	}else if(size == n){
		grow(n + 1);
	}
	// std::cout << "new size: " << size << std::endl;
	return coeff[n];
}

Polynomial Polynomial::operator+(const Polynomial& right) const{
	int tmpSize = 0;
	int smaller = 0;
	if(size >= right.size){
		tmpSize = size;
		smaller = right.size;
	}else{
		tmpSize = right.size;
		smaller = size;
	}
	double* temp = new double[tmpSize];
	for(int i = 0; i < smaller; ++i){
		temp[i] = (coeff[i] + right.coeff[i]);
	}
	if(smaller == size){
		for(int j = smaller; j < tmpSize; ++j){
			temp[j] = right.coeff[j];
		}
	}else{
		for(int j = smaller; j < tmpSize; ++j){
			temp[j] = coeff[j];
		}
	}
	Polynomial p = Polynomial(temp, tmpSize);
	delete [] temp;
	temp = nullptr;
	return p;

}

Polynomial Polynomial::operator-(const Polynomial& right) const{
	double* temp = new double[right.size];
	for(int i = 0; i < right.size; ++i){
		temp[i] = -right.coeff[i];
	}
	Polynomial p = Polynomial(temp, right.size);
	delete [] temp;
	return *this + p;
}

Polynomial Polynomial::operator*(const Polynomial& right) const{
	int rsltSize = size + right.size - 1;
	double* rslt = new double[rsltSize];
	for(int i = 0; i < size; ++i){
		for(int j = 0; j < right.size; ++j){
			rslt[i + j] += (coeff[i] * right.coeff[j]);
		}
	}
	Polynomial p = Polynomial(rslt, rsltSize);
	delete [] rslt;
	return p;
}

Polynomial Polynomial::operator*(double n) const{
	double* rslt = new double[size];
	for(int i = 0; i < size; ++i){
		rslt[i] = n * coeff[i];
	}
	Polynomial p = Polynomial(rslt, size);
	delete [] rslt;
	return p;
}

Polynomial& Polynomial::operator+=(const Polynomial& right){
	*this = *this + right;
	return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& right){
	*this = *this - right;
	return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& right){
	*this = (*this) * right;
	return *this;
}






















std::ostream& operator<<(std::ostream& os, const Polynomial& p){
	os << p.str();
	return os;
}





