#pragma once

#include <cmath>

namespace complex_numbers {

// TODO: add your solution here

	struct Complex {
		double realValue;
		double imagValue;

		Complex(double real, double imaginary) {
			this->realValue = real;
			this->imagValue = imaginary;
		}

		/*Complex& operator+=(const Complex& rhs) {
			return *this;
		}*/

		double real() const {
			return realValue;
		}

		double imag() const {
			return imagValue;
		}

		friend Complex operator+(const Complex& lhs, const Complex& rhs) {
			return Complex{ lhs.realValue + rhs.realValue, lhs.imagValue + rhs.imagValue };
		}

		friend Complex operator+(const Complex& lhs, double rhs) {
			return Complex{ lhs.realValue + rhs, lhs.imagValue };
		}

		friend Complex operator+(double lhs, const Complex& rhs) {
			return rhs + lhs;
		}

		friend Complex operator-(const Complex& lhs, const Complex& rhs) {
			return Complex{ lhs.realValue - rhs.realValue, lhs.imagValue - rhs.imagValue };
		}

		friend Complex operator-(const Complex& lhs, double rhs) {
			return Complex{ lhs.realValue - rhs, lhs.imagValue };
		}

		friend Complex operator-(double lhs, const Complex& rhs) {
			return Complex{ lhs - rhs.realValue, -rhs.imagValue };
		}

		friend Complex operator*(const Complex& lhs, const Complex& rhs) {
			return Complex{ (lhs.realValue * rhs.realValue) - (lhs.imagValue * rhs.imagValue),
				(lhs.realValue * rhs.imagValue) + (lhs.imagValue * rhs.realValue) };
		}

		friend Complex operator*(const Complex& lhs, double rhs) {
			return Complex{ (lhs.realValue * rhs),
				(lhs.imagValue * rhs) };
		}

		friend Complex operator*(double lhs, const Complex& rhs) {
			return rhs * lhs;
		}

		friend Complex operator/(const Complex& lhs, const Complex& rhs) {
			return Complex{ ((lhs.realValue * rhs.realValue) + (lhs.imagValue * rhs.imagValue)) / (std::pow(rhs.realValue, 2) + std::pow(rhs.imagValue, 2)),
				((lhs.imagValue * rhs.realValue) - (lhs.realValue * rhs.imagValue)) / (std::pow(rhs.realValue, 2) + std::pow(rhs.imagValue, 2)) };

		}

		friend Complex operator/(const Complex& lhs, double rhs) {
			return Complex{ (lhs.realValue / rhs),
				(lhs.imagValue / rhs) };

		}

		friend Complex operator/(double lhs, const Complex& rhs) {
			return Complex{ lhs * rhs.realValue / (std::pow(rhs.realValue, 2) + std::pow(rhs.imagValue, 2)),
				- lhs * rhs.imagValue / (std::pow(rhs.realValue, 2) + std::pow(rhs.imagValue, 2)) };
		}

		double abs() const {
			return std::sqrt(std::pow(this->realValue, 2) + std::pow(this->imagValue, 2));
		}

		Complex conj() const {
			return Complex{ this->realValue, -this->imagValue };
		}

		Complex exp() const {
			double expPart = std::exp(this->realValue);
			return Complex{ expPart * std::cos(this->imagValue), expPart * std::sin(this->imagValue) };
		}
	};

}  // namespace complex_numbers
