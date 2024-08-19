#pragma once
#include "poly.h"


class Shape
{
public:
	Shape(const Poly& base, double height, double density);
	
public:
	double surface() const;
	double volume() const;
	double mass() const;
	
private:
	void _CalcSurface();
	void _CalcVolume();
	void _CalcMass();
	
private:
	Poly _base = Poly(-1);
	double _height;
	double _density;
	double _surface;
	double _volume;
	double _mass;
};


Shape::Shape(const Poly& base, double height, double density)
	: _base(base), _height(height), _density(density)
{
	_CalcSurface();
	_CalcVolume();
	_CalcMass();
}

double Shape::surface() const
{
	return _surface;
}

double Shape::volume() const
{
	return _volume;
}

double Shape::mass() const
{
	return _mass;
}

void Shape::_CalcSurface()
{
	double lateral = _base.perimeter() * _height;
	_surface = lateral + (2 * _base.area());
}

void Shape::_CalcVolume()
{
	_volume = _base.area() * _height;
}

void Shape::_CalcMass()
{
	_mass = _volume * _density;
}
