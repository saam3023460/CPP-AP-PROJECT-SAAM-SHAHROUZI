#pragma once
#include <cmath>


const double PI = std::acos(-1);


class Poly
{
	public:
		Poly(double radius);
		Poly(unsigned int num, double radius);
		
	public:
		double perimeter() const;
		double area() const;
		
	private:
		void _CalcPerim();
		void _CalcArea();
		
	private:
		int _num;
		double _radius;
		double _angle;
		double _perimeter;
		double _area;	
};


Poly::Poly(double radius)
: _num(-1), _radius(radius), _angle(0)
{
	_perimeter = 2 * PI * _radius;
	_area = PI * _radius * _radius;
}


Poly::Poly(unsigned int num, double radius)
: _num(num), _radius(radius)
{
	_angle = 2 * PI / _num;
	_CalcPerim();
	_CalcArea();
}


double Poly::perimeter() const
{
	return _perimeter;
}


double Poly::area() const
{
	return _area;
}


void Poly::_CalcPerim()
{
	double side = std::sqrt(2 * _radius * _radius * (1 - std::cos(_angle)));
	_perimeter = _num * side;
}


void Poly::_CalcArea()
{
	_area = _num * _radius * _radius * std::sin(_angle) / 2;
}


