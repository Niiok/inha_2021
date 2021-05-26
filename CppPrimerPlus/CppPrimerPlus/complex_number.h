#ifndef ___COMPLEX_NUMBER
#define ___COMPLEX_NUMBER

#include<iostream>

class ComplexNumber {

public:
	ComplexNumber(double real, double imaginary);
	
private:
	double real_;
	double imaginary_;

public:
	ComplexNumber operator+ (const ComplexNumber& ob) const;
	ComplexNumber operator- (const ComplexNumber& ob) const;
	ComplexNumber operator* (const ComplexNumber& ob) const;
	ComplexNumber operator* (const double ob) const;
	ComplexNumber operator~ () const;
	friend ComplexNumber operator* (const double num, const ComplexNumber& ob);
	friend std::ostream& operator<< (std::ostream& os, ComplexNumber& ob);
	friend std::istream& operator>> (std::istream& is, ComplexNumber& ob);
};

ComplexNumber operator* (const double num, const ComplexNumber& ob);
std::ostream& operator<< (std::ostream& os, ComplexNumber& ob);
std::istream& operator>> (std::istream& is, ComplexNumber& ob);

#endif