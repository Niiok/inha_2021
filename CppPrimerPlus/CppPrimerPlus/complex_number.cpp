#include "complex_number.h"


ComplexNumber::ComplexNumber(double real, double imaginary) : real_{ real }, imaginary_{ imaginary } {}

ComplexNumber ComplexNumber::operator+ (const ComplexNumber& ob) const
{
	return ComplexNumber(
		this->real_ + ob.real_,
		this->imaginary_ + ob.imaginary_);
}

ComplexNumber ComplexNumber::operator- (const ComplexNumber& ob) const
{
	return ComplexNumber(
		this->real_ - ob.real_,
		this->imaginary_ - ob.imaginary_);
}

ComplexNumber ComplexNumber::operator* (const ComplexNumber& ob) const
{
	return ComplexNumber(
		this->real_*ob.real_ - this->imaginary_*ob.imaginary_,
		this->real_*ob.imaginary_ + this->imaginary_*ob.real_);
}

ComplexNumber ComplexNumber::operator* (const double ob) const
{
	return ComplexNumber(
		this->real_*ob,
		this->imaginary_*ob);
}

ComplexNumber ComplexNumber::operator~ () const
{
	return ComplexNumber(
		this->real_,
		-this->imaginary_);
}

ComplexNumber operator* (const double num, const ComplexNumber& ob)
{
	return ob * num;
}

std::ostream& operator<< (std::ostream& os, ComplexNumber& ob)
{
	os << "(" << ob.real_ << ", " << ob.imaginary_ << "i" << ")";

	return os;
}

std::istream& operator>> (std::istream& is, ComplexNumber& ob)
{
	std::cout << "real part: ";
	is >> ob.real_;
	
	std::cout << "imaginary part: ";
	is >> ob.imaginary_;

	return is;
}